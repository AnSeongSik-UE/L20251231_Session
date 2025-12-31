// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleWidget.generated.h"


class UButton;
class UEditableTextBox;

/**
 *
 */
UCLASS()
class PROJECT57_API UTitleWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widget, meta = (BindWidget))
	TObjectPtr<UButton> StartGameButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widget, meta = (BindWidget))
	TObjectPtr<UEditableTextBox> UserID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widget, meta = (BindWidget))
	TObjectPtr<UEditableTextBox> Password;

	virtual void NativeConstruct() override;

	UFUNCTION()
	void StartGame();

	void SaveData();
};
