use libc::*;

#[repr(C)]
pub struct SMF_CONTEXT{
    pub _inner_ctx: *mut c_void,
}

#[repr(C)]
pub struct SMF_CIPHER_CTX{
    pub _inner_ctx: *mut c_void,
    pub _cipher_ctx: *mut c_void,
}
