use std::ptr::null_mut;
use std::ffi::*;

#[repr(C)]
pub struct SMF_CONTEXT{
    pub _inner_ctx: *mut c_void,
}

impl SMF_CONTEXT {
    pub fn init() -> SMF_CONTEXT{
        SMF_CONTEXT{
            _inner_ctx: null_mut(),
        }
    }
}

#[repr(C)]
pub struct SMF_CIPHER_CTX{
    pub _inner_ctx: *mut c_void,
    pub _cipher_ctx: *mut c_void,
}

impl SMF_CIPHER_CTX {
    pub fn init() -> SMF_CIPHER_CTX {
        SMF_CIPHER_CTX {
            _inner_ctx: null_mut(),
            _cipher_ctx: null_mut(),
        }
    }
}
