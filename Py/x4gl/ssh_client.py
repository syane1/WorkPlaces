from ast import Delete
from asyncio.windows_events import NULL
import string
from time import sleep
import paramiko
from scp import SCPClient
from scp import SCPException
import os

pre_path = "/u1/topprd/erp/"

class SSH_Client:
    USERNAME = "s06"#这里填入用户名，例如我的s06
    PASSWORD = "scudxzq06"#这里填入密码
    local_path = os.path.dirname(__file__)+"\\fgls\\"#当前文件同级文件夹fgls
    mod = ""#模块
    ssh_client=paramiko.SSHClient()#ssh客户端
    scp_client=NULL#scp客户端
    
    #初始化
    def __init__(self,HOST,PORT=22) -> None:
        self.ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy)
        self.ssh_client.connect(HOST, PORT, self.USERNAME, self.PASSWORD)
        self.scp_client = SCPClient(self.ssh_client.get_transport(), socket_timeout=15.0)
    
    #上传文件(./fgls/* → /u1/topprd/erp/cxx/cxxx.4gl)
    def up(self,u_path=pre_path,u_mod=mod,l_path=local_path):
        for fname in os.listdir(l_path):
            sleep(0.1)
            try:
                if u_mod[1:3] != fname[1:3]:
                    u_mod = u_mod.replace(u_mod[1:3],fname[1:3])
                self.ssh_client.exec_command("rm -f "+u_path+"a"+u_mod[1:4]+"4gl/"+fname)
                self.scp_client.put(l_path+fname, u_path+"a"+u_mod[1:4]+"4gl/")
            except FileNotFoundError as e:
                print(e)
                print("系统找不到指定文件" + fname)
                self.clean_tmpfiles(self)
            else:
                print("文件"+fname+"上传到"+"a"+u_mod[1:4]+"成功")
        self.clean_tmpfiles(self)

    #下载文件(/u1/topprd/erp/cxx/cxxx.4gl → ./fgls/cxxx.4gl)
    def down(self,d_path="",l_path=local_path):
        if d_path==NULL or d_path=="":
            raise "null input"
        if "," in d_path or "|" in d_path:
            paths = d_path.split(",")
            for path in paths:
                if "," in path or "|" in path:
                    break    
                self.down(path)
            paths = d_path.split("|")
            for path in paths:
                if "," in path or "|" in path:
                    break
                self.down(path)
            return
        if not d_path.endswith(".4gl"):
            d_path = d_path+".4gl"
        self.mod=d_path[1:3]+"/"
        trypath = pre_path+"c"+self.mod+"4gl/"+d_path
        retrypath = pre_path+"a"+self.mod+"4gl/"+d_path
        sleep(0.1)
        try:
            self.scp_client.get(trypath, l_path)
        except SCPException or FileNotFoundError as e:
            sleep(0.1)
            try:
                self.scp_client.get(retrypath, l_path)
            except FileNotFoundError as e:
                print(e)
                #self.clean_tmpfiles(self)
                self.mod = ""
            except SCPException as e:
                print("a"+self.mod+"4gl/"+d_path+"未下载成功，报错："+e.args[0])
                #self.clean_tmpfiles(self)
                self.mod = ""
                return
            else:
                self.mod = "a"+self.mod
                print("下载"+self.mod+"模块文件"+d_path+"成功")
        else:
            self.mod = "c"+self.mod
            print("下载"+self.mod+"模块文件"+d_path+"成功")
    
    #批量重命名（./fgls/底下文件）
    @staticmethod
    def batch_rename(self,l_path=local_path):
        for fname in os.listdir(l_path):
            if os.path.exists(l_path+fname+".src"):
                os.remove(l_path+fname+".src")
            os.rename(l_path+fname,l_path+fname+".src")

    #清理临时文件（./fgls/底下文件）
    @staticmethod
    def clean_tmpfiles(self,l_path=local_path):
        for fname in os.listdir(l_path):
            os.remove(l_path+fname)
        self.ssh_client.close()