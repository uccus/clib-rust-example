#ifndef _SMF_HTTP_TYPE_H_
#define _SMF_HTTP_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum http_request_method_e
{
    M_GET = 0,
    M_POST,
    M_HEAD
} http_request_method_e;

typedef struct SMF_HTTP_CTX_st {
    void* _inner_ctx;
} SMF_HTTP_CTX;

typedef int (*data_recv_cb)(const char* data, int data_size);

#ifdef __cplusplus
}
#endif

#endif // _SMF_HTTP_TYPE_H_
