import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#输出5*5的单位矩阵单位矩阵
'''
eye_5 = np.eye(5)
eye_5 
'''

#h画出数据
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号
#1.读取数据
path = "ML Stu/AndrewNg/ex1/ex1data1.txt"
data = pd.read_csv(path,header=None,names=["人口","盈利"])
#2.打印表格
print(data.head())
#3.画分布图
data.plot(kind="scatter",x="人口",y="盈利",figsize=(5,3))
plt.show()

#这个部分计算J(Ѳ),即Cost函数，X是矩阵
def computeCost(X, y, theta):
    inner = np.power(((X*theta.T)-y),2)
    return np.sum(inner)/(2*len(X))

#在第0列插入一列1,作为θ,此时data为 θ x y
data.insert(0,"θ",1)

#获取data的形状?(维度/行列数)中的列数
cols = data.shape[1]
#X为所有行,第一到倒数第二列数据
X = data.iloc[:,:-1]
#Y为所有行,倒数第一列
Y = data.iloc[:,cols-1:cols]

#观察一下数据
print(X.head())
print(Y.head())

#转换为numpy矩阵
X = np.matrix(X.values)
Y = np.matrix(Y.values)
#θ也需要初始化
theta = np.matrix(np.array([0,0]))

print(computeCost(X,Y,theta))

#梯度下降函数
def gradientDescent(X,y,theta,alpha,iters):
    #先定义一个theta形状的全0的矩阵
    temp = np.matrix(np.zeros(theta.shape))
    #获取theta的个数(ravel函数可以先行后列将矩阵所有的元素拉成一个一维矩阵,然后获取其列数,其含义即为获取theta个数)
    parameters = int(theta.ravel().shape[1])
    #设定初始的cost为iters个0
    cost = np.zeros(iters)

    #第i次迭代
    for i in range(iters):
        #这边的matrix.T是转置矩阵的意思
        #此处的error不是错误的意思,更准确来讲应该是误差的意思,即计算值与实际值的误差
        error = (X*theta.T) - y

        for j in range(parameters):
            #求偏导数,即期望值与实际值的误差*X,求和,再除于X的个数
            term = np.multiply(error,X[:,j])
            temp[0,j] = theta[0,j] - (alpha/len(X)*np.sum(term))
        
        #将当前步骤求出的偏导数还给theta,从而让它可以选择下一步梯度下降的方向和大小
        theta = temp
        cost[i] = computeCost(X,Y,theta)
            
    return theta,cost 

alpha = 0.001
iter = 15000
print(gradientDescent(X,Y,theta,alpha,iter))