// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu.h"
#include "Components/Button.h"
#include "MultiplayerSessionsSubsystem.h"

void UMenu::MenuSetup(int32 NumOfPublicConnections, FString TypeOfMatch)
{
	NumPublicConnections = NumOfPublicConnections;
	MatchType = TypeOfMatch;


	AddToViewport();//将UI设置在界面上
	SetVisibility(ESlateVisibility::Visible); //设置UI是可见的Visible
	bIsFocusable = true;

	//
	//设置输入模式，需要先取得playcontroller控件，然后设置输入模式
	//设置InputModeUIOnly，需要有一个FInputModeUIOnly对象，并设置相关参数
	//
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(TakeWidget());//设置当前组件焦点
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);//设置鼠标锁定模式，设置为不锁定

			PlayerController->SetInputMode(InputModeData);
		}
	}

	UGameInstance* GameInstance = GetGameInstance();
	if (GameInstance)
	{
		MultiplayerSesionsSubsystem = GameInstance->GetSubsystem<UMultiplayerSessionsSubsystem>();
	}


}

bool UMenu::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	if (HostButton)
	{
		HostButton->OnClicked.AddDynamic(this, &ThisClass::HostButtonClicked);
	}

	if (JoinButtom)
	{
		JoinButtom->OnClicked.AddDynamic(this, &ThisClass::JoinButtonClicked);
	}


	return true;
}

void UMenu::NativeDestruct()
{
	Super::NativeDestruct();

	MenuTearDown();
}

void UMenu::HostButtonClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString(TEXT("Host按钮被按下")));
	}

	if (MultiplayerSesionsSubsystem)
	{
		MultiplayerSesionsSubsystem->CreateSession(NumPublicConnections, MatchType);

		UWorld* World = GetWorld();
		if (World)
		{
			World->ServerTravel("/Game/ThirdPerson/Maps/Lobby?listen");
		}
	}
}

void UMenu::JoinButtonClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString(TEXT("Join按钮被按下")));
	}
}

void UMenu::MenuTearDown()
{
	RemoveFromParent();

	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			FInputModeGameOnly InputModeData;
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(false);
		}
	}
}
