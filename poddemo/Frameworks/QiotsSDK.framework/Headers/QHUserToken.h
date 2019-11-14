//
//  HGUserInfo.h
//  360HomeGuard
//
//  Created by AllenLiu on 14-6-12.
//  Copyright (c) 2014年 Jeremy. All rights reserved.
//

#import <Foundation/Foundation.h>


#define CLOSENODISTURB @"0" //关闭


@interface QHUserToken : NSObject

/**  信令push key */
@property (nonatomic, strong) NSString * pushKey;
/*360业务服务器分配 session id*/
@property (nonatomic, strong) NSString * usid;

/*企业ID*/
@property (nonatomic, copy) NSString *eid;


- (void)clear;


@end
