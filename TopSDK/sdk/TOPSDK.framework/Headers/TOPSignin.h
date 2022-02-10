//
//  TOPLogin.h
//  TopSDKCore
//
//  Created by lyj on 2021/3/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^TOPSigninCompletion)(NSString * __nullable code, NSString * __nullable token, NSError * __nullable error);

@protocol TOPSigninProtocol <NSObject>

@required

- (void)loginWithVC:(UIViewController *)vc
         completion:(TOPSigninCompletion)completion;

- (void)logout;

- (NSString *)loginType;
- (NSString *)displayName;

- (nullable UIImage *)loginIcon;
- (nullable UIImage *)bindIcon;

- (NSString *)loginButtonTitle;
- (nullable UIColor *)loginButtonBgColor;
- (nullable UIColor *)loginButtonTitleColor;
- (CGFloat)loginButtonBorderWidth;
- (nullable UIColor *)loginButtonBorderColor;

@end

NS_ASSUME_NONNULL_END
