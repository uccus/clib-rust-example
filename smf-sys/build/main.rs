#![allow(unused_variables)]
use std::env;

fn main(){
    // 参考 https://doc.rust-lang.org/cargo/reference/build-scripts.html
    let target_os = env::var("CARGO_CFG_TARGET_OS").unwrap();
    let target_abi = env::var("CARGO_CFG_TARGET_ARCH").unwrap();

    let lib_dir = format!("smf-sdk/lib/{}/{}", target_os, target_abi);

    println!("cargo:rustc-link-search=native={}", lib_dir);
    println!("cargo:rustc-link-lib={}={}", "dylib", "smf_api");

    if target_abi == "x86" {
        // 条件编译
        println!("cargo:rustc-cfg=cfg_test");
    }
}