//
//  TOPConstants.h
//  TopSDK
//
//  Created by lyj on 2021/2/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 可选择进行账号绑定的平台
extern NSString * const TOPLoginPlatformApple;
extern NSString * const TOPLoginPlatformGoogle;
extern NSString * const TOPLoginPlatformFacebook;
extern NSString * const TOPLoginPlatformLine;
extern NSString * const TOPLoginPlatformNaver;
extern NSString * const TOPLoginPlatformSnapchat;
extern NSString * const TOPLoginPlatformKakao;
extern NSString * const TOPLoginPlatformTwitter;

// 登录、登出事件通知
extern NSString * const TOPDidLoginNotification;
extern NSString * const TOPDidLogoutNotification;

typedef NS_ENUM(NSInteger, TOPSDKErrorCode) {
    TOPSDKErrorCodeAccountExist = 4001,           // 账号已注册
    TOPSDKErrorCodeTokenInvalid = 4002,           // 登录失败，token无效
    TOPSDKErrorCodeAuthFailed = 4003,             // 登录失败
    TOPSDKErrorCodeBindFailed = 4004,             // 绑定失败
    TOPSDKErrorCodeUnboundLastAccount = 4005,     // 解绑失败，请先绑定其他登录方式
    TOPSDKErrorCodeAccountBounded = 4006,         // 已绑定该第三方账号
    TOPSDKErrorCodeResourcePermissionDenied = 4007,   // 无访问权限
    TOPSDKErrorCodeUserBounded = 4009,            // 三方账号已被其他账号绑定
    TOPSDKErrorCodeAccountNotExist = 4010,        // 账号不存在
    TOPSDKErrorCodeTokenExpired = 4011,           // 登录状态过期
    TOPSDKErrorCodeResourceNotFound = 5001,       // 记录不存在
    TOPSDKErrorCodeResourceHasBeTaken = 5002,     // 数据错误
    TOPSDKErrorCodeParameterError = 5003,         // 请求错误，参数不正确
    TOPSDKErrorCodeResourceLocked = 5004,         // 禁止访问
    TOPSDKErrorCodeHttpRequestError = 5005,       // 服务器网络异常
    TOPSDKErrorCodeOrderError = 6002,             // 订单错误
    TOPSDKErrorCodeGuestOrderDenied = 6003,       // 游客禁止下单
    TOPSDKErrorCodePayVerifyFailed = 6004,        // 苹果支付校验失败
    TOPSDKErrorCodePayReceiptEmpty = 6005,        // 苹果支付校验失败，凭证异常
    TOPSDKErrorCodeOrderUserIncorrect = 6006,     // 订单用户不匹配
    TOPSDKErrorCodeNotDefinedException = 10000,   // 服务器错误
    TOPSDKErrorCodeNetworkError = 8000,           // 网络异常
    TOPSDKErrorCodeAuthorizedLoginFailed = 8001,  // 授权登录失败
    TOPSDKErrorCodeAuthorizedLoginCancel = 8002,  // 用户取消授权登录
    TOPSDKErrorCodeNotSupportLoginMethod = 8003,  // 不支持的登录方式
    TOPSDKErrorCodeNotLogin = 8004,               // 未登录
    TOPSDKErrorCodeLoginCancel = 8005,            // 登录取消（窗口关闭）
    TOPSDKErrorCodePaymentUnfinished = 8006,      // 有未完成的支付
    TOPSDKErrorCodeUnfindProduct = 8007,          // 未找到商品
    TOPSDKErrorCodePayFailed = 8008,              // 支付失败
    TOPSDKErrorCodePaymentCancelled = 8009,       // 订单取消，对应SKErrorPaymentCancelled
    TOPSDKErrorCodeClientInvalid = 8010,          // 当前苹果账户无法购买商品，对应SKErrorClientInvalid
    TOPSDKErrorCodePaymentNotAllowed = 8011,      // 当前苹果设备无法购买商品，对应SKErrorPaymentNotAllowed
    TOPSDKErrorCodeProductNotAvailable = 8012,    // 当前商品不可用，对应SKErrorStoreProductNotAvailable
    TOPSDKErrorCodePaymentInvalid = 8013,         // 订单无效，对应SKErrorPaymentInvalid
    TOPSDKErrorCodeUserCannotMakePayment = 8014,  // 用户不被允许进行购买
    TOPSDKErrorCodeUninitialized = 8015,          // 未初始化，请先调用初始化接口
    TOPSDKErrorCodeLogoutCancel = 8016,           // 登出取消
    TOPSDKErrorCodePluginLoadError = 8017         // 插件加载异常
};

NS_ASSUME_NONNULL_END
