import paddle.fluid as fluid
#定义张量
x1=fluid.layers.fill_constant(shape=[2,2],value=1,dtype='int64')
x2=fluid.layers.fill_constant(shape=[2,2],value=1,dtype='int64')
#进行张量加计算
y1=fluid.layers.sum(x=[x1,x2])
#创建一个使用cpu的执行器
place=fluid.CPUPlace()
exe=fluid.executor.Executor(place)
#参数初始化
exe.run(fluid.default_startup_program())
#进行运算，输出结果
result = exe.run(program=fluid.default_main_program(),fetch_list=[y1])
print(result)