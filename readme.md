### Rust call c

这个项目是Rust调用c接口的示例，参考rust-openssl的目录结构，内部设计复杂类型如数组，指针，二级指针，字符串转换等，在此记录一下。

smf-sys项目是对c接口的定义，一般只做定义，不做封装。

smf项目中引入smf-sys为ffi，对接口进行封装，提供最终对外接口。

smf-jni是将smf接口封装给java调用。

针对错误码，还可以创建smf-error项目，单独对错误码进行处理。

文档结构也可以参考rust-openssl。

此外，编译目标指定，例：`cargo build --target i686-pc-windows-msvc`

| target                   |                    |
|:-----|:-----|
| i686-pc-windows-msvc     | :heavy_check_mark: |
| x86_64-pc-windows-msvc   | :heavy_check_mark: |
| i686-unknown-linux-gnu   | :heavy_check_mark: |
| x86_64-unknown-linux-gnu | :heavy_check_mark: |
| x86_64-linux-android | :heavy_check_mark: |

可以通过`rustup show`查看当前工具链安装的`target`

可以通过`rustup target list`查看支持的所有`target`

可以通过`rustup target add`添加`target`

### 编译android版本的jni

```bash
# 设置环境变量(windows中)
set ANDROID_NDK_HOME=E:/tools/android/android-ndk-r23c
set ANDROID_HOME=E:/tools/android/sdk
# 添加android的x86_64目标架构,其他架构类似
rustup target add x86_64-linux-android
# 安装cargo-ndk命令工具
cargo install cargo-ndk
# 编译
cargo ndk -t x86_64 build
```



