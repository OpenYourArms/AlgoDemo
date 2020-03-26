//
// Created by Administrator on 2020/3/26.
//

#ifndef ALGODEMO_LINK_CLI_H
#define ALGODEMO_LINK_CLI_H

#ifndef WIN32

#include "misc.h"
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
namespace oyas {
    const string cli_log_path="/tmp/oyas.loopCli.log";
    class link_cli {
    public:
        link_cli(string net="127.0.0.1",int pt=5401):net_addr(net),port(pt){
            set_socket();
            set_server_addr();
            go_connect();
        }
        int get_fd(){
            return skt_fd;
        }
        ~link_cli(){
            if(skt_fd>0){
                close(skt_fd);
            }
        }
    private:
        void set_socket(){
            skt_fd=socket(PF_INET,SOCK_STREAM,0);
            if(skt_fd==-1){
                wt_log(cli_log_path,"fail to call socket()!");
                sleep(1);
                exit(2);
            }
        }
        void set_server_addr(){
            memset(&server_addr,0,sizeof(server_addr));
            server_addr.sin_family=AF_INET;
            server_addr.sin_addr.s_addr=inet_addr(net_addr.c_str());

            server_addr.sin_port=port;
        }
        void go_connect(){
            int rt=connect(skt_fd,(struct sockaddr*)(&server_addr), sizeof(server_addr));
            if(rt==-1){
                wt_log(cli_log_path,"fail to call connect()!");
                sleep(1);
                exit(2);
            }
        }
    private:
        int port;
        string net_addr;
        int skt_fd;
        struct sockaddr_in server_addr;
    };
}

#endif

#endif //ALGODEMO_LINK_CLI_H
