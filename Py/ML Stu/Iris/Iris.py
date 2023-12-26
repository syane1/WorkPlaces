import os
import pandas as pd
import requests
import matplotlib.pyplot as plt
import numpy as np
import msvcrt
import seaborn as sns
import statsmodels.api as sm
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split

#将工作目录改为当前目录
#os.chdir(os.)

#%% 获取Iris
PATH = os.path.dirname(os.path.realpath(__file__))+'\\Data\\' 

r = requests.get('https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data')

#CSV文件
with open (PATH+'iris.data','w')as f:
    f.write(r.text)

os.chdir(PATH)
#通过Pandas读取csv，并增加列名，若自身已包含列名，Pandas会自行解析
df = pd.read_csv(PATH+'iris.data',names=['萼长','萼宽','瓣长','瓣宽','类'])
#标题
print(df.head())
#列
print(df['萼长'])
#前四行前三列(但去除标题行和序号列，实际也就3行2列)
print(df.iloc[:3, :2])

#%% Matplotlib Python绘图库鼻祖
#解决中文显示问题
plt.rcParams['font.sans-serif'] = ['KaiTi'] # 指定默认字体
plt.rcParams['axes.unicode_minus'] = False # 解决保存图像是负号'-'显示为方块的问题

'''
#直方图(全)
#将风格设置为近似 R 中的 ggplot 库
plt.style.use('ggplot')
#设置插图在记事本中可见（VSCode不可用，Jupyter可用） %matplotlib inline
#创建高6宽4英寸的直方图
fig, ax = plt.subplots(figsize=(6,4))
#用hist传数据，并设置为黑色
ax.hist(df['瓣宽'], color='black')
#xy的标签
ax.set_ylabel('计数', fontsize=12)
ax.set_xlabel('宽度', fontsize=12)
#全图的标题，增加了默认字体的大小，调整y轴相对顶部的位置
plt.title('鸢尾花 瓣宽', fontsize=14, y=1.01)

#直方图(4分)
#创建高6宽4英寸的直方图，两行两列的子图
fig, ax = plt.subplots(2,2, figsize=(6,4))
ax[0][0].hist(df['瓣宽'], color='gray')
ax[0][0].set_ylabel('计数', fontsize=12)
ax[0][0].set_xlabel('宽度', fontsize=12)
ax[0][0].set_title('鸢尾花 瓣宽', fontsize=14, y=1.01)

ax[0][1].hist(df['瓣长'], color='gray')
ax[0][1].set_ylabel('计数', fontsize=12)
ax[0][1].set_xlabel('长度', fontsize=12)
ax[0][1].set_title('鸢尾花 瓣长', fontsize=14, y=1.01)

ax[1][0].hist(df['萼宽'], color='gray')
ax[1][0].set_ylabel('计数', fontsize=12)
ax[1][0].set_xlabel('宽度', fontsize=12)
ax[1][0].set_title('鸢尾花 萼宽', fontsize=14, y=1.01)

ax[1][1].hist(df['萼长'], color='gray')
ax[1][1].set_ylabel('计数', fontsize=12)
ax[1][1].set_xlabel('长度', fontsize=12)
ax[1][1].set_title('鸢尾花 萼长', fontsize=14, y=1.01)
#自动调整子图避免排版过于拥挤
plt.tight_layout()

#散点图
fig, ax = plt.subplots(figsize=(6,6))
ax.scatter(df['瓣宽'],df['瓣长'], color='green')
ax.set_xlabel('瓣宽')
ax.set_ylabel('瓣长')
ax.set_title('花瓣 长-宽 散点图')

#线图
fig, ax = plt.subplots(figsize=(6,6))
ax.plot(df['瓣长'], color='blue')
ax.set_xlabel('标本 数量')
ax.set_ylabel('瓣长')
ax.set_title('瓣长 线图')

#堆积条形图
fig, ax = plt.subplots(figsize=(6,6))
bar_width = .8
#取出所有包含长宽的列的列名
labels = [x for x in df.columns if '长' in x or '宽' in x]
#按照取出的列名，获取不同类的各种长宽属性的平均值
ver_y = [df[df['类']=='Iris-versicolor'][x].mean() for x in labels]
vir_y = [df[df['类']=='Iris-virginica'][x].mean() for x in labels]
set_y = [df[df['类']=='Iris-setosa'][x].mean() for x in labels]
x = np.arange(len(labels))
#讲x，y的值传递给bar()方法
ax.bar(x, vir_y, bar_width, bottom=set_y, color='darkgray')
ax.bar(x, set_y, bar_width, bottom=ver_y, color='white')
ax.bar(x, ver_y, bar_width, color='black')
#为了让x轴的标签对其，将调整标签之间的间隔，设为x加bar_width(0.8)的一般
ax.set_xticks(x + (bar_width/2))
#用列名代替1、2、3、4
ax.set_xticklabels(labels, rotation=-70, fontsize=12)
ax.set_title('各类平均特征测量值 堆积条形图', y=1.01)
#用来描述每个序列的图例（右上角）
ax.legend(['Virginica','Setosa','Versicolor'])
'''

#%% Seaborn 统计可视化
#中文乱码解决
sns.set_style('whitegrid',{'font.sans-serif':['simhei','Arial']}) 
#配对图
'''
#仅需这一行即可获得多个特性的点图和柱状图
sns.pairplot(df,hue="类")

#小提琴图
fig, ax = plt.subplots(2, 2, figsize=(7, 7))
sns.set(style='white', palette='muted')
sns.violinplot(x=df['类'], y=df['萼长'], ax=ax[0,0])
sns.violinplot(x=df['类'], y=df['萼宽'], ax=ax[0,1])
sns.violinplot(x=df['类'], y=df['瓣长'], ax=ax[1,0])
sns.violinplot(x=df['类'], y=df['瓣宽'], ax=ax[1,1])
#为每个子图添加一个标题
fig.suptitle('小提琴图', fontsize=16, y=1.03)
#遍历用列名代替1、2、3、4
for i in ax.flat:
    plt.setp(i.get_xticklabels(), rotation=-90)
fig.tight_layout()
'''

#%% Pandas 数据分析工具
#Map 转变数据框的某个列
'''
#批改列值
df['类'] = df['类'].map({'Iris-setosa':'SET', 'Iris-virginica':'VIR', 'Iris-versicolor':'VER'})
df

#Apply 让我们既可以在数据框上工作，也可以在序列上工作
#新增一列叫宽花瓣，大于1.3的设为1，否则为0，v为瓣宽这列
df['宽花瓣'] = df['瓣宽'].apply(lambda v: 1 if v >= 1.3 else 0)
df
#r为整个数据框，新增一列“面积”
df['花瓣面积'] = df.apply(lambda r: r['瓣长'] * r['瓣宽'],axis=1)

#Applymap 常见用法是根据一定的条件标准来转变或格式化每一个单元
df.applymap(lambda v: np.log(v) if isinstance(v, float) else v)

#Groupby https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.groupby.html
mean = df.groupby('类').mean()
des = df.groupby('类').describe()
uni = df.groupby('瓣宽')['类'].unique().to_frame()
#根据类别来分组花瓣宽度，用最大减最小的，列三列
agg = df.groupby('类')['瓣宽'].agg([('delta',lambda x: x.max() - x.min()),('max',np.max),('min',np.min)])
#agg = df.groupby('类')['瓣宽'].agg({'delta': lambda x: x.max() - x.min(),'max': np.max, 'min': np.min})
'''

#%% Statsmodels 探索数据 估计模型 运行统计校验
'''
#通过散点图来目测二者关系，正向的线性关系
fig, ax = plt.subplots(figsize=(7,7))
ax.scatter(df['萼宽'][:50], df['萼长'][:50])
ax.set_ylabel('花萼的长度')
ax.set_xlabel('花萼的宽度')
ax.set_title('Setosa的 萼宽 vs. 萼长', fontsize=14,y=1.02)

#线性回归模型 y = B0 + B1x
y = df['萼长'][:50]
x = df['萼宽'][:50]
X = sm.add_constant(x)
results = sm.OLS(y, X).fit()
print(results.summary())
#利用结果绘制回归线
fig, ax = plt.subplots(figsize=(7,7))
ax.plot(x, results.fittedvalues, label='回归线')
ax.scatter(x, y, label='数据点', color='r')
ax.set_ylabel('萼长')
ax.set_xlabel('萼宽')
ax.set_title('Setosa 萼宽 vs. 萼长', fontsize=14,y=1.02)
ax.legend(loc=2)
'''

#%% scikit-learn  Python机器学习包之王，分类、回归、聚类、降维、模型选择和预处理
#实例化随机森林分类器
clf = RandomForestClassifier(max_depth=5, n_estimators=10)
#iloc原本为ix
#自由变量n*m矩阵X
X = df.iloc[:,:4]
#因变量y，n*1维向量
y = df.iloc[:,4]
#将数据打乱分成训练组和测试组的模块，30%分配给测试组
X_train, X_test, y_train, y_test = train_test_split(X, y,test_size=.3)
#将切分的测试组传递给分类器来拟合模型
clf.fit(X_train,y_train)
#通过测试数据来调用分类器的预测方法
y_pred = clf.predict(X_test)
rf = pd.DataFrame(list(zip(y_pred, y_test)), columns=['预测','实际'])
rf['正确否'] = rf.apply(lambda r: 1 if r['预测']==r['实际'] else 0, axis=1)
#预测准确率
rf['正确否'].sum()/rf['正确否'].count()

#特征在决策树中划分叶子节点的相对能力
f_importances = clf.feature_importances_
f_names = df.columns[:4]
#计算标准差
f_std = np.std([tree.feature_importances_ for tree in clf.estimators_], axis=0)
zz = zip(f_importances, f_names, f_std)
zzs = sorted(zz, key=lambda x: x[0], reverse=True)
#显示图标
imps = [x[0] for x in zzs]
labels = [x[1] for x in zzs]
errs = [x[2] for x in zzs]
plt.bar(range(len(f_importances)), imps, color="r", yerr=errs,align="center")
plt.xticks(range(len(f_importances)), labels)

#切换分类器并使用支持向量机(SVM)
from sklearn.multiclass import OneVsRestClassifier
from sklearn.svm import SVC
#仅仅是这行改为了支持向量机SVM，其余不变
clf = OneVsRestClassifier(SVC(kernel='linear'))
X = df.iloc[:,:4]
#SVM无法像随机森林分类器那样，将标签解释为Numpy的字符串
y = np.array(df.iloc[:,4]).astype(str)
X_train, X_test, y_train, y_test = train_test_split(X, y,test_size=.3)
clf.fit(X_train,y_train)
y_pred = clf.predict(X_test)
rf = pd.DataFrame(list(zip(y_pred, y_test)), columns=['预测','实际'])
rf['正确否'] = rf.apply(lambda r: 1 if r['预测'] == r['实际'] else 0, axis=1)
res = rf['正确否'].sum()/rf['正确否'].count()
rf

#%% 末尾停留
c = msvcrt.getch() 
