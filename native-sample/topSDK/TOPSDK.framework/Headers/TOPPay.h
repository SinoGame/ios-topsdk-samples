//
//  TOPPay.h
//  TopSDKCore
//
//  Created by lyj on 2021/3/1.
//

#import <Foundation/Foundation.h>
#import <TOPSDK/TOPPayment.h>
#import <TOPSDK/TOPRoleInfo.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TOPPayAction) {
    TOPPayActionAddOrder,
    TOPPayActionDoVerify,
    TOPPayActionRetryVerify,
    TOPPayActionUploadLog
};

@protocol TOPPayActionProtocol <NSObject>

- (void)paySuccessWithPayment:(TOPPayment *)payment;
- (void)payFailureWithPayment:(TOPPayment *)payment error:(NSError *)error;

- (id)handlerPayAction:(TOPPayAction)action params:(NSDictionary *)params callback:(void(^ _Nullable)(NSError *error, id result))callback;

@end

@protocol TOPPayProtocol <NSObject>

@required

- (void)setActionHandler:(id<TOPPayActionProtocol>)handler;

- (void)payWithPayment:(TOPPayment *)payment
                  role:(TOPRoleInfo *)roleInfo;

@end

NS_ASSUME_NONNULL_END
