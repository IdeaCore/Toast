//
//  TWTKeyValueObserver.h
//  Toast
//
//  Created by Josh Johnson on 3/12/14.
//  Copyright (c) 2014 Two Toasters.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <Foundation/Foundation.h>

typedef void(^TWTKeyValueObserverChangeBlock)(id observedObject, NSDictionary *changeDictionary);

/*!
 @abstract An opaque observer object that manages KVO against a single object
 @discussion Under ARC, if the object you are observing is the same as the object that will retain this observer class you need to take extra care as to when observation starts or stops. In these cases you should use the `startObserving`-based methods to not start observing the object at init but rather use the `-startObserving` and `-stopObserving` methods to control observation. This is especially important when the object you are observing (which is stored as a weak reference) is released before this observer object can remove itself as an observer.
 */
@interface TWTKeyValueObserver : NSObject

@property (nonatomic, weak, readonly) id object;
@property (nonatomic, copy, readonly) NSString *keyPath;
@property (nonatomic, assign, getter = isObserving, readonly) BOOL observing;

/*! 
 @abstract Create and return an observer object that can be stored and released as needed.
 @discussion This will automatically start observing the specified object.
 @param object The object to observe
 @param keyPath The keyPath to observe on the object
 @param options Options to use for observations
 @param changeBlock A block to invoke when the observation occurs
 */
+ (instancetype)observerWithObject:(id)object
                           keyPath:(NSString *)keyPath
                           options:(NSKeyValueObservingOptions)options
                       changeBlock:(TWTKeyValueObserverChangeBlock)changeBlock;

/*! 
 @abstract Create and return an observer object that can be stored and released as needed
 @discussion This will automatically start observing the specified object.
 @param object The object to observe
 @param keyPath The keyPath to observe on the object
 @param options Options to use for observations
 @param target An object to notify of changes.
 @param action A selector to call on the target object to notify of changes. 
 */
+ (instancetype)observerWithObject:(id)object
                           keyPath:(NSString *)keyPath
                           options:(NSKeyValueObservingOptions)options
                            target:(id)target
                            action:(SEL)action;

/*! 
 @abstract Create and return an observer object that can be stored and released as needed
 @param object The object to observe
 @param keyPath The keyPath to observe on the object
 @param options Options to use for observations
 @param startObserving Specify whether this should start the observer on creation
 @param changeBlock A block to invoke when the observation occurs
 */
+ (instancetype)observerWithObject:(id)object
                           keyPath:(NSString *)keyPath
                           options:(NSKeyValueObservingOptions)options
                    startObserving:(BOOL)startObserving
                       changeBlock:(TWTKeyValueObserverChangeBlock)changeBlock;

/*! 
 @abstract Create and return an observer object that can be stored and released as needed
 @param object The object to observe
 @param keyPath The keyPath to observe on the object
 @param options Options to use for observations
 @param startObserving Specify whether this should start the observer on creation
 @param target An object to notify of changes.
 @param action A selector to call on the target object to notify of changes. 
 */
+ (instancetype)observerWithObject:(id)object
                           keyPath:(NSString *)keyPath
                           options:(NSKeyValueObservingOptions)options
                    startObserving:(BOOL)startObserving
                            target:(id)target
                            action:(SEL)action;

/*! 
 @abstract Create an observer object that can be stored and released as needed
 @discussion This will automatically start observing the specified object.
 @param object The object to observe
 @param keyPath The keyPath to observe on the object
 @param options Options to use for observations
 @param changeBlock A block to invoke when the observation occurs
 */
- (instancetype)initWithObject:(id)object
                       keyPath:(NSString *)keyPath
                       options:(NSKeyValueObservingOptions)options
                   changeBlock:(TWTKeyValueObserverChangeBlock)changeBlock;

/*! 
 @abstract Create an observer object that can be stored and released as needed
 @param object The object to observe
 @param keyPath The keyPath to observe on the object
 @param options Options to use for observations
 @param target An object to notify of changes.
 @param action A selector to call on the target object to notify of changes. 
 */
- (instancetype)initWithObject:(id)object
                       keyPath:(NSString *)keyPath
                       options:(NSKeyValueObservingOptions)options
                        target:(id)target
                        action:(SEL)action;

/*! 
 @abstract Create an observer object that can be stored and released as needed
 @discussion This will automatically start observing the specified object.
 @param object The object to observe
 @param keyPath The keyPath to observe on the object
 @param options Options to use for observations
 @param startObserving Specify whether this should start the observer on creation
 @param changeBlock A block to invoke when the observation occurs
 */
- (instancetype)initWithObject:(id)object
                       keyPath:(NSString *)keyPath
                       options:(NSKeyValueObservingOptions)options
                startObserving:(BOOL)startObserving
                   changeBlock:(TWTKeyValueObserverChangeBlock)changeBlock;

/*! 
 @abstract Create an observer object that can be stored and released as needed
 @param object The object to observe
 @param keyPath The keyPath to observe on the object
 @param options Options to use for observations
 @param startObserving Specify whether this should start the observer on creation
 @param target An object to notify of changes.
 @param action A selector to call on the target object to notify of changes. 
 */
- (instancetype)initWithObject:(id)object
                       keyPath:(NSString *)keyPath
                       options:(NSKeyValueObservingOptions)options
                startObserving:(BOOL)startObserving
                        target:(id)target
                        action:(SEL)action;

/*!
 @abstract Start observing the object if it isn't already observing.
 */
- (void)startObserving;

/*!
 @abstract Stop observing the object if it is already observing.
 */
- (void)stopObserving;

@end
