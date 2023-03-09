#ifndef _SMF_HTTP_H_
#define _SMF_HTTP_H_

#include "smf_type.h"
#include "smf_http_type.h"

#ifdef _WIN32
#    define EXPORT_C_API __declspec(dllexport)
#else
#    define EXPORT_C_API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 *  功能：http连接初始化
 *
 *  @param  [IN]            sctx            SMF上下文
 *  @param  [IN]            ip              目标ip地址
 *  @param  [IN]            port            目标端口
 *  @param  [IN]            timeout         握手超时时间(ms)
 *  @param  [IN]            nUseCert        是否双向连接,1->是 0 -> 单向连接
 *  @param  [OUT]           hctx            http上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int smf_http_init(SMF_CONTEXT* ctx, const char* ip, int port, int timeout, int nUseCert,
                               SMF_HTTP_CTX** hctx);

/**
 *  功能：http连接初始化,由外部传入套接字
 *
 *  @param  [IN]            sctx            SMF上下文
 *  @param  [IN]            socket          套接字
 *  @param  [IN]            b_asyn          是否是异步套接字,1:异步套接字,0:同步套接字
 *  @param  [IN]            nUseCert        是否双向连接,1->是 0 -> 单向连接
 *  @param  [OUT]           hctx            http上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int smf_http_init_ex(SMF_CONTEXT* ctx, int socket, int asyn, int nUseCert, SMF_HTTP_CTX** hctx);

/**
 *  功能：http连接关闭
 *
 *  @param  [in]           hctx            http上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int smf_http_close(SMF_HTTP_CTX* hctx);

/**
 *  功能：http连接反初始化
 *
 *  @param  [in]           hctx            http上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int smf_http_uninit(SMF_HTTP_CTX* hctx);

/**
 *  功能：设置http方法及路径
 *
 *  @param  [in]           hctx            http上下文
 *  @param  [in]           url             url路径
 *  @param  [in]           method          请求方法
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int smf_http_set_url(SMF_HTTP_CTX* hctx, const char* url, http_request_method_e method);

/**
 *  功能：添加http请求头
 *
 *  @param  [in]           hctx            http上下文
 *  @param  [in]           key             键
 *  @param  [in]           value           值
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int smf_http_add_header(SMF_HTTP_CTX* hctx, const char* key, const char* value);

/**
 *  功能：清除http请求头
 *
 *  @param  [in]           hctx            http上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int smf_http_clear_header(SMF_HTTP_CTX* hctx);

/**
 *  功能：设置http版本,不调用则默认1.1
 *
 *  @param  [in]           hctx            http上下文
 *  @param  [in]           major_ver       主版本
 *  @param  [in]           minor_ver       次版本
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int smf_http_set_version(SMF_HTTP_CTX* hctx, int major_ver, int minor_ver);

/**
 *  功能：发送http请求
 *
 *  @param  [in]           hctx            http上下文
 *  @param  [in]           content         请求内容
 *  @param  [in]       contentlen      输入请求内容数据长度
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int smf_http_send_request(SMF_HTTP_CTX* hctx, const char* content, int contentlen);

/**
 *  功能：接收http响应
 *
 *  @param  [in]           hctx            http上下文
 *  @param  [out]          buf             数据接收回调函数
 *  @param  [in/out]       len             输入buf的长度,输出接收的长度
 *  @param  [in]           timeout         接收超时时间
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int smf_http_recv_response(SMF_HTTP_CTX* hctx, char* buf, int* len, int timeout);

/**
 *  功能：解析http数据
 *
 *  @param  [in]           hctx            http上下文
 *  @param  [in]           data            接收到的数据
 *  @param  [in]           len             数据长度
 *  @param  [out]          head            解析出的http头，以;分割
 *  @param  [in/out]       head_len        输入头部长度，输出所需长度
 *  @param  [out]          body            解析出的http正文
 *  @param  [in/out]       body_len        输入正文长度，输出所需长度
 *  @param  [out]          status          解析出的http状态
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int smf_http_parse_data(SMF_HTTP_CTX* hctx, const char* data, int len, char* head, int* head_len,
                                     char* body, int* body_len, int* status);

/**
 *  功能：获取http头部value
 *
 *  @param  [in]           hctx            http上下文
 *  @param  [in]           key             http头部key
 *  @param  [out]          value           http头部value
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int smf_http_get_header_value(SMF_HTTP_CTX* hctx, const char* key, char* value, int* len);

#ifdef __cplusplus
}
#endif

#endif // _SMF_HTTP_H_