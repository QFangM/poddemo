//
//  BHViewController.m
//  poddemo
//
//  Created by yanghy22@midea.com on 11/14/2019.
//  Copyright (c) 2019 yanghy22@midea.com. All rights reserved.
//

#import "BHViewController.h"
#import "BHTools.h"

@interface BHViewController ()

@end

@implementation BHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    BHTools *tools = [[BHTools alloc] init];
    [tools plus:5 with:100];
    NSLog(@"<< %@", [tools createName]);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
