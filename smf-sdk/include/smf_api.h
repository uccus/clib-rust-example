#ifndef __SMF_API_H__
#define __SMF_API_H__

#include "smf_type.h"

#ifdef _WIN32
#    define EXPORT_C_API __declspec(dllexport)
#else
#    define EXPORT_C_API __attribute__((visibility("default")))
#endif

#if _MSC_VER >= 1900
#    include "stdio.h"
_ACRTIMP_ALT FILE* __cdecl __acrt_iob_func(unsigned);

#    ifdef __cplusplus
extern "C"
#    endif // __cplusplus

    static FILE* __cdecl __iob_func(unsigned i)
{
    return __acrt_iob_func(i);
}

#    pragma comment(lib, "legacy_stdio_definitions.lib")
#endif /* _MSC_VER>=1900 */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __ANDROID__
/**
 *  功能：android额外初始化接口
 *  注意：该接口必须在SMF_Initialize之前调用
 *
 *  @param  [IN]        javaVM                 javaVM环境参数
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_InitialAndroid(void* javaVM);
#endif

/**
 *  功能：设置全局配置信息
 *  注意：该接口设置的是全局配置，存储相关同一进程只有第一次设置有效
 *
 *  @param  [IN]        cfg           全局配置信息,详见{@link smf_type.h}
 *
 *  @return = 0 成功
 *          !=0 错误码,详见{@link smf_error.h}
 */
EXPORT_C_API int SMF_ConfigInit(const Config_t* cfg);

/**
 *  功能：设置代理参数
 *
 *  @param  [IN]        proxy_type           代理协议类型
 *  @param  [IN]        proxy_addr           代理服务地址，例：10.0.90.110:8088, 该参数为NULL或值为""表示不启用proxy
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_SetProxyParam(PROXY_PROTOCOL_TYPE proxy_type, const char* proxy_addr);

/**
 *  功能：初始化在线模式客户端,所有的除基础密码算法接口调用前都需要先调用该类接口中的一个
 *  注意：
 *      <li> 返回的证书管理上下文必须通过 SMF_Uninitialize 释放 </li> 
 *      <li> 初始化的url地址全局进程有效，可以多次覆盖 </li> 
 *
 *  @param  [IN]        uid                 用户相关信息标识码
 *  @param  [IN]        url                 获取安全参数的服务端地址
 *  @param  [OUT]       pctx                成功时返回证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_Initialize(const char* uid, const char* url, SMF_CONTEXT** pctx);

/**
 *  功能：初始化在线模式客户端扩展接口,所有的除基础密码算法接口调用前都需要先调用该类接口中的一个
 *  注意：
 *      <li> 返回的证书管理上下文必须通过 SMF_Uninitialize 释放 </li> 
 *      <li> 初始化的url地址全局进程有效，可以多次覆盖 </li> 
 *
 *  @param  [IN]        uid                 用户相关信息标识码
 *  @param  [IN]        url                 获取安全参数的服务端地址
 *  @param  [IN]        certdir             证书数据存储目录，传入NULL时使用SDK默认的路径
 *  @param  [IN]        devdfk              证书设备的唯一标识，传入NULL时使用SDK按照规则获取的终端设备的id
 *  @param  [OUT]       pctx                成功时返回证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_Initialize_EX(const char* uid, const char* url, const char* certdir, const char* devdfk,
                                   SMF_CONTEXT** pctx);

/**
 *  功能：初始化在线模式用户接口, 所有的除基础密码算法接口调用前都需要先调用该类接口中的一个
 *  注意：
 *      <li> 返回的证书管理上下文必须通过 SMF_Uninitialize 释放 </li> 
 *      <li> 初始化的url地址只对当前uid有效 </li> 
 *
 *  @param  [IN]        uid                 用户唯一标识码
 *  @param  [IN]        certurl             获取安全参数的证书管理服务地址
 *  @param  [IN]        sksurl              协同服务地址，可以和certurl是一个地址
 *  @param  [IN]        timeout             用户访问服务器的超时间(s)
 *  @param  [IN]        certdir             证书数据存储目录，传入NULL时使用SDK默认的路径
 *  @param  [IN]        devdfk              证书设备的唯一标识，传入NULL时使用SDK按照规则获取的终端设备的id
 *  @param  [OUT]       pctx                成功时返回证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_InitializeUser(const char* uid, const char* certurl, const char* sksurl, int timeout,
                                    const char* certdir, const char* devdfk, SMF_CONTEXT** pctx);


/**
 *  功能：初始化在线模式接口，可以外部指定终端id, 所有的除基础密码算法接口调用前都需要先调用该类接口中的一个
 *  注意：
 *      <li> 返回的证书管理上下文必须通过 SMF_Uninitialize 释放 </li> 
 *      <li> 初始化的url地址全局进程有效，可以多次覆盖 </li> 
 *
 *  @param  [IN]        tid                 终端唯一标识码
 *  @param  [IN]        uid                 用户唯一标识码
 *  @param  [IN]        url                 获取安全参数的服务端地址
 *  @param  [IN]        certdir             证书数据存储目录，传入NULL时使用SDK默认的路径
 *  @param  [IN]        devdfk              证书设备的唯一标识，传入NULL时使用SDK按照规则获取的终端设备的id
 *  @param  [OUT]       pctx                成功时返回证书管理上下文
 *
 *  @return = 0 成功，返回码 SMF_USER_UNFIND 标识用户找不到需要调用认证接口后sdk 接口才完全开放
 *          !=0 错误码
 */
EXPORT_C_API int SMF_InitializeTidUid(const char* tid, const char* uid, const char* url, const char* certdir,
                                      const char* devdfk, SMF_CONTEXT** pctx);

EXPORT_C_API int SMF_InitUserPolicy(SMF_CONTEXT* ctx);

/**
 *  功能：初始化离线模式客户端（预先取得安全参数时调用）
 *  注意：证书管理上下文必须通过 SMF_Uninitialize 释放
 *
 *  @param  [IN]        uid                 用户相关信息标识码
 *  @param  [IN]        param               安全参数
 *  @param  [OUT]       pctx                成功时返回证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_InitializeOffline(const char* uid, const char* param, SMF_CONTEXT** pctx);

/**
 *  功能：初始化离线模式客户端扩展接口（预先取得安全参数时调用）
 *  注意：证书管理上下文必须通过 SMF_Uninitialize 释放
 *
 *  @param  [IN]        uid                 用户相关信息标识码
 *  @param  [IN]        param               安全参数
 *  @param  [IN]        certdir             证书数据存储目录，传入NULL时使用SDK默认的路径
 *  @param  [IN]        devdfk              证书设备的唯一标识，传入NULL时使用SDK按照规则获取的终端设备的id
 *  @param  [OUT]       pctx                成功时返回证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_InitializeOffline_Ex(const char* uid, const char* param, const char* certdir, const char* devdfk,
                                          SMF_CONTEXT** pctx);

/**
 *  功能：离线通过查找证书实现初始化上下文，如果本地没有查找到证书，需要重新调用正常的初始化接口重新初始化并签发证书
 *  注意：返回的证书管理上下文必须通过 SMF_Uninitialize 释放
 *
 *  @param  [IN]        certdir             证书存储路径，传入为NULL时在默认路径下查找
 *  @param  [IN]        certitem            查找证书时依据的证书的项，CERT_INFO_ITEM中的值
 *  @param  [IN]        certid              查找证书时依据的证书的项的具体的值
 *  @param  [OUT]       certstatus          返回的证书状态
 *  @param  [OUT]       pctx                成功时返回证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_OffInitByFindCert(const char* certdir, int certitem, const char* certid, int* certstatus,
                                       SMF_CONTEXT** pctx);

/**
 *  功能：关闭证书管理上下文，并回收相关资源
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_Uninitialize(SMF_CONTEXT* ctx);

/**
 *  功能：根据错误码获取错误信息及详细描述
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        err_code            错误码
 *  @param  [IN]        charset             输出字符集, 0: gb2312, 1: utf8
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_ErrString(SMF_CONTEXT* ctx, int err_code, int charset, char* err_msg, int* msg_len);

/**
 *  功能：初始化在线认证
 *  注意：由于该接口返回值的数据每次不一样，所以需要提前申请比较大的空间
 *
 *  @param  [IN]        authtype            认证类型
 *  @param  [IN]        authparam 认证时用到的扩展项，当认证类型为短信时必须传入接收短信的手机号，其他时候可以为空
 *  @param  [OUT]       authresp            存放初始化认证服务端返回的参数，不同的认证方式返回数据不同，有以下对应关系
 *                                          用户名口令认证：<图片验证码> 手机短信认证：输出<短信发送时间>
 * 签名验签认证：输出<签名用的随机数>
 *  @param  [IN,OUT]    nBufLen			   输入authresp的缓冲区大小，返回实际需要的空间大小
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_InitAuth(SMF_CONTEXT* ctx, int authtype, const char* authparam, char* authresp, int* nBufLen);

/**
 *  功能：初始化在线认证扩展接口，用于初始化认证过程需要传入多个参数的认证方式
 *  注意：由于该接口返回值的数据每次不一样，所以需要提前申请比较大的空间
 *
 *  @param  [IN]        authtype            认证类型
 *  @param  [IN]        authparam 认证时用到的扩展项，当认证类型为短信时必须传入接收短信的手机号，其他时候可以为空
 *  @param  [IN]        authname            认证时的用户真实姓名
 *  @param  [IN]        authidno            认证时的用户证件号码（身份证号，护照等唯一码）
 *  @param  [IN]        authext             认证时的扩展信息，如设备特征码等
 *  @param  [OUT]       authresp            存放初始化认证服务端返回的参数，不同的认证方式返回数据不同，有以下对应关系
 *                                          用户名口令认证：<图片验证码> 手机短信认证：输出<短信发送时间>
 * 签名验签认证：输出<签名用的随机数>
 *  @param  [IN,OUT]    nBufLen			   输入authresp的缓冲区大小，返回实际需要的空间大小
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_InitAuth_Ex(SMF_CONTEXT* ctx, int authtype, const char* authparam, const char* authname,
                                 const char* authidno, const char* authext, char* authresp, int* nBufLen);

/**
 *  功能：在线认证
 *  注意：当服务端配置为不验证图片验证码时，口令认证<图片验证码>可以随意输入
 *
 *  @param  [IN]        authuser            认证用户；口令认证<用户名> 短信认证<接收短信的号码> 签名验签认证<nullptr>
 *  @param  [IN]        authpass            密码，只有认证方式是口令时需要；其他可以传入nullptr
 *  @param  [IN]        authcode            认证码：口令认证<图片验证码> 短信认证<短信验证码>
 * 签名验签认证<对随机数的签名结果>
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_DoAuth(SMF_CONTEXT* ctx, const char* authuser, const char* authpass, const char* authcode);

/**
*  功能：在线认证扩展接口
*  注意：当服务端配置为不验证图片验证码时，口令认证<图片验证码>可以随意输入
*
*  @param  [IN]        authuser            认证用户；口令认证<用户名> 短信认证<接收短信的号码> 签名验签认证<nullptr>
*  @param  [IN]        authpass            密码，只有认证方式是口令时需要；其他可以传入nullptr
*  @param  [IN]        authcode            认证码：口令认证<图片验证码> 短信认证<短信验证码>
签名验签认证<对随机数的签名结果>
*  @param  [IN]        bDigst              是否需要对传入的密码做摘要，true：需要对传入的密码做SM3 摘要再传给服务端
，否则直接base64后传递给服务端
*
*  @return = 0 成功
*          !=0 错误码
*/
EXPORT_C_API int SMF_DoAuth_Ex(SMF_CONTEXT* ctx, const char* authuser, const char* authpass, const char* authcode,
                               bool bDigst);

/**
 *  功能：重置用户本地状态，本地删除传入的ctx关联的用户的证书和密钥
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *
 *  @return = 0  成功
 *          !=0  错误码
 */
EXPORT_C_API int SMF_ResetAll(SMF_CONTEXT* ctx);

/**
 *  功能：申请重置PIN码，此业务会按照服务端是否需要审核，分为两种行为
 *          <li> 服务端不审核或自动审核通过，接口返回成功，直接完成证书PIN重置 </li>
 *          <li> 服务端需要审核，接口返回错误码SERVER_STATE_ERROR_TO_UNBLOCK，之后可以通过 SMF_CertState 来判断服务端是否审核通过，再次调用该接口 </li>
 *
 *  注意：
 *          <li> 调用该接口前需要先调用过身份验证和pin验证接口(SMF_InitAuth_Ex->SMF_DoAuth) </li>  
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        newPin              新的用户PIN
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_PinReset(SMF_CONTEXT* ctx, const char* newPin);

/**
 *  功能：离线重置PIN码
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        adminPin            管理员PIN码,要求base64编码
 *  @param  [IN]        newPin              新用户PIN
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_PinResetOffline(SMF_CONTEXT* ctx, const char* adminPin, const char* newPin);

/**
 * 功能：验证用户PIN码，接口返回错误码-10025时需要调用重置接口并重新发证
 *
 * @param   [IN]        ctx                 证书管理上下文
 * @param   [IN]        pin                 用户PIN码
 * @param   [OUT]       retryCount          返回剩余的重试次数
 *
 * @return  = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_VerifyPin(SMF_CONTEXT* ctx, const char* pin, int* retryCount);

/**
 * 功能：修改用户PIN码
 *
 * @param   [IN]        ctx                 证书管理上下文
 * @param   [IN]        oldpin              当前的用户PIN码
 * @param   [IN]        newPin              新的用户PIN码
 * @param   [OUT]       retryCount          返回剩余的重试次数
 *
 * @return  = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_ChangePin(SMF_CONTEXT* ctx, const char* oldPin, const char* newPin, int* retryCount);

/**
 *  功能：查询用户证书状态
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        localOnly           是否仅获取本地证书状态
 *                      <li>  1:只获取本地状态不联网 </li>
 *                      <li>  0:同时联网获取用户证书服务端状态 </li>
 *  @param  [OUT]       state               返回证书管理状态
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertState(SMF_CONTEXT* ctx, int localOnly, int* state);

/**
 *  功能：联网实现证书签发，此业务会按照服务端是否需要审核，分为以下两种行为
 *      <li> 服务端不审核或自动审核通过，接口返回成功，直接完成证书新签 </li>
 *      <li> 服务端需要审核，接口返回错误码SERVER_STATE_ERROR_TO_ISSUER，之后可以通过 SMF_CertState 来判断服务端是否审核通过，再次调用该接口 </li>
 *
 *  注意：
 *          <li> 在本地有正常有效证书时，本接口不做新签，只做证书有效性检查</li>  
 *          <li> 调用该接口前需要先调用过身份验证接口(SMF_InitAuth_Ex->SMF_DoAuth) </li>  
 *          <li> 建议调用前先SMF_CertState检查状态为CERT_ST_NOT_EXIST|CERT_ST_CERT_REVOKED|CERT_ST_TOBE_ISSUE 时才调用 </li> 
 * 
 *  @param  [IN]        ctx                证书管理上下文
 *  @param  [IN]        userPin            用户PIN码
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertEnroll(SMF_CONTEXT* ctx, const char* userPin);

/**
 *  功能：构造证书颁发请求（离线API，每次调用会更新密钥对并生成新的证书请求，需外部管理证书状态）
 *  注意：在开启协同的情况下，该接口内部是有联网操作
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        pin                 用户PIN码
 *  @param  [IN]        dn                  证书DN项,例:C=CN,ST=BJ,L=BJ,O=HD,OU=dev,CN=test,emailAddress=test@koal.com
 *  @param  [OUT]       certReqB64Buf       存放证书请求Base64字符串的缓冲
 *  @param  [IN,OUT]    b64CertReqBufLen    输入b64CertReqBuf的缓冲区大小，返回实际需要的空间大小
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertEnrollOffline(SMF_CONTEXT* ctx, const char* pin, const char* dn, char* b64CertReqBuf,
                                       int* b64CertReqBufLen);

/*
 *  函数：申请密钥恢复（产生新的密钥对和新的证书请求，根据传入的证书序列号恢复加密证书
 *  注意：密钥恢复的只是加密证书和原来保持一致，签名证书是重新生成密钥重新签发的
 *
 * 参数：
 *      [IN]  ctx           证书管理上下文
 *      [IN]  pin           证书PIN码
 *      [IN]  encCertSn     签名证书序列号（十六进制）
 *      [IN]  signCertSn    加密证书序列号（十六进制）
 * 返回：
 *      ERR_OK：返回成功，其他：返回成功 详细错误，查看输出
 */
EXPORT_C_API int SMF_CertRecover(SMF_CONTEXT* ctx, const char* userPin, const char* encCertSn, const char* signCertSn);

/**
 *  功能：证书延期或更新，此业务会按照服务端是否需要审核，分为两种行为
 *      <li> 服务端不审核或自动审核通过，接口返回成功，直接完成证书更新 </li>
 *      <li> 服务端需要审核，接口返回错误码SERVER_STATE_ERROR_TO_POSTPONE，之后可以通过 SMF_CertState 来判断服务端是否审核通过，再次调用该接口 </li>
 *
 *  注意：
 *          <li> 更新证书只做证书信息更新（有效性，信息内容->服务端完成内容更新填写）</li>  
 *          <li> 调用该接口前需要先调用过身份验证和pin验证接口(SMF_InitAuth_Ex->SMF_DoAuth->SMF_VerifyPin) </li>  
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertDelay(SMF_CONTEXT* ctx);

/**
 *  功能：构造证书延期请求（离线API，仅构造证书请求）
 *  注意：在开启协同的情况下，该接口内部是有联网操作
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [OUT]       b64CertReqBuf       存放证书请求Base64字符串的缓冲
 *  @param  [IN,OUT]    b64CertReqBufLen    输入b64CertReqBuf的缓冲区大小，返回实际需要的空间大小
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertDelayOffline(SMF_CONTEXT* ctx, char* b64CertReqBuf, int* b64CertReqBufLen);

/**
 *  功能：申请证书信息更新
 *  注意：接口已废弃，使用SMF_CertDelay接口可完成相同功能
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertRenew(SMF_CONTEXT* ctx);

/**
 *  功能：构造证书更新请求
 *  注意：接口已废弃，使用SMF_CertDelayOffline接口可完成相同功能
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [OUT]       b64CertReqBuf       存放证书请求Base64字符串的缓冲
 *  @param  [IN,OUT]    b64CertReqBufLen    输入b64CertReqBuf的缓冲区大小，返回实际需要的空间大小
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertRenewOffline(SMF_CONTEXT* ctx, char* b64CertReqBuf, int* b64CertReqBufLen);

/**
 *  功能：申请更新（产生新的密钥对和新的证书请求）
 *  注意：接口暂无实现，目前无应用场景
 * 
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *
 *  @return =0 表示成功
 */
EXPORT_C_API int SMF_CertUpdate(SMF_CONTEXT* ctx);

/**
 *  功能：构造证书及密钥更新请求（离线API，产生新的密钥对和新的证书请求，无网络通讯）
 *  注意：接口暂无实现，目前无应用场景
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [OUT]       b64CertReqBuf       存放证书请求Base64字符串的缓冲
 *  @param  [IN,OUT]    b64CertReqBufLen    输入b64CertReqBuf的缓冲区大小，返回实际需要的空间大小
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertUpdateOffline(SMF_CONTEXT* ctx, char* b64CertReqBuf, int* b64CertReqBufLen);

/**
 *  功能：销毁本地证书并通知CA吊销
 *  注意：调用该接口前需要先调用过身份验证和pin验证接口(SMF_InitAuth_Ex->SMF_DoAuth->SMF_VerifyPin)
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertRevoke(SMF_CONTEXT* ctx);

/**
 *  功能：查询本地终端设备所有的证书
 *  @param  [IN]        cert_dir                 证书路径
 *  @param  [IN]        cert_dfk                 证书设备指纹
 *  @param  [OUT]       cert_buf                 证书列表缓冲区,证书格式如下(json格式),返回utf8编码
 *  {
 *    "num": 1,
 *    "certs": [
 *          {
 *              "app_name":  "afasfadfasdf",    // 应用名称
 *              "con_name":  "afasfadfasdf",    // 容器名称
 *              "subjet_cn": "zhangsan",        // 使用者cn项
 *              "subjet_g":  "zhangsan",        // 使用者g项
 *              "subjet_dn": "C=CN,CN=zhangsan,G=afasfadfasdf",// 使用者dn项
 *              "issue_cn":  "koal",            // 颁发者cn项
 *              "issue_dn":  "C=CN,CN=koal",    // 颁发者dn项
 *              "cert_expired": "365",    // 证书有效期
                "user_cert_not_before": "2020-12-09 08:00:00", //证书起始日期
                "user_cert_not_after": "2022-12-09 07:59:59", // 证书截止日期
 *              "sign_cert_no": "11111111111111",   // 签名证书序列号
 *              "sign_cert_cid": "aed0f3c291fc199a59fe8aa559510e193898b61d", //证书ID
 *              "enc_cert_no": "11111111111111",    // 加密证书序列号
 *              "enc_cert_cid": "aed0f3c291fc199a59fe8aa559510e193898b61d", //证书ID
 *          }
 *    ]
 *  }
 */
EXPORT_C_API int SMF_CertQueryAllLocal(const char* cert_dir, const char* cert_dfk, char* cert_buf, int* cert_buf_len);

/**
 *  功能：查询用户所有证书(包含其他终端)
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [OUT]       cert_buf            证书列表缓冲区,证书格式如下(json格式),返回utf8编码
 *  {
    "num": 1,
    "certs": [
        {
            "user_cert_not_before": "2020-12-09T00:00:00.000+0800", //证书起始日期
            "user_cert_not_after": "2022-12-09T23:59:59.000+0800", // 证书截止日期
            "term_manufacturer": "Microsoft", // 终端设备的厂商
            "user_cert_cid": "aed0f3c291fc199a59fe8aa559510e193898b61d", // 证书的cid
			"user_cert_alias": "certalias", // 证书别名,服务端版本2.4.4 后新增返回
            "term_hdtype": "DESKTOP", // 终端设备的类型
            "term_ip": "127.0.0.1", //终端设备的IP
            "term_os": "WINDOWS", //终端设备的操作系统
            "issue_common_name":"sm2_ca", //证书颁发者cn项
            "subject_common_name":"8888;;100887", //证书使用者cn项
            "term_desc":"WINDOWS 6.2", //证书终端信息，配置初始化时传入的terminfo
            "cert_last_use_time":"2021-08-05T11:00:55.787Z",//证书最后使用时间
        }
    ]
    }
*  @param  [IN/OUT]    buf_len             缓冲区大小
*
*  @return = 0 成功
*          !=0 错误码
*/
EXPORT_C_API int SMF_CertQueryAllEndpoint(SMF_CONTEXT* ctx, char* cert_buf, int* buf_len);

/**
 *  功能：废除指定传入cid的用户证书
 *  注意：
 *      <li> 当前用户证书的cid可以通过SMF_GetCid获取到 </li> 
 *      <li> 其他证书对应查询到SMF_CertQueryAllEndpoint的user_cert_cid字段 </li> 
 *      <li> 调用该接口前需要先调用过身份验证(SMF_InitAuth_Ex->SMF_DoAuth) </li> 
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        cid                 证书cid
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertRevokeByCid(SMF_CONTEXT* ctx, const char* cert_cid);

/**
*  功能：废除指定传入cid的用户证书,支持批量废除
*  注意：
*      <li> 当前用户证书的cid可以通过SMF_GetCid获取到 </li>
*      <li> 其他证书对应查询到SMF_CertQueryAllEndpoint的user_cert_cid字段 </li>
*      <li> 调用该接口前需要先调用过身份验证(SMF_InitAuth_Ex->SMF_DoAuth) </li>
*
*  @param  [IN]        ctx                 证书管理上下文
*  @param  [IN]        cid                 证书cid
*  @param  [OUT]       response_buf        输出的操作响应,json格式,返回的数据是utf8编码，格式形如下:
*						[
*						{"cid":"1234566","result_msg":"succ/failed","failed_msg":""}]
*                       字段解释:cid(废除的证书的cid),result_msg(废除结果succ->成功,failed->失败),failed_msg(失败信息)
*
*  @param  [IN/OUT]    buf_len             缓冲区大小,建议如果废除的比较多缓存区取比较大的数据（如：4096）
*  @return = 0 成功
*          !=0 错误码
*/
EXPORT_C_API int SMF_CertRevokeByCids(SMF_CONTEXT* ctx, const char* cert_cid, char* response_buf, int* buf_len);

/**
*  功能：修改指定证书别名(查询所有证书的user_cert_alias字段)
*  注意：
*      <li> 修改的并不是实际证书里面的信息，体现在接口SMF_CertQueryAllEndpoint响应的user_cert_alias字段 </li> 
*      <li> 当前用户证书的cid可以通过SMF_GetCid获取到 </li> 
*      <li> 其他证书对应查询到SMF_CertQueryAllEndpoint的user_cert_cid字段 </li> 
*      <li> 调用该接口前需要先调用过身份验证(SMF_InitAuth_Ex->SMF_DoAuth) </li> 
*
*  @param  [IN]        ctx                 证书管理上下文
*  @param  [IN]        cid                 证书cid
*  @param  [IN]        cert_alias          新的证书别名
*
*  @return = 0 成功
*          !=0 错误码
*/
EXPORT_C_API int SMF_CertAliasUpdate(SMF_CONTEXT* ctx, const char* cert_cid, const char* cert_alias);

/**
 *  功能：销毁本地证书
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertRevokeOffline(SMF_CONTEXT* ctx);

/**
 *  功能：下载证书并安装
 *  注意：接口已废弃，使用SMF_CertEnroll接口可完成相同功能
 * 
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertInstall(SMF_CONTEXT* ctx);

/**
 *  功能：离线安装证书
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        b64Cert             Base64格式的证书数据
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertInstallOffline(SMF_CONTEXT* ctx, const char* b64Cert);

/**
 *  功能：离线安装加密证书和被保护的加密密钥对
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        b64Cert             Base64格式的加密证书数据
 *  @param  [IN]        b64KeyPair          Base64格式的加密密钥对数据
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_EncCertInstallOffline(SMF_CONTEXT* ctx, const char* b64Cert, const char* b64KeyPair);

/**
 *  功能：获取计算好的公钥cid(用于应用与证书综合管理服务端交互时cid参数的获取)
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [OUT]       certCid             证书公钥的cid
 *  @param  [OUT]       certCidLen          返回的cid的数据长度
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_GetCid(SMF_CONTEXT* ctx, char* certCid, int* certCidLen);

/**
 *  功能：本地环境初始化，无网络操作
 *  注意：
 *      <li> 返回的证书管理上下文必须通过 SMF_Uninitialize 释放 </li> 
 *      <li> 初始化的url地址全局进程有效，可以多次覆盖 </li> 
 *
 *  @param  [IN]        uid                 用户唯一标识码
 *  @param  [IN]        url                 获取安全参数的证书管理服务地址
 *  @param  [IN]        certdir             证书数据存储目录，传入NULL时使用SDK默认的路径
 *  @param  [IN]        devdfk              证书设备的唯一标识，传入NULL时使用SDK按照规则获取的终端设备的id
 *  @param  [IN]        sParam              默认使用的安全参数
 *  @param  [OUT]       pctx                成功时返回证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_LocalEnvInit(const char* uid, const char* url, const char* certdir, const char* devdfk,
                                  const char* sParam, SMF_CONTEXT** pctx);

/**
 *  功能：快速证书管理操作（支持新签|延期|废除），适用于认证方式简单的场景
 *  注意：指定的新签命令如果本地证书有效，该接口不做重发
 *
 *  @param  [IN]        cmd                 指定的证书操作命令，延期|废除|新签
 *  @param  [IN]        authtype            认证类型
 *  @param  [IN]        authparam           认证时用到的扩展项，当认证类型为短信时必须传入接收短信的手机号，其他时候可以为空
 *  @param  [IN]        uid                 用户认证账号唯一标识
 *  @param  [IN]        authpass            认证时的密码，如果是三方认证方式，该字段可以随便填写
 *  @param  [IN]        authext             认证时的扩展信息，如设备特征码等
 *  @param  [IN]        userpin             用户证书保护密码，有以下情况
 *                                          <li> cmd 传入新签时，这里设置的是用户新建的密码 </li> 
 *                                          <li> cmd 传入其他时，这里需要输入用户新签时传入的参数 </li> 
 * 
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CertFastMgr(SMF_CONTEXT* ctx, int cmdid, int authtype, const char* uid, const char* authpass,
                                 const char* auth_ext, const char* userpin);

/**
 *  功能：导出用户指定类型证书
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        certType            证书类型详见 { @link smf_type.h->USER_CERT_KEY_TYPE }
 *  @param  [OUT]       b64CertBuf          存放证书Base64编码的缓冲
 *  @param  [IN,OUT]    b64CertBufLen       输入b64CertBuf的缓冲区大小，返回实际需要的空间大小
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_ExportCertificate(SMF_CONTEXT* ctx, int certType, char* b64CertBuf, int* b64CertBufLen);

/**
 *  功能：导入pfx格式证书
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        bSignFlag           true:签名证书,false:加密证书
 *  @param  [IN]        certBuf             存放证书的缓冲区
 *  @param  [IN]        certBufLen          证书缓冲区大小
 *  @param  [IN]        pwd                 文件密码,保护pfx的密码，也作为是私钥的证书pin码
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_ImportPfx(SMF_CONTEXT* ctx, bool bSignFlag, char* certBuf, int certBufLen, char* pwd);

/**
 *  功能：获取证书信息
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        certType            证书类型 详见 { @link smf_type.h->USER_CERT_KEY_TYPE }
 *  @param  [IN]        key                 证书信息项，支持的项如下:
 * 
 *                                          <li> 证书序列号:HEX_SN|DEC_SN </li>
 *                                          <li> 证书颁发者相关项: I_CN|I_E|I_OU|I_O|I_L|I_S|I_C|I_I|I_ST|I_T|I_DN|I_EM </li>
 *                                          <li> 证书使用者相关项:S_CN|S_E|S_OU|S_O|S_L|S_S|S_C|S_I|S_ST|S_T|S_DN|S_EM </li>
 *                                          <li> 证书公钥相关:PUB_KEY|KEY_HASH </li>
 *  
 *  @param  [OUT]       valueBuf            存放证书信息项值的缓冲,返回utf8编码
 *  @param  [IN,OUT]    valueBufLen         输入valueBuf缓冲区的大小，返回实际需要的大小
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_GetCertInfo(SMF_CONTEXT* ctx, int certType, const char* key, char* valueBuf, int* valueBufLen);

/**
 *  功能：获取证书扩展信息信息
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        certType            证书类型 详见 { @link smf_type.h->USER_CERT_KEY_TYPE }
 *  @param  [IN]        oid                 需要获取的证书扩展项的证书oid
 *  @param  [OUT]       valueBuf            存放证书信息项值的缓冲,返回utf8编码
 *  @param  [IN,OUT]    valueBufLen         输入valueBuf缓冲区的大小，返回实际需要的大小
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_GetCertInfoByOid(SMF_CONTEXT* ctx, int certType, const char* oid, char* valueBuf,
                                      int* valueBufLen);

/**
 *  功能：获取证书剩余有效天数
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [OUT]       leftDays            返回证书剩余有效天数，证书已过期时返回的该值小于0
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_GetCertExpired(SMF_CONTEXT* ctx, int* leftDays);

/**
 * 功能：对原文进行PKCS1格式的数据签名
 * 注意：
 *      <li> 该方法传入的是待签名的原文数据，接口内部摘要后签名 </li> 
 *      <li> 该算法使用的摘要算法根据密钥类型，SM2->SM3 RSA-SHA1 </li> 
 *      <li> 开启协同密钥时，该接口有网络操作 </li> 
 * 
 *
 * @param   [IN]        ctx                 证书管理上下文
 * @param   [IN]        b64OriginData       签名原文的Base64编码
 * @param   [OUT]       b64SignDataBuf      存放签名结果Base64编码的缓冲
 * @param   [IN,OUT]    b64SignDataBufLen   输入b64SignDataBuf缓冲区的大小，返回实际需要的大小
 *
 * @return = 0 成功
 *         !=0 错误码
 */
EXPORT_C_API int SMF_SignData(SMF_CONTEXT* ctx, const char* b64OriginData, char* b64SignDataBuf,
                              int* b64SignDataBufLen);

/**
 * 功能：对原文进行PKCS1格式的数据签名
 * 注意：
 *      <li> 该方法传入的是已经经过摘要计算的数据 </li> 
 *      <li> 开启协同密钥时，该接口有网络操作 </li> 
 * 
 *
 * @param   [IN]        ctx                 证书管理上下文
 * @param   [IN]        b64OriginData       原文摘要的Base64编码
 * @param   [OUT]       b64SignDataBuf      存放签名结果Base64编码的缓冲
 * @param   [IN,OUT]    b64SignDataBufLen   输入b64SignDataBuf缓冲区的大小，返回实际需要的大小
 *
 * @return = 0 成功
 *         !=0 错误码
 */
EXPORT_C_API int SMF_SignData_ex(SMF_CONTEXT* ctx, const char* b64MdData, char* b64SignDataBuf, int* b64SignDataBufLen);

/**
 *  功能：验证PKCS#1格式的签名数据
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        dgstAlg             摘要算法名称 详见 { @link smf_type.h->DIGEST_TYPE }
 *  @param  [IN]        b64CertB64          用于验签的证书
 *  @param  [IN]        b64OriginData       原文数据Base64编码后的字符串
 *  @param  [IN]        b64SignData         签名数据Base64编码后的字符串
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_VerifyData(SMF_CONTEXT* ctx, const char* b64CertB64, int dgstAlg, const char* b64OriginData,
                                const char* b64SignData);

/**
 * 功能：对原文进行PKCS#7格式的数据签名
 * 注意：
 *      <li> 该算法使用的摘要算法根据密钥类型，SM2->SM3 RSA-SHA1 </li> 
 *      <li> 开启协同密钥时，该接口有网络操作 </li> 
 *
 * @param   [IN]        ctx                 证书管理上下文
 * @param   [IN]        b64OriginData       签名原文的Base64编码
 * @param   [OUT]       b64Pkcs7MsgBuf      存放签名消息Base64编码的缓冲
 * @param   [IN,OUT]    b64Pkcs7MsgBufLen   输入b64Pkcs7MsgBuf缓冲区的大小，返回实际需要的大小
 *
 * @return = 0 成功
 *         !=0 错误码
 */
EXPORT_C_API int SMF_SignMessage(SMF_CONTEXT* ctx, const char* b64OriginData, char* b64Pkcs7MsgBuf,
                                 int* b64Pkcs7MsgBufLen);

/**
 * 功能：对原文进行PKCS#7格式的数据签名
 * 注意：
 *      <li> 开启协同密钥时，该接口有网络操作 </li> 
 *
 * @param   [IN]        ctx                 证书管理上下文
 * @param   [IN]        b64OriginData       签名原文的Base64编码
 * @param   [IN]        digest              摘要算法 详见 { @link smf_type.h->DIGEST_TYPE }
 * @param   [IN]        flag                生成pcks7数据flag 详见 { @link smf_type.h->SIGN_FLAG }
 * @param   [OUT]       b64Pkcs7MsgBuf      存放签名消息Base64编码的缓冲
 * @param   [IN,OUT]    b64Pkcs7MsgBufLen   输入b64Pkcs7MsgBuf缓冲区的大小，返回实际需要的大小
 *
 * @return = 0 成功
 *         !=0 错误码
 */
EXPORT_C_API int SMF_SignMessage_Ext(SMF_CONTEXT* ctx, const char* b64OriginData, DIGEST_TYPE digest, SIGN_FLAG flag,
                                     char* b64Pkcs7MsgBuf, int* b64Pkcs7MsgBufLen);

/**
 * 功能：验证PKCS#7格式的签名数据
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        b64Pkcs7Message     PKCS#7格式的签名数据Base64编码后的字符串
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_VerifyMessage(SMF_CONTEXT* ctx, const char* b64Pkcs7Message);

/**
 * 功能：验证PKCS#7格式的签名数据扩展接口
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        b64Pkcs7Message     PKCS#7格式的签名数据Base64编码后的字符串
 *  @param  [IN]        bOutIsB64           输出原文的是否是base64格式
 *  @param  [OUT]       OrgBuf              存放签名原文的缓冲区
 *  @param  [IN,OUT]    OrgBufBufLen        输入签名原文缓冲区的大小，返回实际需要的空间大小
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_VerifyMessage_Ex(SMF_CONTEXT* ctx, const char* b64Pkcs7Message, bool bOutIsB64, char* orgBuf,
                                      int* orgBufLen);

/**
 * 功能：验证PKCS#7格式的签名数据扩展接口
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        b64OriginData       签名原文的base64数据
 *  @param  [IN]        b64Cert             证书base64数据
 *  @param  [IN]        b64Pkcs7Message     PKCS#7格式的签名数据Base64编码后的字符串
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_VerifyMessage_Ext(SMF_CONTEXT* ctx, const char* b64OriginData, const char* b64Cert,
                                       const char* b64Pkcs7Message);

/**
 *  功能：对目标数据进行PKCS#7格式的数字信封
 *  注意：
 *      <li> rcvsNum为0时第一次调用该接口有网络阻塞 </li>
 *      <li> rcvsNum为0时，sdk内部与协同网关交互获取加密证书，需要网关支持 </li>
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        rcvrB64Certs        存放接收者Base64证书的数组
 *  @param  [IN]        rcvsNum             接收者个数
 *  @param  [IN]        b64OriginData       原文数据Base64编码后的字符串
 *  @param  [IN]        b64Pkcs7MsgBuf      存放数字信封Base64编码的缓冲区
 *  @param  [IN,OUT]    b64Pkcs7MsgBufLen   输入b64Pkcs7MsgBuf缓冲区的大小，返回实际需要的空间大小
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_EncryptMessage(SMF_CONTEXT* ctx, const char* rcvrB64Certs[], int rcvsNum,
                                    const char* b64OriginData, char* b64Pkcs7MsgBuf, int* b64Pkcs7MsgBufLen);

/**
 *  功能：对PKCS#7格式的数字信封解封
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        b64Pkcs7Envelop     Base64后的PKCS#7数字信封
 *  @param  [OUT]       b64OriginDataBuf    存放原文Base64编码的缓冲区
 *  @param  [IN,OUT]    b64OriginDataBufLen 输入b64OriginDataBuf缓冲区的大小，返回实际需要的大小
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_DecryptMessage(SMF_CONTEXT* ctx, const char* b64Pkcs7Envelop, char* dataBuf, int* dataBufLen);

/**
 *  功能：导出证书和skf2evp导出的pkey
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        pcert                X509 格式的证书
 *  @param  [OUT]       pkey                 EVP_PKEY 格式的key
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_GetUserCertAndKey(SMF_CONTEXT* ctx, void** pcert, void** pkey);

/**
 *  功能： 非对称加密数据，数据原文最大只支持128字节
 *  参数：
 *  @param     [IN]       pubKeyType        用来加密的公钥类型,参见PUBKEY_TYPE
 *  @param     [IN]       b64OriginData     base64 格式的原文数据
 *  @param     [IN]       b64Pubkey         用于加密的公钥数据
 *  @param     [IN]       EncryptedDataType 输出的SM2密文格式，1：国密结构数据；2:国标结构数据
 *  @param     [IN,OUT]   b64OutputBuf      存放的base64密文的缓冲区
 *  @param     [IN,OUT]   b64OutputBufLen   输入b64OutputBuf的缓冲区大小，返回实际需要的空间大小
 * 
 *  @return = 0 成功
 *          !=0 错误码
 */

EXPORT_C_API int SMF_EnCryptDataByPubKey(PUBKEY_TYPE pubKeyType, const char* b64Pubkey, const char* b64OriginData,
                                         int EncryptedDataType, char* b64OutputBuf, int* b64OutputBufLen);

/**
 *  功能： 使用外部私钥非对称解密数据
 *  参数：
 *  @param     [IN]       b64PriKey         用于解密被保护的der格式私钥
 *  @param     [IN]       bRSA              是否是RSA算法，false 则是SM2
 *  @param     [IN]       b64EncryptedData  base64格式的密文数据
 *  @param     [IN]       inEccDataType     输入的SM2密文格式，1：国密结构数据；2:国标结构数据
 *  @param     [IN,OUT]   b64OutputBuf      存放的base64解密后的缓冲区
 *  @param     [IN,OUT]   b64OutputBufLen   输入b64OutputBuf的缓冲区大小，返回实际需要的空间大小
 * 
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_DeCryptDataByPriKey(const char* b64PriKey, bool bRSA, const char* b64EncryptedData,
                                         int EncryptedDataType, char* b64OutputBuf, int* b64OutputBufLen);

/**
 *  功能： 使用用户ECC私钥非对称解密数据
 *  参数：
 *  @param     [IN]       ctx                   证书管理上下文
 *  @param     [IN]       b64EncryptedData      base64 格式的密文数据
 *  @param     [IN]       EncryptedDataType     输入的SM2密文格式，1：国密结构数据；2:国标结构数据
 *  @param     [IN,OUT]   b64OutputBuf          存放的base64解密后的缓冲区
 *  @param     [IN,OUT]   b64OutputBufLen       输入b64OutputBuf的缓冲区大小，返回实际需要的空间大小
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_EccDeCryptData(SMF_CONTEXT* ctx, const char* b64EncryptedData, int EncryptedDataType,
                                    char* b64OutputBuf, int* b64OutputBufLen);

/**
 *  功能： 获取会话密钥分量
 *  参数：
 *	
 *	@param	[IN]		role		当前角色
 *	@param	[IN]		option		保留扩展
 *	@param	[OUT]		data		会话密钥分量
 *	@param	[IN/OUT]	len			密钥分量实际长度
 *	@param	[OUT]		cctx		对称加密上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_Cipher2GetHeft(emSctRole role, int option, char* data, int* len, SMF_CIPHER_CTX** cctx);

/**
 *  功能： 生成会话密钥
 *  参数：
 * 
 *	@param	[IN]		cctx		对称加密上下文
 *	@param	[IN]		peer_data	对端会话密钥分量
 *	@param	[IN]		len			密钥分量长度
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_Cipher2GenKey(SMF_CIPHER_CTX* cctx, const char* peer_data, int len);

/**
 *  功能：对称加解密,默认PKCS5的填充方式
 *  参数：
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        cipherName          对称算法名称，支持的算法如下：
 *              AES128_CBC|AES128_ECB|AES128_ECM
 *              AES256_CBC|AES256_ECB|AES256_GCM
 *              SM4_CBC|SM4_ECB|SM4_GCM
 *              DES_CBC|DES_ECB
 *              3DES_CBC|3DES_ECB
 *  @param  [IN]        key                 对称密钥数据
 *  @param  [IN]        iv                  初始向量
 *  @param  [IN]        in                  原文
 *  @param  [IN]        inLen               原文长度
 *  @param  [OUT]       outBuf              密文缓冲
 *  @param  [IN,OUT]    outBufLen           输入密文缓冲长度，输出密文长度
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_Cipher(SMF_CONTEXT* ctx, const char* cipherName, const char* key, int keyLen, const char* iv,
                            int ivLen, const char* in, int inLen, char* outBuf, int* outBufLen, int mode);

/**
 *  功能：使用会话密钥进行对称加解密
 *  参数：
 *	
 *	@param	[IN]		cctx		对称加密上下文
 *	@param 	[IN] 		cipher_name	对称算法名称，支持的算法同上
 *	@param	[IN] 		iv			初始化向量
 *  @param  [IN] 		iv_len		初始化向量长度
 *	@param	[IN] 		in			输入明文或密文
 *  @param  [IN] 		in_len		明文长度或密文长度
 *	@param	[OUT] 		out			输出密文或明文
 *  @param  [IN/OUT] 	out_len		输出实际的密文长度或明文长度
 *	@param	[IN] 		mode		1：加密，0：解密
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_Cipher2(SMF_CIPHER_CTX* cctx, const char* cipher_name, const char* iv, int iv_len,
                             const char* in, int in_len, char* out, int* out_len, int mode);

/**
 *  功能：三段式对称加解密，第一步
 *  参数：
 *
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        cipherName          对称算法名称，支持的算法同上
 *  @param  [IN]        key                 对称密钥
 *  @param  [IN]        keyLen              对称密钥长度
 *  @param  [IN]        iv                  初始向量
 *  @param  [IN]        ivLen               初始向量长度
 *  @param  [IN]        mode                1:加密 0:解密
 *  @param  [OUT]        cctx                二级指针，返回加密上下文指针
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CipherInit(SMF_CONTEXT* ctx, const char* cipherName, const char* key, int kenLen, const char* iv,
                                int ivLen, int mode, SMF_CIPHER_CTX** cctx);

/**
 *  功能：三段式加解密，第一步，使用会话密钥
 *  参数：
 *	
 *	@param	[IN]		cctx		对称加密上下文
 *	@param 	[IN] 		cipher_name	对称算法名称，支持的算法同上
 *	@param	[IN] 		iv			初始化向量
 *  @param  [IN] 		iv_len		初始化向量长度
 * 	@param	[IN]		mode		1：加密，0：解密
 * 
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_Cipher2Init(SMF_CIPHER_CTX* cctx, const char* cipher_name, const char* iv, int iv_len, int mode);

/**
 *  功能：三段式对称加解密，第二步
 *  参数：
 *	
 *  @param  [IN]        cctx                对称加解密上下文
 *  @param  [IN]        in                  原文
 *  @param  [IN]        inLen               原文长度
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CipherUpdate(SMF_CIPHER_CTX* cctx, const char* in, int inLen);

/**
 *  功能：三段式对称加解密，第三步
 *  参数：
 *	
 *  @param  [IN]        cctx                对称加解密上下文
 *  @param  [OUT]       outBuf              密文缓冲
 *  @param  [IN,OUT]    outBufLen           输入密文缓冲长度，输出密文长度
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CipherFinal(SMF_CIPHER_CTX* cctx, char* out, int* outen);

/**
 *  功能：三段式模式对称算法，第三步加密扩展接口，该接口支持GCM模式
 *
 *  @param  [IN]        cctx                对称加解密上下文
 *  @param  [OUT]       outBuf              加密后密文数据缓存区
 *  @param  [IN,OUT]    outBufLen           输入密文缓存区长度，输出密文长度
 *  @param  [IN,OUT]    outVerifyTag        初始化时使用的是gcm模式算法会输出本次加密时使用的验证tag的缓存区
 *  @param  [IN,OUT]    verifyTagLen        输入或输出verifyTag参数的长度,一般长度是16
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CipherFinalExtEnc(SMF_CIPHER_CTX* cctx, char* outBuf, int* outBufLen, char* outVerifyTag, int* verifyTagLen);

/**
 *  功能：三段式模式对称算法，第三步解密扩展接口，该接口支持GCM模式
 *  参数：
 *	
 *  @param  [IN]        cctx                对称加解密上下文
 *  @param  [IN]        inVerifyTag         初始化时使用的是gcm模式时对端加密时产生的验证tag
 *  @param  [IN,OUT]    verifyTagLen        输入参数inVerifyTag参数的长度,一般长度是16
 *  @param  [OUT]       outBuf              解密后明文缓存区
 *  @param  [IN,OUT]    outBufLen           解密后明文缓存区长度，输出明文长度
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_CipherFinalExtDec(SMF_CIPHER_CTX* cctx, const char* inVerifyTag, int verifyTagLen, char* outBuf, int* outBufLen);

/**
 *  功能：释放对称加解密上下文
 *  参数：
 *	
 *  @param  [IN]        cctx                对称加解密上下文
 *
 *  @return = 0 成功
 */
EXPORT_C_API int SMF_CipherFree(SMF_CIPHER_CTX* cctx);

/**
 *  功能：对数据进行摘要计算
 *  参数：
 *	
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        dgstName            摘要算法名称，详见{ @link smf_type.h->DIGEST_TYPE}
 *  @param  [IN]        in                  原文
 *  @param  [IN]        inLen               原文长度
 *  @param  [OUT]       dgst                摘要缓冲区
 *  @param  [IN,OUT]    dgstLen             输入摘要缓冲区大小，返回摘要长度
 *
 *  @return = 0 成功
 *          !=0 失败
 */
EXPORT_C_API int SMF_Digest(SMF_CONTEXT* ctx, int dgstType, const char* in, int inLen, char* dgst, int* dgstlen);

/**
 *  功能：三段式摘要，第一步
 *  参数：
 *	
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        dgstType            摘要算法类型，详见{ @link smf_type.h->DIGEST_TYPE}
 *
 *  @return !=NULL 摘要上下文
 *          = NULL 参数出错
 */
EXPORT_C_API int SMF_DigestInit(SMF_CONTEXT* ctx, int dgstType, SMF_DGST_CTX** dctx);

/**
 *  功能：三段式摘要，第二步
 *  参数：
 *	
 *  @param  [IN]        ctx                 摘要上下文
 *  @param  [IN]        in                  原文数据[分段]
 *  @param  [IN]        inLen               数据长度
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_DigestUpdate(SMF_DGST_CTX* dctx, const char* in, int inLen);

/**
 *  功能：三段式摘要，第三步
 *  参数：
 *	
 *  @param  [IN]        dctx                摘要上下文
 *  @param  [OUT]       dgst                摘要缓冲区，输出摘要数据
 *  @param  [IN,OUT]    dgstLen             输入摘要缓冲区大小，返回摘要数据长度
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_DigestFinal(SMF_DGST_CTX* dctx, char* dgst, int* dgstLen);

/**
 *  功能：新建SSL上下文
 *  参数：
 *	
 *  @param  [IN]        ctx                 证书管理上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_SSLNew(SMF_CONTEXT* ctx, SMF_SSL_CTX** psctx);

/**
 *  功能：新建SSL上下文扩展接口
 *  参数：
 *	
 *  @param  [IN]        ctx                 证书管理上下文
 *  @param  [IN]        nUseCert            客户端是否提交证书,不同配置说明如下：
 *                                          <li> 1:会使用用户证书双向认证时使用 </li>
 *                                          <li> 0:客户端不提交证书，单向认证时使用 </li>
 * 
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_SSLNew_Ex(SMF_CONTEXT* ctx, int nUseCert, SMF_SSL_CTX** psctx);

/**
 *  功能：使用服务器地址与服务端建立SSL连接
 *  参数：
 *
 *  @param  [IN]            sctx            SSL上下文
 *  @param  [IN]            server          SSL服务地址
 *  @param  [IN]            port            SSL服务端口
 *  @param  [IN]            timeOut         与网关服务器建立SSL握手超时时间(ms)
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_SSLConnect(SMF_SSL_CTX* sctx, const char* server, int port, const int timeOut);

/**
 *  功能：使用同步套接字与服务器建立SSL握手
 *  参数：
 * 
 *  @param  [IN]            sctx            SSL上下文
 *  @param  [IN]            socket          与网关已经建立好的同步套接字
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_SSLConnectSynSocket(SMF_SSL_CTX* sctx, const int socket);

/**
 *  功能：使用异步套接字与服务器建立SSL握手
 *  参数：
 * 
 *  @param  [IN]            sctx            SSL上下文
 *  @param  [IN]            socket          与网关已经建立好的异步套接字
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_SSLConnectAsynSocket(SMF_SSL_CTX* sctx, const int socket);

/**
 *  功能： 从SSL中获取客户端的外网真实地址
 *  注意：
 *      <li> 需要网关开启:客户端地址透析->SDK IP透传地址 </li> 
 * 
 *  参数：
 *
 *  @param  [IN]            sctx            SSL上下文
 *  @param  [OUT]           address         客户端的真实地址返回格式ipv4 -> ip:port; ipv6->[ip]:port
 *  @param  [IN,OUT]        addresslen      输入address长度
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_SSLGetClientAddress(SMF_SSL_CTX* sctx, char* address, int* addresslen);

/**
 *  功能： 向SSL连接发送数据
 *  注意：
 *      <li> 该接口是否阻塞取决于SSLCONNECT时传入的socket是否阻塞 </li> 
 * 
 *  参数：
 *
 *  @param  [IN]            sctx            SSL上下文
 *  @param  [OUT]           buf             数据发送缓冲区
 *  @param  [IN]            len             要发送的数据长度
 *
 *  @return = 0 成功
 *          = SSL_ERROR_WANT_READ|SSL_ERROR_WANT_WRITE 操作未完成，需要等待下一次可写重试
 *			= SSL_ERROR_SYSCALL 发生系统错误，需要获取系统错误码并检查系统错误，如果存在S_EAGAIN|S_EINPROGRESS|S_EINTR 需要重试一次
 *          !=0 其他错误码断开连接重连
 */
EXPORT_C_API int SMF_SSLSend(SMF_SSL_CTX* sctx, const char* buf, int len);

/**
 *  功能： 向SSL连接发送数据扩展接口，输出参数带有实际的发送数据长度
 *  注意：
 *      <li> 该接口是否阻塞取决于SSLCONNECT时传入的socket是否阻塞 </li> 
 * 
 *  参数：
 * 
 *  @param  [IN]            sctx            SSL上下文
 *  @param  [OUT]           buf             数据发送缓冲区
 *  @param  [IN,OUT]        len             输入要发送buf长度，输出实际发送的数据长度
 *
 *  @return = 0 成功
 *          = SSL_ERROR_WANT_READ|SSL_ERROR_WANT_WRITE 操作未完成，需要等待下一次可写重试
 *			= SSL_ERROR_SYSCALL 发生系统错误，需要获取系统错误码并检查系统错误，如果存在S_EAGAIN|S_EINPROGRESS|S_EINTR 需要重试一次
 *          !=0 其他错误码断开连接重连
 */
EXPORT_C_API int SMF_SSLSendEx(SMF_SSL_CTX* sctx, const char* buf, int* len);

/**
 *  功能： 从SSL连接上接收数据
 *  注意：
 *      <li> 该接口是否阻塞取决于SSLCONNECT时传入的socket是否阻塞 </li> 
 * 
 *  参数：
 *
 *  @param  [IN]            sctx            SSL上下文
 *  @param  [OUT]           buf             数据接收缓冲区
 *  @param  [IN,OUT]        len             输入buf长度，输出收到的数据长度
 *
 *  @return = 0 成功
 *          = SSL_ERROR_WANT_READ|SSL_ERROR_WANT_WRITE 操作未完成，需要等待下一次可读重试
 *			= SSL_ERROR_SYSCALL 发生系统错误，需要获取系统错误码并检查系统错误，如果存在S_EAGAIN|S_EINPROGRESS|S_EINTR 需要重试一次
 *          !=0 其他错误码断开连接重连
 */
EXPORT_C_API int SMF_SSLRecv(SMF_SSL_CTX* sctx, char* buf, int* len);

/**
 *  功能： 关闭SSL连接
 *  参数：
 *
 *  @param  [IN]            sctx            SSL上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_SSLShutdown(SMF_SSL_CTX* sctx);

/**
 *  功能：释放SSL上下文
 *  参数：
 *
 *  @param  [IN]            sctx            SSL上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_SSLFree(SMF_SSL_CTX* sctx);

/**
 *  功能：设置sslctx 绑定指定传入的socket fd
 *  参数：
 *
 *  @param  [IN]            sctx            SSL上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_SSLSetSocket(SMF_SSL_CTX* sctx, int socket);

/**
 *  功能：获取sslctx 已经绑定的socket fd
 *  参数：
 *
 *  @param  [IN]            sctx            SSL上下文
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_SSLGetSoket(SMF_SSL_CTX* sctx, int* pSocket);

/**
 *  功能：检查SSL中还有多少可读数据
 *  参数：
 *
 *  @param  [IN]            sctx            SSL上下文
 *
 *  @return = 0 SSL中数据已经接收完
 *          > 0 SSL中剩余的可读数据
 */
EXPORT_C_API int SMF_SSLPending(SMF_SSL_CTX* sctx);

/**
 *  功能：获取sdk版本号
 *  参数：
 *
 *  @return  char*  当前版本号
 */
EXPORT_C_API char* SMF_GetSdkVersion();

/**
 * 功能：单向连接测速接口
 *  参数：
 * 
 *  @param  [IN]            server          SSL服务地址
 *  @param  [IN]            port            SSL服务端口
 *  @param  [IN]            timeOut         与网关服务器建立SSL握手超时时间(ms)
 *  @param  [IN]            dateLen         测速请求的数据长度，传入0 代表不做业务数据测速
 *  @param  [IN]            bUseGmProtocl    测试ssl 时是否使用国密算法 true-> 使用，false -> 不使用
 *
 *  @return = 0 成功
 *          !=0 错误码
 *          = ERROR_SSL_CONNECT（-30055）握手失败，检查服务端配置
 *          = SMF_SERVER_CONNECT_ERROR（-30074） 网络连接失败
 *          = SMF_ERROR_SSL_CONNECT_TIMEOUT（-30072）握手超时
 */
EXPORT_C_API int SMF_SSLConnectTest(const char* server, int port, int timeOut, int dateLen, bool UseGmProtocl);

/**
 *  功能：设置租户参数，一般对接的服务器是云服务器需要验证租户id时需要调用该接口
 *  参数：
 *
 *  @param  [IN]        tenant_id            租户id
 *  @param  [IN]        tenant_auth          租户授权信息
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_SetTenantParam(const char* tenant_id, const char* tenant_auth);

/**
 *  功能：注册用户
 *  参数：
 *
 *  @param  [IN]        url          服务器地址,必填；protocol://ip:port protocol可以为 http|https|https_tls_psk|gmvpn
 *  @param  [IN]        uid          用户唯一标识，必填
 *  @param  [IN]        pwd          用户用于认证时的密码，选填
 *  @param  [IN]        phone        用户关联的手机号，选填
 *  @param  [IN]        user_type    用户类型，选填
 *
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_RegisteUser(const char* url, const char* uid, const char* pwd, const char* phone, const char* user_type);

/**
 *  功能:协商密钥并使用协商密钥加密数据
 *  注意：
 *      <li> 该接口是一个会联网操作的接口，如果本地没有产生过密钥因子会联网获取，联网服务器地址是协同服务地址 </li> 
 * 
 *  参数：
 * 
 *  @param   [IN]       ctx:证书管理上下文，调用初始化接口得到
 *  @param   [IN]       orgData:待加密的原文数据
 *  @param   [IN]  	    orgDataLen:待加密的原文数据长度
 *  @param   [IN]       cipherName: 对称算法名称，支持的算法如下：
 *						AES128_CBC|AES128_ECB|AES128_ECM
 *						AES256_CBC|AES256_ECB|AES256_GCM
 *						SM4_CBC|SM4_ECB|SM4_GCM
 *						DES_CBC|DES_ECB
 *						3DES_CBC|3DES_ECB
 *  @param   [IN]       exParam：扩展参数
 *  @param   [IN,OUT]    outBuf              加密后密文数据缓存区
 *  @param   [IN,OUT]    outBufLen           输入密文缓存区长度，输出密文长度
 *  @return = 0 成功
 *          !=0 错误码
 */

EXPORT_C_API int SMF_EncryptDataBySessionKey(SMF_CONTEXT* ctx, const char* orgData, int orgDataLen,
	const char *cipherName, const void *exParam, char* outBuf, int* outBufLen);

/**
 *  功能:协商密钥并使用协商密钥解密数据
 *  注意：
 *      <li> 该接口是一个会联网操作的接口，如果本地没有产生过密钥因子会联网获取，联网服务器地址是协同服务地址 </li> 
 * 
 *  参数：
 * 
 *  @param   [IN]       ctx:证书管理上下文，调用初始化接口得到
 *  @param   [IN]       encData:待解密的密文数据
 *  @param   [IN]  	    encDataLen:待解密的密文数据长度
 *  @param   [IN]       exParam：扩展参数
 *  @param  [IN,OUT]    outBuf              解密后原文数据缓存区
 *  @param  [IN,OUT]    outBufLen           解密后原文数据缓存区长度，输出原文长度
 *  @return = 0 成功
 *          !=0 错误码
 */
EXPORT_C_API int SMF_DecryptDataBySessionKey(SMF_CONTEXT* ctx, const char* encData, int encDataLen, const void *exParam, char* outBuf, int* outBufLen);

/**
*  功能:获取指定长度随机数
*  参数：
*
*  @param   [IN]       nRandomLen:指定长度的随机数
*  @param  [IN,OUT]    b64RandomBuf        base64 格式的随机数输出缓存区
*  @param  [IN,OUT]    b64RandomBufLen     base64 格式的随机数输出缓存区长度，输出数据长度
*  @return = 0 成功
*          !=0 错误码
*/
EXPORT_C_API int SMF_GenRandom(int nRandomLen, char* b64RandomBuf, int* b64RandomBufLen);

/**
*  功能:解析pkcs7签名数据包得到证书或其他信息
*  注意：如果有多个签名值，需要先获取签名个数然后传入索引获取不同的签名数据
*  参数：
*
*  @param  [IN]        b64SignedData       待解析的pkcs签名数据
*  @param  [IN]        signIndex           获取签名数据时传入的索引
*  @param  [IN]        signItem            获取签名数据的中的项
*  @param  [IN,OUT]    b64ValueBuf         base64 格式的获取到的数据所在缓存
*  @param  [IN,OUT]    b64ValueBufLen      输入参数时是b64ValueBuf缓存区长度，输出是实际数据长度
*  @return = 0 成功
*          !=0 错误码
*/
EXPORT_C_API int SMF_ParseSignedMessage(const char* b64SignedData, int signIndex, SIGN_DATA_ITEM signItem, char *b64ValueBuf, int* b64ValueBufLen);

#ifdef __cplusplus
}
#endif

#endif //__SMF_API_H__
