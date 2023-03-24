use wasm_bindgen::prelude::*;
use smf::*;

#[wasm_bindgen]
extern {
    pub fn alert(s: &str);
}

#[wasm_bindgen]
pub fn greet(name: &str) {
    let mut helper = SmfHelper::new();
    helper.initUser().unwrap();
    alert(&format!("Hello, {}!", name));
}
