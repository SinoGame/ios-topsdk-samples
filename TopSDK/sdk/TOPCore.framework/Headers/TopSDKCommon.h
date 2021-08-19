//
//  TopSDKCommon.h
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

typedef NS_ENUM(NSInteger, TOPErrorCode) {
    TOPErrorCodeAccountExist = 4001,           // 账号已注册
    TOPErrorCodeTokenInvalid = 4002,           // 登录失败，token无效
    TOPErrorCodeAuthFailed = 4003,             // 登录失败
    TOPErrorCodeBindFailed = 4004,             // 绑定失败
    TOPErrorCodeUnboundLastAccount = 4005,     // 解绑失败，请先绑定其他登录方式
    TOPErrorCodeAccountBounded = 4006,         // 已绑定该第三方账号
    TOPErrorCodeResourcePermissionDenied = 4007,   // 无访问权限
    TOPErrorCodeUserBounded = 4009,            // 三方账号已被其他账号绑定
    TOPErrorCodeAccountNotExist = 4010,        // 账号不存在
    TOPErrorCodeTokenExpired = 4011,           // 登录状态过期
    TOPErrorCodeResourceNotFound = 5001,       // 记录不存在
    TOPErrorCodeResourceHasBeTaken = 5002,     // 数据错误
    TOPErrorCodeParameterError = 5003,         // 请求错误，参数不正确
    TOPErrorCodeResourceLocked = 5004,         // 禁止访问
    TOPErrorCodeHttpRequestError = 5005,       // 服务器网络异常
    TOPErrorCodeOrderError = 6002,             // 订单错误
    TOPErrorCodeGuestOrderDenied = 6003,       // 游客禁止下单
    TOPErrorCodePayVerifyFailed = 6004,        // 苹果支付校验失败
    TOPErrorCodePayReceiptEmpty = 6005,        // 苹果支付校验失败，凭证异常
    TOPErrorCodeOrderUserIncorrect = 6006,     // 订单用户不匹配
    TOPErrorCodeNotDefinedException = 10000,   // 服务器错误
    TOPErrorCodeNetworkError = 8000,           // 网络异常
    TOPErrorCodeAuthorizedLoginFailed = 8001,  // 授权登录失败
    TOPErrorCodeAuthorizedLoginCancel = 8002,  // 用户取消授权登录
    TOPErrorCodeNotSupportLoginMethod = 8003,  // 不支持的登录方式
    TOPErrorCodeNotLogin = 8004,               // 未登录
    TOPErrorCodeLoginCancel = 8005,            // 登录取消（窗口关闭）
    TOPErrorCodePaymentUnfinished = 8006,      // 有未完成的支付
    TOPErrorCodeUnfindProduct = 8007,          // 未找到商品
    TOPErrorCodePayFailed = 8008,              // 支付失败
    TOPErrorCodePaymentCancelled = 8009,       // 订单取消，对应SKErrorPaymentCancelled
    TOPErrorCodeClientInvalid = 8010,          // 当前苹果账户无法购买商品，对应SKErrorClientInvalid
    TOPErrorCodePaymentNotAllowed = 8011,      // 当前苹果设备无法购买商品，对应SKErrorPaymentNotAllowed
    TOPErrorCodeProductNotAvailable = 8012,    // 当前商品不可用，对应SKErrorStoreProductNotAvailable
    TOPErrorCodePaymentInvalid = 8013,         // 订单无效，对应SKErrorPaymentInvalid
    TOPErrorCodeUserCannotMakePayment = 8014,  // 用户不被允许进行购买
};

NS_ASSUME_NONNULL_END
