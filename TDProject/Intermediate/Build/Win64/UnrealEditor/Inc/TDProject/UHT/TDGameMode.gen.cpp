// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TDProject/Settings/TDGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTDGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	TDPROJECT_API UClass* Z_Construct_UClass_ATDGameMode();
	TDPROJECT_API UClass* Z_Construct_UClass_ATDGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TDProject();
// End Cross Module References
	void ATDGameMode::StaticRegisterNativesATDGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATDGameMode);
	UClass* Z_Construct_UClass_ATDGameMode_NoRegister()
	{
		return ATDGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ATDGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATDGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TDProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATDGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Settings/TDGameMode.h" },
		{ "ModuleRelativePath", "Settings/TDGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATDGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATDGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATDGameMode_Statics::ClassParams = {
		&ATDGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATDGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ATDGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ATDGameMode()
	{
		if (!Z_Registration_Info_UClass_ATDGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATDGameMode.OuterSingleton, Z_Construct_UClass_ATDGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATDGameMode.OuterSingleton;
	}
	template<> TDPROJECT_API UClass* StaticClass<ATDGameMode>()
	{
		return ATDGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATDGameMode);
	ATDGameMode::~ATDGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Settings_TDGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Settings_TDGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATDGameMode, ATDGameMode::StaticClass, TEXT("ATDGameMode"), &Z_Registration_Info_UClass_ATDGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATDGameMode), 4083778850U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Settings_TDGameMode_h_1910974443(TEXT("/Script/TDProject"),
		Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Settings_TDGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Settings_TDGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
