use super::*;
use libc::*;

extern "C" {
    pub fn SMF_ConfigInit(config: *mut Config_t) -> i32;
    pub fn SMF_Initialize(uid: *const c_char, url: *const c_char, pctx: *mut *mut SMF_CONTEXT) -> i32;
}