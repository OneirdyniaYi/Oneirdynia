#ifndef NONTEST_H
#define NONTEST_H

#include <netinet/in.h>
/* uint32_t htonl(uint32_t host32bitvalue);
 * return 网络字节序
 * uint32_t ntohl(uint32_t net32bitvalue);
 * return 主机字节序
 */

#include <strings.h>
/* void bzero(void *dest,size_t nbytes);
 * void bcopy(const void *src,void *dest,size_t nbytes);
 * void bcmp(const void *ptr1,const void *ptr2,size_t nbytes);
 * return 0:= !0:不等
 */

#include <string.h>
inline void memZero(void* p,size_t len){
	memset(p,0,len);
}
/* void *memset(void *dest,int c,size_t len);
 * void *memcpy(void *dest,const void *src,size_t nbytes);
 * memcpy 当源与目的内存重叠时，会出现不确定结果
 * int memcmp(const void *ptr1,const void *ptr2,size_t nbytes);
 * return 0:= !0:不等
 */

#include <arpa/inet.h>
/* int inet_pton(int family,const char* strptr,void *addrptr);
 * return 1:成功 0:表达式无效 -1:出错
 * const char* inet_ntop(int family,const char* strptr,void *addrptr);
 * return NULL:出错
 */

#include <sys/socket.h>
/* int socket(int family,int type,int protocol);
 * return >=0:描述符 -1:出错
 * int connet(int sockfd,const struct sockaddr* sercaddr,socklen_t addrlen);
 * return 0:成功 -1:出错
 * int bind(int sockfd,const struct sockaddr* sercaddr,socklen_t addrlen);
 * bind 需要root权限
 * return 0:成功 -1:出错
 * int listen(int sockfd,int backlog);
 * backlog参数影响已排队连接最大数目
 * return 0:成功 -1:出错
 * int accept(int sockfd,struct sockaddr* cliaddr,socklen_t *addrlen);
 * return >=0:描述符 -1:出错
 * int shutdown(int sockfd,int howto);
 * howto: SHUT_RD 关闭读
 * 	  SHUT_WR 关闭写
 * 	  SHUT_RDWR 
 * return 0:成功 -1:出错 
 */

#include <unistd.h>
/* ssize_t read(int filedes,void *buff,size_t nbytes);
 * ssize_t write(int filedes,const void *buff,size_t nbytes);
 * ssize_t readline(int filedes,void *buff,size_t maxlen);
 * return >=0:读写字节数 -1:出错 
 * pid_t fork(void);
 * return >0:父进程返回子进程id 0:子进程中返回为0 -1:出错
 * 
 * exec函数提供一个进程启动另一个程序的方法
 *
 * int close(int fd);
 * return 0:成功 -1:出错
 */

#include <fcntl.h>
/* int open(const char* pathname,int flags);
 * int open(const char* pathname,int flags,mode_t mode);
 * flags:1.O_RDONLY 2.O_WRONLY 3.O_RDWR 这三个参数必须指定一个
 * 	 可选参数 4.O_APPEND:追加末尾 5.O_CREAT:创建文件 
 * 	 6.O_EXCL:测试文件是否存在与4同时使用构成创建的原子操作
 * 	 7.O_TRUNC:文件存在时只读或者读写打开将其长度置0
 * 	 8.O_NOCTTY:如果pathname是终端设备，不将该设备分配作为此进程的控制终端
 * 	 9.O_NONBLOCK:设置非阻塞模式 10.O_DSYNC 11.O_RSYNC 12:O_SYNC
 */

#include <sys/select.h>
#include <sys/time.h>
#include <signal.h> //sigmask
#include <time.h>
/* int select(int maxfdpl,fd_set *readset,fd_set *writeset,fd_set *exceptset,const struct timeval *timeout);
 * return >0:就绪描述符数目 0:超时 -1:出错
 * struct timeval{
 *	long tv_sec;     seconds
 *	long tv_usec;    microseconds
 * }
 * void FD_ZERO(fd_set *fdset);
 * void FD_SET(int fd,fd_set *fdset);
 * void FD_CLR(int fd,fd_set *fdset);
 * int FD_ISSET(int fd,fd_set *fdset);
 * int pselect(int maxfdpl,fd_set *readset,fd_set *writeset,fd_set *exceptset,const struct timeval *timeout,const sigset_t *sigmask);
 * return >0:就绪描述符数目 0:超时 -1:出错
 * struct timespec{
 *	time_t tv_sec;
 *	long tv_nsec;   nanoseconds纳秒
 * }
 */
#include <poll.h>
/* int poll(struct pollfd *fdarray,unsigned long nfds,int timeout);
 * return >0:就绪描述符数目 0:超时 -1:出错
 * struct pollfd{
 *	int fd;
 *	short events;
 *	short revents;
 * }
 * events:POLLIN,POLLRDNORM,POLLRDBAND,POLLPRI,POLLOUT,POLLWRNORM,POLLWRBAND
 * revents:上述值+POLLERR,POLLHUP(挂起),POLLNVAL(描述符不是打开的文件)
 * timeout: INFTIM:永远等待 0:立即返回，不阻塞进程 >0:等待指定毫秒数
 * INFTIM被定义在<sys/stropts.h>中
 */

class tcpServer{
public:
	tcpServer();
	~tcpServer();	
private:
}


#endif
