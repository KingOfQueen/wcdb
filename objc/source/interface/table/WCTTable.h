/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <WCDB/WCTCommon.h>
#import <WCDB/WCTOptional.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WCTTable

- (WCTOptional<BOOL, NO>)tableExists:(NSString *)tableName;

- (BOOL)createTableAndIndexes:(NSString *)tableName
                    withClass:(Class<WCTTableCoding>)cls;

- (WCTTable *)getTable:(NSString *)tableName
             withClass:(Class<WCTTableCoding>)cls;

- (BOOL)createVirtualTable:(NSString *)tableName
                 withClass:(Class<WCTTableCoding>)cls;

- (BOOL)dropTable:(NSString *)tableName;

- (BOOL)dropIndex:(NSString *)indexName;

@end

@interface WCTTable<ObjectType> : NSObject

/**
 The name of the table.
 */
@property (nonatomic, readonly) NSString *name;

/**
 The class binding to this table.
 */
@property (nonatomic, readonly) Class cls;

@property (nonatomic, readonly) WCTDatabase *database;

- (BOOL)dropIndexWithSubfix:(NSString *)indexSubfix;

- (WCTError *)error;

- (void)invalidate;

@end

NS_ASSUME_NONNULL_END
