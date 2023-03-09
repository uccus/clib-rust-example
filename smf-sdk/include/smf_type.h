#ifndef __SMF_TYPE_H__
#define __SMF_TYPE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SMF_CONTEXT_st {
    void* _inner_ctx;
} SMF_CONTEXT;

typedef struct SMF_CIPHER_CTX_st {
    void* _inner_ctx;
    void* _cipher_ctx;
} SMF_CIPHER_CTX;

typedef struct SMF_DGST_CTX_st {
    void* _inner_ctx;
    void* _dgst_ctx;
} SMF_DGST_CTX;

typedef struct SMF_SSL_CTX_st {
    void* _inner_ctx;
    void* _inner_ssl;
    void* _inner_ssl_ctx;
} SMF_SSL_CTX;

typedef struct Config_s {
    char* cert_server_url; /* 非必填 证书管理服务地址,如果有多个负载地址则传入的地址用“;” 分隔格式形如gmvpn://10.0.80.168:1855; */
    char* sks_server_url;  /* 非必填(如果有协同系统必须要设置) 协同服务地址，可以和证书管理服务是同一个地址,如果有多个负载地址则传入的地址用“;”分隔格式形如gmvpn://10.0.80.168:1855;*/
    int cert_expired_days; /* 证书快要过期提示的天数，默认3天 */
    int log_level;         /* 日志级别，默认警告级别,日志级别详见详见{ @link SMF_LOG_LEVEL} */
    char* log_dir;         /* 日志目录，默认当前目录*/
    int recv_exception;    /* 是否接收异常，1：接收，0：不接收，默认不接收异常  */
    int time_out;          /* 网络通信超时时间,(单位s), 默认60s*/
    int simple_auth;       /* (对端是协同网关时必须要设置1)是否开启单向简单认证，1：是，0：否  默认开启 */
    int pin_retry_count;   /* pin码最大重试次数,默认5次 */
    int cert_chain_count;  /* 证书链文件个数 */
    char* cert_chain[32];  /* 非必填 ca的证书链，用于可以验证服务端证书有效性为空则不校验服务端证书  */
    char* term_info;       /* 终端描述信息，默认为空 */
    int verify_cert_trust_partial; /* 开启验证服务端证书链验证时,允许信任本地只有部分ca证书的情况,默认关闭,建议不开启 */
    char* client_cert_file;        /* 非必填(对端开启强制验证时必填)客户端p12 格式证书文件路径 */
    char* client_cert_pwd;         /* 非必填(对端开启强制验证时必填)客户端p12 格式证书文件保护密码 */
    char* simple_auth_secret;      /* 非必填(对端使用自定义密钥因子时必填) 单向简单认证所用的共享密钥 */
    int data_exlen;        /* 扩展数据长度 */
    char data_ex[1];       /* 扩展数据 */
} Config_t;

// 用户证书信息
typedef struct UserCertInfo_s {
    char issue_name[32];        /*颁发者CN项*/
    char subject_name[32];      /*使用者CN项*/
    char cid[64];               /*证书ID*/
    char not_before[32];        /*生效时间*/
    char not_after[32];         /*失效时间*/
    char last_use_time[32];     /*最后一次使用时间*/
    char term_os[32];           /*终端操作系统*/
    char term_ip[32];           /*终端IP*/
    char term_desc[32];         /*终端描述信息*/
    char term_hdtype[32];       /*终端硬件类型*/
    char term_manufacturer[32]; /*终端厂商*/
} UserCertInfo_t;

// 证书项
typedef enum
{
    CERT_INFO_SERIALNUMBER = 0, /* 证书十六进制序列号 */
    CERT_INFO_DEC_SERIALNUMBER, /* 证书十进制序列号 */
    //颁发者
    CERT_INFO_ISSUER_CN,		/* 证书颁发者CN项 */
    CERT_INFO_ISSUER_E,			/* 证书颁发者E项 */
    CERT_INFO_ISSUER_EM,		/* 证书颁发者Email项 */
    CERT_INFO_ISSUER_OU,        /* 证书颁发者OU项 */
    CERT_INFO_ISSUER_O,         /* 证书颁发者O项 */
    CERT_INFO_ISSUER_L,         /* 证书颁发者L项 */
    CERT_INFO_ISSUER_S,         /* 证书颁发者S项 */
    CERT_INFO_ISSUER_ST,        /* 证书颁发者ST项 */
    CERT_INFO_ISSUER_C,         /* 证书颁发者C项 */
    CERT_INFO_ISSUER_G,         /* 证书颁发者G项 */
    CERT_INFO_ISSUER_I,         /* 证书颁发者I项 */
    CERT_INFO_ISSUER_T,         /* 证书颁发者T项 */
    CERT_INFO_ISSUER_DN,        /* 证书颁发者DN项 */
    //持有者
    CERT_INFO_SUBJECT_CN,       /* 证书使用者CN项 */
    CERT_INFO_SUBJECT_E,        /* 证书使用者E项 */
    CERT_INFO_SUBJECT_EM,       /* 证书使用者Email项 */
    CERT_INFO_SUBJECT_OU,       /* 证书使用者OU项 */
    CERT_INFO_SUBJECT_O,        /* 证书使用者O项 */
    CERT_INFO_SUBJECT_L,        /* 证书使用者L项 */
    CERT_INFO_SUBJECT_S,        /* 证书使用者S项 */
    CERT_INFO_SUBJECT_ST,       /* 证书使用者SR项 */
    CERT_INFO_SUBJECT_C,        /* 证书使用者C项 */
    CERT_INFO_SUBJECT_G,        /* 证书使用者G项 */
    CERT_INFO_SUBJECT_I,        /* 证书使用者I项 */
    CERT_INFO_SUBJECT_T,        /* 证书使用者T项 */
    CERT_INFO_SUBJECT_DN,       /* 证书使用者DN项 */
    //证书
    CERT_INFO_BODY_BASE64,      /* base64格式的证书 */
    //公钥
    CERT_INFO_PUBLIC_KEY,       /* 当前用户证书公钥 */
    //证书指纹
    CERT_KEY_HASH,              /* 当前证书 */
    //证书扩展项
    CERT_INFO_EXTOID_AUTHID,   /* 证书使用者认证扩展项 */
} CERT_ITEM_NAME;

// 摘要类型
typedef enum
{
    DIGEST_TYPE_MD5     = 0x00,     /* MD5 摘要算法*/
    DIGEST_TYPE_SHA1    = 0x01,     /* SHA1 摘要算法*/
    DIGEST_TYPE_SHA256  = 0x02,     /* SHA256 摘要算法*/
    DIGEST_TYPE_SHA512  = 0x03,     /* SHA512 摘要算法*/
    DIGEST_TYPE_SM3     = 0x04,     /* SM3 摘要算法*/
    DIGEST_TYPE_UNKNOWN = 0xFF      /* 未定义算法 */
} DIGEST_TYPE;

// 对称算法常量定义
typedef enum
{
    SYM_ALGOR_DES        = 0x00,    /* C接口对应DES_CBC对称算法 */
    SYM_ALGOR_3DES       = 0x01,    /* C接口对应3DES_CBC对称算法 */
    SYM_ALGOR_AES        = 0x02,    /* C接口对应AES_CBC对称算 */
    SYM_ALGOR_SM4        = 0x03,    /* C接口对应SM4_CBC对称算法 */
    SYM_ALGOR_AES256     = 0x04,    /* C接口对应AES256_CBC对称算法*/
    SYM_ALGOR_AES_ECB    = 0x05,    /* C接口对应AES_ECB对称算法 */
    SYM_ALGOR_SM4_ECB    = 0x06,    /* C接口对应SM4_ECB对称算法 */
    SYM_ALGOR_3DES_ECB   = 0X07,    /* C接口对应3DES_ECB对称算法 */
    SYM_ALGOR_DES_ECB    = 0X08,    /* C接口对应DES_ECB对称算法 */
    SYM_ALGOR_AES256_ECB = 0X09,    /* C接口对应AES256_ECB对称算法 */
    SYM_ALGOR_SM4_GCM    = 0x0A,    /* C接口对应SM4_GCM对称算法 */
    SYM_ALGOR_AES_GCM    = 0x0B,    /* C接口对应AES_GCM对称算法 */
    SYM_ALGOR_AES256_GCM = 0x0C,    /* C接口对应AES256_GCM对称算法 */
    SYM_UNKNOWN          = 0xFF,
} SYM_ALGOR;

// P7签名方式
typedef enum
{
    ATTACH_DATA_AND_CERT = 0,   // 包含原文和证书
    DETACH_DATA          = 0x1, // 不包含原文
    DETACH_CERT          = 0x2, // 不包含证书
    DETACH_CERT_AND_DATA = 0x3, // 不包含原文和证书
} SIGN_FLAG;

typedef enum {
	P7SIGN_ORGDATA,  //P7签名数据中的原文，如果是detach 则返回空
	P7SIGN_NUM,      //P7签名数据的个数
	P7SIGN_CERT,     //P7签名数据中的证书
	P7SIGN_DIGST,    //P7签名数据包中的签名值
}SIGN_DATA_ITEM;

// 客户端认证方式
typedef enum
{
    AT_None            = 0,  // 不认证
    AT_PWD             = 1,  // 密码认证
    AT_SM              = 2,  // 短信认证
    AT_FID             = 4,  // 人脸认证
    AT_SIG             = 8,  // 签名认证
    AT_PWD_THRID       = 16, // 第三方口令认证，不对密码做摘要处理
    AT_SM_THRID_TYPE_1 = 32, // 第三方短信认证，用户类型是正式用户需要输入用户证件号码
    AT_SM_THRID_TYPE_2 = 64, // 第三方短信认证，用户类型是虚拟用户不需要输入用户证件号码
} AT_TYPE;

// 快速证书管理接口操作命令
enum CERTMGR_CMD_Type
{
    CERTMGR_CMD_INIT_AUTH = 1, //初始化认证
    CERTMGR_CMD_ENROLL_CERT,   //证书快速签发
    CERTMGR_CMD_DELAY_CERT,    //证书快速延期
    CERTMGR_CMD_REVOKE_CERT,    //证书快速废除
	CERTMGR_CMD_UNLOCK_CERT,    //证书PIN重置
};

// SSL协议常量定义
typedef enum
{
    SSL_SSLV3 = 0, // SSLV3.0
    SSL_SSLV2,     // SSLV2.0
    SSL_TLS1_0,    // TLS1.0
    SSL_TLS1_1,    // TLS1.1
    SSL_TLS1_2,    // TLS1.2
    SSL_GMVPN,     // gmvpn
} SSL_PROTOCOL_TYPE;

// 代理协议
typedef enum
{
    PROXY_HTTP            = 0,
    PROXY_HTTP_1_0        = 1,
    PROXY_HTTPS           = 2,
    PROXY_SOCKS4          = 4,
    PROXY_SOCKS5          = 5,
    PROXY_SOCKS4A         = 6,
    PROXY_SOCKS5_HOSTNAME = 7,
} PROXY_PROTOCOL_TYPE;

//公钥格式类型
typedef enum
{
    PUBKEY_IN_CERT = 0, // 证书中携带的公钥
    PUBKEY_DER,         // der 格式的公钥，带算法id
    PUBKEY_DER_RSA,     // der 格式的rsa公钥，不带算法id
    PUBKEY_DER_ECC,     // der 格式的ecc公钥，不带算法id
    PUBKEY_SKF,         // SKF标准接口输出的公钥base64后处理的数据
} PUBKEY_TYPE;

//会话密钥分量角色
typedef enum
{
    SCT_UNDEF = 0,
    SCT_INITIATOR, // 发起方
    SCT_RESPONDER, // 响应方
} emSctRole;

// SMF日志级别
typedef enum {
    SMF_LOG_NONE,     // 不记录日志
    SMF_LOG_FATAL,    // 致命错误日志
    SMF_LOG_ERROR,    // 错误日志
    SMF_LOG_WARNING,  // 警告日志
    SMF_LOG_INFO,     // 信息级别日志
    SMF_LOG_DEBUG,    // 调试级别日志

} SMF_LOG_LEVEL;

//证书类型
typedef enum{
    CERT_SIGN_TYPE = 0, //签名证书
    CERT_ENC_TYPE       //加密证书
} USER_CERT_KEY_TYPE;

#ifdef __cplusplus
}
#endif

// 没有可读数据,数据处理正常
#define SSL_ERROR_NONE             0
// ssl 内部错误，由于一个ssl没有处理完成，有其他线程再同时处理导致，需要断开重连
#define SSL_ERROR_SSL              1
// 需要等待可读
#define SSL_ERROR_WANT_READ        2
// 需要等待可写
#define SSL_ERROR_WANT_WRITE       3
// ssl 内部错误，需要断开重连
#define SSL_ERROR_WANT_X509_LOOKUP 4
// 发生系统错误，需要获取系统错误码并检查系统错误，如果存在S_EAGAIN|S_EINPROGRESS|S_EINTR 需要重试一次
#define SSL_ERROR_SYSCALL          5
// 对端服务断开了连接
#define SSL_ERROR_ZERO_RETURN      6

#ifdef WIN32
#    define S_EADDRINUSE WSAEADDRINUSE
/* winsock does not define WSAEAGAIN */
/* in most (but not all!) BSD implementations EAGAIN==EWOULDBLOCK */
#    define S_EAGAIN      WSAEWOULDBLOCK
#    define S_ETIMEOUT    WSAETIMEDOUT
#    define S_ECONNRESET  WSAECONNRESET
#    define S_EINPROGRESS WSAEINPROGRESS
#    define S_EINTR       WSAEINTR
#    define S_EINVAL      WSAEINVAL
#    define S_EISCONN     WSAEISCONN
#    define S_EMFILE      WSAEMFILE
/* winsock does not define WSAENFILE */
#    define S_ENOBUFS WSAENOBUFS
/* winsock does not define WSAENOMEM */
#    define S_ENOPROTOOPT  WSAENOPROTOOPT
#    define S_ENOTSOCK     WSAENOTSOCK
#    define S_EOPNOTSUPP   WSAEOPNOTSUPP
#    define S_EWOULDBLOCK  WSAEWOULDBLOCK
#    define S_ECONNABORTED WSAECONNABORTED
#else
#    define S_EADDRINUSE   EADDRINUSE
/* winsock does not define WSAEAGAIN */
/* in most (but not all!) BSD implementations EAGAIN==EWOULDBLOCK */
#    define S_EAGAIN       EAGAIN
#    define S_ETIMEOUT     ETIMEDOUT
#    define S_ECONNRESET   ECONNRESET
#    define S_EINPROGRESS  EINPROGRESS
#    define S_EINTR        EINTR
#    define S_EINVAL       EINVAL
#    define S_EISCONN      EISCONN
#    define S_EMFILE       EMFILE
/* winsock does not define WSAENFILE */
#    define S_ENOBUFS      ENOBUFS
/* winsock does not define WSAENOMEM */
#    define S_ENOPROTOOPT  ENOPROTOOPT
#    define S_ENOTSOCK     ENOTSOCK
#    define S_EOPNOTSUPP   EOPNOTSUPP
#    define S_EWOULDBLOCK  EWOULDBLOCK
#    define S_ECONNABORTED ECONNABORTED
#endif
#endif //__SMF_TYPE_H__
