#已失败，故而注释
'''
from pywinauto.application import Application
from pywinauto import Desktop
import time

# 对于Windows中自带应用程序，直接执行，对于外部应用应输入完整路径
app = Application().start(r"D:\lebo\PCCast\PCCast.exe")
# 睡眠1s
time.sleep(1) 
# 获取乐播投屏的窗口
dlg = app.window(best_match="乐播投屏")

# 打印其底下的控件
dlg.print_control_identifiers()
cc = dlg.child_window(title='开始投屏')
wraper = cc.wrapper_object()
wraper.click()
cw = dlg.child_window(title="乐播投屏")
cw.print_control_identifiers()
'''