# ArcRtcEngine-iOS

## 安装方式
### 1. 修改podfile
  ~~~
    target 'Sample' do
	    pod 'ArcRtcEngine'
    end
  ~~~
### 2. 终端运行命令：pod install
  
## 集成步骤：
### 1. ArcCamera（可替换任意第三方源）
    ~~~
    1.1 初始化ArcCamera  
    #import <ArcRtcEngine/ArcCamera.h>  
      
    mCamera = [[ArcCamera alloc] init];  
    mCamera.delegate = self;  
  
    NSString *preset = @"AVCaptureSessionPreset1280x720";  
    __weak __typeof(self) weakSelf = self;  
    NSDictionary * paramDic = @{@"FrameRate": [NSString stringWithFormat:@"%ld",25], @"sessionPreset":preset, @"CameraPosition":@(0)};  
    [mCamera openCamera:paramDic callbackBlock:^(bool authorize) {  
      if(!authorize) {  
          NSLog(@"需要先授权!");  
          return;  
        }  
    }];  
    ~~~
    ~~~
    1.2 监听Camera数据返回，并且将视频数据传递给ArcRtcEngine（记得mEngine初始化在[camera openCamera]前） 
    #pragma mark - ArcCameraDelegate  
    - (void)camera:(ArcCamera *)camera DidRecVideoData:(CMSampleBufferRef)samplebuffer {  
      if(mEngine) {  
          // 将自己的video源传入视频通讯SDK，发给其他成员
          [mEngine sendFrameWithSampleBuffer:samplebuffer];  
      }  
    }  
    ~~~
    ~~~
      
    1.3 释放camera资源
    mCamera.delegate = nil;
    [mCamera closeCamera];
    ~~~
### 2. 初始化RtcEngine（视频通讯SDK）：音频来源内部自动获取
  ~~~
  
  ~~~
  
