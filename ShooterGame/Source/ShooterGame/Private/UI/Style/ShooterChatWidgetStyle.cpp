// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ShooterChatWidgetStyle.h"
#include "ShooterGame.h"

FShooterChatStyle::FShooterChatStyle()
{
}

FShooterChatStyle::~FShooterChatStyle()
{
}

const FName FShooterChatStyle::TypeName(TEXT("FShooterChatStyle"));

const FShooterChatStyle& FShooterChatStyle::GetDefault()
{
	static FShooterChatStyle Default;
	return Default;
}

void FShooterChatStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	TextEntryStyle.GetResources(OutBrushes);

	OutBrushes.Add(&BackingBrush);
}


UShooterChatWidgetStyle::UShooterChatWidgetStyle( const FObjectInitializer& ObjectInitializer )
	: Super(ObjectInitializer)
{
	
}
