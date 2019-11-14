//
//  QiotsPtzControl.h
//  QiotsSDK
//
//  Created by 谢印超 on 2018/3/31.
//  Copyright © 2018年 qihoo. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, QiotsPtzMovingDirection) {
    
    QiotsPtzMovingLeft = 0,
    QiotsPtzMovingRight = 1,
    QiotsPtzMovingUp = 2,
    QiotsPtzMovingDown = 3,
    QiotsPtzMovingNone = 4,
};

@protocol QiotsPtzControlDelegate <NSObject>

@optional
/** 移动过程状态回调 */
- (void) qiotsPtzMovingStatus:(NSString *)msg ;
/** 错误信息 */
- (void) qiotsPtzFailedToMove:(NSString *)msg ;
/** 移动到边缘提醒 */
- (void) qiotsPtzMovedToEdge;
/** 正在移动的方向 实时状态回调 */
- (void) qiotsPtzMovingDirection:(QiotsPtzMovingDirection)direct;
@end

@interface QiotsPtzControl : NSObject


@property (nonatomic, weak) id<QiotsPtzControlDelegate> delegate;

/**
 初始化摇杆控件
 参数1: did
 参数2: token
 参数3: 父view (摇杆将会四周填充到 父View上，所以父View必须为正方形)
 
 返回值：block形式回调 （用户产生的行为，发送后回调）
 */
- (instancetype) initQiotsPtzControl:(NSString *)did deviceToken:(NSString *)token  overView:(UIView *) ptzSuperView;

@end
