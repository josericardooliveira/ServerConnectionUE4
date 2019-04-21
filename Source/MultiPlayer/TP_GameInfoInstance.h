// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TP_GameInfoInstance.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API UTP_GameInfoInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void CreateNetworkSession();
};
