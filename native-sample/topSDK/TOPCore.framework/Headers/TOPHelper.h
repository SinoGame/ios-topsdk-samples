//
//  TOPHelper.h
//  TOPCore
//
//  Created by lyj on 2021/3/8.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPHelper : NSObject

#pragma mark - String Utils
+ (CGSize)sizeWithString:(NSString *)str maxSize:(CGSize)size font:(UIFont *)font;
+ (CGSize)sizeWithString:(NSString *)str noLimitInFont:(UIFont *)font;
+ (NSString *)randomStringWithLength:(NSInteger)length;
+ (nullable NSString *)md5hexOfString:(NSString *)plain;
+ (NSString *)urlEncodeWithString:(NSString *)str;
+ (NSString *)urlDecodeWithString:(NSString *)str;

#pragma mark - base64
+ (NSString *)base64Encode:(NSData *)data;

#pragma mark - idfa
+ (NSString *)getIDFA;

#pragma mark - error
+ (NSError *)errorWithCode:(NSInteger)code
                   message:(nonnull NSString *)message
                     extra:(nonnull NSString *)extra;

#pragma mark - localized
+ (NSString *)getLocaliedStringByKey:(NSString *)key;

#pragma mark - image
+ (UIImage *)getImage:(NSString *)imageName;

#pragma mark - Timer
+ (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)ti
                                     target:(id)aTarget
                                   selector:(SEL)aSelector
                                   userInfo:(nullable id)userInfo
                                     repeat:(BOOL)repeat;

#pragma mark - Json
+ (nullable NSDictionary *)jsonDictOfData:(NSData *)data;
+ (nullable NSData *)jsonDataWithObj:(id)obj;

@end

UIWindow * TOPCurrentWindow(void);

UIEdgeInsets TOPViewSafeAreaInset(void);

CGFloat const TOPAppStatusBarHeight(void);

NS_ASSUME_NONNULL_END

#ifndef TOPHelper_h
#define TOPHelper_h

#define TOP_SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#define TOP_SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)

#define TOP_BLOCK_EXEC(block, ...) if (block) { block(__VA_ARGS__); };

#define TOP_EXEC_ON_MAIN(block, ...) \
if ([NSThread isMainThread]) { \
  TOP_BLOCK_EXEC(block, __VA_ARGS__); \
} else { \
  dispatch_async(dispatch_get_main_queue(), ^{ TOP_BLOCK_EXEC(block, __VA_ARGS__) }); \
};

#define topweakify(var) __weak typeof(var) TOPWeak_##var = var;

#define topstrongify(var) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
__strong typeof(var) var = TOPWeak_##var; \
_Pragma("clang diagnostic pop")

#define TOPWindow TOPCurrentWindow()
#define TOPStatusBarHeight TOPAppStatusBarHeight()
#define TOPSafeArea TOPViewSafeAreaInset()
#define TOPSafeTopInset TOPViewSafeAreaInset().top
#define TOPSafeBottomInset TOPViewSafeAreaInset().bottom

#define TOPLocalize(key) \
[TOPHelper getLocaliedStringByKey:(key)]

#define TOPImage(imageName) \
[TOPHelper getImage:(imageName)]

#define TOPError(code, messageStr, extraStr) \
[TOPHelper errorWithCode:(code) message:(messageStr) extra:(extraStr)]

#define top_dispatchAfter(seconds, block) do { \
  dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)((seconds) * NSEC_PER_SEC)), dispatch_get_main_queue(), block);\
} while(0)

#endif /* TOPHelper_h */
