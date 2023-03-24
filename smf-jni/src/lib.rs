use jni::JNIEnv;
use jni::objects::JClass;
use jni::sys::jstring;
use std::ffi::CString;
use smf::SmfHelper;

#[no_mangle]
pub unsafe extern fn Java_com_example_myktapp_MainActivity_greeting(env: JNIEnv, _: JClass) -> jstring {
    let mut helper = SmfHelper::new();
    helper.initUser().unwrap();
    let world_ptr = CString::new("Hello world from Rust world").unwrap();
    let output = env.new_string(world_ptr.to_str().unwrap()).expect("Couldn't create java string!");
    output.into_raw()
}