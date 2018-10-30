//
//  ArcCameraType.h
//  CameraRecoder
//
//  Created by li fu on 2017/7/19.
//  Copyright © 2017年 li fu. All rights reserved.
//

#ifndef ArcCameraType_h
#define ArcCameraType_h

#import <CoreMedia/CoreMedia.h>

// camera
typedef enum
{
    CameraPosition_front = 0,
    CameraPosition_back
}CameraPosition;

typedef enum
{
    CameraDisplay_fillIn = 0,
    CameraDisplay_fillOut,
    CameraDisplay_stretch
}CameraDisplayModel;

typedef enum
{
    ACCESS_ANCHOR = 0,          // 主播
    ACCESS_AUDIENCE             // 观众
}ACCESSTYPE;

typedef void (^callbackBlock)(bool authorize);

// open camera error
#define CAMERA_INIT_SUCCESS             0       // 初始化成功
#define CAMERA_INIT_FAILED              -1      // 初始化失败
#define CAMERA_NOT_SUPPORT_RESOLUTION   -2      // 不支持此分辨率
#define CAMERARECORD_SDK_EXPIRED        -100    // sdk过期

#define MEDIA_ERR_INVALID_PARAM                 0x0002

typedef void  (* PFNVIDEODATACALLBACK)(CMSampleBufferRef samplebuffer, void *pObj);

#endif /* ArcCameraType_h */
