// Fill out your copyright notice in the Description page of Project Settings.


#include "Session/SessionListWidget.h"
#include "SessionItemWidget.h"
#include "Components/WrapBox.h"
#include "Components/Button.h"
#include "FindSessionsCallbackProxy.h"

bool USessionListWidget::Initialize()
{
    if (!Super::Initialize())
    {
        return false;
    }

    SetInfo();

    return true;
}

void USessionListWidget::SetInfo()
{
    Sessions.Empty();

    for (int i = 0; i < 10; ++i)
    {
        if (SessionItemClass == nullptr)
        {
            continue;
        }

        USessionItemWidget* ChildWidget = CreateWidget<USessionItemWidget>(GetWorld(), SessionItemClass);
        
        if (ChildWidget)
        {
            //WrapBox(UI)에 ChildWidget 붙이기
            SessionList->AddChildToWrapBox(ChildWidget);

            //데이터로 생성된 Child 들고있기
            Sessions.Add(ChildWidget);
        }
    }
    RefreshUI();
}

void USessionListWidget::RefreshUI()
{
    //접속자 수 확인
    const int32 SessionLength = SessionInfos.Num();

    for (int32 i = 0; i < 10; ++i)
    {
        const int32 Index = i;

        if (Index < SessionLength) //접속자 Index
        {
            Sessions[Index]->SetVisibility(ESlateVisibility::Visible);
            FBlueprintSessionResult Result = SessionInfos[Index];
            Sessions[Index]->SetInfo(Result);
        }
        else                       //비접속자 Index
        {
            Sessions[Index]->SetVisibility(ESlateVisibility::Collapsed);
        }
    }
}
