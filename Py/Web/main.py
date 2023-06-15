import os
from flask import Flask
app = Flask(__name__)

@app.route('/castTV')
def castTV():
    #直接输出控制台命令
    os.system('python "C:\WorkPlaces\Py\WinAuto\CV_and_PyAutoGUI.py"')
    return 'castTV executed'

if __name__ == '__main__':
    app.run(host='0.0.0.0',port=23333)