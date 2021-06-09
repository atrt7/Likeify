#import "Likeify.h"
#include <RemoteLog.h>
#import <substrate.h>

static id <HUBComponentLayoutManager> albumComponentLayoutManager;
static SPTFreeTierAlbumViewController *albumViewController;
static SPTExternalIntegrationCollectionControllerImplementation *externalIntegrationCollectionControllerImplementation;
static SPTNowPlayingAuxiliaryActionsModel *nowPlayingAuxiliaryActionsModel;
static NSString *bundlePrefix = @"/Library/MobileSubstrate/DynamicLibraries/com.atrt7.likeify.bundle";

%hook SPTFreeTierAlbumViewController

-(id)initWithTheme:(id)arg1 pageIdentifier:(id)arg2 pageURI:(id)arg3 componentRegistry:(id)arg4 componentLayoutManager:(id)arg5 imageLoaderFactory:(id)arg6 commandHandler:(id)arg7 viewModelProvider:(id)arg8 impressionLogger:(id)arg9 loadingLogger:(id)arg10 ubiLogger:(id)arg11 feedbackButtonViewModel:(id)arg12 contextMenuButtonViewModel:(id)arg13 player:(id)arg14 offlineModel:(id)arg15 shareDragDelegateFactory:(id)arg16 pageInstanceIdProvider:(id)arg17 {
    if([((NSString *) arg2) isEqualToString:@"free-tier-album"]) {
        //((HUBContainerView *) (self.viewIfLoaded)).componentLayoutManager = homeHugsLayoutManager;
        albumComponentLayoutManager = [[%c(HUGSComponentLayoutManager) alloc] initWithTheme:arg1];
        SPTFreeTierAlbumViewController *tempOrig = %orig(arg1, arg2, arg3, arg4, albumComponentLayoutManager, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
        albumViewController = tempOrig;
        return tempOrig; 
    } else {
        return %orig(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
    }
}

- (void)determineIfContextContainsURI:(id)arg1 responseHandler:(id)arg2 {
    RLog(@"arg1: %@\targ2: %@\n", arg1, arg2);
    %orig(arg1, arg2);
}

%end

%hook SPTFreeTierAlbumUBILogger

- (id)logSwipeLeftLikeWithPosition:(long long)arg1 targetURI:(id)arg2 {
    NSString *tempOrig = %orig(arg1, arg2);
    ////RLog(@"arg1: %ld\targ2: %@\treturn: %@", arg1, arg2, tempOrig);
    return tempOrig;
}

%end

%hook SPTEncoreSwipeableTableViewCell

%new
-(void)likeButtonClicked:(UIButton *)sender {
    int index = MSHookIvar<HUBComponentModelImplementation *>(self.superview.superview, "_model").index;
    NSURL *trackURI = [albumViewController.contextMenuButtonViewModel.albumViewModel.albumTracks objectAtIndex:index];
    //RLog(@"BUTTON:\t%@\n", [((SPTFreeTierAlbumUBILogger *) albumViewController.ubiLogger) logSwipeLeftLikeWithPosition:index targetURI:trackURI]);
    //[externalIntegrationCollectionControllerImplementation collectionContainsContentWithURI:trackURI completionHandler:nil];
    /*[externalIntegrationCollectionControllerImplementation collectionContainsContentWithURI:trackURI completionHandler:^_Bool{
        RLog(@"YES");
        return YES;
    }];*/
    /*[externalIntegrationCollectionControllerImplementation addContentToCollectionWithURI:trackURI fromContext:albumViewController.URI completionHandler:^ {
        RLog(@"DABABY AMOGUS SUS IMPOSTER FORTNITE\n");
    }];*/
    [externalIntegrationCollectionControllerImplementation collectionContainsContentWithURI:trackURI completionHandler:^void (_Bool liked) {
        RLog(@"DABOOl %d", liked);
        [externalIntegrationCollectionControllerImplementation changeTrackCollectionStateWithURI:trackURI fromContext:albumViewController.URI add:!liked completionHandler:^ {
            RLog(@"COMPLETED LMAO");
        }];
        sender.selected = !liked;
    }];
    //sender.selected = !shouldAdd;
    //RLog(@"shouldAdd: %d", shouldAdd);
    //[externalIntegrationCollectionControllerImplementation changeTrackCollectionStateWithURI:trackURI fromContext:albumViewController.URI add:shouldAdd completionHandler:^ {
    //    RLog(@"COMPLETED LMAO");
    //}];
    //[nowPlayingAuxiliaryActionsModel addToCollection];
    //RLog(@"BUTTON:\t%@\n", ((SPTask *) [albumViewController.contextMenuButtonViewModel createLikeAllTracksTask]).completedError);
    //[%c(SPTask) [[SPTUBIMobileAlbumPage_TrackList_TrackPreviewEventFactoryImplementation factoryWithPosition:nil uri:nil components:nil parentAbsoluteLocation:nil] swipeLikeWithItemToBeLiked:trackURI] performWork: onQueue:];
    //RLog(@"BUTTON PRESS\t%@\n", trackURI);
}

- (id)containerView {
    UIView *tempOrig = (UIView *) %orig;
    if(tempOrig.subviews.count != 0) {
        if(tempOrig.subviews[0].subviews.count != 0) {

            if(tempOrig.subviews[0].subviews.count < 2) {
                CGRect tempFrame = tempOrig.subviews[0].subviews[0].subviews[0].subviews[0].subviews[0].subviews[0].frame;
                tempOrig.subviews[0].subviews[0].subviews[0].subviews[0].subviews[0].subviews[0].bounds = CGRectMake((tempFrame.origin.x - 30), tempFrame.origin.y, tempFrame.size.width, tempFrame.size.height);
                NSBundle *bundle = [[NSBundle alloc] initWithPath:bundlePrefix];
                UIButton *likeButton = [UIButton buttonWithType:UIButtonTypeCustom];
                [likeButton setImage:[UIImage imageNamed:[bundle pathForResource:@"likeButtonUnselected" ofType:@"png"]] forState:UIControlStateNormal];
                [likeButton setImage:[UIImage imageNamed:[bundle pathForResource:@"likeButtonSelected" ofType:@"png"]] forState:UIControlStateSelected];
                [likeButton setImage:[UIImage imageNamed:[bundle pathForResource:@"likeButtonHighlighted" ofType:@"png"]] forState:UIControlStateHighlighted];
                [likeButton addTarget:self action:@selector(likeButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
                likeButton.frame = CGRectMake(((tempOrig.frame.origin.x + 10) / 2), ((tempOrig.frame.origin.y + 25) / 2), 35, 35);
                likeButton.clipsToBounds = YES;
                likeButton.layer.cornerRadius = 35/2.0f;
                //button.layer.borderColor=[UIColor redColor].CGColor;
                likeButton.layer.borderWidth=2.0f;
                likeButton.selected = 0;
                //likeButton.layer.borderColor = [UIColor whiteColor].CGColor;

                /*_Bool shouldAdd = 0;
                [externalIntegrationCollectionControllerImplementation collectionContainsContentWithURI:trackURI completionHandler:^void (_Bool dabool) {
                    RLog(@"DABOOl %d", dabool);
                    shouldAdd = !dabool;
                }];
                likeButton.selected = !shouldAdd;*/

                /*[externalIntegrationCollectionControllerImplementation collectionContainsContentWithURI:trackURI completionHandler:^void (_Bool liked) {
                    RLog(@"DABOOl2 %d", liked);
                    likeButton.selected = !liked;
                }];*/

                [tempOrig.subviews[0] addSubview:likeButton];
                RLog(@"ADDDED LIKE BUTTON");
            }

        }

    }
    return tempOrig;
}

%end

%hook SPTUBIMobileAlbumPage_TrackList_TrackRowEventFactoryImplementation

- (id)swipeLikeWithItemToBeLiked:(id)arg1 {
    UBIInteractionEvent *tempOrig = %orig(arg1);
    //RLog(@"LIKED: %@", tempOrig.action);
    return tempOrig;
}

%end

%hook UBILogger

- (void)addActionParametersToEvent:(id)arg1 fromInteraction:(id)arg2 {
    //RLog(@"BRUH ::: arg1:%@\n", arg2);
    %orig(arg1, arg2);
}

%end

%hook SPTExternalIntegrationCollectionControllerImplementation

- (id)initWithCollectionPlatform:(id)arg1 collectionPlatformTestManager:(id)arg2 playlistPlatformService:(id)arg3 playbackController:(id)arg4 followFactory:(id)arg5 debugLog:(id)arg6 {
    externalIntegrationCollectionControllerImplementation = %orig(arg1, arg2, arg3, arg4, arg5, arg6);
    //RLog(@"arg1: %@\targ2: %@\targ3: %@\targ4: %@\targ5: %@\targ6: %@\treturn: %@\n", arg1, arg2, arg3, arg4, arg5, arg6, externalIntegrationCollectionControllerImplementation);
    return externalIntegrationCollectionControllerImplementation;
}

- (void)collectionContainsContentWithTrackURI:(id)arg1 completionHandler:(id)arg2 {
    //RLog(@"uri: %@\tcompletionHandler: %@", arg1, arg2);
    %orig(arg1, arg2);
}

%end

%hook SPTNowPlayingAuxiliaryActionsModel

- (id)initWithCollectionPlatform:(id)arg1 adsManager:(id)arg2 testManager:(id)arg3 statefulPlayer:(id)arg4 {
    nowPlayingAuxiliaryActionsModel = %orig(arg1, arg2, arg3, arg4);
    //RLog(@"NOW PLAYING INIT");
    return nowPlayingAuxiliaryActionsModel;
}

%end