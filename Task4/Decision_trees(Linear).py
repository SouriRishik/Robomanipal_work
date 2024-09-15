import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeRegressor
from sklearn.preprocessing import StandardScaler
from sklearn.impute import SimpleImputer

from sklearn.metrics import r2_score, mean_squared_error

# Load dataset
df = pd.read_csv('linear_regression_dataset.csv')

# Define dependent and independent variables
dependent_variable = 'TOTCHG'
independent_variables = df.columns[df.columns != dependent_variable]

X = df[independent_variables].values
y = df[dependent_variable].values

# Split the dataset into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)

# Impute missing values with mean
imputer = SimpleImputer(strategy='mean')
X_train = imputer.fit_transform(X_train)
X_test = imputer.transform(X_test)

# Scale features
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Create and train Decision Tree Regressor with tuned hyperparameters
reg = DecisionTreeRegressor(criterion="squared_error", max_depth=15, min_samples_split=5, random_state=5)
reg.fit(X_train, y_train)

# Make predictions
y_pred = reg.predict(X_test)

# Evaluate the model using RMSE
rmse = mean_squared_error(y_test, y_pred, squared=False)
print(f"Root Mean Squared Error (RMSE): {rmse}")
print( r2_score(y_test, y_pred))
