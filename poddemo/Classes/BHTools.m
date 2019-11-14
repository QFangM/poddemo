//
//  BHTools.m
//  poddemo
//
//  Created by yanghy on 2019/11/14.
//

#import "BHTools.h"
#import <TestFramework/TestFramework.h>
#import <QiotsSDK/QHCamLivePlayer.h>

@implementation BHTools

- (void) plus:(NSInteger)valA with:(NSInteger)valB{
    BHTestHelper *helper = [[BHTestHelper alloc] init];
    [helper add:valA];
}

- (NSString *)createName{
    BHTestHelper *helper = [[BHTestHelper alloc] init];
    QHCamLivePlayer *player = [[QHCamLivePlayer alloc] init];
    return [NSString stringWithFormat:@"<<< %@", [helper getName]];
    
}

@end
