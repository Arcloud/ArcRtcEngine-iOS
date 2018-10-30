//
//  ArcCamera.h
//  ArcCamera
//
//  Created by li fu on 2017/6/16.
//  Copyright © 2017年 li fu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ArcCameraType.h"

@class ArcCamera;
@protocol ArcCameraDelegate <NSObject>

@optional
- (void) camera:(ArcCamera *) camera DidRecVideoData:(CMSampleBufferRef) samplebuffer;

@end

@interface ArcCamera : NSObject

@property (nonatomic, assign) id<ArcCameraDelegate>  delegate;

/**
 *  创建ArcCamera对象
 *
 *  @return 返回ArcCamera句柄
 */
- (instancetype) init;

/**
 *  打开摄像头
 *
 *  @param paramDic 包含摄像头的基本信息
    必选    {FrameRate：帧率，
            sessionPreset：预览分辨率，
            accessKey：鉴权的accesskey，
            accessSecret：鉴权的accessSecret，
            appKey：根据不同bundleid生成的appKey
            }
    可选    {CameraPosition：前后置摄像头，默认前置}
*  @param callback 授权返回结果，根据authorize来判断
 *
 *  @return return 打开摄像头结果
 */
- (int) openCamera:(NSDictionary *) paramDic callbackBlock:(callbackBlock) callback;

/**
 *  释放ArcCamera对象
 *
 */
- (void) closeCamera;

/**
 *  切换摄像头前后置
 *
 *  @param position 摄像头前后置，默认前置
 *
 *  @return return 切换摄像头前后置结果
 */
- (BOOL) setCameraState:(CameraPosition) position;

/**
 *  打开或关闭后置灯
 *
 *  @param state 后置灯的状态值，true：打开，false：关闭
 *
 *  @return return 设置后置灯状态结果
 */
- (BOOL) setTorchState:(BOOL) state;

/**
 *  根据传入的前后置枚举和分辨率，来判断设备是否支持
 *
 *  @param preset 预览分辨率
 *  @param position 前后置枚举值
 *
 *  @return return 判断结果
 */
- (BOOL) checkSupportPreset:(NSString *) preset position:(CameraPosition) position;

/**
 *  获取当前设备支持的帧率范围(min - max)
 *
 *  @param minNum 摄像头支持的最小帧率
 *  @param maxNum 摄像头支持的最大帧率
 *
 *  @return return 获取结果(支持true，不支持false)
 */
- (BOOL) getFrameRate:(double *) minNum maxNum:(double *) maxNum;

/**
 *  根据传入的分辨率宽高，获取参考码率
 *
 *  @param width 选择的预览分辨率宽
 *  @param height 选择的预览分辨率高
 *
 *  @return return 返回参考码率集合
 */
- (NSArray *) getReferenceBitratesWithWidth:(double) width height:(double) height;

/**
 *  根据摄像头的前后置来获取支持的预览分辨率集合
 *
 *  @param position 前后置枚举值
 *
 *  @return return 返回预览分辨率集合
 */
- (NSArray *) getSupportPresetsWithPosition:(CameraPosition) position;

/**
 *  手动点击预览界面，对焦某一个点(手动和自动对焦只允许一个生效)
 *
 *  @param point 点击预览界面的点(point)
 *  @param view 预览界面
 *
 */
- (void) handFocusAtPoint:(CGPoint) point prewView:(UIView *) view;

/**
 *  启用自动对焦(手动和自动对焦只允许一个生效)
 *
 */
- (void) autoFocus;

/**
 *  放大或者缩小预览的画面
 *
 *  @param scale 手势放大和缩小的系数
 *
 */
- (void) pichZoomWithScale:(CGFloat) scale;

/**
 *  当需要横竖显示时候请不要调用，默认跟随状态栏方向而变动
 *  注意：推流或连麦过程中需要禁止跟随旋转，请调用该接口
 *
 */
- (void) lockOrientation;

/**
 *  调用lockOrientation之后，解锁方向。
 *  注意：推流或连麦停止后，需要调用该接口恢复跟随状态栏方向而变化
 *
 */
- (void) unlockOrientation;

@end
