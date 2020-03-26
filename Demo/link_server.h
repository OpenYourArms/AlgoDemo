//
// Created by Administrator on 2020/3/26.
//

#ifndef ALGODEMO_LINK_SERVER_H
#define ALGODEMO_LINK_SERVER_H

#ifndef WIN32


#include "misc.h"
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

namespace oyas{
    const string log_path="/tmp/oyas.loopServer.log";
    class link_server {
    public:
        link_server(/*string ptl="tcp",*/int pt=5401,int qsz=10):port(pt),que_sz(qsz){
            set_sock();
            init_addr(pt);
            s_bind();
            set_listen();
        }
        ~link_server(){
            if(socket_fd){
                close(socket_fd);
            }
        }
        int i_accept(struct sockaddr_in* addr,socklen_t& addr_size){
            int rt=accept(socket_fd,(sockaddr*)&addr,&addr_size);
            if(rt==-1){
                wt_log(log_path,"fail to call accept()!");
                sleep(1);
                exit(2);
            }
            return rt;
        }
    private:
        void set_sock(){
            socket_fd = socket(PF_INET,SOCK_STREAM,0);
            if(socket_fd==-1){
                wt_log(log_path,"fail to call socket()!");
                sleep(1);
                exit(2);
            }
        }
        void init_addr(int pt){
            memset(&server_addr,0, sizeof(server_addr));
            server_addr.sin_family=AF_INET;
            server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
            server_addr.sin_port=pt;
        };
        void s_bind(){
            int rt=bind(socket_fd,(const struct sockaddr*)(&server_addr),sizeof(server_addr));
            if(rt==-1){
                wt_log(log_path,"fail to call bind()!");
                sleep(1);
                exit(2);
            }
        }
        void set_listen(){
            int rt=listen(socket_fd,que_sz);
            if(rt==-1){
                wt_log(log_path,"fail to call listen()!");
                sleep(1);
                exit(2);
            }
        }
    private:
        int port;
        //string ptl;
        struct sockaddr_in server_addr;
        int socket_fd;
        int que_sz;
    };
}

#endif

#endif //ALGODEMO_LINK_SERVER_H
