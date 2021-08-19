//
//  ViewController.m
//  native-sample
//
//  Created by lyj on 2021/8/19.
//

#import "ViewController.h"
#import <TOPCore/TOPCore.h>

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UILabel *titleLabel;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.titleLabel.text = [NSString stringWithFormat:@"TopSDK V%@",TopSDK.getSDKVersion];
}

- (IBAction)loginHandler:(id)sender {
    [TopSDK.sharedInstance login];
}

- (IBAction)getUserInfoHandler:(id)sender {
    [TopSDK.sharedInstance getUserInfo];
}

- (IBAction)getBindInfoHandler:(id)sender {
    [TopSDK.sharedInstance getUserBindInfo];
}

- (IBAction)enterUserCenterHandler:(id)sender {
    [TopSDK.sharedInstance enterUserCenter];
}

- (IBAction)payHandler:(id)sender {
    TOPPayment *payment = [TOPPayment new];
    payment.productId = @"com.gameplus.product.01";
    payment.amount = 1.01;
    payment.productName = @"小礼包";
    
    TOPRoleInfo *role = [TOPRoleInfo new];
    role.roleName = @"小明";
    role.roleLevel = @"101";
    role.roleId = @"1001";
    role.vipLevel = @"10";
    role.serverName = @"1区";
    [TopSDK.sharedInstance payWithPayment:payment role:role];
}

- (IBAction)bindGoogleHandler:(id)sender {
    [TopSDK.sharedInstance bindPlatform:TOPLoginPlatformGoogle];
}

- (IBAction)logoutHandler:(id)sender {
    [TopSDK.sharedInstance logout];
}

@end
