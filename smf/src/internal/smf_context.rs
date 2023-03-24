pub struct SmfContext{
    pub ctx: *mut ffi::SMF_CONTEXT,
}

impl SmfContext {
    pub fn new() -> SmfContext{
        SmfContext{
            ctx: std::ptr::null_mut(),
        }
    }
}