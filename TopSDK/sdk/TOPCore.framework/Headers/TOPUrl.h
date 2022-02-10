//
//  TOPBaseUrl.h
//  TopSDK
//
//  Created by lyj on 2021/1/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPUrl : NSObject

@property (nonatomic, strong) NSString *httpMethod;
@property (nonatomic, assign) NSTimeInterval timeout;
@property (nonatomic, strong) NSString *requestBody;
@property (nonatomic, strong) NSString *baseUrl;

@property (nonatomic, strong) NSData *bodyData;

- (instancetype)initWithBaseUrl:(NSString *)baseUrl;

- (NSString *)paramForKey:(NSString *)key;
- (void)addParameter:(NSString *)value forKey:(NSString *)name;
- (void)addNumberParameter:(NSNumber *)value forKey:(NSString *)name;
- (void)addEmptyParameterWithKey:(NSString *)name;
- (void)addHeaderWithValue:(NSString *)value forKey:(NSString *)name;

- (NSURL *)urlOfSignatured;

- (void)setPostMethod;
- (void)setGetMethod;

- (NSURLRequest *)requestOfSignatured;

@end

NS_ASSUME_NONNULL_END
