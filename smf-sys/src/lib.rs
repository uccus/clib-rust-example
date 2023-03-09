#![allow(dead_code, non_snake_case, unused_imports, unused_must_use)]

mod libs;
pub use libs::*;

// 条件编译
// #[cfg(not(cfg_test))]
pub fn add(a:i32, b: i32) -> i32{
    a + b
}
