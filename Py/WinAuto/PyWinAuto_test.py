import time
import os
import pywinauto
from pywinauto.keyboard import send_keys

#time.sleep(1)
#点击显示适配器
#subprocess.run(["adb", "shell", "input", "tap", "350", "2200"])
# 打开设备管理器
os.system("start devmgmt.msc")

time.sleep(1)

# 使用快捷键打开显示适配器属性
keys_str = "{TAB}{DOWN 5}{RIGHT 2}+{F10}{DOWN}{ENTER}{DOWN}{ENTER}{TAB 3}{ENTER}{DOWN}{PGDN 3}{UP}{ENTER}"
send_keys(keys_str)

app = pywinauto.Application().connect(title_re="Update Drivers*")# 使用正则表达式匹配标题
window = app.window(title_re="Update Drivers.*") # 获取窗口对象
window.wait("exists", timeout=30) # 等待窗口存在，最多10秒

send_keys("{ENTER}")
send_keys(keys_str)

time.sleep(15)

send_keys("{ENTER}")

# 选择显示适配器
#item = tv.GetItem("AqsPC")



# 获取显示适配器的坐标位置
#item_loc = item.rectangle.rectangle().mid_point()

# 点击显示适配器
#app.click_input(coords=(item_loc.x, item_loc.y), double=True)
