// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LobbyGameMode.generated.h"


/**
 * The GameModeBase defines the game being played. It governs the game rules, scoring, what actors
 * are allowed to exist in this game type, and who may enter the game.
 *
 * It is only instanced on the server and will never exist on the client. 
 *
 * A GameModeBase actor is instantiated when the level is initialized for gameplay in
 * C++ UGameEngine::LoadMap().  
 * 
 * The class of this GameMode actor is determined by (in order) either the URL ?game=xxx, 
 * the GameMode Override value set in the World Settings, or the DefaultGameMode entry set 
 * in the game's Project Settings.
 *
 * @see https://docs.unrealengine.com/latest/INT/Gameplay/Framework/GameMode/index.html
 */


/**
	 * Called to login new players by creating a player controller, overridable by the game
	 * 通过创建玩家控制器来登录新玩家
	 *
	 * Sets up basic properties of the player (name, unique id, registers with backend, etc) and should not be used to do
	 * more complicated game logic.  The player controller is not fully initialized within this function as far as networking is concerned.
	 * 设置玩家的基本属性（名称、唯一 ID、后台注册等），不应用于执行更复杂的游戏逻辑。 就联网而言，玩家控制器并未在此函数中完全初始化
	 * 
	 * Save "game logic" for PostLogin which is called shortly afterward.
	 * 将 "游戏逻辑 "留给随后调用的 PostLogin。
	 *
	 * @param NewPlayer pointer to the UPlayer object that represents this player (either local or remote)
	 * 指向代表该玩家（本地或远程）的 UPlayer 对象
	 * 
	 * @param RemoteRole the remote role this controller has
	 * RemoteRole 该控制器的远程角色
	 * 
	 * @param Portal desired portal location specified by the client
	 * Portal 客户端指定的所需门户位置
	 * 
	 * @param Options game options passed in by the client at login
	 * Options 客户端登录时传入的游戏选项
	 * 
	 * @param UniqueId platform specific unique identifier for the logging in player
	 * UniqueId 登录玩家的平台特定唯一标识符
	 * 
	 * @param ErrorMessage [out] error message, if any, why this login will be failing
	 * ErrorMessage [out] 错误信息（如果有），说明登录失败的原因
	 *
	 * If login is successful, returns a new PlayerController to associate with this player. Login fails if ErrorMessage string is set.
	 *如果登录成功，则返回一个新的 PlayerController 与该玩家关联。如果设置了 ErrorMessage 字符串，则登录失败
	 *
	 * @return a new player controller for the logged in player, NULL if login failed for any reason
	 * 返回已登录玩家的新玩家控制器，如果登录失败则为 NULL
	 */

/**
 * 
 */
UCLASS()
class MENUSYSTEM_API ALobbyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Called after a successful login.  This is the first place it is safe to call replicated functions on the PlayerController.
	//在登录成功后调用。 这是在 PlayerController 上调用复制函数的第一个安全位置
	virtual void PostLogin(APlayerController* NewPlayer) override;

	//Called when a Controller with a PlayerState leaves the game or is destroyed
	//当具有玩家状态的控制器离开游戏或被销毁时调用
	virtual void Logout(AController* Exiting) override;

protected:

private:
	
	
};
