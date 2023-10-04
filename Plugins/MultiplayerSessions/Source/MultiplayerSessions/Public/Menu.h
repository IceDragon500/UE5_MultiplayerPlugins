// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Menu.generated.h"



class UButton;
class UMultiplayerSessionsSubsystem;
/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()
	


public:

	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumOfPublicConnections = 4, FString TypeOfMatch = FString(TEXT("FreeForAll")));

protected:

	//重写UUserWidget中的Initialize()方法
	virtual bool Initialize() override;

	virtual void NativeDestruct() override;


private:

	//Host按钮按下的功能
	UFUNCTION()
	void HostButtonClicked();

	//Join按钮按下的功能
	UFUNCTION()
	void JoinButtonClicked();

	void MenuTearDown();


	//声明button变量，对应UMG中的两个按钮，名称需要一致
	UPROPERTY(meta = (BinWidget))
	UButton* HostButton;

	//声明button变量，对应UMG中的两个按钮，名称需要一致
	UPROPERTY(meta = (BinWidget))
	UButton* JoinButtom;

	//The subsystem designed to handle all online session functionality
	//处理所有在线会话功能的子系统
	UMultiplayerSessionsSubsystem* MultiplayerSesionsSubsystem;

	int32 NumPublicConnections = 4;
	FString MatchType = TEXT("FreeForAll");
};
