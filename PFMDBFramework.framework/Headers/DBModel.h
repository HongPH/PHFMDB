//
//  DBModel.h
//  PFMDB
//
//  Created by admin on 2019/1/20.
//  Copyright © 2019年 Hong. All rights reserved.
//  数据库 数据模型基类 需要使用到数据库的模型需要继承该类
//  每一个模型就对应一张表

#import <Foundation/Foundation.h>
@class DBProperty;

NS_ASSUME_NONNULL_BEGIN

@interface DBModel : NSObject

/**
 内部调用: 获取数据属性列表
 */
+ (NSArray<DBProperty *> *)getDBProperties;
/**
 表名
 */
+ (NSString *)tableName;

/**
 主键列表
 */
+ (NSArray<NSString *> *)primaryKeys;


/**
 忽略字段列表
 */
+ (NSArray<NSString *> *)ignoreProperties;


/**
 获取属性
 
 @param property 属性属性
 @return 更改后的数据属性
 */
+ (DBProperty *)getDBProperty:(DBProperty *)property;




@end

NS_ASSUME_NONNULL_END
