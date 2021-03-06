/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//			Copyright 2016 (C) Bruno Xavier Leite			//
//////////////////////////////////////////////////////////////
/*
	BY EXECUTING, READING, EDITING, COPYING OR KEEPING FILES FROM THIS SOFTWARE SOURCE CODE,
	YOU AGREE TO THE FOLLOWING TERMS IN ADDITION TO EPIC GAMES MARKETPLACE EULA:
	- YOU HAVE READ AND AGREE TO EPIC GAMES TERMS: https://publish.unrealengine.com/faq
	- YOU AGREE DEVELOPER WILL NOT PROVIDE SOFTWARE OUTSIDE MARKETPLACE ENVIRONMENT.
	- YOU AGREE DEVELOPER WILL NOT PROVIDE PAID OR EXCLUSIVE SUPPORT SERVICES.
	- YOU AGREE DEVELOPER PROVIDED SUPPORT CHANNELS, ARE UNDER HIS SOLE DISCRETION.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "EMoneytalksPrivatePCH.h"
#include "EMoneytalksStyle.h"
#include "SlateGameResources.h"
#include "SlateStyle.h"
#include "IPluginManager.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define PLUGIN_BRUSH(RelativePath,...) FSlateImageBrush(Style->RootToContentDir(RelativePath,TEXT(".png")),__VA_ARGS__)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TSharedPtr< FSlateStyleSet > FEMoneytalksStyle::Instance = NULL;

void FEMoneytalksStyle::Initialize() {
	if (!Instance.IsValid()) {
		Instance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*Instance);
	}
}

void FEMoneytalksStyle::Shutdown() {
	FSlateStyleRegistry::UnRegisterSlateStyle(*Instance);
	ensure(Instance.IsUnique());
	Instance.Reset();
}

const ISlateStyle& FEMoneytalksStyle::Get() {
	return *Instance;
}

FName FEMoneytalksStyle::GetStyleSetName() {
	static FName StyleName(TEXT("EdMoneytalksStyle"));
	return StyleName;
}

void FEMoneytalksStyle::ReloadTextures() {
	if (FSlateApplication::IsInitialized())	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

TSharedRef<FSlateStyleSet> FEMoneytalksStyle::Create() {
	const FVector2D Icon16x16(16.0f,16.0f);
	const FVector2D Icon40x40(40.0f,40.0f);
	const FVector2D Icon128x128(128.0f,128.0f);
	//
	TSharedRef<FSlateStyleSet> Style = MakeShareable(new FSlateStyleSet("EdMoneytalksStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin(TEXT("Moneytalks"))->GetContentDir());
	Style->Set("ClassIcon.Decimal",new PLUGIN_BRUSH(TEXT("Icons/Pi_16x"),Icon16x16));
	//
	return Style;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#undef PLUGIN_BRUSH

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////