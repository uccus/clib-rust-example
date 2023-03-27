#![allow(unused_variables)]
use std::env;

fn main(){
    // 参考 https://doc.rust-lang.org/cargo/reference/build-scripts.html
    let target_os = env::var("CARGO_CFG_TARGET_OS").unwrap();
    let target_arch = env::var("CARGO_CFG_TARGET_ARCH").unwrap();
    
    let mut platform = target_os;
    
    if target_arch == "wasm32" {
        platform = "wasm".to_string();
    }

    let lib_dir = format!("smf-sdk/lib/{}/{}", platform, target_arch);

    println!("cargo:rustc-link-search=native={}", lib_dir);
    
    if target_arch == "wasm32" {
        println!("cargo:rustc-link-lib={}", "smf_api");
    }
    else {
        println!("cargo:rustc-link-lib={}={}", "dylib", "smf_api");
    }

    if platform == "x86" {
        // 条件编译
        println!("cargo:rustc-cfg=cfg_test");
    }
}