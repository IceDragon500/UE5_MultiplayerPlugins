// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu.h"

void UMenu::MenuSetup()
{
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

}
