//
//  DatabaseManager.h
//  PFMDB
//
//  Created by admin on 2019/1/21.
//  Copyright © 2019年 Hong. All rights reserved.
//  对外数据库操作类 封装了常用数据库操作方法

#import <Foundation/Foundation.h>
@class DatabaseSQLOprator;
@class SQLParam;
@class DBConfiguration;



@interface DatabaseManager : NSObject

@property (nonatomic, strong) DatabaseSQLOprator *dbOprator;         //数据库处理器(sql)
@property (nonatomic, strong) NSString *dbConfigPath;       //数据库配置路径
@property (nonatomic, strong) NSString *dbPath;             //数据库存放路径
@property (nonatomic, strong) DBConfiguration *dbConfiguration;//数据库信息

/**
 *  单例
 *
 *  @return 本地数据库管理对象
 */
+ (instancetype)sharedWithDBConfigPath:(NSString *)dbConfigPath;

/**
 *  开启数据库组件
 *
 *  @param dbPath 数据库存放路径
 */
- (void)startWithDBPath:(NSString *)dbPath;

/**
 关闭数据库组件
 */
- (void)stop;

/**
 *  打开数据库
 */
- (BOOL)openDB;

/**
 *  关闭数据库
 */
- (BOOL)closeDB;

/**
 安全更新
 
 @param param sql参数
 @return 是否成功
 */
- (BOOL)security_execute_update:(SQLParam *)param;

/**
 安全数据查询
 
 @param param sql参数
 @param clsArr 返回类型数组/nil表示返回字典数组
 @return 查询结果数组
 */
- (NSArray *)security_execute_query:(SQLParam *)param returnClassArray:(NSArray *)clsArr;

/**
 开启事务
 @param block 操作block
 */
- (void)inTransaction:(void (^)(BOOL *commit))block;

@end
 
