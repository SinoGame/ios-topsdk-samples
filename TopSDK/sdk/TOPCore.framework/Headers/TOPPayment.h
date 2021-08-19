//
//  TOPPayment.h
//  TOPCore
//
//  Created by lyj on 2021/3/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPPayment : NSObject

/// 商品id
@property (nonatomic, copy) NSString *productId;

/// 商品名称
@property (nonatomic, copy, nullable) NSString *productName;

/// 商品价格，小数点后最多保留2位
@property (nonatomic, assign) double amount;

#pragma mark - 苹果商店信息

@property (nonatomic, copy, nullable) NSString *transactionid;      // 苹果支付的唯一id
@property (nonatomic, copy, nullable) NSString *currency;           // 币种
@property (nonatomic, copy, nullable) NSString *countryCode;        // 国家
@property (nonatomic, copy, nullable) NSString *price;              // 价格
@property (nonatomic, copy, nullable) NSString *title;              // 名称
@property (nonatomic, copy, nullable) NSString *receipt;            // 苹果的支付凭证（base64后）

#pragma mark - 我方订单信息
/// 订单号
@property (nonatomic, copy, nullable) NSString *orderNo;

/// 订单创建时间
@property (nonatomic, copy, nullable) NSString *orderCreateTime;

/// 是否经过猜单
@property (nonatomic, assign) BOOL isGuess;

@end

NS_ASSUME_NONNULL_END
