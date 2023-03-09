use super::*;
use libc::*;

extern "C" {
    pub fn SMF_ConfigInit(config: *mut Config) -> c_int;
    pub fn SMF_Initialize(uid: *const c_char, url: *const c_char, pctx: *mut *mut SMF_CONTEXT) -> c_int;
}