//
// Created by Administrator on 2020/3/26.
//

#ifndef ALGODEMO_LVDB_MISC_H
#define ALGODEMO_LVDB_MISC_H

#ifndef WIN32
#include "link_server.h"
#include "link_cli.h"
#include <iostream>
#include <string>

namespace oyas{

    void db_shell(){
        oyas::link_server Li(5401);
        struct sockaddr_in cliaddr={};
        socklen_t clilen= sizeof(cliaddr);
        char buffer[256]="sv:";
        for(int i=0;i<3;i++){
            cout<<"con:"<<i<<endl;
            int fd=Li.i_accept(&cliaddr,clilen);
            buffer[3]='+';
            while(buffer[3]!='Q'){
                read(fd,buffer+3,sizeof(buffer));
                cout<<"get buf:"<<buffer+3<<endl;
                if(buffer[3]=='Q') continue;
                write(fd,buffer,sizeof(buffer));
            }
            cout<<"QQ"<<endl;
            close(fd);
            cout<<"Q"<<endl;
        }
    }

    void db_cli(){
        oyas::link_cli Li;
        int fd=Li.get_fd();
        char buf[256]={};
        char rbuf[256]={};
        while(buf[0]!='E'){
            cin>>buf;
            write(fd,buf,sizeof(buf));
            if(buf[0]=='Q') continue;
            read(fd,rbuf,sizeof(rbuf));
            cout<<rbuf<<endl;

        }
    }

}
#endif

#endif //ALGODEMO_LVDB_MISC_H
