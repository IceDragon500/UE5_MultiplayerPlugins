// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if(GameState)
	{
		//获得进入游戏的玩家数量
		int32 NumberOfPlayer =  GameState.Get()->PlayerArray.Num();

		if(GEngine)
		{
			//打印进入游戏的玩家数量
			GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString::Printf(TEXT("Player in Game :%d"), NumberOfPlayer));

			APlayerState* PlayerState =NewPlayer->GetPlayerState<APlayerState>();

			if(PlayerState)
			{
				FString PlayerName = PlayerState->GetPlayerName();
				//打印进入游戏的玩家名称
				GEngine->AddOnScreenDebugMessage(2, 60.f, FColor::Green, FString::Printf(TEXT("%s has joined the game!"), *PlayerName));
			}
		}
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	APlayerState* PlayerState =Exiting->GetPlayerState<APlayerState>();

	if (PlayerState)
	{
		int32 NumberOfPlayer = GameState.Get()->PlayerArray.Num();

		//打印进入游戏的玩家数量
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString::Printf(TEXT("Player in Game :%d"), NumberOfPlayer - 1));

		if (PlayerState)
		{
			FString PlayerName = PlayerState->GetPlayerName();
			//打印进入游戏的玩家名称
			GEngine->AddOnScreenDebugMessage(2, 60.f, FColor::Green, FString::Printf(TEXT("%s has exited the game!"), *PlayerName));
		}
	}
}
