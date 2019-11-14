//
//  QHCamSDK.h
//  QHCamSDK
//
//  Created by chengbao on 16/3/3.
//  Copyright © 2016年 qihoo. All rights reserved.
//  QiotsSdk

#import <Foundation/Foundation.h>
@class QHUserToken;
typedef enum __tagQHCamSDKCommonErr
{
    QHCamSDKCommonErr_None = 0,                  //没有错误发生
    QHCamSDKCommonErr_Params = -101000,          //参数不正确
    QHCamSDKCommonErr_NOAuth,                    //没有配置正确的appID和appKey
    QHCamSDKCommonErr_User,                      //设置的user 信息不正确
    
    QHCamSDKCommonErr_NoSupport = - 110000,      //此功能不支持
}QHCamSDKCommonErr;


@interface QiotsSDK : NSObject

/**
 * app获取360分配的push key，usid后调用配置方法 并传入Eid
 * （使用QHCamSDK前，必须要调用下面函数，设置pushKey和usid，以及Eid）
 * @param QHUserToken[pushKey,usid,eid]
 * @return 配置成功，返回0， 失败返回 请看：QHCamSDKCommonErr
 *
 */

+ (QHCamSDKCommonErr) loginSDK:(QHUserToken *)userToken;

/**
 * 登出SDK，切换账号的时候使用
 *
 */

+ (void)logoutSDK;

/**
 * 调用下面函数可以用来开启debug模式，debug的信息会打印处理。
 * 默认，QHCamSDK处于关闭debug模式
 *
 * @param enble YES表示开启debug模式， NO表示关闭debug模式
 */
+ (void)debugEnble:(BOOL)enble;


/**
 * 获取当前sdk的版本号
 * 
 * @return NSString 返回版本号信息
 */
+ (NSString *)sdkVersion;


@end


#import "QHCamLivePlayer.h"
#import "QHCamRelayInfoService.h"
#import "QHMainAPIService.h"
#import "QHCamMsgPushService.h"
#import "QHUserToken.h"
