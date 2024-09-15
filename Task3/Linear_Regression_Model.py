import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.metrics import r2_score
#Reading csv file
data = pd.read_csv('C:\\Users\\SOURI\\Desktop\\Robomanipal\\linear_regression_dataset.csv')

#Initializing m and b to zero
m, b = np.array([0, 0, 0, 0, 0]), 0
m_temp, b_temp = m, b

#To count number of iterations
n = 1

#To run till convergence
while True:

    #To check for convergence
    d = 0

    #To iterate between all rows of csv file
    for i in range (1, 501):

        #Reading row i - 1
        z = list(data.iloc[i - 1])
        
        #Storing value of y = TOTCHG value
        y = z[4] / 48388

        #Storing only features in z
        z.remove(z[4])

        #Simple feature scaling
        z[0] = z[0] / 17
        z[2] = z[2] / 41
        z[3] = z[3] / 6
        z[4] = z[4] / 952

        #Converting to numpy array
        x = np.array(z)

        #Editing m_temp and b_temp
        m_temp = m_temp - 0.1 * (1 / 500) * (np.dot(m, x) + b - y) * (np.dot(1, x))
        b_temp = b_temp - 0.1 * (1 / 500) * (np.dot(m, x) + b - y)
    
    #To check if m_temp and m converge
    c = m_temp.round(6) == m.round(6)
    if False in list(c):
        d = d + 1
    if d == 0:
        break

    #Changing value of m and b
    m = m_temp
    b = b_temp

    #Adding iterations and printing when a multiple of 100 is reached
    n = n + 1
    if n % 100 == 0:
        print (n)

def plot (listt, maxx, index, strr):
    
    #x list
    x = list([listt.iloc[i] for i in range(0, 500)])
    for i in range (len(x)):
        x[i] = x[i] / maxx
    
    #y list
    y = []
    for i in x:
        y.append(m[index] * i + b)

    #Plotting points
    plt.scatter(listt / maxx, data.TOTCHG / 48388, color = 'red', label = 'Data Points')
    plt.xlabel(strr)
    plt.ylabel("TOTCHG")
    plt.title("Linear Regression")

    #Plotting line
    plt.plot(x, y, color = 'black', label = 'Linear Regression Line')
    plt.legend()
    plt.show()

def r2 (m, b):

    #x values
    x0 = np.array(list(data['AGE'])) / 17
    x1 = np.array(list(data['FEMALE']))
    x2 = np.array(list(data['LOS'])) / 41
    x3 = np.array(list(data['RACE'])) / 6
    x4 = np.array(list(data['APRDRG'])) / 952

    #y values
    y1 = np.array(list(data['TOTCHG'])) / 48388

    #Predictions
    predictions = []
    for i in range(500):
        x = [x0[i], x1[i], x2[i], x3[i], x4[i]]
        predictions.append(np.dot(m, x) + b)

    return(r2_score(y1,predictions))

    # #Mean calculation
    # mean = 0
    # for i in y1:
    #     mean = mean + i
    # mean = mean / len(y1)
    
    # #Calculating sum of square distances between given values and mean
    # given_to_mean = 0
    # for i in y1:
    #     given_to_mean = given_to_mean + ((i - mean) ** 2)
    
    # #Calculating sum of square distances between predicted values and mean
    # pred_to_mean = 0
    # for i in predictions:
    #     pred_to_mean = pred_to_mean + ((i - mean) ** 2)

    # #Returning r2 score
    # return pred_to_mean / given_to_mean

print ((r2(m, b))*100)

plot(data.AGE, 17, 0, "AGE")
plot(data.FEMALE, 1, 1, "FEMALE")
plot(data.LOS, 41, 2, "LOS")
plot(data.RACE, 6, 3, "RACE")
plot(data.APRDRG, 952, 4, "APRDRG")