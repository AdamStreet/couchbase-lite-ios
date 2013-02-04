//
//  CBL_ReplicatorManager.h
//  CouchbaseLite
//
//  Created by Jens Alfke on 2/15/12.
//  Copyright (c) 2012 Couchbase, Inc. All rights reserved.
//

#import "CBL_Database.h"
#import "CBLManager+Internal.h"
@protocol CBLAuthorizer;


extern NSString* const kCBL_ReplicatorDatabaseName;


/** Manages the _replicator database for persistent replications.
    It doesn't really have an API; it works on its own by monitoring the '_replicator' database, and docs in it, for changes. Applications use the regular document APIs to manage replications.
    A CBL_Server owns an instance of this class. */
@interface CBL_ReplicatorManager : NSObject
{
    CBLManager* _dbManager;
    CBL_Database* _replicatorDB;
    NSMutableDictionary* _replicatorsByDocID;
    BOOL _updateInProgress;
}

- (id) initWithDatabaseManager: (CBLManager*)dbManager;

- (void) start;
- (void) stop;

@end
