import cv2
import numpy as np
import os
import pyautogui
from pywinauto.application import Application
from pywinauto import Desktop
import time
import subprocess

#变量定义
# 获取当前运行的Python文件的目录
current_dir = os.path.dirname(os.path.abspath(__file__))
cache_dir_name = "src"
sb_img_name = "sb.png"
sb1_img_name = "sb1.png"
bt_img_name = "bt.png"
sc_img_name = "screenshot.png"
app_path = r"D:\lebo\PCCast\PCCast.exe"
src_dir = os.path.join(current_dir, cache_dir_name)

#删除临时文件
def del_cacheimg():
    if os.path.exists(os.path.join(src_dir,sc_img_name)):
        os.remove(os.path.join(src_dir,sc_img_name))

#获取屏幕截图并保存到文件中
def get_screenshot():
    del_cacheimg()
    start_app()
    screenshot = pyautogui.screenshot()
    screenshot.save(os.path.join(src_dir,sc_img_name))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
    return screenshot

#在屏幕截图中查找图像
def get_locs(screenshot, temp_selectbox, temp_botton):
    result_sb = cv2.matchTemplate(screenshot, temp_selectbox, cv2.TM_CCOEFF_NORMED)
    min_val, max_val, min_loc, max_loc_sb = cv2.minMaxLoc(result_sb)
    result_bt = cv2.matchTemplate(screenshot, temp_botton, cv2.TM_CCOEFF_NORMED)
    min_val, max_val, min_loc, max_loc_bt = cv2.minMaxLoc(result_bt)
    return max_loc_sb,max_loc_bt

#启动程序
def start_app():
    try:
        app = Application().connect(path=app_path.split('\\')[-1])
    except:    
        # 对于Windows中自带应用程序，直接执行，对于外部应用应输入完整路径
        #弃用这个，脚本结束后会自动关闭
        #app = Application().start(app_path) 
        subprocess.Popen(app_path)
        # 睡眠5s
        time.sleep(5) 
        app = Application().connect(path=app_path.split('\\')[-1])

    # 最前置乐播投屏
    app['乐播投屏'].set_focus()

def main():
    # 确保src文件夹存在
    if not os.path.exists(src_dir):
        os.makedirs(src_dir)

    # 加载要查找的图像
    temp_selectbox = cv2.imread(os.path.join(src_dir,sb_img_name), 0)
    temp_selectbox = cv2.cvtColor(temp_selectbox, cv2.COLOR_RGB2BGR)
    if temp_selectbox is None:
        raise ValueError("无'AqCast'列表选项截图,本目录下"+cache_dir_name+"/"+sb_img_name)
    temp_selectbox1 = cv2.imread(os.path.join(src_dir,sb1_img_name), 0)
    temp_selectbox1 = cv2.cvtColor(temp_selectbox1, cv2.COLOR_RGB2BGR)
    #这个有没有都无所谓，所以不做判空报错
    temp_botton = cv2.imread(os.path.join(src_dir,bt_img_name), 0)
    temp_botton = cv2.cvtColor(temp_botton, cv2.COLOR_RGB2BGR)
    if temp_botton is None:
        raise ValueError("无'开始投屏'按钮截图,本目录下"+cache_dir_name+"/"+bt_img_name)

    # 获取屏幕截图并保存到文件中
    screenshot = get_screenshot()
    
    # 在屏幕截图中查找图像
    try:
        max_loc_sb, max_loc_bt = get_locs(screenshot, temp_selectbox, temp_botton)
        max_loc_sb1, max_loc_bt = get_locs(screenshot, temp_selectbox1, temp_botton)
    except:
        screenshot = get_screenshot()
        max_loc_sb, max_loc_bt = get_locs(screenshot, temp_selectbox, temp_botton)
        max_loc_sb1, max_loc_bt = get_locs(screenshot, temp_selectbox1, temp_botton)

    # 获取图像的位置
    x_sb, y_sb = max_loc_sb
    x_sb1, y_sb1 = max_loc_sb1
    x_bt, y_bt = max_loc_bt

    # 点击找到的图像
    pyautogui.click(x_sb, y_sb)
    pyautogui.click(x_bt, y_bt)
    time.sleep(2)
    pyautogui.click(x_sb1, y_sb1)
    pyautogui.click(x_bt, y_bt)

    del_cacheimg()

if __name__ == '__main__':
    try:
        main()
    except :
        del_cacheimg()
        raise