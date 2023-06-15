import time
from pywinauto.application import Application
from pywinauto import Desktop

app = Application().start(r"D:\lebo\PCCast\PCCast.exe")
dlg = Desktop(backend="uia").window(title="PCCast")
time.sleep(1)
for ctrl in app.descendants():
    print("Control:", ctrl.window_text(), ctrl.control_type)