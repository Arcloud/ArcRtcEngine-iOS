//
//  ArcFiltersController.h
//  ARCPlayer
//
//  Created by li fu on 2017/7/5.
//  Copyright © 2017年 fu.li. All rights reserved.
//

/*
 *  处理视频帧效果类，可以对视频帧进行滤镜，美颜，大眼瘦脸等功能
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// filter
#define ARC_GPUIMG_FILTER_BRIGHTNESS        0x101
#define ARC_GPUIMG_FILTER_SATURATION        0x102
#define ARC_GPUIMG_FILTER_FACEDEFORMATION   0x103
#define ARC_GPUIMG_FILTER_CONTRAST          0x104
#define ARC_GPUIMG_FILTER_REDEFFECT         0x105
#define ARC_GPUIMG_FILTER_COLORLEVELS       0x106
#define ARC_GPUIMG_FILTER_COLORWHITEBALANCE 0x107
#define ARC_GPUIMG_FILTER_EXPOSURE          0x108
#define ARC_GPUIMG_FILTER_SHARPEN           0x109

@interface ArcFiltersController : NSObject

@property (nonatomic, assign) void*     _render;

/**
 *  创建ArcFiltersController对象
 *
 *  @param apresetSize 推流分辨率
 *  @return 返回ArcFiltersController句柄
 */
- (instancetype) initWithPresetSize:(CGSize) apresetSize;

/**
 *  启用或关闭滤镜(统一打开或关闭滤镜的开关)
 *
 *  @param state 开关的状态
 *
 */
- (void) enableFilter:(BOOL) state;

/**
 *  添加滤镜
 *
 *  @param filterType 滤镜类型
 *
 *  @return 0:成功，!0:失败
 */
- (int) addFilter:(int) filterType;

/**
 *  移除指定的滤镜
 *
 *  @param filterType 滤镜类型 (filter)
 *
 */
- (void) removeFilter:(int) filterType;

/**
 *  设置红润效果
 *
 *  @param value 红润效果参数 (0 - 100)
 *
 */
- (void) setRedEffectLevel:(int) value;

/**
 *  设置饱和度
 *
 *  @param value 饱和度参数 (0 - 100)
 *
 */
- (void) setSaturationLevel:(int) value;

/**
 *  设置对比度
 *
 *  @param value 对比度参数 (0 - 100)
 *
 */
- (void) setContrastLevel:(int) value;

/**
 *  设置曝光度
 *
 *  @param value 曝光度参数 (0 - 100)
 *
 */
- (void) setExposureLevel:(int) value;

/**
 *  设置亮度
 *
 *  @param value 亮度参数 (0 - 100)
 *
 */
- (void) setBrightnessLevel:(int) value;

/**
 *  设置色温
 *
 *  @param value 色温参数 (0 - 100)
 *
 */
- (void) setTemperatureLevel:(int) value;

/**
 *  设置色阶
 *
 *  @param value 色阶参数 (0 - 100)
 *
 */
- (void) setTintLevel:(int) value;

/**
 *  设置锐化度
 *
 *  @param value 锐化度参数 (0 - 100)
 *
 */
- (void) setSharpenLevel:(int) value;

/**
 *  设置颜色空间的红色分量
 *
 *  @param value 红色分量参数 (0 - 100)
 *
 */
- (void) setRedColorLevel:(int) value;

/**
 *  设置颜色空间的绿色分量
 *
 *  @param value 绿色分量参数 (0 - 100)
 *
 */
- (void) setGreenColorLevel:(int) value;

/**
 *  设置颜色空间的蓝色分量
 *
 *  @param value 蓝色分量参数 (0 - 100)
 *
 */
- (void) setBlueColorLevel:(int) value;

/**
 *  根据系数整体调整颜色空间(相对于单个分量设置，整体效果会根据系统自动调整)
 *
 *  @param value 颜色空间系数 (0 - 100)
 *
 */
- (void) setColorLevelAdjust:(int) value;

/**
 *  启用或关闭镜像
 *
 *  @param state 是否镜像的状态值
 *
 */
- (void) enableVideoMirrored:(BOOL) state;

/**
 *  设置大眼
 *
 *  @param value 大眼系数 (0 - 100)
 *
 *  @return 0:成功，!0:失败
 */
- (int) setEyeScale:(int) value;

/**
 *  设置瘦脸系数(0为默认，0以下为大脸，0以上为瘦脸)
 *
 *  @param value 瘦脸系数 (0 - 100)
 *
 *  @return 0:成功，!0:失败
 */
- (int) setFaceScale:(int) value;

/**
 *  设置贴纸资源路径,如需更换请设置新的资源路径并生效即可
 *
 *  @param path 贴纸资源路径
 */
- (void) set2DStickerResPath:(NSString *) path;

/**
 *  启用或关闭贴纸
 *
 *  @param state 启用或关闭状态值
 *  @param rotation 贴纸是否旋转，影响图像和贴纸的相对位置（0，90，180，270），默认：0
 *  @param mirror 贴纸是否镜像，默认：false
 *
 *  @return 0:成功，!0:失败
 */
- (int) enableSticker:(BOOL) state rotation:(int) rotation mirror:(BOOL) mirror;

/**
 *  启用或关闭美颜功能
 *
 *  @param state 美颜状态值
 *
 *  @return 0:成功，!0:失败
 */
- (int) setBeautyState:(BOOL) state;

/**
 *  设置美颜的磨皮
 *
 *  @param value 磨皮参数(0 - 100)
 *
 */
- (void) setFaceSkinSoftenLevel:(unsigned int) value;

/**
 *  设置美颜的亮度
 *
 *  @param value 亮度参数(0 - 100)
 *
 */
- (void) setFaceBrightLevel:(unsigned int) value;

/**
 *  在预览上添加水印图片
 *
 *  @param image 水印图片
 *  @param rect 水印相对于预览的位置，是1比1的关系，如rect(100, 100, 200, 200)，对于预览分辨率720x1280来说，相对左上顶点右偏移100，向下偏移100，宽x高：200x200，注意：不是相对于屏幕的宽高
 *
 */
- (void) addWatermarkWithImage:(UIImage *) image info:(CGRect) rect;

@end
