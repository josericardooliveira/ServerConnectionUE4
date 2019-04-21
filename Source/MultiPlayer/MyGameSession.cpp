// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameSession.h"
#include "MultiPlayer.h"
#include "MultiPlayerGameMode.h"
#include "Engine/World.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Online.h"

void AMyGameSession::RegisterServer()
{
	Super::RegisterServer();
	UE_LOG(LogTemp, Warning, TEXT("****************************Attempt to register server**************************"));

	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{
			AMultiPlayerGameMode* GameMode = Cast<AMultiPlayerGameMode>(GetWorld()->GetAuthGameMode());
			if (GameMode)
			{
				FOnlineSessionSettings* HostSettings = new FOnlineSessionSettings();
				HostSettings->Set(SETTING_MAPNAME, FString("ThirdPersonExampleMap"), EOnlineDataAdvertisementType::ViaOnlineService);

				HostSettings->NumPublicConnections = 32;
				HostSettings->bShouldAdvertise = true;
				HostSettings->bAllowJoinInProgress = true;
				HostSettings->bIsLANMatch = true;
				HostSettings->bUsesPresence = false;
				HostSettings->bAllowJoinViaPresence = false;
				HostSettings->bIsDedicated = true;

				Sessions->CreateSession(0, GameSessionName, *HostSettings);

				UE_LOG(LogTemp, Warning, TEXT("****************************Session created**************************"));
			}
		}
	}
}
