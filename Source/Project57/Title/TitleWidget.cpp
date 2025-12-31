// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "DataGameInstanceSubsystem.h"
#include "Kismet/GameplayStatics.h"

void UTitleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	StartGameButton->OnClicked.AddDynamic(this, &UTitleWidget::StartGame);
}

void UTitleWidget::StartGame()
{
	SaveData();
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Session"));
}

void UTitleWidget::SaveData()
{
	UGameInstance* GI = UGameplayStatics::GetGameInstance(GetWorld());
	if (GI)
	{
		UDataGameInstanceSubsystem* MySubsystem = GI->GetSubsystem<UDataGameInstanceSubsystem>();
		MySubsystem->UserID = UserID->GetText().ToString();
		MySubsystem->Password = Password->GetText().ToString();
	}
}
