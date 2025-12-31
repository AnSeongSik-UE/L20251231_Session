// Fill out your copyright notice in the Description page of Project Settings.


#include "Session/SessionItemWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void USessionItemWidget::SetInfo(FBlueprintSessionResult InSessionResult)
{
	Result = InSessionResult;
	RefreshUI();
}

void USessionItemWidget::RefreshUI()
{
	FString SessionName;
	Result.OnlineResult.Session.SessionSettings.Get(FName("SESSION_NAME"), OUT SessionName);
	Txt_SessionName->SetText(FText::FromString(SessionName));

	FString MapName;
	Result.OnlineResult.Session.SessionSettings.Get(FName("MAP_NAME"), OUT MapName);
	Txt_MapName->SetText(FText::FromString(MapName));

	const int32 CurrentPlayers = Result.OnlineResult.Session.SessionSettings.NumPublicConnections - Result.OnlineResult.Session.NumOpenPublicConnections;
	const int32 MaxPlayers = Result.OnlineResult.Session.SessionSettings.NumPublicConnections;
	FString PlayerCountString = FString::Printf(TEXT("%d / %d"), CurrentPlayers, MaxPlayers);
	Txt_PlayerCount->SetText(FText::FromString(PlayerCountString));
}
