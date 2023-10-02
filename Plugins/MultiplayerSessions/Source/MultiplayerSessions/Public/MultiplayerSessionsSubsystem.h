// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"

#include "MultiplayerSessionsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMultiplayerSessionsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UMultiplayerSessionsSubsystem();

	//
	//To handle session functionality. The Menu class will call these
	//为了处理会话功能，Menu类将调用以下命令

	//创建会话，传入一个Num编号和MatchType，可以选择特定的匹配类型
	void CreateSession(int32 NumPublicConnections, FString MatchType);

	//查找会话，传入一个最大结果，这样可以指定搜索结果的数量
	void FindSessions(int32 MaxSearchResults);

	//加入会话，传入一个被找到的会话对象，从对象中获取加入他人对局的信息
	void JoinSession(const FOnlineSessionSearchResult& SessionResult);


	//摧毁会话，结束使用
	void DestroySession();

	//开始会话
	void StartSession();




protected:

	//
	//Internal callbacks for the delegates we'll add to the online session interface delegate list
	//我们将添加到在线会话界面代表列表中的代表的内部回调
	//Thise don't need to be called ouside this class
	//无需在本类之外调用它们
	//

	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionsComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void OnStartSessionComplete(FName SessionName, bool bWasSuccessful);






private:

	IOnlineSessionPtr SessionInterface;


	//
	//To add to the Online Session Interface delegate list
	//添加到在线会话接口代表列表
	//we'll bind our MultiplayerSessionSubsystem internal callbacks to these.
	//我们将把 MultiplayerSessionSubsystem 的内部回调绑定到这些回调上。
	//

	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FDelegateHandle CreateSessionCompleteDelegateHandle;

	FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;
	FDelegateHandle FindSessionCompleteDelegateHandle;

	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;
	FDelegateHandle JoinSessionCompleteDelegateHandle;

	FOnDestroySessionCompleteDelegate DestroySessionCompleteDelegate;
	FDelegateHandle DestroySessionCompleteDelegateHandle;

	FOnStartSessionCompleteDelegate StartSessionCompleteDelegate;
	FDelegateHandle StartSessionCompleteDelegateHandle;

};
