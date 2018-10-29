// Copyright (c) 2018 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#include "AccelByteUe4SdkModule.h"
#include "Developer/Settings/Public/ISettingsModule.h"
#include "Developer/Settings/Public/ISettingsSection.h"
#include "Developer/Settings/Public/ISettingsContainer.h"
#include "CoreUObject.h"
#include "AccelByteSettings.h"

void FAccelByteUe4SdkModule::StartupModule()
{
	RegisterSettings();
	LoadSettingsFromConfigUobject();
}

void FAccelByteUe4SdkModule::ShutdownModule()
{
	UnregisterSettings();
}

void FAccelByteUe4SdkModule::RegisterSettings()
{

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings(TEXT("Project"), TEXT("Plugins"), TEXT("AccelByte Unreal Engine 4 SDK"),
			FText::FromName(TEXT("AccelByte Unreal Engine 4 SDK")),
			FText::FromName(TEXT("Setup your plugin.")),
			GetMutableDefault<UAccelByteSettings>()
		);
		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &FAccelByteUe4SdkModule::LoadSettingsFromConfigUobject);
		}
	}
}

void FAccelByteUe4SdkModule::UnregisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings(TEXT("Project"), TEXT("Plugins"), TEXT("AccelByte Unreal Engine 4 SDK"));
	}
}

bool FAccelByteUe4SdkModule::LoadSettingsFromConfigUobject()
{
	using AccelByte::Settings;
	Settings::ClientId = GetDefault<UAccelByteSettings>()->ClientId;
	Settings::ClientSecret = GetDefault<UAccelByteSettings>()->ClientSecret;
	Settings::GameId = GetDefault<UAccelByteSettings>()->GameId;
	Settings::PublisherId = GetDefault<UAccelByteSettings>()->PublisherId;
	Settings::IamServerUrl = GetDefault<UAccelByteSettings>()->IamServerUrl;
	Settings::PlatformServerUrl = GetDefault<UAccelByteSettings>()->PlatformServerUrl;
	Settings::LobbyServerUrl = GetDefault<UAccelByteSettings>()->LobbyServerUrl;
	return true;
}

IMPLEMENT_MODULE(FAccelByteUe4SdkModule, AccelByteUe4Sdk)