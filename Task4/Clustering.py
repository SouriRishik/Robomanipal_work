import pandas as pd
pd.options.mode.chained_assignment = None
import warnings
warnings.simplefilter(action='ignore',category=FutureWarning)
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import make_pipeline

data=pd.read_csv('C:\\Users\\SOURI\\Desktop\\Robomanipal\\weatherAUS.csv')
cat = data.select_dtypes(include=['object', 'category']).columns
data= pd.get_dummies(data, columns=cat, drop_first=True)
data=data.fillna(data.mean())

features = ['MinTemp', 'MaxTemp', 'Rainfall', 'WindGustSpeed', 'Humidity9am', 'Humidity3pm', 'Temp9am', 'Temp3pm']
X = data[features]

X = SimpleImputer(strategy='mean').fit_transform(X)
X_std = StandardScaler().fit_transform(X)


inertia = []
for n_clusters in range(1, 15):
    kmeans = KMeans(n_clusters=n_clusters, random_state=42)
    kmeans.fit(X_std)
    inertia.append(kmeans.inertia_)

plt.plot(range(1, 15), inertia, marker='o')
plt.title('Elbow Method for Optimal Number of Clusters')
plt.xlabel('Number of Clusters')
plt.ylabel('Inertia (Within-cluster sum of squares)')
plt.show()

def pseudo_accuracy(labels, true_labels):
        correct_assignments = np.sum(labels == true_labels)
        total_points = len(true_labels)
        accuracy = correct_assignments / total_points
        return accuracy

k = 2
predicted_labels = kmeans.fit_predict(X_std)

# Calculate silhouette score
silhouette_avg = silhouette_score(X_std, predicted_labels)
print("Silhouette Score:", silhouette_avg)
kmeans = KMeans(n_clusters=k, random_state=42)
kmeans.fit(X_std)

cluster_centers = kmeans.cluster_centers_
print("Cluster Centers:")
print(pd.DataFrame(cluster_centers, columns=features))

plt.scatter(X_std[:, 0], X_std[:, 1], c=kmeans.labels_, cmap='viridis', alpha=0.5)
plt.scatter(cluster_centers[:, 0], cluster_centers[:, 1], c='red', marker='X', s=100)
plt.title('K-means Clustering')
plt.xlabel('MinTemp (Standardized)')
plt.ylabel('MaxTemp (Standardized)')
plt.show()
