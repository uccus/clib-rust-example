use std::ffi::c_int;

pub const SMF_LOG_NONE: c_int = 0;
pub const SMF_LOG_FATAL: c_int = 1;    // 致命错误日志
pub const SMF_LOG_ERROR: c_int = 2;    // 错误日志
pub const SMF_LOG_WARNING: c_int = 3;  // 警告日志
pub const SMF_LOG_INFO: c_int = 4;     // 信息级别日志
pub const SMF_LOG_DEBUG: c_int = 5;    // 调试级别日志