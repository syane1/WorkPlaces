import requests
import re

class GroupAuto(object):
  def __init__(self):
    # 创建session并设置初始登录Cookie
    self.session = requests.session()
    self.session.cookies['BDUSS'] = 'lLT2IxbXZKQ3NrY34xU3lIOG5Fd29KSERGQ0ZpN0c5N25ZcU1XOERVa3ZZVXhpRVFBQUFBJCQAAAAAAAAAAAEAAAAfgcMjz6PHlrTzudnIywAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAC~UJGIv1CRiaE'
    self.session.cookies['STOKEN'] = '9008a81505460c1c5e937bb08ce3960c5df9c43a7b6ca1ca934875d8000c8d3a'
    self.headers = {
    'Host': 'pan.baidu.com',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.51 Safari/537.36 Edg/99.0.1150.30',
    }

  '''
  验证Cookie是否已登录
  返回值errno代表的意思
  0 有效的Cookie;1 init方法中未配置登录Cookie;2 无效的Cookie
  '''
  def verifyCookie(self):
    if(self.session.cookies['BDUSS'] == '' or self.session.cookies['STOKEN'] == ''):
      return {'errno': 1, 'err_msg': '请在init方法中配置百度网盘登录Cookie'}
    else:
      response = self.session.get('https://pan.baidu.com/disk/main#/index?category=all', headers=self.headers)
      home_page = response.content.decode("utf-8")
    if('<title>百度网盘-全部文件</title>' in home_page):
      user_name = re.findall(r'initPrefetch\((.+?)\'\)', home_page)[0]
      user_name = re.findall(r'\, \'(.+?)\'\)', home_page)[0]
      return {'errno': 0, 'err_msg': '有效的Cookie,用户名:%s' % user_name}
    else:
      return {'errno': 2, 'err_msg': '无效的Cookie!'}

auto = GroupAuto()
auto.verifyCookie()