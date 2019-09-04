#include <cstdio>
#include <cstdlib>
#include <mysql/mysql.h>

int main()
{
 //使用mysql API 来操作数据库
 //1. 先创建一个mysql的操作句柄
 MYSQL* mysql = mysql_init(NULL);

 //2.拿着操作句柄来和数据库建立连接
  if(mysql_real_connect(mysql, "127.0.0.1", "root", "123", "image_system", 3306, NULL, 0) == NULL)
  {
    //数据库连接失败
    printf("数据库连接失败! %s\n", mysql_error(mysql));
    return 1;
  }
  //3.设置编码格式
  mysql_set_character_set(mysql, "utf8");
  //4.拼接SQL语句
  char sql[4096] = {0};
  sprintf(sql, "insert into image_table values(null, 'test.png',1024, '2019/08/29', 'abcdef','png', 'test_8_29_image/test.png')");
  //5. 执行sql语句，负责了客户端给服务端发送数据的过程
  int ret = mysql_query(mysql, sql);
  if(ret != 0)
  {
    printf("执行sql语句失败！%s\n", mysql_error(mysql));
    //进程退出码
    return 1;
  }
  //6.关闭句柄
  mysql_close(mysql);
  return 0;
}

