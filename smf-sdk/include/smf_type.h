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
    char* cert_server_url; /* �Ǳ��� ֤���������ַ,����ж�����ص�ַ����ĵ�ַ�á�;�� �ָ���ʽ����gmvpn://10.0.80.168:1855; */
    char* sks_server_url;  /* �Ǳ���(�����Эͬϵͳ����Ҫ����) Эͬ�����ַ�����Ժ�֤����������ͬһ����ַ,����ж�����ص�ַ����ĵ�ַ�á�;���ָ���ʽ����gmvpn://10.0.80.168:1855;*/
    int cert_expired_days; /* ֤���Ҫ������ʾ��������Ĭ��3�� */
    int log_level;         /* ��־����Ĭ�Ͼ��漶��,��־����������{ @link SMF_LOG_LEVEL} */
    char* log_dir;         /* ��־Ŀ¼��Ĭ�ϵ�ǰĿ¼*/
    int recv_exception;    /* �Ƿ�����쳣��1�����գ�0�������գ�Ĭ�ϲ������쳣  */
    int time_out;          /* ����ͨ�ų�ʱʱ��,(��λs), Ĭ��60s*/
    int simple_auth;       /* (�Զ���Эͬ����ʱ����Ҫ����1)�Ƿ����������֤��1���ǣ�0����  Ĭ�Ͽ��� */
    int pin_retry_count;   /* pin��������Դ���,Ĭ��5�� */
    int cert_chain_count;  /* ֤�����ļ����� */
    char* cert_chain[32];  /* �Ǳ��� ca��֤���������ڿ�����֤�����֤����Ч��Ϊ����У������֤��  */
    char* term_info;       /* �ն�������Ϣ��Ĭ��Ϊ�� */
    int verify_cert_trust_partial; /* ������֤�����֤������֤ʱ,�������α���ֻ�в���ca֤������,Ĭ�Ϲر�,���鲻���� */
    char* client_cert_file;        /* �Ǳ���(�Զ˿���ǿ����֤ʱ����)�ͻ���p12 ��ʽ֤���ļ�·�� */
    char* client_cert_pwd;         /* �Ǳ���(�Զ˿���ǿ����֤ʱ����)�ͻ���p12 ��ʽ֤���ļ��������� */
    char* simple_auth_secret;      /* �Ǳ���(�Զ�ʹ���Զ�����Կ����ʱ����) �������֤���õĹ�����Կ */
    int data_exlen;        /* ��չ���ݳ��� */
    char data_ex[1];       /* ��չ���� */
} Config_t;

// �û�֤����Ϣ
typedef struct UserCertInfo_s {
    char issue_name[32];        /*�䷢��CN��*/
    char subject_name[32];      /*ʹ����CN��*/
    char cid[64];               /*֤��ID*/
    char not_before[32];        /*��Чʱ��*/
    char not_after[32];         /*ʧЧʱ��*/
    char last_use_time[32];     /*���һ��ʹ��ʱ��*/
    char term_os[32];           /*�ն˲���ϵͳ*/
    char term_ip[32];           /*�ն�IP*/
    char term_desc[32];         /*�ն�������Ϣ*/
    char term_hdtype[32];       /*�ն�Ӳ������*/
    char term_manufacturer[32]; /*�ն˳���*/
} UserCertInfo_t;

// ֤����
typedef enum
{
    CERT_INFO_SERIALNUMBER = 0, /* ֤��ʮ���������к� */
    CERT_INFO_DEC_SERIALNUMBER, /* ֤��ʮ�������к� */
    //�䷢��
    CERT_INFO_ISSUER_CN,		/* ֤��䷢��CN�� */
    CERT_INFO_ISSUER_E,			/* ֤��䷢��E�� */
    CERT_INFO_ISSUER_EM,		/* ֤��䷢��Email�� */
    CERT_INFO_ISSUER_OU,        /* ֤��䷢��OU�� */
    CERT_INFO_ISSUER_O,         /* ֤��䷢��O�� */
    CERT_INFO_ISSUER_L,         /* ֤��䷢��L�� */
    CERT_INFO_ISSUER_S,         /* ֤��䷢��S�� */
    CERT_INFO_ISSUER_ST,        /* ֤��䷢��ST�� */
    CERT_INFO_ISSUER_C,         /* ֤��䷢��C�� */
    CERT_INFO_ISSUER_G,         /* ֤��䷢��G�� */
    CERT_INFO_ISSUER_I,         /* ֤��䷢��I�� */
    CERT_INFO_ISSUER_T,         /* ֤��䷢��T�� */
    CERT_INFO_ISSUER_DN,        /* ֤��䷢��DN�� */
    //������
    CERT_INFO_SUBJECT_CN,       /* ֤��ʹ����CN�� */
    CERT_INFO_SUBJECT_E,        /* ֤��ʹ����E�� */
    CERT_INFO_SUBJECT_EM,       /* ֤��ʹ����Email�� */
    CERT_INFO_SUBJECT_OU,       /* ֤��ʹ����OU�� */
    CERT_INFO_SUBJECT_O,        /* ֤��ʹ����O�� */
    CERT_INFO_SUBJECT_L,        /* ֤��ʹ����L�� */
    CERT_INFO_SUBJECT_S,        /* ֤��ʹ����S�� */
    CERT_INFO_SUBJECT_ST,       /* ֤��ʹ����SR�� */
    CERT_INFO_SUBJECT_C,        /* ֤��ʹ����C�� */
    CERT_INFO_SUBJECT_G,        /* ֤��ʹ����G�� */
    CERT_INFO_SUBJECT_I,        /* ֤��ʹ����I�� */
    CERT_INFO_SUBJECT_T,        /* ֤��ʹ����T�� */
    CERT_INFO_SUBJECT_DN,       /* ֤��ʹ����DN�� */
    //֤��
    CERT_INFO_BODY_BASE64,      /* base64��ʽ��֤�� */
    //��Կ
    CERT_INFO_PUBLIC_KEY,       /* ��ǰ�û�֤�鹫Կ */
    //֤��ָ��
    CERT_KEY_HASH,              /* ��ǰ֤�� */
    //֤����չ��
    CERT_INFO_EXTOID_AUTHID,   /* ֤��ʹ������֤��չ�� */
} CERT_ITEM_NAME;

// ժҪ����
typedef enum
{
    DIGEST_TYPE_MD5     = 0x00,     /* MD5 ժҪ�㷨*/
    DIGEST_TYPE_SHA1    = 0x01,     /* SHA1 ժҪ�㷨*/
    DIGEST_TYPE_SHA256  = 0x02,     /* SHA256 ժҪ�㷨*/
    DIGEST_TYPE_SHA512  = 0x03,     /* SHA512 ժҪ�㷨*/
    DIGEST_TYPE_SM3     = 0x04,     /* SM3 ժҪ�㷨*/
    DIGEST_TYPE_UNKNOWN = 0xFF      /* δ�����㷨 */
} DIGEST_TYPE;

// �Գ��㷨��������
typedef enum
{
    SYM_ALGOR_DES        = 0x00,    /* C�ӿڶ�ӦDES_CBC�Գ��㷨 */
    SYM_ALGOR_3DES       = 0x01,    /* C�ӿڶ�Ӧ3DES_CBC�Գ��㷨 */
    SYM_ALGOR_AES        = 0x02,    /* C�ӿڶ�ӦAES_CBC�Գ��� */
    SYM_ALGOR_SM4        = 0x03,    /* C�ӿڶ�ӦSM4_CBC�Գ��㷨 */
    SYM_ALGOR_AES256     = 0x04,    /* C�ӿڶ�ӦAES256_CBC�Գ��㷨*/
    SYM_ALGOR_AES_ECB    = 0x05,    /* C�ӿڶ�ӦAES_ECB�Գ��㷨 */
    SYM_ALGOR_SM4_ECB    = 0x06,    /* C�ӿڶ�ӦSM4_ECB�Գ��㷨 */
    SYM_ALGOR_3DES_ECB   = 0X07,    /* C�ӿڶ�Ӧ3DES_ECB�Գ��㷨 */
    SYM_ALGOR_DES_ECB    = 0X08,    /* C�ӿڶ�ӦDES_ECB�Գ��㷨 */
    SYM_ALGOR_AES256_ECB = 0X09,    /* C�ӿڶ�ӦAES256_ECB�Գ��㷨 */
    SYM_ALGOR_SM4_GCM    = 0x0A,    /* C�ӿڶ�ӦSM4_GCM�Գ��㷨 */
    SYM_ALGOR_AES_GCM    = 0x0B,    /* C�ӿڶ�ӦAES_GCM�Գ��㷨 */
    SYM_ALGOR_AES256_GCM = 0x0C,    /* C�ӿڶ�ӦAES256_GCM�Գ��㷨 */
    SYM_UNKNOWN          = 0xFF,
} SYM_ALGOR;

// P7ǩ����ʽ
typedef enum
{
    ATTACH_DATA_AND_CERT = 0,   // ����ԭ�ĺ�֤��
    DETACH_DATA          = 0x1, // ������ԭ��
    DETACH_CERT          = 0x2, // ������֤��
    DETACH_CERT_AND_DATA = 0x3, // ������ԭ�ĺ�֤��
} SIGN_FLAG;

typedef enum {
	P7SIGN_ORGDATA,  //P7ǩ�������е�ԭ�ģ������detach �򷵻ؿ�
	P7SIGN_NUM,      //P7ǩ�����ݵĸ���
	P7SIGN_CERT,     //P7ǩ�������е�֤��
	P7SIGN_DIGST,    //P7ǩ�����ݰ��е�ǩ��ֵ
}SIGN_DATA_ITEM;

// �ͻ�����֤��ʽ
typedef enum
{
    AT_None            = 0,  // ����֤
    AT_PWD             = 1,  // ������֤
    AT_SM              = 2,  // ������֤
    AT_FID             = 4,  // ������֤
    AT_SIG             = 8,  // ǩ����֤
    AT_PWD_THRID       = 16, // ������������֤������������ժҪ����
    AT_SM_THRID_TYPE_1 = 32, // ������������֤���û���������ʽ�û���Ҫ�����û�֤������
    AT_SM_THRID_TYPE_2 = 64, // ������������֤���û������������û�����Ҫ�����û�֤������
} AT_TYPE;

// ����֤�����ӿڲ�������
enum CERTMGR_CMD_Type
{
    CERTMGR_CMD_INIT_AUTH = 1, //��ʼ����֤
    CERTMGR_CMD_ENROLL_CERT,   //֤�����ǩ��
    CERTMGR_CMD_DELAY_CERT,    //֤���������
    CERTMGR_CMD_REVOKE_CERT,    //֤����ٷϳ�
	CERTMGR_CMD_UNLOCK_CERT,    //֤��PIN����
};

// SSLЭ�鳣������
typedef enum
{
    SSL_SSLV3 = 0, // SSLV3.0
    SSL_SSLV2,     // SSLV2.0
    SSL_TLS1_0,    // TLS1.0
    SSL_TLS1_1,    // TLS1.1
    SSL_TLS1_2,    // TLS1.2
    SSL_GMVPN,     // gmvpn
} SSL_PROTOCOL_TYPE;

// ����Э��
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

//��Կ��ʽ����
typedef enum
{
    PUBKEY_IN_CERT = 0, // ֤����Я���Ĺ�Կ
    PUBKEY_DER,         // der ��ʽ�Ĺ�Կ�����㷨id
    PUBKEY_DER_RSA,     // der ��ʽ��rsa��Կ�������㷨id
    PUBKEY_DER_ECC,     // der ��ʽ��ecc��Կ�������㷨id
    PUBKEY_SKF,         // SKF��׼�ӿ�����Ĺ�Կbase64���������
} PUBKEY_TYPE;

//�Ự��Կ������ɫ
typedef enum
{
    SCT_UNDEF = 0,
    SCT_INITIATOR, // ����
    SCT_RESPONDER, // ��Ӧ��
} emSctRole;

// SMF��־����
typedef enum {
    SMF_LOG_NONE,     // ����¼��־
    SMF_LOG_FATAL,    // ����������־
    SMF_LOG_ERROR,    // ������־
    SMF_LOG_WARNING,  // ������־
    SMF_LOG_INFO,     // ��Ϣ������־
    SMF_LOG_DEBUG,    // ���Լ�����־

} SMF_LOG_LEVEL;

//֤������
typedef enum{
    CERT_SIGN_TYPE = 0, //ǩ��֤��
    CERT_ENC_TYPE       //����֤��
} USER_CERT_KEY_TYPE;

#ifdef __cplusplus
}
#endif

// û�пɶ�����,���ݴ�������
#define SSL_ERROR_NONE             0
// ssl �ڲ���������һ��sslû�д�����ɣ��������߳���ͬʱ�����£���Ҫ�Ͽ�����
#define SSL_ERROR_SSL              1
// ��Ҫ�ȴ��ɶ�
#define SSL_ERROR_WANT_READ        2
// ��Ҫ�ȴ���д
#define SSL_ERROR_WANT_WRITE       3
// ssl �ڲ�������Ҫ�Ͽ�����
#define SSL_ERROR_WANT_X509_LOOKUP 4
// ����ϵͳ������Ҫ��ȡϵͳ�����벢���ϵͳ�����������S_EAGAIN|S_EINPROGRESS|S_EINTR ��Ҫ����һ��
#define SSL_ERROR_SYSCALL          5
// �Զ˷���Ͽ�������
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
