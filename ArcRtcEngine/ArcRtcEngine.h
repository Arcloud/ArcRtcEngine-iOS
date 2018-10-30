//
//  ArcRtcEngine.h
//  ARCPlayer
//
//  Created by Zhiming He on 2018/4/11.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <UIKit/UIKit.h>

//分辨率模式
typedef enum
{
    ArcVideoProfile_Portrait_360P = 1,
    ArcVideoProfile_Portrait_450P,
    ArcVideoProfile_Portrait_480P,
    ArcVideoProfile_Portrait_720P,
    ArcVideoProfile_Portrait_1080P,
    
    ArcVideoProfile_Landscape_360P = 20,
    ArcVideoProfile_Landscape_450P,
    ArcVideoProfile_Landscape_480P,
    ArcVideoProfile_Landscape_720P,
    ArcVideoProfile_Landscape_1080P
}ArcVideoProfile;

//音频模式
typedef enum
{
    ArcAudioProfile_Profile1 = 0,           // 16KHz采样率，16kbps,单声道，Opus编码
    ArcAudioProfile_Profile2,            // 16KHz采样率，码率 64Kbps, 单声道，AAC编码
    ArcAudioProfile_Profile3,            // 48KHz采样率, 码率 32Kbps, 双声道， Opus编码
    ArcAudioProfile_Default = ArcAudioProfile_Profile1
}ArcAudioProfile;

//视频类型
typedef enum {
    VideoType_H264
}ArcVideoType;

//显示模式
typedef NS_ENUM(NSInteger, ArcRtcDisplayModel)
{
    ArcRtc_Display_FillIn = 0,
    ArcRtc_Display_FillOut,
    ArcRtc_Display_Stretch
};

// Error info (need to real)
#define Arc_Error_rtcEngine_base                            0x8000
#define Arc_Error_rtcEngine_connect_base                    0x8000 + 100
#define Arc_Error_rtcEngine_streaming_base                  0x8000 + 200
typedef NS_ENUM(NSInteger, ArcRtcErrorType)
{
    ArcRtc_Error_None = 0,
    ArcRtc_Error_Unknown = Arc_Error_rtcEngine_base + 1,
    ArcRtc_Error_RtcInitialized = Arc_Error_rtcEngine_base + 2,
    ArcRtc_Error_InvalidArgument = Arc_Error_rtcEngine_base + 3,
    ArcRtc_Error_NoPermission = Arc_Error_rtcEngine_base + 4,
    ArcRtc_Error_NotReady = Arc_Error_rtcEngine_base + 5,
    ArcRtc_Error_VideoEncode_NotSupported = Arc_Error_rtcEngine_base + 8,
    ArcRtc_Error_AudioEncode_NotSupported = Arc_Error_rtcEngine_base + 9,
    ArcRtc_Error_Refused = Arc_Error_rtcEngine_base + 10,
    ArcRtc_Error_MicNoAuthorized = Arc_Error_rtcEngine_base + 12,
    ArcRtc_Error_RenderFailed = Arc_Error_rtcEngine_base + 13,
    ArcRtc_Error_VideoDecode_Initialized = Arc_Error_rtcEngine_base + 14,
    ArcRtc_Error_AudioDecode_Initialized = Arc_Error_rtcEngine_base + 15,
    ArcRtc_Error_AudioDecode_Failed = Arc_Error_rtcEngine_base + 16,
    ArcRtc_Error_VideoDecode_Failed = Arc_Error_rtcEngine_base + 17,
    
    ArcRtc_Error_ConnectTimeout = Arc_Error_rtcEngine_connect_base + 1,
    ArcRtc_Error_ConnectFailed = Arc_Error_rtcEngine_connect_base + 2,
    ArcRtc_Error_ConnectRelogin = Arc_Error_rtcEngine_connect_base + 3,
    
    ArcRtc_Error_StreamingTimeout = Arc_Error_rtcEngine_streaming_base + 1,
    ArcRtc_Error_StreamingFailed = Arc_Error_rtcEngine_streaming_base + 2,
    ArcRtc_Error_Streaming_Initialized = Arc_Error_rtcEngine_streaming_base + 3
};

//收发模式
typedef NS_ENUM(NSInteger, ArcRtcPayloadMode)
{
    ArcRtc_Mode_None = 0,
    ArcRtc_Mode_SendOnly,         //只发
    ArcRtc_Mode_RecvOnly,          //只收
    ArcRtc_Mode_SendRecv    //收发
};

typedef NS_ENUM(NSInteger, ArcRtcWarningType)
{
    ArcRtcWarning_None,
    ArcRtcWarning_Reconnecting, //重连中
    ArcRtcWarning_Black_On,     //黑帧
    ArcRtcWarning_Black_Off,
    ArcRtcWarning_VideoDecode_NotSupported,
    ArcRtcWarning_AudioDecode_NotSupported
};

//会话类型
typedef enum
{
    ArcRtc_Session_Create,           // 创建并且加入会话返回通知
    ArcRtc_Session_Join,             // 加入会话返回通知
    ArcRtc_Session_RecJoin,          // 收到成员加入会话返回通知
    ArcRtc_Session_RecLeft,          // 会话中有成员离开
    ArcRtc_Session_RecMessage          // 收到自定义消息
    
}ArcRtc_Session_Type;

@class ArcRtcEngine;
@protocol ArcRtcEngineDelegate <NSObject>

/**
 会话回调
 
 @param engine Engine对象
 @param type 会话回调的类型
 @param code 回调码 0代表成功
 @param infoDic 附带信息
 */
- (void)rtcEngine:(ArcRtcEngine *)engine didRecType:(ArcRtc_Session_Type)type code:(int)code info:(NSDictionary *)infoDic;

/**
 收到首帧的回调
 
 @param engine Engine对象
 @param userId 用户的userId
 @param size 视频宽高信息
 */
- (void)rtcEngine:(ArcRtcEngine *)engine didRecUserId:(NSString *)userId videoSize:(CGSize)size;

/**
 收到错误码
 
 @param engine Engine对象
 @param code 错误码
 @param subCode 附属错误码
 @param errMsg 错误信息
 */
- (void)rtcEngine:(ArcRtcEngine *)engine didRecErrorCode:(ArcRtcErrorType)code subCode:(int)subCode msg:(NSString *)errMsg;

/**
 收到警告
 
 @param engine Engine对象
 @param type 错误码
 @param errMsg 附件信息
 */
- (void)rtcEngine:(ArcRtcEngine *)engine didRecWarning:(ArcRtcWarningType)type msg:(NSString *)errMsg;

/**
 didRecSelfVideoFrame

 @param engine Engine对象
 @param state Exist or Not
 @param rect frame信息
 */
- (void)rtcEngine:(ArcRtcEngine *)engine state:(BOOL)state didRecSelfVideoFrame:(CGRect)rect;

@end

@interface ArcRtcVideoCanvas : NSObject

@property (nonatomic, strong) UIView*               view;  //渲染父View
@property (nonatomic, assign) ArcRtcDisplayModel    renderMode; //渲染模式
@property (nonatomic, copy)   NSString*             uid;
@property (nonatomic, assign) int                   frameWidth;
@property (nonatomic, assign) int                   frameHeight;
@end



@interface ArcRtcEngine : NSObject

@property (nonatomic, copy) NSString * productID;        //产品ID，必填
@property (nonatomic, copy) NSString * userId;          //用户id,必填
@property (nonatomic, assign) NSUInteger customeId;     //customer id，必填
@property (nonatomic, copy) NSString * orgId;           //组织码，选填默认为0
@property (nonatomic, assign) NSUInteger memberMax;     //会话最大成员数，必填
@property (nonatomic, assign) BOOL encrypt;             //加密当前还未支持,选填


@property (nonatomic, weak) id <ArcRtcEngineDelegate> delegate;


/**
 创建Engine
 
 @param accesskey accesskey
 @param accessSecret accessSecret
 @param appKey appKey
 @return instance
 */
+ (instancetype)createEngineWithAccessKey:(NSString *)accesskey
                             accessSecret:(NSString *)accessSecret
                                   appKey:(NSString *)appKey;

/**
 创建会话
 */
- (void)createSession;

/**
 加入会话
 
 @param sessionId 会话ID
 */
- (void)joinSessionWithSessionId:(NSUInteger)sessionId;
/**
 离开会话
 */
- (void)leaveSession;
/**
 设置视频参数
 
 @param profile 参数枚举
 @param fps 帧率
 @param type 视频类型
 @param bit 码率
 */
- (void)setVideoInfo:(ArcVideoProfile)profile frameRate:(unsigned int)fps videoType:(ArcVideoType)type bitrate:(unsigned int)bit;
/**
 设置音频参数
 
 @param profile 音频枚举
 */
- (void)setAudioProfile:(ArcAudioProfile)profile;
/**
 设置视频帧率fps

 @param fps 帧率
 */
- (void)setVideoFps:(unsigned)fps;
/**
 *  推流过程中可以动态改变video的编码码率
 *
 *  @param value 码率 (单位B)，建议是min：宽*高/2、max：宽*高*2
 */
- (void) setVideoBitrate:(unsigned)value;
/**
 是否开启自己方声音传输
 
 @param state YES:开启 NO:关闭
 */
- (void)enableAudioMute:(BOOL)state;

/**
 是否开启不让对方开到自己画面
 
 @param state YES:开启 NO:关闭
 */
- (void)enableLocalVideoBlackFrame:(BOOL)state;

/**
 是否开启不看对方某个人的画面
 
 @param state YES:开启 NO:关闭
 @param uid 对方ID
 */
- (void)enableRemoteVideoBlackFrame:(BOOL)state uid:(NSString *)uid;

/**
 创建对方渲染画布、
 
 @param canva 对方渲染画布
 */
- (void)setupRemoteVideoCanvas:(ArcRtcVideoCanvas *)canva;

/**
 更新对方画布布局
 
 @param uid 对方ID
 */
- (void)updateRemoteVideoCanvasFrameWithUid:(NSString *)uid;

/**
 设置自己预览画布
 
 @param canva 预览画布
 */
- (void)setupLocalVideoCanva:(UIView *)canva;

/**
 更新自己预览画布布局
 */
- (void)updateLocalVideoCanvaFrame;

/**
 将Camera生成的SampleBuffer发送给Engine
 
 @param buf SampleBuffer
 */
- (void)sendFrameWithSampleBuffer:(CMSampleBufferRef)buf;

/**
 是否开启预览画面的镜像
 
 @param state YES:开启 NO:关闭
 */
- (void)enablePreviewMirror:(BOOL) state;
/**
 *  Enable or close the remote mute audio (caller will not hear the sound)
 *
 *  @param state      audio state
 *  @param uid        remote user uid
 *
 */
- (void)enableRemoteAudioMute:(BOOL)state uid:(NSString *)uid;

/**
 是否开启其他所有人静音
 
 @param state YES:开启 NO:关闭
 */
- (void)enableAllRemoteAudioMute:(BOOL)state;

//********************以下方法对外SDK不开放*******************************
/**
 set IM addr

 @param imAddr IM Addr
 */
- (void)setImAddr:(NSString *)imAddr;
/**
 set extInfo

 @param extInfo extInfo
 */
- (void)setExtInfo:(NSString *)extInfo;
/**
 set transportType

 @param transportType transportType
 */
- (void)setTransportType:(NSInteger)transportType;
/**
 set payloadMode

 @param payloadMode payloadMode
 */
- (void)setPayloadMode:(ArcRtcPayloadMode)payloadMode;
/**
 set role

 @param role role description
 */
- (void)setRole:(NSUInteger)role;
/**
 发送信息给某人
 
 @param uid 其他人ID
 @param infoStr 发送内容
 */
- (int)sendDataWithCid:(NSString *)uid info:(NSString *)infoStr;
/**
 获取会议信息
 
 @return 会议信息
 */
- (NSDictionary *)getSessionInfo;

+ (void)printLog:(NSString *)format, ...;

@end


