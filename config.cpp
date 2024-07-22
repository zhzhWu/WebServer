#include "config.h"

Config::Config(){
    //端口号,默认12345,也可在启动服务器时通过 -p 选项自定义端口号
    PORT = 12345;

    //日志写入方式，默认同步，也可在启动服务器时通过 -l 选项自定义日志写入方式，
    // 0 ： 同步写入
    // 1 ： 异步写入
    LOGWrite = 0;

    //触发组合模式,默认listenfd LT + connfd LT，
    // 也可在启动服务器时通过 -m 选项来自定义listenfd和connfd触发模式组合
    // 0 ： LT + LT
    // 1 ： LT + ET
    // 2 ： ET + LT
    // 3 ： ET + ET
    TRIGMode = 0;

    //listenfd触发模式，默认LT
    LISTENTrigmode = 0;

    //connfd触发模式，默认LT
    CONNTrigmode = 0;

    //优雅关闭链接，默认不使用
    //也可在启动服务器时通过 -o 选项来自定义是否优雅的关闭连接
    OPT_LINGER = 0;

    //数据库连接池数量,默认8
    //也可在启动服务器时通过 -s 选项来自定义数据库连接池中的连接数量
    sql_num = 8;

    //线程池内的线程数量,默认4
    //也可在启动服务器时通过 -t 选项来自定义线程池中的工作线程数量
    thread_num = 4;

    //关闭日志,默认不关闭
    //也可在启动服务器时通过 -c 选项来进行配置
    // 1 关闭日志
    // 0 打开日志
    close_log = 0;

    //并发模型,默认是proactor
    //也可在启动服务器时通过 -a 选项来进行配置
    // 1 Reactor模型
    // 0 模拟proactor模型
    actor_model = 0;
}

void Config::parse_arg(int argc, char*argv[]){
    int opt;
    const char *str = "p:l:m:o:s:t:c:a:";
    while ((opt = getopt(argc, argv, str)) != -1)
    {
        switch (opt)
        {
            case 'p':
            {
                PORT = atoi(optarg);
                break;
            }
            case 'l':
            {
                LOGWrite = atoi(optarg);
                break;
            }
            case 'm':
            {
                TRIGMode = atoi(optarg);
                break;
            }
            case 'o':
            {
                OPT_LINGER = atoi(optarg);
                break;
            }
            case 's':
            {
                sql_num = atoi(optarg);
                break;
            }
            case 't':
            {
                thread_num = atoi(optarg);
                break;
            }
            case 'c':
            {
                close_log = atoi(optarg);
                break;
            }
            case 'a':
            {
                actor_model = atoi(optarg);
                break;
            }
            default:
                break;
        }
    }
}