//
//  DBProperty.h
//  PFMDB
//
//  Created by admin on 2019/1/20.
//  Copyright © 2019年 Hong. All rights reserved.
//  属性模型 对应 数据模型里的属性 也就是数据库中 表 的 字段

#import <Foundation/Foundation.h>

//属性类型枚举
typedef enum {
    DBPropertyTypeString = 0x00,  //字符串
    DBPropertyTypeInteger = 0x01, //整数
    DBPropertyTypeFloat = 0x02,   //浮点数
    DBPropertyTypeDecimal = 0x03, //十进制数
    DBPropertyTypeDatetime = 0x04,//时间
    DBPropertyTypeData = 0x05,    //二进制数据
}DBPropertyType;


@interface DBProperty : NSObject

@property (nonatomic, strong) NSString *propertyName;       //属性名
@property (nonatomic, strong) NSString *columnName;         //字段名
@property (nonatomic, assign) DBPropertyType type;          //类型
@property (nonatomic, strong) NSString *defaultValue;       //默认值
@property (nonatomic, assign) BOOL ignore;                  //是否允许忽略
@property (nonatomic, assign) BOOL uniqueKey;               //是否唯一键(未开通)
@property (nonatomic, assign) BOOL primaryKey;              //是否主键
@property (nonatomic, assign) BOOL collaseNOCase;           //是否忽略大小写, DBPropertyTypeString有效 默认为NO

/**
 初始化
 
 @param propertyName 属性名
 */
- (instancetype)initWithPropertyName:(NSString *)propertyName;

@end
 
