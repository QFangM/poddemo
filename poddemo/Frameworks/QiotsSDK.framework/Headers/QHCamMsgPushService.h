//
//  QHCamMsgPushService.h
//  QHCamSDKDemo
//
//  Created by 谢印超 on 2017/9/20.
//
//

#import <Foundation/Foundation.h>
#import "QHCamError.h"

@protocol QHCamMsgPushServiceDelegate <NSObject>

@optional
/** 可选监听代理，被动接收来自服务器的长连push消息，例如安防报警等（根据需要监听）
 
 */
- (void) msgHandlerCallback:(id) obj ;
@end

@interface QHCamMsgPushService : NSObject

+ (instancetype)shareInstance;

/**
    自定义封装消息发送 (发送给固件后立马返回)
    参数1: 消息文本
    参数2: 设备did
    参数3: 设备令牌
    
    返回值：block形式回调 （用户产生的行为，发送后回调）
 */
- (void)QiotsSendMsg:(NSString*)command did:(NSString *)did  device_Token:(NSString *)token withSuccess:(void (^)(id response,NSString *taskId))success withFailed:(void (^)(QHCamError *error))failed;

/**
 自定义封装消息发送，(发送给固件后,轮询等待固件异步反馈结果，根据业务需要调用)
 参数1: 消息文本
 参数2: 设备did
 参数3: 设备令牌
 
 返回值：block形式回调 （用户产生的行为，发送后回调）
 */
- (void)QiotsSendWaitingMsg:(NSString*)command did:(NSString *)did  device_Token:(NSString *)token withSuccess:(void (^)(id response,NSString *taskId))success withFailed:(void (^)(QHCamError *error))failed;


@end
