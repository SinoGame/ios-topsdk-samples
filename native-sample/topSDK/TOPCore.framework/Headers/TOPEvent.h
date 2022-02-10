//
//  TOPEventData.h
//  TOPCore
//
//  Created by lyj on 2021/4/28.
//

#import <TOPCore/TOPDataModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPEvent : TOPDataModel

@property (nullable, nonatomic, retain) NSString *level;
@property (nullable, nonatomic, retain) NSString *content;
@property (nonnull, nonatomic, retain) NSNumber *status;
@property (nonnull, nonatomic, retain) NSDate *date;

@end

NS_ASSUME_NONNULL_END
