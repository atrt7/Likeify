#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*#import "SpotifyHeaders/SPTReaderWriterMutableDictionary.h"
#import "SpotifyHeaders/SPTTheme.h"
#import "SpotifyHeaders/SPTTheHUBComponentRegistryme.h"
#import "SpotifyHeaders/HUBComponentView.h"
#import "SpotifyHeaders/HUBComponentRegistry.h"
#import "SpotifyHeaders/HUBComponentCollectionViewCell.h"
#import "SpotifyHeaders/HUBView.h"
#import "SpotifyHeaders/HUBViewController.h"
#import "SpotifyHeaders/SPTHubViewController.h"
#import "SpotifyHeaders/SPTHomeUIComponentLayoutManager.h"
#import "SpotifyHeaders/SPTFreeTierAlbumViewController.h"
#import "SpotifyHeaders/HUBContainerView.h"
#import "SpotifyHeaders/SPTHomeUIComponentLayoutManager.h"
#import "SpotifyHeaders/HUGSComponentLayoutManager.h"
#import "SpotifyHeaders/HUBComponentLayoutManager.h"*/

@class HUBContainerView, SPTask;

@protocol SPTCollectionPlatform, HUBViewModel, HUBComponentModel, HUBComponentLayoutManager, SPTFreeTierEntityFeedbackButtonViewModelDelegate, SPTFreeTierEntityFeedbackButtonViewModel, SPTContextMenuActionsProvider;

@protocol SPTUBIPageInstanceIdentifierProvider <NSObject>
@property(nonatomic, readonly) NSString *currentPageInstanceId;
@end

@protocol SPTUBIPageInstanceIdentifierManager <SPTUBIPageInstanceIdentifierProvider>
- (NSString *)invalidatePageInstanceId;
@end

@interface SPTUBIPageInstanceIdentifierManagerImplementation : NSObject

@property(readonly, copy, nonatomic) NSString *currentPageInstanceId; // @synthesize currentPageInstanceId;
- (id)invalidatePageInstanceId;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@protocol SPCallbackHolderParent <NSObject>
- (_Bool)isCancelled;
@end

@interface SPTCollectionPlatformFetchOptions : NSObject <NSCopying>
{
    _Bool _showsOnlyOfflinedContent;
    _Bool _showOnlyLocalFiles;
    _Bool _showOnlyPlayable;
    _Bool _groupByName;
    double _minimumUpdateInterval;
    NSArray *_sort;
    NSString *_textFilter;
    NSString *_customContentFilter;
    unsigned long long _followedArtistFilter;
    unsigned long long _mediaType;
    struct _NSRange _range;
}

@property(nonatomic) unsigned long long mediaType; // @synthesize mediaType=_mediaType;
@property(nonatomic) _Bool groupByName; // @synthesize groupByName=_groupByName;
@property(nonatomic) unsigned long long followedArtistFilter; // @synthesize followedArtistFilter=_followedArtistFilter;
@property(nonatomic) _Bool showOnlyPlayable; // @synthesize showOnlyPlayable=_showOnlyPlayable;
@property(nonatomic) _Bool showOnlyLocalFiles; // @synthesize showOnlyLocalFiles=_showOnlyLocalFiles;
@property(nonatomic) _Bool showsOnlyOfflinedContent; // @synthesize showsOnlyOfflinedContent=_showsOnlyOfflinedContent;
@property(copy, nonatomic) NSString *customContentFilter; // @synthesize customContentFilter=_customContentFilter;
@property(copy, nonatomic) NSString *textFilter; // @synthesize textFilter=_textFilter;
@property(copy, nonatomic) NSArray *sort; // @synthesize sort=_sort;
@property(nonatomic) struct _NSRange range; // @synthesize range=_range;
@property(nonatomic) double minimumUpdateInterval; // @synthesize minimumUpdateInterval=_minimumUpdateInterval;
- (id)description;
- (_Bool)isEqual:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)init;
- (void)applyFilterRules:(id)arg1;
- (void)applySortRules:(id)arg1;
- (void)applySortRule:(id)arg1;

@end

@protocol UBIEventLocation <NSObject>
@property(readonly, nonatomic) _Bool impressionEnabled;
@property(readonly, copy, nonatomic) NSArray *eventPathComponents;
@property(readonly, copy, nonatomic) NSString *mode;
@property(readonly, copy, nonatomic) NSString *annotatorConfigurationVersion;
@property(readonly, copy, nonatomic) NSString *annotatorVersion;
@property(readonly, copy, nonatomic) NSString *specificationVersion;
@property(readonly, copy, nonatomic) NSString *generatorVersion;
@property(readonly, copy, nonatomic) NSString *applicationId;
@end

@interface UBIEventLocation : NSObject <UBIEventLocation>
@property(readonly, nonatomic) _Bool impressionEnabled; // @synthesize impressionEnabled=_impressionEnabled;
@property(readonly, copy, nonatomic) NSArray *eventPathComponents; // @synthesize eventPathComponents=_eventPathComponents;
@property(readonly, copy, nonatomic) NSString *mode; // @synthesize mode=_mode;
@property(readonly, copy, nonatomic) NSString *annotatorConfigurationVersion; // @synthesize annotatorConfigurationVersion=_annotatorConfigurationVersion;
@property(readonly, copy, nonatomic) NSString *annotatorVersion; // @synthesize annotatorVersion=_annotatorVersion;
@property(readonly, copy, nonatomic) NSString *specificationVersion; // @synthesize specificationVersion=_specificationVersion;
@property(readonly, copy, nonatomic) NSString *generatorVersion; // @synthesize generatorVersion=_generatorVersion;
@property(readonly, copy, nonatomic) NSString *applicationId; // @synthesize applicationId=_applicationId;
- (_Bool)isEqualToUBIEventLocation:(id)arg1;
- (_Bool)isEqual:(id)arg1;
- (id)initWithLocation:(id)arg1;
- (id)initWithApplicationId:(id)arg1 generatorVersion:(id)arg2 specificationVersion:(id)arg3 annotatorVersion:(id)arg4 annotatorConfigurationVersion:(id)arg5 mode:(id)arg6 eventPathComponents:(id)arg7 impressionEnabled:(_Bool)arg8;
@property(readonly, copy) NSString *debugDescription;

// Remaining properties
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@protocol UBIInteractionEventLocation <UBIEventLocation>
@property(readonly, copy, nonatomic) NSString *interactionType;
@end

@interface UBIInteractionEventLocation : UBIEventLocation <UBIInteractionEventLocation>
@property(readonly, copy, nonatomic) NSString *interactionType; // @synthesize interactionType=_interactionType;
- (_Bool)isEqualToUBIInteractionEventLocation:(id)arg1;
- (_Bool)isEqual:(id)arg1;
- (id)initWithLocation:(id)arg1 interactionType:(id)arg2;
- (id)initWithInteractionLocation:(id)arg1;
- (id)initWithApplicationId:(id)arg1 generatorVersion:(id)arg2 specificationVersion:(id)arg3 annotatorVersion:(id)arg4 annotatorConfigurationVersion:(id)arg5 interactionType:(id)arg6 mode:(id)arg7 eventPathComponents:(id)arg8 impressionEnabled:(_Bool)arg9;
@property(readonly, copy) NSString *debugDescription;

// Remaining properties
@property(readonly, copy, nonatomic) NSString *annotatorConfigurationVersion;
@property(readonly, copy, nonatomic) NSString *annotatorVersion;
@property(readonly, copy, nonatomic) NSString *applicationId;
@property(readonly, copy) NSString *description;
@property(readonly, copy, nonatomic) NSArray *eventPathComponents;
@property(readonly, copy, nonatomic) NSString *generatorVersion;
@property(readonly, nonatomic) _Bool impressionEnabled;
@property(readonly, copy, nonatomic) NSString *mode;
@property(readonly, copy, nonatomic) NSString *specificationVersion;
@property(readonly) Class superclass;

@end

@protocol UBIEventAbsoluteLocation <NSObject>
@property(readonly, copy, nonatomic) NSArray *locations;
@end

@interface UBIEventAbsoluteLocation : NSObject <UBIEventAbsoluteLocation>
@property(readonly, copy, nonatomic) NSArray *locations; // @synthesize locations=_locations;
- (_Bool)isEqualToUBIEventAbsoluteLocation:(id)arg1;
- (_Bool)isEqual:(id)arg1;
- (id)initWithLocations:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@protocol UBIInteractionEvent <NSObject>
@property(readonly, copy, nonatomic) NSArray *errors;
@property(readonly, copy, nonatomic) NSDictionary *actionParameters;
@property(readonly, nonatomic) long long actionVersion;
@property(readonly, copy, nonatomic) NSString *action;
@property(readonly, nonatomic) UBIInteractionEventLocation *location;
@property(readonly, nonatomic) UBIEventAbsoluteLocation *parentAbsoluteLocation;
@end

@interface UBIInteractionEvent : NSObject <UBIInteractionEvent>
@property(readonly, copy, nonatomic) NSArray *errors; // @synthesize errors=_errors;
@property(readonly, copy, nonatomic) NSDictionary *actionParameters; // @synthesize actionParameters=_actionParameters;
@property(readonly, nonatomic) long long actionVersion; // @synthesize actionVersion=_actionVersion;
@property(readonly, copy, nonatomic) NSString *action; // @synthesize action=_action;
@property(readonly, nonatomic) UBIEventAbsoluteLocation *parentAbsoluteLocation; // @synthesize parentAbsoluteLocation=_parentAbsoluteLocation;
@property(readonly, nonatomic) UBIInteractionEventLocation *location; // @synthesize location=_location;
- (_Bool)isEqualToUBIInteractionEvent:(id)arg1;
- (_Bool)isEqual:(id)arg1;
- (id)initWithLocation:(id)arg1 parentAbsoluteLocation:(id)arg2 action:(id)arg3 actionVersion:(long long)arg4 actionParameters:(id)arg5 errors:(id)arg6;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@protocol UBIImpressionEvent <NSObject>
@property(readonly, copy, nonatomic) NSArray *errors;
@property(readonly, nonatomic) UBIEventLocation *location;
@property(readonly, nonatomic) UBIEventAbsoluteLocation *parentAbsoluteLocation;
@end

@interface UBIImpressionEvent : NSObject <UBIImpressionEvent>
@property(readonly, copy, nonatomic) NSArray *errors; // @synthesize errors=_errors;
@property(readonly, nonatomic) UBIEventLocation *location; // @synthesize location=_location;
@property(readonly, nonatomic) UBIEventAbsoluteLocation *parentAbsoluteLocation; // @synthesize parentAbsoluteLocation=_parentAbsoluteLocation;
- (_Bool)isEqualToUBIImpressionEvent:(id)arg1;
- (_Bool)isEqual:(id)arg1;
- (id)initWithLocation:(id)arg1 parentAbsoluteLocation:(id)arg2 errors:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@protocol SPTCollectionPlatformDataLoaderField <NSObject>
@end

@interface SPTCollectionPlatformDataLoaderResponse : NSObject
@property(copy, nonatomic) NSArray *sections; // @synthesize sections=_sections;
@property(copy, nonatomic) NSArray *sectionIndices; // @synthesize sectionIndices=_sectionIndices;
@property(nonatomic) unsigned long long availableOfflineStatus; // @synthesize availableOfflineStatus=_availableOfflineStatus;
@property(nonatomic) unsigned long long length; // @synthesize length=_length;
@property(nonatomic) unsigned long long unrangedLength; // @synthesize unrangedLength=_unrangedLength;
@property(nonatomic) unsigned long long unfilteredLength; // @synthesize unfilteredLength=_unfilteredLength;
@property(copy, nonatomic) NSArray *items; // @synthesize items=_items;

@end

@interface SPTCollectionPlatformDataLoaderFieldsFactory : NSObject

- (id)fieldsFactoryForEpisodes;
- (id)fieldsFactoryForPodcastMetadata;
- (id)fieldsFactoryForSectionIndex;
- (id)fieldsFactoryForTracks;
- (id)fieldsFactoryForArtistMetadata;
- (id)fieldsFactoryForAlbumMetadata;

@end

@protocol SPTCollectionPlatformDataLoaderRequestToken <NSObject>
- (void)cancel;
@end

@protocol SPTFreeTierAlbumFeedbackButtonViewModelLogger <NSObject>
- (void)logHitUnfollowForURI:(NSURL *)arg1;
- (void)logHitFollowForURI:(NSURL *)arg1;
@end


@protocol SPTEncoreItemCardLikablePlayableDelegate
- (void)playButtonTappedWithSender:(UIView *)arg1;
- (void)likeButtonTappedWithSender:(UIView *)arg1;
@end

@protocol SPTFreeTierEntityFeedbackButtonViewModelDelegate <NSObject>
- (void)viewModel:(id <SPTFreeTierEntityFeedbackButtonViewModel>)arg1 didUpdateState:(unsigned long long)arg2;
@end

@protocol SPTFreeTierEntityFeedbackButtonViewModel <NSObject>
@property(readonly, nonatomic) NSString *actionName;
@property(readonly, nonatomic) unsigned long long actionIcon;
@property(readonly, nonatomic) unsigned long long state;
@property(nonatomic) __weak id <SPTFreeTierEntityFeedbackButtonViewModelDelegate> delegate;
- (void)tapFeedbackButton;
@end


@protocol _TtP12EncoreMobile10EncoreView_
@property(nonatomic, readonly) UIView *uiView;
@end

@interface SPTTransparentAdjustableView : UIView
@property(retain, nonatomic) UIColor *sideBackgroundColor; // @synthesize sideBackgroundColor=_sideBackgroundColor;
@property(nonatomic) double transparenBackgroundOffset; // @synthesize transparenBackgroundOffset=_transparenBackgroundOffset;
- (void)clearSideBackgroundColor;
- (void)setSideBackgroundColor:(id)arg1 forTransparentBackgroundOffset:(double)arg2;
- (id)backgroundColor;
- (void)setBackgroundColor:(id)arg1;
- (void)drawRect:(struct CGRect)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)init;
@end

@interface SPTEncoreItemCardLikablePlayable : NSObject
- (id)init;
@property(nonatomic, readonly) UIView *uiView;
- (void)update:(id)arg1;
@property(nonatomic) __weak id <SPTEncoreItemCardLikablePlayableDelegate> delegate; // @synthesize delegate;

@end

@interface HUGSCustomViewControl : UIControl
@property(readonly, copy, nonatomic) id onSelectionChange; // @synthesize onSelectionChange=_onSelectionChange;
@property(readonly, copy, nonatomic) id onHighlightChange; // @synthesize onHighlightChange=_onHighlightChange;
@property(readonly, nonatomic) UIView *contentView; // @synthesize contentView=_contentView;
- (void)setSelected:(_Bool)arg1;
- (void)setHighlighted:(_Bool)arg1;
- (id)hitTest:(struct CGPoint)arg1 withEvent:(id)arg2;
- (id)initWithView:(id)arg1 onHighlightChange:(id)arg2 onSelectionChange:(id)arg3;
- (id)initWithStatefulView:(id)arg1;
@end

@interface SPTHubShelvesManager : NSObject <UIGestureRecognizerDelegate>
@end

@protocol SPTHubKeyboardManagerNavigationBarProvider <NSObject>
- (UINavigationBar *)provideNavigationBar;
@end


@protocol SPTHubImpressionLogger <NSObject>
- (void)logImpressionWithComponentModel:(id <HUBComponentModel>)arg1;
@end

@protocol SPTHubLoadingLogger <NSObject>
- (void)logLoadingCancelledWithDataSource:(unsigned long long)arg1;
- (void)logLoadingFailedWithDataSource:(unsigned long long)arg1;
- (void)logLoadingCompletedWithDataSource:(unsigned long long)arg1;
- (void)logLoadingStartedWithReason:(unsigned long long)arg1;
@end

@protocol HUBSerializable <NSObject>
- (NSDictionary *)serialize;
@end

@interface SPTCollectionPlatformDataLoaderFieldsImplementation : NSObject
@property(nonatomic) unsigned long long availableOfflineStatus; // @synthesize availableOfflineStatus=_availableOfflineStatus;
@property(retain, nonatomic) NSURL *imageURL; // @synthesize imageURL=_imageURL;
@property(retain, nonatomic) NSURL *URL; // @synthesize URL=_URL;
@property(copy, nonatomic) NSString *name; // @synthesize name=_name;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end


@protocol HUBIcon
- (UIImage *)imageWithSize:(struct CGSize)arg1 color:(UIColor *)arg2;
@property(nonatomic, readonly) NSString *identifier;
@end

@interface SPTHubKeyboardManager : NSObject
@property(readonly, nonatomic) HUBContainerView *containerView; // @synthesize containerView=_containerView;
@property(readonly, nonatomic) __weak id <SPTHubKeyboardManagerNavigationBarProvider> navigationBarProvider; // @synthesize navigationBarProvider=_navigationBarProvider;
- (unsigned long long)animationOptionsWithCurve:(long long)arg1;
- (void)setUpOverlayWithTheKeyboardNotification:(id)arg1;
- (void)handleKeyboardWillChangeNotification:(id)arg1;
- (void)unregisterNotificationObservers;
- (void)registerNotificationObservers;
- (id)initWithNavigationBarProvider:(id)arg1 containerView:(id)arg2;
@end

@protocol HUBComponentImageData <HUBSerializable>
@property(nonatomic, readonly) NSDictionary *customData;
@property(nonatomic, readonly) UIImage *localImage;
@property(nonatomic, readonly) id <HUBIcon> placeholderIcon;
@property(nonatomic, readonly) NSURL *URL;
@property(nonatomic, readonly) long long type;
@property(nonatomic, readonly) NSString *identifier;
@end


@protocol HUBComponentTarget <HUBSerializable>
@property(readonly, copy, nonatomic) NSDictionary *customData;
@property(readonly, nonatomic) NSArray *actionIdentifiers;
@property(readonly, nonatomic) id <HUBViewModel> initialViewModel;
@property(readonly, copy, nonatomic) NSURL *URI;
@end

@interface HUBIdentifier : NSObject <NSCopying>
@property(readonly, copy, nonatomic) NSString *namePart; // @synthesize namePart=_namePart;
@property(readonly, copy, nonatomic) NSString *namespacePart; // @synthesize namespacePart=_namespacePart;
- (id)description;
- (unsigned long long)hash;
- (_Bool)isEqual:(id)arg1;
- (_Bool)isEqualToIdentifier:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
@property(readonly, copy, nonatomic) NSString *identifierString;
- (id)initWithString:(id)arg1;
- (id)initWithNamespace:(id)arg1 name:(id)arg2;
@end

@protocol HUBComponentModel <HUBSerializable>
- (NSArray *)childrenInGroupWithIdentifier:(NSString *)arg1;
- (id <HUBComponentModel>)childWithIdentifier:(NSString *)arg1;
- (id <HUBComponentModel>)childAtIndex:(unsigned long long)arg1;
@property(nonatomic, readonly) NSArray *children;
@property(nonatomic, readonly) id <HUBComponentModel> parent;
@property(nonatomic, readonly) NSDictionary *customData;
@property(nonatomic, readonly) NSDictionary *loggingData;
@property(nonatomic, readonly) NSDictionary *metadata;
@property(nonatomic, readonly) NSDictionary *events;
@property(nonatomic, readonly) id <HUBComponentTarget> target;
@property(nonatomic, readonly) id <HUBIcon> icon;
@property(nonatomic, readonly) NSDictionary *customImageData;
@property(nonatomic, readonly) id <HUBComponentImageData> backgroundImageData;
@property(nonatomic, readonly) id <HUBComponentImageData> mainImageData;
@property(nonatomic, readonly) NSString *descriptionText;
@property(nonatomic, readonly) NSString *accessoryTitle;
@property(nonatomic, readonly) NSString *subtitle;
@property(nonatomic, readonly) NSString *title;
@property(nonatomic, readonly) NSString *componentCategory;
@property(nonatomic, readonly) HUBIdentifier *componentIdentifier;
@property(nonatomic, readonly) NSString *groupIdentifier;
@property(nonatomic, readonly) unsigned long long index;
@property(nonatomic, readonly) unsigned long long type;
@property(nonatomic, readonly) NSString *identifier;
@end

@interface HUBComponentModelImplementation : NSObject
@property(copy, nonatomic) NSDictionary *childrenByGroupIdentifier; // @synthesize childrenByGroupIdentifier=_childrenByGroupIdentifier;
@property(copy, nonatomic) NSDictionary *childIdentifierToIndexMap; // @synthesize childIdentifierToIndexMap=_childIdentifierToIndexMap;
@property(copy, nonatomic) NSArray *children; // @synthesize children=_children;
//@property(readonly, nonatomic) __weak id <HUBComponentModel> parent; // @synthesize parent=_parent;
@property(readonly, copy, nonatomic) NSDictionary *customData; // @synthesize customData=_customData;
@property(readonly, copy, nonatomic) NSDictionary *loggingData; // @synthesize loggingData=_loggingData;
@property(readonly, copy, nonatomic) NSDictionary *metadata; // @synthesize metadata=_metadata;
@property(readonly, copy, nonatomic) NSDictionary *events; // @synthesize events=_events;
//@property(readonly, nonatomic) id <HUBComponentTarget> target; // @synthesize target=_target;
//@property(readonly, nonatomic) id <HUBIcon> icon; // @synthesize icon=_icon;
@property(readonly, copy, nonatomic) NSDictionary *customImageData; // @synthesize customImageData=_customImageData;
//@property(readonly, nonatomic) id <HUBComponentImageData> backgroundImageData; // @synthesize backgroundImageData=_backgroundImageData;
//@property(readonly, nonatomic) id <HUBComponentImageData> mainImageData; // @synthesize mainImageData=_mainImageData;
@property(readonly, copy, nonatomic) NSString *descriptionText; // @synthesize descriptionText=_descriptionText;
@property(readonly, copy, nonatomic) NSString *accessoryTitle; // @synthesize accessoryTitle=_accessoryTitle;
@property(readonly, copy, nonatomic) NSString *subtitle; // @synthesize subtitle=_subtitle;
@property(readonly, copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(readonly, copy, nonatomic) NSString *componentCategory; // @synthesize componentCategory=_componentCategory;
@property(readonly, copy, nonatomic) HUBIdentifier *componentIdentifier; // @synthesize componentIdentifier=_componentIdentifier;
@property(readonly, copy, nonatomic) NSString *groupIdentifier; // @synthesize groupIdentifier=_groupIdentifier;
@property(readonly, nonatomic) unsigned long long index; // @synthesize index=_index;
@property(readonly, nonatomic) unsigned long long type; // @synthesize type=_type;
@property(readonly, copy, nonatomic) NSString *identifier; // @synthesize identifier=_identifier;
- (id)serializedChildren;
- (id)serializedEvents;
- (id)serializedImageData;
- (id)serializedTextData;
- (id)serializedComponentData;
- (id)childrenInGroupWithIdentifier:(id)arg1;
- (id)childWithIdentifier:(id)arg1;
- (id)childAtIndex:(unsigned long long)arg1;
- (id)serialize;
@property(readonly, copy) NSString *debugDescription;
- (_Bool)isEqual:(id)arg1;
- (id)valueForKey:(id)arg1;
- (id)initWithIdentifier:(id)arg1 type:(unsigned long long)arg2 index:(unsigned long long)arg3 groupIdentifier:(id)arg4 componentIdentifier:(id)arg5 componentCategory:(id)arg6 title:(id)arg7 subtitle:(id)arg8 accessoryTitle:(id)arg9 descriptionText:(id)arg10 mainImageData:(id)arg11 backgroundImageData:(id)arg12 customImageData:(id)arg13 icon:(id)arg14 target:(id)arg15 events:(id)arg16 metadata:(id)arg17 loggingData:(id)arg18 customData:(id)arg19 parent:(id)arg20;

// Remaining properties
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@protocol HUBViewModelBuilder
@end

@protocol HUBViewModel
- (id <HUBViewModelBuilder>)createBuilder;
@property(nonatomic, readonly) NSDate *buildDate;
@property(nonatomic, readonly) NSDictionary *customData;
@property(nonatomic, readonly) NSArray *overlayComponentModels;
@property(nonatomic, readonly) NSArray *bodyComponentModels;
@property(nonatomic, readonly) id <HUBComponentModel> headerComponentModel;
@property(nonatomic, readonly) NSString *navigationBarTitle;
@property(nonatomic, readonly) NSString *identifier;
@end

@protocol SPTShareCroppableDragPreview <NSObject>
@property(copy, nonatomic) id dragPreviewCropRectBlock;
@end

@protocol SPTShareDragDelegateFactory <NSObject>
@end

@interface SPTReaderWriterMutableDictionary : NSMutableDictionary
+ (_Bool)supportsSecureCoding;
@property(readonly, nonatomic) NSMutableDictionary *dictionary; // @synthesize dictionary=_dictionary;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(id)arg1;
- (void)removeObjectForKey:(id)arg1;
- (void)setObject:(id)arg1 forKey:(id)arg2;
- (id)initWithCapacity:(unsigned long long)arg1;
- (id)objectForKey:(id)arg1;
- (id)keyEnumerator;
- (unsigned long long)count;
- (id)initWithObjects:(const id *)arg1 forKeys:(const id *)arg2 count:(unsigned long long)arg3;
- (id)init;
- (void)commonInit;
@end

@protocol SPTThemeConfigurationResolver <NSObject>
@property(readonly, nonatomic) NSSet *suffixes;
@property(readonly, nonatomic) NSDictionary *configuration;
@property(readonly, nonatomic) __weak NSDictionary *flags;
- (NSSet *)dependentKeysOfKeys:(NSSet *)arg1;
- (id)configurationValueForKey:(NSString *)arg1 reportErrors:(_Bool)arg2;
- (NSSet *)setFlag:(NSString *)arg1 enabled:(_Bool)arg2 priority:(unsigned long long)arg3;
- (NSSet *)registerConfigurationDictionary:(NSDictionary *)arg1 overridingCurrentValues:(_Bool)arg2;
- (NSSet *)registerConfigurationFromFileNamed:(NSString *)arg1 inBundle:(NSBundle *)arg2;
- (id)initWithSuffixes:(NSSet *)arg1;
@end

@interface SPTTheme : NSObject
+ (const char *)typeEncodingForSelector:(SEL)arg1;
+ (_Bool)resolveInstanceMethod:(SEL)arg1;
+ (void)loadFonts;
+ (id)binaryThemeWithPlist:(id)arg1;
+ (id)loadBinaryThemeConfiguration;
+ (void)setupTheme:(id)arg1 withThemeConfiguration:(id)arg2;
+ (id)createThemeWithThemeConfiguration:(id)arg1;
+ (void)setUpCatTheme;
+ (void)preloadCatThemeAndWait;
+ (void)preloadCatTheme;
+ (id)catThemeConfiguration;
+ (id)catTheme;
@property(retain, nonatomic) SPTReaderWriterMutableDictionary *resolvedFonts; // @synthesize resolvedFonts=_resolvedFonts;
@property(retain, nonatomic) id <SPTThemeConfigurationResolver> fontResolver; // @synthesize fontResolver=_fontResolver;
- (id)intervalForKey:(id)arg1 reportErrors:(_Bool)arg2;
- (id)resolveIntervalForKey:(id)arg1;
- (id)edgeInsetsForKey:(id)arg1 reportErrors:(_Bool)arg2;
- (id)resolveEdgeInsetsForKey:(id)arg1;
- (id)sizeForKey:(id)arg1 reportErrors:(_Bool)arg2;
- (id)resolveSizeForKey:(id)arg1;
- (id)pointForKey:(id)arg1 reportErrors:(_Bool)arg2;
- (id)resolvePointForKey:(id)arg1;
- (id)metricForKey:(id)arg1 reportErrors:(_Bool)arg2;
- (id)resolveMetricForKey:(id)arg1;
- (id)fontForKey:(id)arg1 reportErrors:(_Bool)arg2;
- (id)resolveFontForKey:(id)arg1;
- (id)colorForKey:(id)arg1 reportErrors:(_Bool)arg2;
- (id)resolveColorForKey:(id)arg1;
- (void)reportConfigurationErrorForKind:(id)arg1 expectedType:(id)arg2 key:(id)arg3 value:(id)arg4;
- (double)undefinedInterval;
- (struct UIEdgeInsets)undefinedInsets;
- (struct CGSize)undefinedSize;
- (struct CGPoint)undefinedPoint;
- (double)undefinedMetric;
- (id)undefinedFont;
- (id)undefinedColor;
- (void)noteFlagSettingsChanged:(id)arg1;
- (void)noteMetricsSettingsChanged:(id)arg1 postSettingsChanged:(_Bool)arg2;
- (void)noteFontSettingsChanged:(id)arg1 postSettingsChanged:(_Bool)arg2;
- (void)noteColorSettingsChanged:(id)arg1 postSettingsChanged:(_Bool)arg2;
- (void)postSettingsChanged;
- (void)endUpdate;
- (void)beginUpdate;
- (_Bool)isFlagEnabled:(id)arg1;
- (void)setFlag:(id)arg1 enabled:(_Bool)arg2;
- (void)setFlag:(id)arg1 enabled:(_Bool)arg2 priority:(unsigned long long)arg3;
- (void)registerMetricsDictionary:(id)arg1;
- (void)registerMetricsDictionaryFromFileNamed:(id)arg1;
- (void)registerFontDictionary:(id)arg1;
- (void)registerFontDictionaryFromFileNamed:(id)arg1;
- (void)registerColorDictionary:(id)arg1;
- (void)registerColorDictionaryFromFileNamed:(id)arg1;
- (id)debugDescription;
- (void)dealloc;
- (id)initWithColorResolver:(id)arg1 fontResolver:(id)arg2 metricsResolver:(id)arg3;
- (id)init;
@end


@interface HUBComponentRegistry : NSObject
@property(retain, nonatomic) NSMutableDictionary *internalRegistry; // @synthesize internalRegistry=_internalRegistry;
- (id)component:(id)arg1 childComponentForModel:(id)arg2;
- (void)unregisterComponentsForNamespace:(id)arg1;
- (void)registerComponents:(id)arg1 forNamespace:(id)arg2;
- (id)componentForModel:(id)arg1;
- (id)initWithFallbackHandler:(id)arg1;
@property(readonly, nonatomic) NSDictionary *registeredComponents;
@end

@interface UIView (EncoreMobile)
+ (id)glue_lottieAnimationStylerForAnimationView:(id)arg1;
+ (id)glue_createStatefulAnimationView;
+ (id)glue_createAnimationViewWithName:(id)arg1;
+ (id)glue_createAnimationView;
+ (void)glue_animateWithDuration:(double)arg1 animations:(id)arg2 degradationPolicy:(unsigned long long)arg3;
+ (void)glue_animateWithDuration:(double)arg1 animations:(id)arg2 completion:(id)arg3 degradationPolicy:(unsigned long long)arg4;
+ (void)glue_animateWithDuration:(double)arg1 delay:(double)arg2 options:(unsigned long long)arg3 animations:(id)arg4 completion:(id)arg5 degradationPolicy:(unsigned long long)arg6;
+ (double)glue_maxViewWidthForReadableContentGuide;
+ (id)glue_newForConstraints;
+ (_Bool)spt_isRTL;
@property(nonatomic, readonly) UIView *uiView;
@property(nonatomic, readonly) UIView *playButton;
@property(nonatomic, readonly) UIButton *downloadButton;
@property(nonatomic, copy) NSString *className;
@property(nonatomic) double linkPreviewBorderWidth;
@property(nonatomic, retain) UIColor *linkPreviewBorderColor;
@property(nonatomic, retain) UIColor *borderColor;
@property(nonatomic) double borderWidth;
@property(nonatomic) double cornerRadius;
- (struct CGSize)encore_systemLayoutSizeFittingSize:(struct CGSize)arg1 withHorizontalFittingPriority:(float)arg2 verticalFittingPriority:(float)arg3;
- (struct CGSize)encore_systemLayoutSizeFittingSize:(struct CGSize)arg1;
@property(readonly, nonatomic) struct UIEdgeInsets glue_layoutMarginsForReadableContentGuide;
- (id)glue_constrainHorizontallyWithinReadableContentGuideForContainer:(id)arg1 withMargin:(double)arg2 activate:(_Bool)arg3;
- (id)glue_constrainHorizontallyWithinReadableContentGuideForContainer:(id)arg1 activate:(_Bool)arg2;
- (id)glue_constrainHorizontallyWithinReadableContentGuideForContainer:(id)arg1;
- (id)glue_constrainHorizontallyWithinContainer:(id)arg1 withMargin:(double)arg2 activate:(_Bool)arg3;
- (id)glue_constrainHorizontallyWithinContainer:(id)arg1 withMargin:(double)arg2;
- (id)glue_constrainHorizontallyWithinContainer:(id)arg1 activate:(_Bool)arg2;
- (id)glue_constrainHorizontallyWithinContainer:(id)arg1;
- (id)glue_constrainWithinReadableContentGuideForContainer:(id)arg1 withInsets:(struct UIEdgeInsets)arg2 activate:(_Bool)arg3;
- (id)glue_constrainWithinReadableContentGuideForContainer:(id)arg1 activate:(_Bool)arg2;
- (id)glue_constrainWithinReadableContentGuideForContainer:(id)arg1;
- (id)glue_constrainWithinContainer:(id)arg1 withInsets:(struct UIEdgeInsets)arg2 activate:(_Bool)arg3;
- (id)glue_constrainWithinContainer:(id)arg1 withInsets:(struct UIEdgeInsets)arg2;
- (id)glue_constrainWithinContainer:(id)arg1 withMargin:(double)arg2 activate:(_Bool)arg3;
- (id)glue_constrainWithinContainer:(id)arg1 withMargin:(double)arg2;
- (id)glue_constrainWithinContainer:(id)arg1 activate:(_Bool)arg2;
- (id)glue_constrainWithinContainer:(id)arg1;
@property(readonly, nonatomic) UILayoutGuide *glue_readableContentGuide;
- (id)glue_readableContentGuide_internal;
@property(readonly, nonatomic, getter=glue_compatibleSafeGuide) UILayoutGuide *compatibleSafeGuide;
- (id)sp_subviewWithAccessibilityIdentifier:(id)arg1 recursive:(_Bool)arg2;
@property(nonatomic, getter=spt_isEligibleForTransition) _Bool spt_eligibleForTransition;
- (void)keyboardWillHide:(id)arg1;
- (void)keyboardWillShow:(id)arg1;
- (void)unsubscribeToKeyboardWillShowWillHideNotifications;
- (void)subscribeToKeyboardWillShowWillHideNotifications;
- (void)shakeView;
- (id)spt_podcastUIRoundedCornerMaskLayerForViewRect:(struct CGRect)arg1 cornerRadius:(double)arg2;
- (id)spt_imageRepresentation;
@property(readonly, nonatomic, getter=spt_isRTL) _Bool isRTL;
- (void)spt_centerVertically;
- (void)spt_centerHorizontally;
@property(nonatomic, getter=spt_frameHeight, setter=spt_setFrameHeight:) double frameHeight;
@property(nonatomic, getter=spt_frameWidth, setter=spt_setFrameWidth:) double frameWidth;
@property(nonatomic, getter=spt_frameBottom, setter=spt_setFrameBottom:) double frameBottom;
@property(nonatomic, getter=spt_frameRight, setter=spt_setFrameRight:) double frameRight;
@property(nonatomic, getter=spt_frameY, setter=spt_setFrameY:) double frameY;
@property(nonatomic, getter=spt_frameX, setter=spt_setFrameX:) double frameX;
@property(nonatomic, getter=spt_frameSize, setter=spt_setFrameSize:) struct CGSize frameSize;
@property(nonatomic, getter=spt_frameOrigin, setter=spt_setFrameOrigin:) struct CGPoint frameOrigin;
- (id)sp_screenshot;
- (id)sp_screenshot:(double)arg1;
- (id)spt_findNextResponderOfClass:(Class)arg1;
- (id)spt_viewController;
- (void)sp_removeSubviewsOfClass:(Class)arg1;
- (id)sp_firstResponder;
- (id)sp_subviewWithClass:(Class)arg1 recursive:(_Bool)arg2;
- (id)sp_subviewWithClass:(Class)arg1;
- (id)sp_superviewWithClass:(Class)arg1;
- (_Bool)sp_isOrHasSuperviewOfClass:(Class)arg1;
- (void)visref_removeAllSubviews;
@end

@interface HUBComponentView : UIView
+ (_Bool)percentage:(double)arg1 ofComponentView:(id)arg2 isVisibleInContext:(id)arg3;
//@property(retain, nonatomic) id <HUBComponent> component; // @synthesize component=_component;
//@property(retain, nonatomic) HUBContext *context; // @synthesize context=_context;
//@property(retain, nonatomic) id <HUBComponentModel> model; // @synthesize model=_model;
- (struct CGSize)preferredSizeForContainerViewSize:(struct CGSize)arg1;
- (void)prepareForReuse;
- (void)configureWithModel:(id)arg1;
- (void)hub_setupAccessibility;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;
@end

@interface SPTSwipeableTableViewCell : UITableViewCell
+ (long long)gestureFromTranslation:(double)arg1;
+ (long long)gestureFromPercentage:(double)arg1;
@property(retain, nonatomic) NSMutableDictionary *shelvesForGesture; // @synthesize shelvesForGesture=_shelvesForGesture;
@property(retain, nonatomic) NSMutableDictionary *shelveModelsForGesture; // @synthesize shelveModelsForGesture=_shelveModelsForGesture;
@property(nonatomic, getter=isGestureActivated) _Bool gestureActivated; // @synthesize gestureActivated=_gestureActivated;
@property(nonatomic) long long initialGesture; // @synthesize initialGesture=_initialGesture;
@property(retain, nonatomic) UIView *containerView; // @synthesize containerView=_containerView;
@property(retain, nonatomic) SPTTransparentAdjustableView *shelvesView; // @synthesize shelvesView=_shelvesView;
@property(nonatomic) double currentTime; // @synthesize currentTime=_currentTime;
@property(nonatomic) double initialTime; // @synthesize initialTime=_initialTime;
@property(nonatomic) struct CGPoint currentTranslation; // @synthesize currentTranslation=_currentTranslation;
@property(nonatomic) struct CGPoint initialTranslation; // @synthesize initialTranslation=_initialTranslation;
@property(nonatomic) long long ongoingGesture; // @synthesize ongoingGesture=_ongoingGesture;
//@property(nonatomic) __weak id <SPTSwipeableTableViewCellDelegate> swipeDelegate; // @synthesize swipeDelegate=_swipeDelegate;
- (_Bool)supportsSwiping;
- (void)handlePanGestureRecognizer:(id)arg1;
- (void)resetContainerFromPoint:(struct CGPoint)arg1 subjectToInertia:(_Bool)arg2 horizontalVelocity:(double)arg3 withCompletionBlock:(id)arg4;
- (void)resetShelves;
- (void)moveContainerWithHorizontalTranslation:(double)arg1 horizontalVelocity:(double)arg2;
- (double)percentageFromOffset:(double)arg1;
- (long long)shelfPositionFromGesture:(long long)arg1;
- (long long)gestureFromShelfPosition:(long long)arg1;
- (void)configureShelf:(id)arg1 forGesture:(long long)arg2;
- (id)shelfForOffset:(double)arg1;
- (id)oppositeShelfForGesture:(long long)arg1;
- (id)shelfForGesture:(long long)arg1;
- (void)setShelfModel:(id)arg1 atPosition:(long long)arg2;
- (id)shelfModelAt:(long long)arg1;
- (void)setSelected:(_Bool)arg1 animated:(_Bool)arg2;
- (void)setHighlighted:(_Bool)arg1 animated:(_Bool)arg2;
- (void)setBackgroundView:(id)arg1;
- (void)setBackgroundColor:(id)arg1;
- (void)prepareForReuse;
- (void)layoutSubviews;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;
@end

@interface SPTEncoreSwipeableTableViewCell : SPTSwipeableTableViewCell
- (id)initWithCoder:(id)arg1;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;
- (void)setHighlighted:(_Bool)arg1 animated:(_Bool)arg2;
@property(nonatomic, copy) id onHighlight;
@end

@interface HUBComponentCollectionViewCell : UICollectionViewCell
@property(retain, nonatomic) HUBComponentView *componentView; // @synthesize componentView=_componentView;
@property(readonly, nonatomic) NSUUID *identifier; // @synthesize identifier=_identifier;
- (void)layoutSubviews;
- (void)prepareForReuse;
- (id)initWithFrame:(struct CGRect)arg1;
@end


@interface HUBComponentViewManager : NSObject
@property(readonly, nonatomic) HUBComponentRegistry *componentRegistry; // @synthesize componentRegistry=_componentRegistry;
- (void)componentView:(id)arg1 didEndDisplayingChildComponentView:(id)arg2;
- (void)componentView:(id)arg1 willDisplayChildComponentView:(id)arg2;
- (id)componentView:(id)arg1 childComponentViewForModel:(id)arg2;
- (void)restoreComponentUIStateForComponentView:(id)arg1;
- (void)saveComponentUIStateForComponentView:(id)arg1;
- (void)componentViewDidDisappear:(id)arg1;
- (void)componentViewWillAppear:(id)arg1;
- (id)createComponentViewForModel:(id)arg1 containerViewSize:(struct CGSize)arg2;
- (id)initWithComponentRegistry:(id)arg1 componentEventHandler:(id)arg2;
@end

@interface HUBCollectionViewLayout : UICollectionViewLayout
@property(nonatomic) struct CGSize contentSize; // @synthesize contentSize=_contentSize;
@property(readonly, nonatomic) NSMutableDictionary *layoutAttributesByIndexPath; // @synthesize layoutAttributesByIndexPath=_layoutAttributesByIndexPath;
@property(nonatomic) _Bool adjustsTargetContentOffset; // @synthesize adjustsTargetContentOffset=_adjustsTargetContentOffset;
- (id)finalLayoutAttributesForDisappearingItemAtIndexPath:(id)arg1;
- (id)initialLayoutAttributesForAppearingItemAtIndexPath:(id)arg1;
- (id)layoutTraitsForComponentAtIndexPath:(id)arg1;
- (struct CGSize)preferredSizeForComponentAtIndexPath:(id)arg1 containerViewSize:(struct CGSize)arg2;
- (void)updateLayoutAttributesForComponentsTraits:(id)arg1 horizontalAdjustment:(double)arg2 lastComponentIndex:(long long)arg3;
- (void)updateLayoutAttributesForComponentsTraitsIfNeeded:(id)arg1 lastComponentIndex:(long long)arg2 firstComponentX:(double)arg3 lastComponentX:(double)arg4 rowWidth:(double)arg5;
- (struct CGSize)contentSizeForContentHeight:(double)arg1 bottomRowComponentTraits:(id)arg2 minimumBottomMargin:(double)arg3 collectionViewSize:(struct CGSize)arg4;
- (void)registerComponentViewFrame:(struct CGRect)arg1 forIndexPath:(id)arg2;
- (struct CGRect)horizontallyAdjustComponentViewFrame:(struct CGRect)arg1 forCollectionViewSize:(struct CGSize)arg2 margins:(struct UIEdgeInsets)arg3;
- (struct UIEdgeInsets)containerEdgeInsetsForComponentWithLayoutTraits:(id)arg1 collectionViewSize:(struct CGSize)arg2;
- (double)rightMarginForComponontWithLayoutTraits:(id)arg1 containerEdgeInsets:(struct UIEdgeInsets)arg2;
- (double)leftMarginForComponontWithLayoutTraits:(id)arg1 containerEdgeInsets:(struct UIEdgeInsets)arg2;
- (struct UIEdgeInsets)defaultMarginsForLayoutTraits:(id)arg1 isInTopRow:(_Bool)arg2 layoutTraitsOnCurrentRow:(id)arg3 containerEdgeInsets:(struct UIEdgeInsets)arg4;
- (struct CGSize)collectionViewContentSize;
- (_Bool)shouldInvalidateLayoutForBoundsChange:(struct CGRect)arg1;
- (id)layoutAttributesForItemAtIndexPath:(id)arg1;
- (id)layoutAttributesForElementsInRect:(struct CGRect)arg1;
- (_Bool)flipsHorizontallyInOppositeLayoutDirection;
- (struct CGPoint)targetContentOffsetForProposedContentOffset:(struct CGPoint)arg1;
- (void)prepareLayout;
- (id)initWithComponentLayoutManager:(id)arg1;
@end

@interface HUBView : UIView
@property(retain, nonatomic) HUBCollectionViewLayout *collectionViewLayout; // @synthesize collectionViewLayout=_collectionViewLayout;
@property(readonly, nonatomic) NSHashTable *contentOffsetObservers; // @synthesize contentOffsetObservers=_contentOffsetObservers;
@property(readonly, nonatomic) NSHashTable *visibleContentOffsetObservingComponentViews; // @synthesize visibleContentOffsetObservingComponentViews=_visibleContentOffsetObservingComponentViews;
@property(readonly, nonatomic) HUBComponentViewManager *componentViewManager; // @synthesize componentViewManager=_componentViewManager;
@property(readonly, nonatomic) UICollectionView *contentView; // @synthesize contentView=_contentView;
@property(nonatomic) _Bool useDiffingOnComponentModelChanges; // @synthesize useDiffingOnComponentModelChanges=_useDiffingOnComponentModelChanges;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;
@end

@interface HUBViewController : UIViewController
@end

@interface SPTHubViewModelProvider : NSObject
- (void)viewModelLoader:(id)arg1 didFailLoadingWithError:(id)arg2;
- (void)viewModelLoader:(id)arg1 didLoadViewModel:(id)arg2;
- (void)loadViewModel;
- (id)initWithViewModelLoader:(id)arg1;
@end

@interface SPTHubViewController : HUBViewController
@property(retain, nonatomic) id <SPTShareDragDelegateFactory> shareDragDelegateFactory; // @synthesize shareDragDelegateFactory=_shareDragDelegateFactory;
@property(retain, nonatomic) id <HUBViewModel> initialViewModel; // @synthesize initialViewModel=_initialViewModel;
@property(nonatomic) _Bool wasInitialLoadViewModelPerformed; // @synthesize wasInitialLoadViewModelPerformed=_wasInitialLoadViewModelPerformed;
@property(readonly, nonatomic) id <SPTHubLoadingLogger> loadingLogger; // @synthesize loadingLogger=_loadingLogger;
@property(readonly, nonatomic) id <SPTHubImpressionLogger> impressionLogger; // @synthesize impressionLogger=_impressionLogger;
@property(retain, nonatomic) SPTHubKeyboardManager *keyboardManager; // @synthesize keyboardManager=_keyboardManager;
@property(readonly, nonatomic) SPTTheme *theme; // @synthesize theme=_theme;
@property(retain, nonatomic) SPTHubShelvesManager *shelvesManager; // @synthesize shelvesManager=_shelvesManager;
@property(retain, nonatomic) NSMutableDictionary *dragDelegateHolders; // @synthesize dragDelegateHolders=_dragDelegateHolders;
@property(nonatomic) unsigned long long viewModelLoadingType; // @synthesize viewModelLoadingType=_viewModelLoadingType;
@property(nonatomic) unsigned long long preferredNavigationBarState; // @synthesize preferredNavigationBarState=_preferredNavigationBarState;
@property(readonly, nonatomic) SPTHubViewModelProvider *viewModelProvider; // @synthesize viewModelProvider=_viewModelProvider;
@property(readonly, copy, nonatomic) NSURL *viewURI; // @synthesize viewURI=_viewURI;
@property(readonly, nonatomic, getter=spt_pageIdentifier) NSString *pageIdentifier; // @synthesize pageIdentifier=_pageIdentifier;
- (id)shareDragDelegateWithModel:(id)arg1;
- (void)installViewModel:(id)arg1;
- (void)loadViewModel;
- (id)provideNavigationBar;
- (void)sp_updateContentInsets;
- (void)overlayView:(id)arg1 componentViewDidDisappear:(id)arg2;
- (void)overlayView:(id)arg1 componentViewWillAppear:(id)arg2;
- (_Bool)hubViewShouldStartScrolling:(id)arg1;
- (void)hubView:(id)arg1 componentViewDidDisappear:(id)arg2;
- (void)hubView:(id)arg1 componentViewWillAppear:(id)arg2;
- (void)headerView:(id)arg1 componentViewDidDisappear:(id)arg2;
- (void)headerView:(id)arg1 componentViewWillAppear:(id)arg2;
- (void)viewModelDidLoad:(id)arg1 dataSource:(unsigned long long)arg2;
- (void)viewModelDidLoad:(id)arg1;
@property(readonly, copy, nonatomic, getter=spt_pageURI) NSURL *pageURI;
- (void)enableShelves:(id)arg1 componentModelURIResolver:(id)arg2;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)viewWillAppear:(_Bool)arg1;
- (id)initWithTheme:(id)arg1 pageIdentifier:(id)arg2 pageURI:(id)arg3 componentRegistry:(id)arg4 componentLayoutManager:(id)arg5 imageLoaderFactory:(id)arg6 commandHandler:(id)arg7 viewModelProvider:(id)arg8 impressionLogger:(id)arg9 loadingLogger:(id)arg10 shareDragDelegateFactory:(id)arg11;
- (id)initWithTheme:(id)arg1 pageIdentifier:(id)arg2 pageURI:(id)arg3 componentRegistry:(id)arg4 componentLayoutManager:(id)arg5 imageLoaderFactory:(id)arg6 commandHandler:(id)arg7 viewModelProvider:(id)arg8 initialViewModel:(id)arg9 impressionLogger:(id)arg10 loadingLogger:(id)arg11 shareDragDelegateFactory:(id)arg12;
- (id)initWithTheme:(id)arg1 pageIdentifier:(id)arg2 pageURI:(id)arg3 containerViewFactory:(id)arg4 viewModelProvider:(id)arg5 initialViewModel:(id)arg6 impressionLogger:(id)arg7 loadingLogger:(id)arg8 shareDragDelegateFactory:(id)arg9;
- (void)spt_scrollToTopAnimated:(_Bool)arg1;
- (void)spt_scrollToTop;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;
@end

@interface SPTFreeTierAlbumViewModel : NSObject
@property(readonly, copy, nonatomic) NSURL *albumURL; // @synthesize albumURL=_albumURL;
@property(readonly, copy, nonatomic) NSString *albumName; // @synthesize albumName=_albumName;
@property(readonly, copy, nonatomic) NSString *artistName; // @synthesize artistName=_artistName;
@property(readonly, copy, nonatomic) NSArray *albumTracks; // @synthesize albumTracks=_albumTracks;
- (void)updateModelWithTracksURIs:(id)arg1 albumName:(id)arg2 artistName:(id)arg3;
- (id)initWithAlbumURL:(id)arg1;

@end

@interface SPTaskCompletionSource : NSObject
- (void)cancel;
- (void)addCancellationCallback:(id)arg1;
- (id)resolver;
- (id)voidResolver;
- (void)completeWithTask:(id)arg1;
- (void)failWithError:(id)arg1;
- (void)completeWithValue:(id)arg1;
- (id)task;
- (id)init;

@end

@protocol SPTContextMenuActionsProvider <NSObject>
- (NSArray *)actionsForTrackURL:(NSURL *)arg1 name:(NSString *)arg2 metadata:(NSDictionary *)arg3 playable:(_Bool)arg4 imageURL:(NSURL *)arg5 artists:(NSArray *)arg6 albumName:(NSString *)arg7 albumURL:(NSURL *)arg8 viewURL:(NSURL *)arg9 logContext:(NSString *)arg10 contextSourceURL:(NSURL *)arg11;
- (SPTask *)actionForURIs:(NSArray *)arg1 logContext:(NSString *)arg2 sourceURL:(NSURL *)arg3 containerURL:(NSURL *)arg4 playlistName:(NSString *)arg5 actionIdentifier:(unsigned long long)arg6 contextSourceURL:(NSURL *)arg7;
- (SPTask *)actionForURI:(NSURL *)arg1 logContext:(NSString *)arg2 sourceURL:(NSURL *)arg3 tracks:(NSArray *)arg4 actionIdentifier:(unsigned long long)arg5;
- (SPTask *)actionForURI:(NSURL *)arg1 logContext:(NSString *)arg2 sourceURL:(NSURL *)arg3 itemName:(NSString *)arg4 creatorName:(NSString *)arg5 sourceName:(NSString *)arg6 imageURL:(NSURL *)arg7 clipboardLinkTitle:(NSString *)arg8 actionIdentifier:(unsigned long long)arg9;
- (SPTask *)actionForURI:(NSURL *)arg1 logContext:(NSString *)arg2 sourceURL:(NSURL *)arg3 contextURL:(NSURL *)arg4 actionIdentifier:(unsigned long long)arg5;
- (SPTask *)actionForURI:(NSURL *)arg1 logContext:(NSString *)arg2 sourceURL:(NSURL *)arg3 actionIdentifier:(unsigned long long)arg4;
- (SPTask *)offlineSync:(NSURL *)arg1 isOffline:(_Bool)arg2 collectionPlatform:(id <SPTCollectionPlatform>)arg3 collectionOptions:(SPTCollectionPlatformFetchOptions *)arg4 logContext:(NSString *)arg5;
- (SPTask *)viewAlbumWithAlbumURL:(NSURL *)arg1 logContext:(NSString *)arg2;
- (SPTask *)viewArtists:(NSArray *)arg1 logContext:(NSString *)arg2;
- (SPTask *)viewArtistWithURL:(NSURL *)arg1 logContext:(NSString *)arg2;
@end

/*@interface SPTContextMenuActionsProviderImplementation : NSObject <SPTFeatureFlagSignalObserver, SPTContextMenuActionsProvider>
{
    _Bool _freeTierEnabled;
    id <SPContextMenuActionsFactory> _actionsFactory;
    id <SPTUIPresentationService> _UIPresentationService;
    id <SPTContributingArtistsService> _contributingArtistService;
    id <SPTFeatureFlagSignal> _freeTierEnabledSignal;
}

- (void).cxx_destruct;
@property(nonatomic) _Bool freeTierEnabled; // @synthesize freeTierEnabled=_freeTierEnabled;
@property(readonly, nonatomic) id <SPTFeatureFlagSignal> freeTierEnabledSignal; // @synthesize freeTierEnabledSignal=_freeTierEnabledSignal;
@property(readonly, nonatomic) __weak id <SPTContributingArtistsService> contributingArtistService; // @synthesize contributingArtistService=_contributingArtistService;
@property(readonly, nonatomic) __weak id <SPTUIPresentationService> UIPresentationService; // @synthesize UIPresentationService=_UIPresentationService;
@property(readonly, nonatomic) id <SPContextMenuActionsFactory> actionsFactory; // @synthesize actionsFactory=_actionsFactory;
- (void)featureFlagSignal:(id)arg1 hasAssumedState:(long long)arg2;
- (id)actionsDictionaryForTrackURL:(id)arg1 name:(id)arg2 metadata:(id)arg3 playable:(_Bool)arg4 imageURL:(id)arg5 artists:(id)arg6 albumName:(id)arg7 albumURL:(id)arg8 viewURL:(id)arg9 logContext:(id)arg10 contextSourceURL:(id)arg11;
- (id)generateCorrectTaskArrayWithTaskOrder:(id)arg1 actionDictionary:(id)arg2;
- (id)actionsForTrackURL:(id)arg1 name:(id)arg2 metadata:(id)arg3 playable:(_Bool)arg4 imageURL:(id)arg5 artists:(id)arg6 albumName:(id)arg7 albumURL:(id)arg8 viewURL:(id)arg9 logContext:(id)arg10 contextSourceURL:(id)arg11;
- (id)actionForURIs:(id)arg1 logContext:(id)arg2 sourceURL:(id)arg3 containerURL:(id)arg4 playlistName:(id)arg5 actionIdentifier:(unsigned long long)arg6 contextSourceURL:(id)arg7;
- (id)actionForURI:(id)arg1 logContext:(id)arg2 sourceURL:(id)arg3 tracks:(id)arg4 actionIdentifier:(unsigned long long)arg5;
- (id)actionForURI:(id)arg1 logContext:(id)arg2 sourceURL:(id)arg3 itemName:(id)arg4 creatorName:(id)arg5 sourceName:(id)arg6 imageURL:(id)arg7 clipboardLinkTitle:(id)arg8 actionIdentifier:(unsigned long long)arg9;
- (id)actionForURI:(id)arg1 logContext:(id)arg2 sourceURL:(id)arg3 contextURL:(id)arg4 actionIdentifier:(unsigned long long)arg5;
- (id)actionForURI:(id)arg1 logContext:(id)arg2 sourceURL:(id)arg3 actionIdentifier:(unsigned long long)arg4;
- (id)offlineSync:(id)arg1 isOffline:(_Bool)arg2 collectionPlatform:(id)arg3 collectionOptions:(id)arg4 logContext:(id)arg5;
- (id)viewAlbumWithAlbumURL:(id)arg1 logContext:(id)arg2;
- (id)viewArtists:(id)arg1 logContext:(id)arg2;
- (id)viewArtistWithURL:(id)arg1 logContext:(id)arg2;
- (void)dealloc;
- (id)initWithActionsFactory:(id)arg1 presentationService:(id)arg2 contributingArtistService:(id)arg3 freeTierEnabledSignal:(id)arg4;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end*/

@interface SPTask : NSObject <SPCallbackHolderParent>
{
    _Bool _completed;
    _Bool _cancelled;
    NSMutableArray *_callbacks;
    NSMutableArray *_errbacks;
    NSMutableArray *_finallys;
    NSMutableArray *_childTasks;
    SPTaskCompletionSource *_source;
    id _completedValue;
    NSError *_completedError;
}

+ (id)awaitAll:(id)arg1;
+ (id)fetchWork:(id)arg1 onQueue:(id)arg2;
+ (id)performWork:(id)arg1 onQueue:(id)arg2;
+ (id)failedTask:(id)arg1;
+ (id)completedTask:(id)arg1;
+ (id)delay:(double)arg1;
+ (id)delay:(double)arg1 completeValue:(id)arg2;
@property(retain, nonatomic) NSError *completedError; // @synthesize completedError=_completedError;
@property(retain, nonatomic) id completedValue; // @synthesize completedValue=_completedValue;
@property(nonatomic, getter=isCancelled) _Bool cancelled; // @synthesize cancelled=_cancelled;
@property(nonatomic, getter=isCompleted) _Bool completed; // @synthesize completed=_completed;
@property(nonatomic) __weak SPTaskCompletionSource *source; // @synthesize source=_source;
@property(retain, nonatomic) NSMutableArray *childTasks; // @synthesize childTasks=_childTasks;
@property(retain, nonatomic) NSMutableArray *finallys; // @synthesize finallys=_finallys;
@property(retain, nonatomic) NSMutableArray *errbacks; // @synthesize errbacks=_errbacks;
@property(retain, nonatomic) NSMutableArray *callbacks; // @synthesize callbacks=_callbacks;
- (void)failWithError:(id)arg1;
- (void)completeWithValue:(id)arg1;
- (id)addFinallyCallback:(id)arg1;
- (id)addFinallyCallback:(id)arg1 on:(id)arg2;
- (id)addErrorCallback:(id)arg1;
- (id)addErrorCallback:(id)arg1 on:(id)arg2;
- (id)addCallback:(id)arg1;
- (id)addCallback:(id)arg1 on:(id)arg2;
- (id)initFromSource:(id)arg1;
- (void)cancel;
- (id)recover:(id)arg1 on:(id)arg2;
- (id)chain;
- (id)chain:(id)arg1 on:(id)arg2;
- (id)then:(id)arg1 on:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface SPTFreeTierAlbumContextMenuButtonViewModel : NSObject
@property(retain, nonatomic) NSDictionary *metadata; // @synthesize metadata=_metadata;
@property(retain, nonatomic) NSURL *viewURI; // @synthesize viewURI=_viewURI;
//@property(readonly, nonatomic) id <SPTFreeTierAlbumContextMenuButtonViewModelLogger> ubiLogger; // @synthesize ubiLogger=_ubiLogger;
//@property(readonly, nonatomic) id <SPTCollectionPlatformTestManager> collectionTestManager; // @synthesize collectionTestManager=_collectionTestManager;
@property(readonly, nonatomic) id <SPTContextMenuActionsProvider> actionFactory; // @synthesize actionFactory=_actionFactory;
//@property(readonly, nonatomic) id <SPTContextMenuPresenterFactory> presenterFactory; // @synthesize presenterFactory=_presenterFactory;
@property(readonly, nonatomic) SPTFreeTierAlbumViewModel *albumViewModel; // @synthesize albumViewModel=_albumViewModel;
@property(readonly, nonatomic) unsigned long long state; // @synthesize state=_state;
//@property(nonatomic) __weak id <SPTFreeTierEntityContextMenuButtonViewModelDelegate> delegate; // @synthesize delegate=_delegate;
- (id)createWatchUIDownloadTask;
- (id)createRadioTask;
- (id)createAddToQueueTask;
- (id)createAddToPlaylistTask;
- (id)createLikeAllTracksTask;
- (id)createShareAlbumTask;
- (id)createViewArtistTask;
- (id)createLikeTask;
- (id)createContextMenuTasks;
- (id)contextMenuPresenterWithSenderView:(id)arg1;
- (void)transitionToState:(unsigned long long)arg1;
- (void)tapContextMenuButton:(id)arg1;
- (void)configureWithViewURI:(id)arg1 metadata:(id)arg2;
- (id)initWithPresenterFactory:(id)arg1 actionFactory:(id)arg2 albumViewModel:(id)arg3 collectionTestManager:(id)arg4 ubiLogger:(id)arg5;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@protocol SPTFreeTierEntityViewControllerLogger <NSObject>
- (NSString *)logSwipeRightAddToQueueWithPosition:(long long)arg1 targetURI:(NSURL *)arg2;
- (NSString *)logSwipeLeftRemoveLikeWithPosition:(long long)arg1 targetURI:(NSURL *)arg2;
- (NSString *)logSwipeLeftLikeWithPosition:(long long)arg1 targetURI:(NSURL *)arg2;
@end

@protocol SPTFreeTierAlbumViewControllerLogger <SPTFreeTierEntityViewControllerLogger>
- (void)logOfflineSwitchImpression;
- (NSString *)logHitPlayDeeplinkingWithTrackURI:(NSURL *)arg1;
@end

@interface SPTFreeTierAlbumUBILogger : NSObject
//@property(readonly, nonatomic) id <SPTUBIMobileAlbumPageEventFactory> eventFactory; // @synthesize eventFactory=_eventFactory;
//@property(readonly, nonatomic) id <SPTUBILogger> logger; // @synthesize logger=_logger;
- (void)logOfflineSwitchImpression;
- (id)logHitPlayDeeplinkingWithTrackURI:(id)arg1;
- (void)logHitUnlikeItem:(id)arg1 position:(long long)arg2;
- (void)logHitPauseItem:(id)arg1;
- (id)logHitShufflePlayContext:(id)arg1;
- (void)logHitBack;
- (void)logHitRemoveDownloadForItem:(id)arg1;
- (void)logHitDownloadForItem:(id)arg1;
- (void)logHitContextMenu;
- (void)logHitUnfollowForURI:(id)arg1;
- (void)logHitFollowForURI:(id)arg1;
- (id)logSwipeRightAddToQueueWithPosition:(long long)arg1 targetURI:(id)arg2;
- (id)logSwipeLeftRemoveLikeWithPosition:(long long)arg1 targetURI:(id)arg2;
- (id)logSwipeLeftLikeWithPosition:(long long)arg1 targetURI:(id)arg2;
- (id)initWithLogger:(id)arg1 eventFactory:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface SPTFreeTierAlbumViewController : SPTHubViewController
//@property(retain, nonatomic) SPTProgressView *progressView; // @synthesize progressView=_progressView;
@property(readonly, nonatomic) id <SPTUBIPageInstanceIdentifierProvider> pageInstanceIdProvider; // @synthesize pageInstanceIdProvider=_pageInstanceIdProvider;
@property(readonly, nonatomic) id <SPTFreeTierAlbumViewControllerLogger> ubiLogger; // @synthesize ubiLogger=_ubiLogger;
//@property(readonly, nonatomic) id <SPTPlayer> player; // @synthesize player=_player;
//@property(readonly, nonatomic) SPTFreeTierAlbumOfflineModel *offlineModel; // @synthesize offlineModel=_offlineModel;
@property(readonly, nonatomic) SPTFreeTierAlbumContextMenuButtonViewModel *contextMenuButtonViewModel; // @synthesize contextMenuButtonViewModel=_contextMenuButtonViewModel;
//@property(readonly, nonatomic) SPTFreeTierAlbumFeedbackButtonViewModel *feedbackButtonViewModel; // @synthesize feedbackButtonViewModel=_feedbackButtonViewModel;
- (id)hubShelvesManager:(id)arg1 didAction:(long long)arg2 position:(long long)arg3 componentModel:(id)arg4;
- (void)enableShelves:(id)arg1 componentModelURIResolver:(id)arg2;
- (unsigned long long)preferredNavigationBarState;
- (void)hubView:(id)arg1 componentViewWillAppear:(id)arg2;
- (void)headerView:(id)arg1 componentViewWillAppear:(id)arg2;
- (void)playURIInContext:(id)arg1;
- (void)determineIfContextContainsURI:(id)arg1 responseHandler:(id)arg2;
@property(readonly, nonatomic) NSURL *URI;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewModelDidLoad:(id)arg1;
- (id)initWithTheme:(id)arg1 pageIdentifier:(id)arg2 pageURI:(id)arg3 componentRegistry:(id)arg4 componentLayoutManager:(id)arg5 imageLoaderFactory:(id)arg6 commandHandler:(id)arg7 viewModelProvider:(id)arg8 impressionLogger:(id)arg9 loadingLogger:(id)arg10 ubiLogger:(id)arg11 feedbackButtonViewModel:(id)arg12 contextMenuButtonViewModel:(id)arg13 player:(id)arg14 offlineModel:(id)arg15 shareDragDelegateFactory:(id)arg16 pageInstanceIdProvider:(id)arg17;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;
@end

@interface HUBContainerView : UIView
@property(readonly, nonatomic) HUBView *hubView; // @synthesize hubView=_hubView;
@property(retain, nonatomic) HUBComponentRegistry *componentRegistry; // @synthesize componentRegistry=_componentRegistry;
@property(retain, nonatomic) id <HUBComponentLayoutManager> componentLayoutManager; // @synthesize componentLayoutManager=_componentLayoutManager;
@end

@protocol HUBComponentLayoutManager <NSObject>
- (unsigned long long)containerAlignmentForComponentWithLayoutTraits:(NSSet *)arg1;
- (double)containerMaxWidthForComponentWithLayoutTraits:(NSSet *)arg1;
- (double)horizontalOffsetForComponentsWithLayoutTraits:(NSArray *)arg1 firstComponentLeadingHorizontalOffset:(double)arg2 lastComponentTrailingHorizontalOffset:(double)arg3;
- (double)verticalMarginForComponentWithLayoutTraits:(NSSet *)arg1 precedingComponentLayoutTraits:(NSSet *)arg2;
- (double)horizontalMarginForComponentWithLayoutTraits:(NSSet *)arg1 precedingComponentLayoutTraits:(NSSet *)arg2;
- (double)verticalMarginBetweenComponentWithLayoutTraits:(NSSet *)arg1 andHeaderComponentWithLayoutTraits:(NSSet *)arg2;
- (double)marginBetweenComponentWithLayoutTraits:(NSSet *)arg1 andContentEdge:(unsigned long long)arg2;

@optional
- (UICollectionViewLayoutAttributes *)collectionView:(UICollectionView *)arg1 layout:(HUBCollectionViewLayout *)arg2 finalLayoutAttributesForDisappearingItemAtIndexPath:(NSIndexPath *)arg3 startingAttributes:(UICollectionViewLayoutAttributes *)arg4;
- (UICollectionViewLayoutAttributes *)collectionView:(UICollectionView *)arg1 layout:(HUBCollectionViewLayout *)arg2 initialLayoutAttributesForAppearingItemAtIndexPath:(NSIndexPath *)arg3 finalAttributes:(UICollectionViewLayoutAttributes *)arg4;
@end

@interface HUGSComponentLayoutManager : NSObject <HUBComponentLayoutManager>
{
    SPTTheme *_theme;
}
@property(readonly, nonatomic) SPTTheme *theme; // @synthesize theme=_theme;
- (_Bool)shouldStackComponentWithLayoutTraits:(id)arg1 belowComponentWithLayoutTraits:(id)arg2;
- (id)collectionView:(id)arg1 layout:(id)arg2 initialLayoutAttributesForAppearingItemAtIndexPath:(id)arg3 finalAttributes:(id)arg4;
- (double)horizontalOffsetForComponentsWithLayoutTraits:(id)arg1 firstComponentLeadingHorizontalOffset:(double)arg2 lastComponentTrailingHorizontalOffset:(double)arg3;
- (double)horizontalMarginForComponentWithLayoutTraits:(id)arg1 precedingComponentLayoutTraits:(id)arg2;
- (double)verticalMarginForComponentWithLayoutTraits:(id)arg1 precedingComponentLayoutTraits:(id)arg2;
- (double)verticalMarginBetweenComponentWithLayoutTraits:(id)arg1 andHeaderComponentWithLayoutTraits:(id)arg2;
- (double)marginBetweenComponentWithLayoutTraits:(id)arg1 andContentEdge:(unsigned long long)arg2;
- (unsigned long long)containerAlignmentForComponentWithLayoutTraits:(id)arg1;
- (double)containerMaxWidthForComponentWithLayoutTraits:(id)arg1;
@property(readonly, nonatomic) double defaultComponentMargin;
- (id)initWithTheme:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@protocol GLUETheme <NSObject>
@property(nonatomic, readonly) SPTTheme *sptTheme;
@end

@interface SPTHomeUIComponentLayoutManager : NSObject <HUBComponentLayoutManager>
@property(readonly, nonatomic) id <HUBComponentLayoutManager> hugsLayoutManager; // @synthesize hugsLayoutManager=_hugsLayoutManager;
@property(readonly, nonatomic) id <GLUETheme> theme; // @synthesize theme=_theme;
- (double)containerMaxWidthForComponentWithLayoutTraits:(id)arg1;
- (unsigned long long)containerAlignmentForComponentWithLayoutTraits:(id)arg1;
- (double)horizontalOffsetForComponentsWithLayoutTraits:(id)arg1 firstComponentLeadingHorizontalOffset:(double)arg2 lastComponentTrailingHorizontalOffset:(double)arg3;
- (double)verticalMarginForComponentWithLayoutTraits:(id)arg1 precedingComponentLayoutTraits:(id)arg2;
- (double)horizontalMarginForComponentWithLayoutTraits:(id)arg1 precedingComponentLayoutTraits:(id)arg2;
- (double)verticalMarginBetweenComponentWithLayoutTraits:(id)arg1 andHeaderComponentWithLayoutTraits:(id)arg2;
- (double)marginBetweenComponentWithLayoutTraits:(id)arg1 andContentEdge:(unsigned long long)arg2;
- (id)initWithHugsLayoutManager:(id)arg1 theme:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface SPTEncoreTrackRow : NSObject
- (id)init;
@property(nonatomic, readonly) UIView *uiView;
- (void)update:(id)arg1;
//@property(nonatomic) __weak id <SPTEncoreTrackRowDelegate> delegate; // @synthesize delegate;
@end

@interface SPTEncoreTrackRowAlbum : SPTEncoreTrackRow
{
}
@end

@interface SPTFreeTierAlbumTrackRowComponentView : HUBComponentView
//@property(readonly, nonatomic) id <_TtP24EncoreIntegrationFeature28SPTEncoreTrackRowModelHelper_> trackRowModelHelper; // @synthesize trackRowModelHelper=_trackRowModelHelper;
@property(retain, nonatomic) SPTEncoreTrackRowAlbum *trackRow; // @synthesize trackRow=_trackRow;
@property(readonly, nonatomic) SPTEncoreSwipeableTableViewCell *tableCell; // @synthesize tableCell=_tableCell;
//@property(readonly, nonatomic) id <EncoreView> encoreView; // @synthesize encoreView=_encoreView;
//@property(retain, nonatomic) id <HUBComponentModel> model; // @synthesize model=_model;
//@property(retain, nonatomic) id <HUBComponentEventHandler> eventHandler; // @synthesize eventHandler=_eventHandler;
- (long long)makeHashFor:(id)arg1;
- (long long)trackModifierFromModel:(id)arg1;
- (_Bool)trackIsPausedFromModel:(id)arg1;
- (_Bool)trackIsActiveFromModel:(id)arg1;
- (_Bool)trackIsDisabledFromModel:(id)arg1;
- (_Bool)trackIsPremiumOnlyFromModel:(id)arg1;
- (id)artistNamesFromModel:(id)arg1;
- (long long)restrictionFromModel:(id)arg1;
- (id)createTrackRowModelFromModel:(id)arg1 withPressedState:(_Bool)arg2;
- (void)wrapCellInControl:(id)arg1;
- (void)unlikeWithSender:(id)arg1;
- (void)unhideWithSender:(id)arg1;
- (void)unbanWithSender:(id)arg1;
- (void)contextMenuTappedWithSender:(id)arg1;
- (void)sendSelectionEvent;
- (void)prepareForReuse;
- (void)configureWithModel:(id)arg1;
@property(readonly, nonatomic) SPTSwipeableTableViewCell *tableViewCell;
- (id)makeTrackRowWithComponentFactory:(id)arg1 testManager:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1 encoreComponentFactory:(id)arg2 testManager:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface SPTYourLibraryMusicSongsLogger : NSObject
@property(retain, nonatomic) NSMutableDictionary *impressionTracking; // @synthesize impressionTracking=_impressionTracking;
@property(retain, nonatomic) NSURL *pageURL; // @synthesize pageURL=_pageURL;
//@property(retain, nonatomic) id <SPTUBIMobileYourLibraryLikedSongsEventFactory> eventFactory; // @synthesize eventFactory=_eventFactory;
//@property(retain, nonatomic) id <SPTUBIPageInstanceIdentifierProvider> pageInstanceIdProvider; // @synthesize pageInstanceIdProvider=_pageInstanceIdProvider;
//@property(readonly, nonatomic) id <SPTUBILogger> ubiLogger; // @synthesize ubiLogger=_ubiLogger;
//@property(retain, nonatomic) id <SPTLogCenter> logCenter; // @synthesize logCenter=_logCenter;
- (void)logUBIImpression:(id)arg1;
- (id)logUBIInteractionEvent:(id)arg1;
- (void)logUIInteractionWithSectionId:(id)arg1 itemIndex:(long long)arg2 targetURI:(id)arg3 interactionType:(id)arg4 userIntent:(id)arg5;
- (void)logUIInteractionWithSectionId:(id)arg1 userIntent:(id)arg2;
- (id)userIntent:(id)arg1 withReason:(id)arg2;
- (id)sectionIdForSection:(unsigned long long)arg1;
- (void)logQuickScrollDragEnded;
- (void)logQuickScrollDragStarted;
- (void)logQuickScrollIsVisible;
- (void)logClearFilterWithIdentifier:(id)arg1 index:(unsigned long long)arg2;
- (void)logFilterIdentifier:(id)arg1 sectionId:(id)arg2 filterAdded:(_Bool)arg3 index:(unsigned long long)arg4;
- (void)logSortingIdentifier:(id)arg1 index:(unsigned long long)arg2;
- (void)logSortFilterPickerCanceledWithReason:(unsigned long long)arg1;
- (void)logFilterSortInteractionType:(unsigned long long)arg1;
- (void)clearTrackedImpression:(unsigned long long)arg1;
- (void)trackImpression:(unsigned long long)arg1;
- (_Bool)isTrackedImpressionOpen:(unsigned long long)arg1;
- (void)logFilterChipImpressionForFilterChip:(id)arg1 index:(long long)arg2 isSelected:(_Bool)arg3;
- (void)logFilterChipClearButtonImpresson;
- (void)logFilterChipsImpression;
- (void)logEmptyViewImpression;
- (void)logUnlikeSongDialogInteractionAtIndex:(unsigned long long)arg1 isUnliked:(_Bool)arg2 trackURI:(id)arg3 reason:(id)arg4;
- (void)logUnlikeSongDialogShownAtIndex:(unsigned long long)arg1 trackURI:(id)arg2 reason:(id)arg3;
- (void)logClearFilterChips;
- (void)logFilterChipAtIndex:(unsigned long long)arg1 identifier:(id)arg2 isSelected:(_Bool)arg3;
- (void)logCloseExtraSongsExplanation;
- (void)logExtraSongsWhyAction;
- (id)logSongsShufflePlayWitReason:(id)arg1;
- (void)logAddSongsButtonAction;
- (void)logDiscoverSongsButton:(id)arg1;
- (void)logCancelRemoveDownloads;
- (void)logAvailableOffline:(_Bool)arg1;
- (id)logSwipeActionAtIndex:(unsigned long long)arg1 itemType:(unsigned long long)arg2 section:(unsigned long long)arg3 trackURI:(id)arg4 shelfPosition:(long long)arg5 reason:(id)arg6;
- (void)logAudioPreviewAtIndex:(long long)arg1 itemType:(unsigned long long)arg2 section:(unsigned long long)arg3 trackURI:(id)arg4 playing:(_Bool)arg5 isOriginCoverItem:(_Bool)arg6;
- (void)logTrackBanActionSelectedAtIndex:(unsigned long long)arg1 itemType:(unsigned long long)arg2 section:(unsigned long long)arg3 trackURI:(id)arg4 banned:(_Bool)arg5;
- (void)logTrackLikeActionSelectedAtIndex:(unsigned long long)arg1 itemType:(unsigned long long)arg2 section:(unsigned long long)arg3 trackURI:(id)arg4 liked:(_Bool)arg5 reason:(id)arg6;
- (void)logTrackContextMenuSelectedAtIndex:(unsigned long long)arg1 itemType:(unsigned long long)arg2 section:(unsigned long long)arg3 trackURI:(id)arg4 reason:(id)arg5;
- (id)logTrackItemSelectedAtIndex:(unsigned long long)arg1 itemType:(unsigned long long)arg2 section:(unsigned long long)arg3 trackURI:(id)arg4 reason:(id)arg5;
- (id)initWithLogCenter:(id)arg1 eventFactory:(id)arg2 ubiLogger:(id)arg3 pageInstanceIdProvider:(id)arg4;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface SPTFreeTierEntityFeedbackButtonViewModelBase : NSObject <SPTFreeTierEntityFeedbackButtonViewModel>
//@property(readonly, nonatomic) id <SPTCollectionPlatformConfiguration> configuration; // @synthesize configuration=_configuration;
//@property(readonly, nonatomic) SPTFreeTierEntityFeedbackLogger *logger; // @synthesize logger=_logger;
@property(nonatomic, getter=isForceDisabled) _Bool forceDisabled; // @synthesize forceDisabled=_forceDisabled;
@property(readonly, nonatomic) NSURL *entityURI; // @synthesize entityURI=_entityURI;
@property(nonatomic) __weak id <SPTFreeTierEntityFeedbackButtonViewModelDelegate> delegate; // @synthesize delegate=_delegate;
- (void)setState:(unsigned long long)arg1;
@property(readonly, nonatomic) unsigned long long state;
- (void)unban;
- (void)unlike;
- (void)like;
- (void)tapFeedbackButton;
@property(readonly, nonatomic) NSString *actionName;
@property(readonly, nonatomic) unsigned long long actionIcon;
- (id)initWithEntityURI:(id)arg1 configuration:(id)arg2 logger:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

/*@protocol SPTCollectionPlatformDataLoader <NSObject>
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeBansWithWithOptions:(SPTCollectionPlatformFetchOptions *)arg1 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *, SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg2 onError:(void (^)(NSError *))arg3;
- (void)fetchBansWithOptions:(SPTCollectionPlatformFetchOptions *)arg1 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *, SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg2 onError:(void (^)(NSError *))arg3;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeYourEpisodesWithPolicyProtocols:(NSArray *)arg1 options:(SPTCollectionPlatformFetchOptions *)arg2 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg3 onError:(void (^)(NSError *))arg4;
- (void)fetchYourEpisodesWithPolicyProtocols:(NSArray *)arg1 options:(SPTCollectionPlatformFetchOptions *)arg2 replyOnMainThread:(_Bool)arg3 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg4 onError:(void (^)(NSError *))arg5;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribePodcastsMetadataWithPolicyProtocols:(NSArray *)arg1 options:(SPTCollectionPlatformFetchOptions *)arg2 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg3 onError:(void (^)(NSError *))arg4;
- (void)fetchPodcastsMetadataWithPolicyProtocols:(NSArray *)arg1 options:(SPTCollectionPlatformFetchOptions *)arg2 replyOnMainThread:(_Bool)arg3 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg4 onError:(void (^)(NSError *))arg5;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeAllTracksMetadataWithOptions:(SPTCollectionPlatformFetchOptions *)arg1 onCompletion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg2 onError:(void (^)(NSError *))arg3;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeAllTracksWithPolicyProtocols:(NSArray *)arg1 options:(SPTCollectionPlatformFetchOptions *)arg2 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg3 onError:(void (^)(NSError *))arg4;
- (void)fetchAllTracksWithPolicyProtocols:(NSArray *)arg1 options:(SPTCollectionPlatformFetchOptions *)arg2 replyOnMainThread:(_Bool)arg3 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg4 onError:(void (^)(NSError *))arg5;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeArtistTracksForArtistURL:(NSURL *)arg1 withPolicyProtocols:(NSArray *)arg2 options:(SPTCollectionPlatformFetchOptions *)arg3 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg4 onError:(void (^)(NSError *))arg5;
- (void)fetchArtistViewForArtistURL:(NSURL *)arg1 withMetadataProtocols:(NSArray *)arg2 andTracksProtocols:(NSArray *)arg3 options:(SPTCollectionPlatformFetchOptions *)arg4 replyOnMainThread:(_Bool)arg5 completion:(void (^)(id <SPTCollectionPlatformArtistMetadataFields>, SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg6 onError:(void (^)(NSError *))arg7;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeArtistViewForArtistURL:(NSURL *)arg1 withMetadataProtocols:(NSArray *)arg2 andTracksProtocols:(NSArray *)arg3 options:(SPTCollectionPlatformFetchOptions *)arg4 completion:(void (^)(id <SPTCollectionPlatformDataLoaderField>, SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg5 onError:(void (^)(NSError *))arg6;
- (void)fetchArtistTracksForArtistURL:(NSURL *)arg1 withPolicyProtocols:(NSArray *)arg2 options:(SPTCollectionPlatformFetchOptions *)arg3 replyOnMainThread:(_Bool)arg4 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg5 onError:(void (^)(NSError *))arg6;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeArtistsMetadataWithPolicyProtocols:(NSArray *)arg1 options:(SPTCollectionPlatformFetchOptions *)arg2 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg3 onError:(void (^)(NSError *))arg4;
- (void)fetchArtistsMetadataWithPolicyProtocols:(NSArray *)arg1 options:(SPTCollectionPlatformFetchOptions *)arg2 replyOnMainThread:(_Bool)arg3 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg4 onError:(void (^)(NSError *))arg5;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeAlbumTracksForAlbumURL:(NSURL *)arg1 withPolicyProtocols:(NSArray *)arg2 options:(SPTCollectionPlatformFetchOptions *)arg3 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg4 onError:(void (^)(NSError *))arg5;
- (void)fetchAlbumTracksForAlbumURL:(NSURL *)arg1 withPolicyProtocols:(NSArray *)arg2 options:(SPTCollectionPlatformFetchOptions *)arg3 replyOnMainThread:(_Bool)arg4 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg5 onError:(void (^)(NSError *))arg6;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeAlbumViewForAlbumURL:(NSURL *)arg1 withMetadataProtocols:(NSArray *)arg2 andTracksProtocols:(NSArray *)arg3 options:(SPTCollectionPlatformFetchOptions *)arg4 completion:(void (^)(id <SPTCollectionPlatformDataLoaderField>, SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg5 onError:(void (^)(NSError *))arg6;
- (void)fetchAlbumViewForAlbumURL:(NSURL *)arg1 withMetadataProtocols:(NSArray *)arg2 andTracksProtocols:(NSArray *)arg3 options:(SPTCollectionPlatformFetchOptions *)arg4 replyOnMainThread:(_Bool)arg5 completion:(void (^)(id <SPTCollectionPlatformAlbumMetadataFields>, SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg6 onError:(void (^)(NSError *))arg7;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeAlbumsMetadataWithPolicyProtocols:(NSArray *)arg1 options:(SPTCollectionPlatformFetchOptions *)arg2 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg3 onError:(void (^)(NSError *))arg4;
- (void)fetchAlbumsMetadataWithPolicyProtocols:(NSArray *)arg1 options:(SPTCollectionPlatformFetchOptions *)arg2 replyOnMainThread:(_Bool)arg3 completion:(void (^)(SPTCollectionPlatformDataLoaderResponse<SPTCollectionPlatformDataLoaderField> *))arg4 onError:(void (^)(NSError *))arg5;
- (void)decorateAlbumsURLs:(NSArray *)arg1 withPolicyProtocols:(NSArray *)arg2 completion:(void (^)(NSArray *))arg3 onError:(void (^)(NSError *))arg4;
- (void)decorateAlbumURL:(NSURL *)arg1 withPolicyProtocols:(NSArray *)arg2 completion:(void (^)(id <SPTCollectionPlatformAlbumMetadataFields>))arg3 onError:(void (^)(NSError *))arg4;
- (void)decorateArtistURLs:(NSArray *)arg1 withPolicyProtocols:(NSArray *)arg2 completion:(void (^)(NSArray *))arg3 onError:(void (^)(NSError *))arg4;
- (void)decorateArtistURL:(NSURL *)arg1 withPolicyProtocols:(NSArray *)arg2 completion:(void (^)(id <SPTCollectionPlatformArtistMetadataFields>))arg3 onError:(void (^)(NSError *))arg4;
- (void)decorateTrackURLs:(NSArray *)arg1 withPolicyProtocols:(NSArray *)arg2 completion:(void (^)(NSArray *))arg3 onError:(void (^)(NSError *))arg4;
- (void)decorateTrackURL:(NSURL *)arg1 withPolicyProtocols:(NSArray *)arg2 completion:(void (^)(id <SPTCollectionPlatformTrackFields>))arg3 onError:(void (^)(NSError *))arg4;
@end

@protocol SPTCollectionPlatformStateProvider <NSObject>
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeCollectionStateForURLs:(NSArray *)arg1 inContextURL:(NSURL *)arg2 completion:(void (^)(NSArray *, NSError *))arg3;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeCollectionStateForURL:(NSURL *)arg1 inContextURL:(NSURL *)arg2 completion:(void (^)(unsigned long long, NSError *))arg3;
- (void)collectionStateForURLs:(NSArray *)arg1 inContextURL:(NSURL *)arg2 completion:(void (^)(NSArray *, NSError *))arg3;
- (void)collectionStateForURL:(NSURL *)arg1 inContextURL:(NSURL *)arg2 completion:(void (^)(unsigned long long, NSError *))arg3;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeCollectionStateForURLs:(NSArray *)arg1 completion:(void (^)(NSArray *, NSError *))arg2;
- (id <SPTCollectionPlatformDataLoaderRequestToken>)subscribeCollectionStateForURL:(NSURL *)arg1 completion:(void (^)(unsigned long long, NSError *))arg2;
- (void)collectionStateForURLs:(NSArray *)arg1 completion:(void (^)(NSArray *, NSError *))arg2;
- (void)collectionStateForURL:(NSURL *)arg1 completion:(void (^)(unsigned long long, NSError *))arg2;
@end

@protocol SPTCollectionPlatform <NSObject>
- (void)offlineStateForEntityURL:(NSURL *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)removeOfflineURL:(NSURL *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)addOfflineURL:(NSURL *)arg1 options:(SPTCollectionPlatformFetchOptions *)arg2 completion:(void (^)(_Bool, NSError *))arg3;
- (void)playEntityURL:(NSURL *)arg1 playPolicy:(SPTCollectionPlayPolicy *)arg2 loggingParams:(SPTLoggingParams *)arg3 replyOnMainThread:(_Bool)arg4 completion:(void (^)(_Bool, NSError *))arg5;
- (void)removeObserver:(id <SPTCollectionPlatformObserver>)arg1;
- (void)addObserver:(id <SPTCollectionPlatformObserver>)arg1;
- (void)removeBanURL:(NSURL *)arg1 bySource:(NSString *)arg2 fromContext:(NSURL *)arg3 showUIConfirmation:(_Bool)arg4 completion:(void (^)(_Bool))arg5;
- (void)banURL:(NSURL *)arg1 bySource:(NSString *)arg2 fromContext:(NSURL *)arg3 showUIConfirmation:(_Bool)arg4 completion:(void (^)(_Bool))arg5;
- (void)removeEpisodeURLs:(NSArray *)arg1 showUIConfirmation:(_Bool)arg2 completion:(void (^)(_Bool))arg3;
- (void)removeEpisodeURL:(NSURL *)arg1 showUIConfirmation:(_Bool)arg2 completion:(void (^)(_Bool))arg3;
- (void)addEpisodesURLs:(NSArray *)arg1 showUIConfirmation:(_Bool)arg2 completion:(void (^)(_Bool))arg3;
- (void)addEpisodeURL:(NSURL *)arg1 showUIConfirmation:(_Bool)arg2 completion:(void (^)(_Bool))arg3;
- (void)removeURLs:(NSArray *)arg1 bySource:(NSString *)arg2 fromContext:(NSURL *)arg3 showUIConfirmation:(_Bool)arg4 completion:(void (^)(_Bool))arg5;
- (void)removeURL:(NSURL *)arg1 bySource:(NSString *)arg2 fromContext:(NSURL *)arg3 showUIConfirmation:(_Bool)arg4 completion:(void (^)(_Bool))arg5 entityName:(NSString *)arg6;
- (void)removeURL:(NSURL *)arg1 bySource:(NSString *)arg2 fromContext:(NSURL *)arg3 showUIConfirmation:(_Bool)arg4 completion:(void (^)(_Bool))arg5;
- (void)addURLs:(NSArray *)arg1 bySource:(NSString *)arg2 fromContext:(NSURL *)arg3 showUIConfirmation:(_Bool)arg4 completion:(void (^)(_Bool))arg5;
- (void)addURL:(NSURL *)arg1 bySource:(NSString *)arg2 fromContext:(NSURL *)arg3 showUIConfirmation:(_Bool)arg4 completion:(void (^)(_Bool))arg5 entityName:(NSString *)arg6;
- (void)addURL:(NSURL *)arg1 bySource:(NSString *)arg2 fromContext:(NSURL *)arg3 showUIConfirmation:(_Bool)arg4 completion:(void (^)(_Bool))arg5;
- (_Bool)canAddTrackWithURL:(NSURL *)arg1;
@property(nonatomic, readonly) id <SPTCollectionPlatformStateProvider> stateProvider;
@property(nonatomic, readonly) id <SPTCollectionPlatformDataLoader> dataLoader;
@end

@protocol SPTCollectionPlatformObserver <NSObject>
- (void)collectionPlatformDidChange:(id <SPTCollectionPlatform>)arg1;
@end*/

@interface SPTFreeTierTrackFeedbackButtonViewModel : SPTFreeTierEntityFeedbackButtonViewModelBase
@property(readonly, nonatomic) id <SPTCollectionPlatformDataLoaderRequestToken> collectionStateRequestToken; // @synthesize collectionStateRequestToken=_collectionStateRequestToken;
//@property(readonly, nonatomic) id <SPTCollectionPlatform> collectionPlatform; // @synthesize collectionPlatform=_collectionPlatform;
- (void)evaluateStateForCollectionState:(unsigned long long)arg1 error:(id)arg2;
- (void)unban;
- (void)unlike;
- (void)like;
- (id)initWithTrackURI:(id)arg1 configuration:(id)arg2 collectionPlatform:(id)arg3 logger:(id)arg4;

@end

@protocol SPTUBIMobileAlbumPage_TrackList_TrackRow_UnlikeButtonEventFactory <NSObject>
- (UBIInteractionEvent *)hitRemoveLikeWithItemNoLongerLiked:(NSURL *)arg1;
- (UBIEventAbsoluteLocation *)absoluteLocation;
- (UBIEventLocation *)_location;
@end

@protocol SPTUBIMobileAlbumPage_TrackList_TrackPreviewEventFactory <NSObject>
- (UBIInteractionEvent *)hitUiReveal;
- (UBIInteractionEvent *)hitRemoveHideSongWithItemNoLongerHidden:(NSURL *)arg1;
- (UBIInteractionEvent *)hitHideSongWithItemToHide:(NSURL *)arg1;
- (UBIInteractionEvent *)hitRemoveLikeWithItemNoLongerLiked:(NSURL *)arg1;
- (UBIInteractionEvent *)hitLikeWithItemToBeLiked:(NSURL *)arg1;
- (UBIInteractionEvent *)hitPlayPreviewWithItemToBePreviewed:(NSURL *)arg1;
- (UBIImpressionEvent *)impression;
//- (id <SPTUBIMobileAlbumPage_TrackList_TrackPreview_EducationalMessageEventFactory>)educationalMessageFactory;
- (UBIEventAbsoluteLocation *)absoluteLocation;
- (UBIEventLocation *)_location;
@end

@protocol SPTUBIMobileAlbumPage_TrackList_TrackRowEventFactory <NSObject>
- (UBIInteractionEvent *)swipeAddItemToQueueWithItemToAddToQueue:(NSURL *)arg1;
- (UBIInteractionEvent *)swipeRemoveLikeWithItemNoLongerLiked:(NSURL *)arg1;
- (UBIInteractionEvent *)swipeLikeWithItemToBeLiked:(NSURL *)arg1;
- (UBIInteractionEvent *)hitUiReveal;
- (UBIInteractionEvent *)hitPlayWithItemToBePlayed:(NSURL *)arg1;
- (UBIImpressionEvent *)impression;
- (id <SPTUBIMobileAlbumPage_TrackList_TrackRow_UnlikeButtonEventFactory>)unlikeButtonFactoryWithUri:(NSURL *)arg1;
- (UBIEventAbsoluteLocation *)absoluteLocation;
- (UBIEventLocation *)_location;
@end

@protocol SPTUBIMobileAlbumPage_TrackListEventFactory <NSObject>
- (id <SPTUBIMobileAlbumPage_TrackList_TrackPreviewEventFactory>)trackPreviewFactoryWithPosition:(long long)arg1 uri:(NSURL *)arg2;
- (id <SPTUBIMobileAlbumPage_TrackList_TrackRowEventFactory>)trackRowFactoryWithPosition:(long long)arg1 uri:(NSURL *)arg2;
- (UBIEventAbsoluteLocation *)absoluteLocation;
- (UBIEventLocation *)_location;
@end

@interface SPTUBIMobileAlbumPage_TrackList_TrackPreviewEventFactoryImplementation : NSObject <SPTUBIMobileAlbumPage_TrackList_TrackPreviewEventFactory>
+ (id)factoryWithPosition:(long long)arg1 uri:(id)arg2 components:(id)arg3 parentAbsoluteLocation:(id)arg4;
@property(retain, nonatomic) UBIEventAbsoluteLocation *parentAbsoluteLocation; // @synthesize parentAbsoluteLocation=_parentAbsoluteLocation;
@property(copy, nonatomic) NSArray *components; // @synthesize components=_components;
- (id)hitUiReveal;
- (id)hitRemoveHideSongWithItemNoLongerHidden:(id)arg1;
- (id)hitHideSongWithItemToHide:(id)arg1;
- (id)hitRemoveLikeWithItemNoLongerLiked:(id)arg1;
- (id)hitLikeWithItemToBeLiked:(id)arg1;
- (id)hitPlayPreviewWithItemToBePreviewed:(id)arg1;
- (id)impression;
- (id)educationalMessageFactory;
- (id)absoluteLocation;
- (id)_location;
- (id)initWithPosition:(long long)arg1 uri:(id)arg2 components:(id)arg3 parentAbsoluteLocation:(id)arg4;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface SPTUBIMobileAlbumPage_TrackListEventFactoryImplementation : NSObject <SPTUBIMobileAlbumPage_TrackListEventFactory>
+ (id)factoryWithComponents:(id)arg1 parentAbsoluteLocation:(id)arg2;
@property(retain, nonatomic) UBIEventAbsoluteLocation *parentAbsoluteLocation; // @synthesize parentAbsoluteLocation=_parentAbsoluteLocation;
@property(copy, nonatomic) NSArray *components; // @synthesize components=_components;
- (id)trackPreviewFactoryWithPosition:(long long)arg1 uri:(id)arg2;
- (id)trackRowFactoryWithPosition:(long long)arg1 uri:(id)arg2;
- (id)absoluteLocation;
- (id)_location;
- (id)initWithComponents:(id)arg1 parentAbsoluteLocation:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

@interface SPTUBIMobileAlbumPage_TrackList_TrackRowEventFactoryImplementation : NSObject <SPTUBIMobileAlbumPage_TrackList_TrackRowEventFactory>
+ (id)factoryWithPosition:(long long)arg1 uri:(id)arg2 components:(id)arg3 parentAbsoluteLocation:(id)arg4;
@property(retain, nonatomic) UBIEventAbsoluteLocation *parentAbsoluteLocation; // @synthesize parentAbsoluteLocation=_parentAbsoluteLocation;
@property(copy, nonatomic) NSArray *components; // @synthesize components=_components;
- (id)swipeAddItemToQueueWithItemToAddToQueue:(id)arg1;
- (id)swipeRemoveLikeWithItemNoLongerLiked:(id)arg1;
- (id)swipeLikeWithItemToBeLiked:(id)arg1;
- (id)hitUiReveal;
- (id)hitPlayWithItemToBePlayed:(id)arg1;
- (id)impression;
- (id)unlikeButtonFactoryWithUri:(id)arg1;
- (id)absoluteLocation;
- (id)_location;
- (id)initWithPosition:(long long)arg1 uri:(id)arg2 components:(id)arg3 parentAbsoluteLocation:(id)arg4;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end