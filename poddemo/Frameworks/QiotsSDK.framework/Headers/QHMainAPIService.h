//
//  QHCCamUploadService.h
//  QHCamSDK
//
//  Created by youzhenbei on 2017/9/13.
//  Copyright © 2017年 qihoo. All rights reserved.
//

#import <Foundation/Foundation.h>



typedef void(^filePullCallBack) (NSInteger errorCode,NSString *errorMsg,NSString *url);
typedef void(^fileDownloadFileCallBack) (NSInteger errorCode,NSString *errorMsg,NSProgress *progress, NSURL *savePathUrl);

typedef void(^fileUploadCallBack) (NSInteger errorCode,NSString *errorMsg,NSProgress *progress,NSString *key);
typedef void(^fileResultCallBack) (NSInteger errorCode,NSString *errorMsg);

@interface QHMainAPIService : NSObject

+ (instancetype)shareInstance;

/**  上传文件接口,与消息接口配合使用【先上传文件到服务器，然后通知固件去服务器下载】
   参数1: 文件路径filePath
   参数2: 设备did
   参数3: 设备token
 */
- (void)QiotsPushFile:(NSString *) filePath did:(NSString *)did token:(NSString *)token preparedCallback:(fileUploadCallBack)callBack;

/** 下载文件接口,与消息接口配合使用【先通知固件去上传文件到服务器，然后去服务器下载】
    参数1: 设备did
    参数2: 设备deviceToken
    参数3: 存储路径
    参数4: 文件名(可选)
    参数5: 消息串
 */
- (void)QiotsPullFile:(NSString *)did token:(NSString *)token savePath:(NSString *)savePath saveName:(NSString *)fileName cmd:(NSString *)cmd preparedCallback:(filePullCallBack)callBack fileCallback:(fileDownloadFileCallBack)fileCallback;


/** 取消上传
 */
- (void) QiotsCancelUpload;
/** 取消 当前请求
 */
- (void) QiotsCancelCurrentRequest;
/** 取消某请求
    参数1: 请求的Url
 */

- (void) QiotsCancelRequestWithUrl:(NSString *)url;

/**
 获取设备在线状态
 参数1: did
 参数2: token
 block返回状态(0:网络错误原因 未知状态， 1:在线， 2:离线)
 */
- (void) QiotsGetDeviceStatus:(NSString *)did token:(NSString *)token callBack:(void (^)(int status)) callBack;


/** （可选） 调用pullFile接口后，拿到服务器的Url，然后调用 这个方法去下载文件（当然也可以用app自带的下载模块去下载）
 根据Url 下载服务器文件
 参数1: 服务器返回的Url

 */
- (void)QiotsDownloadFile:(NSString *)url destination:(NSString *)savePath fileName:(NSString *)fileName callBack:(fileDownloadFileCallBack)callBack;

@end
