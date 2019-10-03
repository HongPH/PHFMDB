//
//  PFMDBDataOperator.h
//  PFMDB
//
//  Created by admin on 2019/1/26.
//  Copyright © 2019年 Hong. All rights reserved.
//  PFMDB 的数据操作类 外界使用该类进行数据操作

#import <Foundation/Foundation.h>
 

@interface PFMDBDataOperator : NSObject

@property (nonatomic) Class entityClass;                //实体类
@property (nonatomic, strong) NSString *dbConfigPath;   //数据库配置文件路径

/**
 *  初始化
 *
 *  @param cls 实体类
 *  @param dbConfigPath 数据库配置文件路径
 *
 *  @return 数据库操作基类
 */
- (instancetype)initWithEntityClass:(Class)cls dbConfigPath:(NSString *)dbConfigPath;

/**
 *  插入
 *
 *  @param entity 实体类
 *
 *  @return 是否成功
 */
- (BOOL)insert:(NSObject *)entity;

/**
 *  插入数组
 *
 *  @param entityArray 实体数组
 *
 *  @return 是否成功
 */
- (BOOL)insertArray:(NSArray *)entityArray;

/**
 *  更新数组
 *
 *  @param entityArray 实体数组
 *
 *  @return 是否成功
 */
- (BOOL)updateArray:(NSArray *)entityArray;

/**
 *  更新
 *
 *  @param entity 实体类
 *
 *  @return 是否成功
 */
- (BOOL)update:(NSObject *)entity;

/**
 *  是否有该记录
 *
 *  @param entity 实体类
 *
 *  @return 是否有该记录
 */
- (BOOL)hasRecord:(NSObject *)entity;

/**
 *  插入或更新
 *
 *  @param entity 实体类
 *
 *  @return 是否成功
 */
- (BOOL)insertOrUpdate:(NSObject *)entity;

/**
 *  插入或者修改数组
 *
 *  @param entityArray 实体类数组
 *
 *  @return 是否成功
 */
- (BOOL)insertOrUpdateArray:(NSArray *)entityArray;

/**
 *  删除
 *
 *  @param entity 实体类
 *
 *  @return 是否成功
 */
- (BOOL)delete:(NSObject *)entity;


/**
 删除数组
 
 @param entityArray 实体数组
 @return 删除的数量
 */
- (NSInteger)deleteArray:(NSArray <NSObject *>*)entityArray;

//删除表中所有记录
- (BOOL)deleteAll;


#pragma mark - database search
/**
 *  条件查询方法
 *
 *  @param sql    查询语句,条件用@"?"号表示
 *  @param array  条件数组
 *  @param cls    返回的类 返回类为空则默认返回NSDictionary
 *
 *  @return 指定类/字典结果数组
 */
- (NSArray *)executeQuery:(NSString *)sql argumentArray:(NSArray *)array cls:(Class)cls;

/**
 *  基础条件查询方法
 *
 *  @param sql    查询语句,条件用@"?"号表示
 *  @param array  条件数组
 *  @param clsArr 返回类数据,数组第一个为返回类,之后为返回类的父类, 返回类数组为空则默认返回NSDictionary
 *
 *  @return 指定类/字典结果数组
 */
- (NSArray *)executeQuery:(NSString *)sql argumentArray:(NSArray *)array returnClassArray:(NSArray *)clsArr;

/**
 *  条件查询
 *
 *  @param condition 条件(字符串)
 *  @param columns   指定查询的列
 *  @param orderBy   排序
 *  @param groupBy   分组
 *  @param offset    下标偏移
 *  @param limit     每页个数
 *
 *  @return 当前类结果集数组
 */
- (NSArray *)getByQuery:(NSString *)condition catchColumns:(NSString *)columns orderBy:(NSString *)orderBy groupBy:(NSString *)groupBy  offset:(NSInteger)offset limit:(NSInteger)limit;

/**
 *  获取实体记录
 *
 *  @param primaryKeyDict 主键数组
 *
 *  @return 实体记录
 */
- (NSObject *)getById:(NSDictionary *)primaryKeyDict;
/**
 *  获取总数量
 *
 *  @param dict 条件字典
 *
 *  @return 总数量
 */
- (NSInteger)getCount:(NSDictionary *)dict;

/**
 *  执行修改
 *
 *  @param sql       sql语句
 *  @param arguments 参数
 *
 *  @return 是否成功
 */
- (BOOL)executeUpdate:(NSString *)sql args:(NSArray *)arguments;



@end

