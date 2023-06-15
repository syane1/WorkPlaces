from linecache import getline
import os

from ssh_client import SSH_Client

def main():
    print("开始处理…")
    d_ssh = SSH_Client("192.168.0.73")
    u_ssh = SSH_Client("192.168.0.131")
    progs = input("请输入本次文件名：")
    d_ssh.down(progs)
    SSH_Client.batch_rename(d_ssh)
    u_ssh.up(u_mod=d_ssh.mod)
    SSH_Client.clean_tmpfiles(u_ssh)

main()