//
//  TOPDataModel.h
//  TOPCore
//
//  Created by lyj on 2021/4/12.
//

#import <CoreData/CoreData.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPDataModel : NSManagedObject

+ (instancetype)createWithContext:(NSManagedObjectContext *)ctx;

+ (NSString *)entityName;

+ (NSArray *)allObjects:(NSManagedObjectContext *)ctx;
+ (NSArray *)allUploadedData:(NSManagedObjectContext *)ctx;
+ (NSArray *)getObjectsWithLimitCount:(NSInteger)count context:(NSManagedObjectContext *)ctx;

- (void)delete;

- (BOOL)save;

- (BOOL)save:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
