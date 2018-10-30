#
#  Be sure to run `pod spec lint ArcRtcEngine.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

# 名称 使用的时候pod search [name]
s.name = "ArcRtcEngine"
# 代码库的版本
s.version = "1.0.0"
# 简介
s.summary = "一个快捷支持音视频通讯的SDK"
# 主页
s.homepage = "https://github.com/Arcloud"
# 许可证书类型，要和仓库的LICENSE 的类型一致
s.license = "MIT"
# 作者名称 和 邮箱
s.author = { "fuli" => "lf3136@arcvideo.com" }
# 作者主页
s.social_media_url =""
# 代码库最低支持的版本
s.platform = :ios, "8.0"
# 代码的Clone 地址 和 tag 版本
s.source = { :git => "https://github.com/Arcloud/ArcRtcEngine-iOS.git", :tag => "1.0.0" }
# 如果使用pod 需要导入哪些资源
s.source_files = "ArcRtcEngine/**/*.{h,m}"

# 框架是否使用的ARC
s.requires_arc = true

# 依赖的framework
s.frameworks = 'CoreLocation', 'AVFoundation', 'VideoToolbox', 'SystemConfiguration', 'CoreTelephony'

# 依赖的lib
s.libraries = 'resolv', 'c++'

# 依赖的非系统lib
s.vendored_libraries = 'ArcRtcEngine/Libraries/libARCRtcEngine.a', 'ArcRtcEngine/Libraries/libArcVideoTool.a', 'ArcRtcEngine/Libraries/libArcCamera.a'
end
