#ifndef __SMF_ERROR_H__
#define __SMF_ERROR_H__
#define ERR_OK                  0    //函数返回成功
#define ERR_PENDING             -1   //异步调用，函数已经执行
#define ERR_FUNCTION_INCOMPLETE -2   //功能暂未实现
#define ERR_LICENSE_EXPIRED     -3   // license过期
#define ERR_UNDEFINED           -100 //错误未定义

#define ERROR_DEVICE_BASE     -10000     //设备基准错误
#define ERROR_CERT_BASE       -20000     //证书错误
#define ERROR_LOCAL_FUNC_BASE -30000     //本地函数接口调用错误
#define ERROR_SERVER_BASE     -50000     //服务基准错误
#define ERROR_CDS_API_BASE    -333700000 // CDS系统API接口处理失败错误基础
#define ERROR_CDS_INNER_BASE  -305500000 // CDS系统内部失败错误基础
#define ERROR_CDS_PKI_BASE    -328300000 // CDS系统与PKI交互失败处理基础
#define ERROR_CDS_REDIS_BASE  -383400000 // CDS系统与redis交互失败错误基础
#define ERROR_CDS_M_BASE      -345200000 // CDS系统与CDSM交互失败错误基础
#define ERROR_CDS_T_BASE      1000000    // 云cds 服务基础错误

#define ERROR_DEVICE_NOT_FIND    ERROR_DEVICE_BASE - 0  //设备没有找到
#define ERROR_DEVICE_AUTH        ERROR_DEVICE_BASE - 1  //设备认证失败
#define ERROR_CREATE_APP         ERROR_DEVICE_BASE - 2  //创建应用失败
#define ERROR_DELETE_APP         ERROR_DEVICE_BASE - 3  //删除应用失败
#define ERROR_CREATE_CON         ERROR_DEVICE_BASE - 4  //创建容器失败
#define ERROR_DELETE_CON         ERROR_DEVICE_BASE - 5  //删除容器失败
#define ERROR_CONNECT_DEV        ERROR_DEVICE_BASE - 6  //连接设备失败
#define ERROR_OPEN_APP           ERROR_DEVICE_BASE - 7  //打开应用失败
#define ERROR_OPEN_CON           ERROR_DEVICE_BASE - 8  //打开容器失败
#define ERROR_USER_LOGIN         ERROR_DEVICE_BASE - 9  // pin码验证失败
#define ERROR_AMIN_LOGIN         ERROR_DEVICE_BASE - 10 //管理员登录失败
#define ERROR_CHANGE_PIN         ERROR_DEVICE_BASE - 11 // pin码修改失败
#define ERROR_UNLOCK_PIN         ERROR_DEVICE_BASE - 12 // pin码解锁失败
#define ERROR_DEV_LOCK           ERROR_DEVICE_BASE - 13 // pin码错误次数过多，设备已锁定
#define ERROR_PIN_REPEAT         ERROR_DEVICE_BASE - 14 //新老PIN码不能一样
#define ERROR_DEVICE_NOT_OPEN    ERROR_DEVICE_BASE - 15 //设备打开失败
#define ERROR_APP_NOT_OPEN       ERROR_DEVICE_BASE - 16 //应用未打开
#define ERROR_APP_NOT_FOUND      ERROR_DEVICE_BASE - 17 //应用没有找到
#define ERROR_CON_NOT_OPEN       ERROR_DEVICE_BASE - 18 //容器未打开
#define ERROR_CON_NOT_FOUND      ERROR_DEVICE_BASE - 19 //容器未找到，没有发证
#define ERROR_LOAD_ENGINE        ERROR_DEVICE_BASE - 20 //加载engine失败
#define ERROR_LOAD_FILE_STORE    ERROR_DEVICE_BASE - 21 //加载设备失败
#define ERROR_KEYPAIR_NOT_FOUND  ERROR_DEVICE_BASE - 22 //密钥不存在，需要重新发证
#define ERROR_NOT_VERIFY_PIN     ERROR_DEVICE_BASE - 23 //未调用验证PIN的接口
#define ERROR_SKS_SERVER_ERROR   ERROR_DEVICE_BASE - 24 //协同服务器处理失败
#define ERROR_APP_NEED_RESET     ERROR_DEVICE_BASE - 25 //设备特征码改变导致应用不可用需要重置
#define ERROR_USER_NOT_LOGIN     ERROR_DEVICE_BASE - 26 //用户没有认证
#define ERROR_USER_BIND_THREAD   ERROR_DEVICE_BASE - 27 //用户容器绑定线程失败
#define ERROR_LOAD_SO_FAILED     ERROR_DEVICE_BASE - 28 //加载动态库失败
#define ERROR_SKS_SERVER_CONNECT ERROR_DEVICE_BASE - 29 //协同服务连接失败
#define ERROR_SKS_SERVER_SSLERR  ERROR_DEVICE_BASE - 30 //协同服务握手失败
#define ERROR_PIN_LEN            ERROR_DEVICE_BASE - 31 //pin码长度小于6不满足安全要求

#define ERROR_GEN_RSA_KEYPAIR        ERROR_CERT_BASE - 0  //生成RSA秘钥对失败
#define ERROR_GEN_SM2_KEYPAIR        ERROR_CERT_BASE - 1  //生成SM2秘钥对失败
#define ERROR_GEN_REQ                ERROR_CERT_BASE - 2  //生成证书请求失败
#define ERROR_IMPORT_CERT            ERROR_CERT_BASE - 3  //导入证书失败
#define ERROR_EXPORT_CERT            ERROR_CERT_BASE - 4  //导出证书失败
#define ERROR_REVOKE_CERT            ERROR_CERT_BASE - 5  //废除证书失败
#define ERROR_SIGN_DATA              ERROR_CERT_BASE - 6  //签名失败
#define ERROR_VERIFY_DATA            ERROR_CERT_BASE - 7  //验证签名失败
#define ERROR_SIGN_P7_DATA           ERROR_CERT_BASE - 8  //生成p7签名失败
#define ERROR_VERIFY_P7_DATA         ERROR_CERT_BASE - 9  //验证p7签名失败
#define ERROR_ENC_MESSAGE_DATA       ERROR_CERT_BASE - 10 //加密数字信封失败
#define ERROR_DEC_MESSAGE_DATA       ERROR_CERT_BASE - 11 //解密数字信封失败
#define ERROR_CERT_KEYPAIR_NOT_MATCH ERROR_CERT_BASE - 12 //证书公钥与Key中秘钥对不匹配
#define ERROR_LOAD_PRIKEY            ERROR_CERT_BASE - 13 //加载私钥失败
#define ERROR_LOAD_PUBKEY            ERROR_CERT_BASE - 14 //加载公钥失败
#define ERROR_EXPORT_PUBKEY          ERROR_CERT_BASE - 15 //导出公钥失败
#define ERROR_USER_PRIKEY_ERROR      ERROR_CERT_BASE - 16 //使用私钥操作失败
#define ERROR_CERT_EXIST             ERROR_CERT_BASE - 17 //证书已存在
#define ERROR_IMPORT_KEYPAIR         ERROR_CERT_BASE - 18 //导入密钥失败
#define ERROR_CERTMGR_CMD            ERROR_CERT_BASE - 19 //错误的证书指令
#define ERROR_CERT_UNFIND            ERROR_CERT_BASE - 20 //证书不存在
#define ERROR_CERT_INVALID           ERROR_CERT_BASE - 21 //证书无效
#define ERROR_CERT_EXPIRED           ERROR_CERT_BASE - 22 //证书过期
#define ERROR_UNKNOWN_CA             ERROR_CERT_BASE - 23 //未知的CA
#define ERROR_SESSION_KEY            ERROR_CERT_BASE - 24 //错误的会话密钥
#define ERROR_ENCORDEC_FAILED        ERROR_CERT_BASE - 25 //加解密失败

#define ERROR_PARAM                     ERROR_LOCAL_FUNC_BASE - 0  //参数错误
#define ERROR_TERMINAL_PARAM            ERROR_LOCAL_FUNC_BASE - 1  //错误的终端ID
#define ERROR_URL_PARAM                 ERROR_LOCAL_FUNC_BASE - 2  // url参数错误
#define ERROR_SAFE_PARAM                ERROR_LOCAL_FUNC_BASE - 3  //安全参数错误
#define ERROR_CERT_CTX_PARAM            ERROR_LOCAL_FUNC_BASE - 4  //证书上下文错误
#define ERROR_DIGEST_CTX_PARAM          ERROR_LOCAL_FUNC_BASE - 5  //摘要上下文错误
#define ERROR_CIPHER_CTX_PARAM          ERROR_LOCAL_FUNC_BASE - 6  //加密上下文错误
#define ERROR_CERT_TYPE_PARAM           ERROR_LOCAL_FUNC_BASE - 7  //错误的证书类型
#define ERROR_CIPHER_TYPE_PARAM         ERROR_LOCAL_FUNC_BASE - 8  //加密算法错误
#define ERROR_DIGEST_TYPE_PARAM         ERROR_LOCAL_FUNC_BASE - 9  //摘要算法错误
#define ERROR_SSL_VERSION_PARAM         ERROR_LOCAL_FUNC_BASE - 10 // SSL协议无效
#define ERROR_SSL_CIPHER_PARAM          ERROR_LOCAL_FUNC_BASE - 11 //错误的SSL cipher
#define ERROR_SSL_SERVER_ADDR_PARAM     ERROR_LOCAL_FUNC_BASE - 12 //连接SSL地址参数错误
#define ERROR_SSL_SERVER_PORT_PARAM     ERROR_LOCAL_FUNC_BASE - 13 //连接SSL端口参数错误
#define ERROR_SSL_RECV_PARAM            ERROR_LOCAL_FUNC_BASE - 14 //接受SSL服务端数据错误
#define ERROR_SSL_SEND_PARAM            ERROR_LOCAL_FUNC_BASE - 15 //发送SSL服务端数据错误
#define ERROR_GENERRATE_TID             ERROR_LOCAL_FUNC_BASE - 16 //生成终端ID失败
#define ERROR_GENERRATE_MID             ERROR_LOCAL_FUNC_BASE - 17 //生成介质ID失败
#define ERROR_GENERRATE_CID             ERROR_LOCAL_FUNC_BASE - 18 //生成证书ID失败
#define ERROR_TERMINAL_TYPE             ERROR_LOCAL_FUNC_BASE - 19 //终端类型错误
#define ERROR_TERMINAL_OS               ERROR_LOCAL_FUNC_BASE - 20 //终端操作系统错误
#define ERROR_DEVICE_TYPE               ERROR_LOCAL_FUNC_BASE - 21 //设备类型错误
#define ERROR_DEVICE_SERIAL_NUM         ERROR_LOCAL_FUNC_BASE - 22 //设备序列号错误
#define ERROR_DEVICE_MANUFACTURER       ERROR_LOCAL_FUNC_BASE - 23 //设备厂商错误
#define ERROR_DEVICE_MODEL              ERROR_LOCAL_FUNC_BASE - 24 //设备型号错误
#define ERROR_DEVICE_CSP_NAME           ERROR_LOCAL_FUNC_BASE - 25 //设备名称错误
#define ERROR_REQ_FUNC_ID               ERROR_LOCAL_FUNC_BASE - 26 //发送请求时的函数ID错误
#define ERROR_REQ_GETURL_BY_FUNC_ID     ERROR_LOCAL_FUNC_BASE - 27 //发送请求时的根据函数ID获取URL错误
#define ERROR_REQ_GET_PARAM_BY_FUNC_ID  ERROR_LOCAL_FUNC_BASE - 28 //发送请求时的根据函数ID获取请求参数错误
#define ERROR_INIT_CURL_HERLPER         ERROR_LOCAL_FUNC_BASE - 29 //初始化CURL helper对象失败
#define ERROR_REQ_PROTOCOL_RETURN       ERROR_LOCAL_FUNC_BASE - 30 //请求服务端发生错误
#define ERROR_REQ_SERVER_RETURN         ERROR_LOCAL_FUNC_BASE - 31 //服务端返回了错误信息
#define ERROR_ENCODE_BASE64             ERROR_LOCAL_FUNC_BASE - 32 //做Base64加密时错误
#define ERROR_DECODE_BASE64             ERROR_LOCAL_FUNC_BASE - 33 //做Base64解密时错误
#define ERROR_PARSE_JSON                ERROR_LOCAL_FUNC_BASE - 34 //服务端响应数据不正确
#define ERROR_PARSE_JSON_RETURN_BODY    ERROR_LOCAL_FUNC_BASE - 35 //解析JSON数据错误，没有biz_body字段
#define ERROR_PARSE_JSON_RETURN_CERT_ST ERROR_LOCAL_FUNC_BASE - 36 //解析JSON数据错误，没有cert_status字段
#define ERROR_PARSE_JSON_RETURN_SOPIN   ERROR_LOCAL_FUNC_BASE - 37 //解析JSON数据错误，没有管理员PIN字段
#define ERROR_PARAM_CERT_PUBKEY         ERROR_LOCAL_FUNC_BASE - 38 //传入的证书公钥错误
#define ERROR_PARAM_CERT_SN_OR_EMAIL    ERROR_LOCAL_FUNC_BASE - 39 //传入的证书CN或Email项错误
#define ERROR_PARAM_CID                 ERROR_LOCAL_FUNC_BASE - 40 //证书ID错误失败
#define ERROR_PARAM_MID                 ERROR_LOCAL_FUNC_BASE - 41 //介质ID错误失败
#define ERROR_PARAM_TID                 ERROR_LOCAL_FUNC_BASE - 42 //终端ID错误失败
#define ERROR_ERROR_GEN_WID             ERROR_LOCAL_FUNC_BASE - 43 //产生业务UUID错误
#define ERROR_RSP_ERR_NO_ERRBODY        ERROR_LOCAL_FUNC_BASE - 44 //返回了错误的请求头，但是没有错误body
#define ERROR_PARAM_CERTTYPE            ERROR_LOCAL_FUNC_BASE - 45 //证书类型参数错误
#define ERROR_PARAM_SIGN_DATA           ERROR_LOCAL_FUNC_BASE - 46 //传入的签名数据错误
#define ERROR_PARAM_APPNAME             ERROR_LOCAL_FUNC_BASE - 47 //传入的应用名错误
#define ERROR_INVALID_P7_DATA           ERROR_LOCAL_FUNC_BASE - 48 //传入的签名数据不正确
#define ERROR_CERT_DATA                 ERROR_LOCAL_FUNC_BASE - 49 //传入的证书不格式不正确
#define ERROR_CERT_ITEM                 ERROR_LOCAL_FUNC_BASE - 50 //传入的证书项不支持
#define ERROR_BUF_INSUFFICIENT          ERROR_LOCAL_FUNC_BASE - 51 //传入的数据缓存区长度不够
#define ERROR_INVALID_KEY_TYPE          ERROR_LOCAL_FUNC_BASE - 52 //证书的密钥类型不正确
#define ERROR_SMF_UNINIT                ERROR_LOCAL_FUNC_BASE - 53 //没有初始化
#define ERROR_PARAM_NULL                ERROR_LOCAL_FUNC_BASE - 54 //接口调用时传入的参数不正确
#define ERROR_SSL_CONNECT               ERROR_LOCAL_FUNC_BASE - 55 //ssl握手失败，检查连接的ssl服务是否正常
#define ERROR_SSL_SEND_FAIL             ERROR_LOCAL_FUNC_BASE - 56 //发送数据失败，检查连接的ssl服务是否正常
#define ERROR_SSL_CTX_ERR               ERROR_LOCAL_FUNC_BASE - 57 //传入的sslctx上下文不正确
#define ERROR_SSL_RECV_FAIL             ERROR_LOCAL_FUNC_BASE - 58 //接收数据失败，检查后台服务是否正常
#define ERROR_SSL_SET_SOCKET            ERROR_LOCAL_FUNC_BASE - 59 //设置socket失败
#define ERROR_SSL_GET_SOCKET            ERROR_LOCAL_FUNC_BASE - 60 //获取socket 失败
#define ERROR_PARAM_AUTH_INFO           ERROR_LOCAL_FUNC_BASE - 61 //错误的认证输入信息
#define ERROR_PARAM_AUTH_TYPE           ERROR_LOCAL_FUNC_BASE - 62 //不支持的认证类型
#define ERROR_SSL_SET_CILENT_CERT       ERROR_LOCAL_FUNC_BASE - 63 //设置SSL客户端证书失败
#define ERROR_SSL_DISCONNECTED          ERROR_LOCAL_FUNC_BASE - 64 //连接已断开
#define SMF_SKS_ASYNC_SHOULD_RETRY      ERROR_LOCAL_FUNC_BASE - 65 //异步接口协同服务流程数据需要重试
#define SMF_SKS_SET_IO                  ERROR_LOCAL_FUNC_BASE - 66 //SKS设置外部io 失败
#define SMF_SKS_CONNECT_DISCONNECTED    ERROR_LOCAL_FUNC_BASE - 67 //异步协同服务断开连接
#define SMF_SSL_ASYNC_SHOULD_RETRY      ERROR_LOCAL_FUNC_BASE - 68 //异步接口非协同服务流程数据需要重试
#define SMF_ERROR_PARSE_HTTP            ERROR_LOCAL_FUNC_BASE - 69 //解析http失败
//异步证书管理接口由于其他线程正在操作需要等待重试，调用者需要外部sleep等待
#define SMF_MGR_ASYNC_SHOULD_RETRY      ERROR_LOCAL_FUNC_BASE - 71
// ssl握手超时，可能传入的地址不是一个正常的服务器或者服务器数据没有返回
#define SMF_ERROR_SSL_CONNECT_TIMEOUT     ERROR_LOCAL_FUNC_BASE - 72 // ssl握手超时
#define ERROR_FILE_OPEN_FAILED            ERROR_LOCAL_FUNC_BASE - 73 //文件打开失败
#define SMF_SERVER_CONNECT_ERROR          ERROR_LOCAL_FUNC_BASE - 74 //服务端网络不通
#define SMF_SERVER_SITECERT_VERIFY_FAILED ERROR_LOCAL_FUNC_BASE - 75 //服务端站点证书验证失败
#define SMF_SERVER_SSL_ERROR              ERROR_LOCAL_FUNC_BASE - 76 // cds握手失败
#define SMF_SERVER_RESPONSE_TIMEOUT       ERROR_LOCAL_FUNC_BASE - 77 //服务响应超时
#define SMF_SERVER_RESPONSE_ERROR         ERROR_LOCAL_FUNC_BASE - 78 //服务响应错误，50x
#define SMF_SERVER_PATH_NOT_EXIST         ERROR_LOCAL_FUNC_BASE - 79 //网络路径不存在
#define SERVER_STATE_ERROR_TO_ISSUER      ERROR_LOCAL_FUNC_BASE - 80 //服务端证书状态不正确，无法执行签发证书
#define SERVER_STATE_ERROR_TO_POSTPONE    ERROR_LOCAL_FUNC_BASE - 81 //服务端证书状态不正确，无法执行延期
#define SERVER_STATE_ERROR_TO_REVOKE      ERROR_LOCAL_FUNC_BASE - 82 //服务端证书状态不正确，无法执行废除
#define SERVER_STATE_ERROR_TO_RENEW       ERROR_LOCAL_FUNC_BASE - 83 //服务端证书状态不正确，无法执行更新信息
#define SERVER_STATE_ERROR_TO_UNBLOCK     ERROR_LOCAL_FUNC_BASE - 84 //服务端证书状态不正确，无法执行申请解锁
#define SERVER_STATE_ERROR_TO_INSTALL     ERROR_LOCAL_FUNC_BASE - 85 //服务端证书状态不正确，无法执行证书安装
#define ERROR_MALLOC_BUFF                 ERROR_LOCAL_FUNC_BASE - 86 //内存空间分配失败
#define ERROR_GET_SESSION_KEY             ERROR_LOCAL_FUNC_BASE - 87 //从服务端获取密钥因子失败
#define ERROR_PARAM_IV                    ERROR_LOCAL_FUNC_BASE - 88 //传入的iv错误
#define ERROR_GENRANDOM                   ERROR_LOCAL_FUNC_BASE - 89 //获取随机数失败

// 服务不可用
#define SMF_SERVER_UNAVAILABLE_ERROR ERROR_SERVER_BASE - 0 //服务异常不可用
#define SMF_STORE_UNUSABLE           ERROR_SERVER_BASE - 1 //存储不可用
#define SMF_SERVER_NODE_ERROR        ERROR_SERVER_BASE - 2 //服务节点不可用

// CDS-api返回的错误
#define SMF_USER_OR_PASS_ERROR        ERROR_CDS_API_BASE - 9   //用户认证失败
#define SMF_USER_AUTHCODE_ERROR       ERROR_CDS_API_BASE - 10  //用户验证码验证失败
#define SMF_SMS_SEND_FAILED           ERROR_CDS_API_BASE - 12  //短信发送失败
#define SMF_TOKEN_VERIFY_FAILED       ERROR_CDS_API_BASE - 15  // TOKEN验证失败,用户需要重新登录
#define SMF_USER_CERTTYPE_ERROR       ERROR_CDS_API_BASE - 16  //用户申请的证书类型不正确
#define SMF_PIC_CODE_EXPIRED          ERROR_CDS_API_BASE - 17  //图形验证码过期
#define SMF_CERT_STATUS_ERROR         ERROR_CDS_API_BASE - 100 //证书状态异常
#define SMF_CDSSERVER_LICENSE_INVALID ERROR_CDS_INNER_BASE - 2 // CDS服务授权文件失效，需要重新申请
#define SMF_CDSSERVER_DBOP_ERROR      ERROR_CDS_INNER_BASE - 4 // CDS服务端数据库操作失败
// cds-s未知异常
#define SMF_CDS_S_UNKNOWN_ERROR ERROR_CDS_INNER_BASE - 1
//未在系统中找到此用户，可能未注册，此时的如果调用的是初始化接口返回的上下文状态不完全
#define SMF_USER_UNFIND ERROR_CDS_INNER_BASE - 63
//服务不可用(CA/CDS/KMS,license超期),切换站点
#define SMF_SERVICE_DISABLED ERROR_CDS_INNER_BASE - 66
// CA服务达到能力阈值
#define SMF_SERVICE_THRESHOLD ERROR_CDS_INNER_BASE - 67
// CA服务出错
#define SMF_CA_SERVICE_ERROR ERROR_CDS_INNER_BASE - 68
// 当前用户证书数量达到限制，不可发证
#define SMF_USER_CERT_MAXIMUM ERROR_CDS_PKI_BASE - 54
// CDSM管理端处理失败，可能是用户不存在，具体看CDS服务器api日志
#define SMF_CDSM_SERVER_OP_ERROR ERROR_CDS_M_BASE - 8
// 管理端没有找到对应的数据记录
#define SMF_CDSM_SERVER_UNFIND_DATA ERROR_CDS_M_BASE - 26
#define SMF_USER_TERM_LOCKED		ERROR_CDS_API_BASE - 253  //终端设备由于用户登录次数过多导致锁定
#define SMF_USER_LOCKED		        ERROR_CDS_API_BASE - 252  //用户登录错误次数过多导致锁定

#endif //__SMF_ERROR_H__
