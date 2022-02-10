//
//  TOPBaseRequest.h
//  TopSDK
//
//  Created by lyj on 2021/1/4.
//

#import <Foundation/Foundation.h>
#import <TOPCore/TOPUrl.h>

NS_ASSUME_NONNULL_BEGIN

typedef TOPUrl *_Nonnull(^prepareBlock)(NSString *baseUrl);

@interface TOPRequest : NSObject

- (instancetype)initWithPrepare:(prepareBlock)block;

- (id)execute:(NSError *__autoreleasing *)error
      netList:(NSArray<NSString *> *)netlist;

@end

NS_ASSUME_NONNULL_END
