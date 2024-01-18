// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TDProject/Characters/TDCharacterBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTDCharacterBase() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter();
	TDPROJECT_API UClass* Z_Construct_UClass_ATDCharacterBase();
	TDPROJECT_API UClass* Z_Construct_UClass_ATDCharacterBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TDProject();
// End Cross Module References
	DEFINE_FUNCTION(ATDCharacterBase::execCharacterLookAt)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CharacterLookAt();
		P_NATIVE_END;
	}
	void ATDCharacterBase::StaticRegisterNativesATDCharacterBase()
	{
		UClass* Class = ATDCharacterBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CharacterLookAt", &ATDCharacterBase::execCharacterLookAt },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATDCharacterBase_CharacterLookAt_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDCharacterBase_CharacterLookAt_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Characters/TDCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDCharacterBase_CharacterLookAt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDCharacterBase, nullptr, "CharacterLookAt", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATDCharacterBase_CharacterLookAt_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATDCharacterBase_CharacterLookAt_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ATDCharacterBase_CharacterLookAt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDCharacterBase_CharacterLookAt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATDCharacterBase);
	UClass* Z_Construct_UClass_ATDCharacterBase_NoRegister()
	{
		return ATDCharacterBase::StaticClass();
	}
	struct Z_Construct_UClass_ATDCharacterBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TopDownCameraComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TopDownCameraComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultRotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultRotation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnRotation_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnRotation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATDCharacterBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_TDProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATDCharacterBase_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ATDCharacterBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATDCharacterBase_CharacterLookAt, "CharacterLookAt" }, // 1485741802
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATDCharacterBase_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDCharacterBase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/TDCharacterBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Characters/TDCharacterBase.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_TopDownCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Top down camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Characters/TDCharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Top down camera" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_TopDownCameraComponent = { "TopDownCameraComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATDCharacterBase, TopDownCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_TopDownCameraComponent_MetaData), Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_TopDownCameraComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom positioning the camera above the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Characters/TDCharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom positioning the camera above the character" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATDCharacterBase, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CameraBoom_MetaData), Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CameraBoom_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_DefaultRotation_MetaData[] = {
		{ "Category", "TDCharacterBase" },
		{ "ModuleRelativePath", "Characters/TDCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_DefaultRotation = { "DefaultRotation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATDCharacterBase, DefaultRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_DefaultRotation_MetaData), Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_DefaultRotation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_TurnRotation_MetaData[] = {
		{ "Category", "TDCharacterBase" },
		{ "ModuleRelativePath", "Characters/TDCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_TurnRotation = { "TurnRotation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATDCharacterBase, TurnRotation), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_TurnRotation_MetaData), Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_TurnRotation_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATDCharacterBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_TopDownCameraComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_DefaultRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_TurnRotation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATDCharacterBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATDCharacterBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATDCharacterBase_Statics::ClassParams = {
		&ATDCharacterBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATDCharacterBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ATDCharacterBase_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATDCharacterBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ATDCharacterBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATDCharacterBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ATDCharacterBase()
	{
		if (!Z_Registration_Info_UClass_ATDCharacterBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATDCharacterBase.OuterSingleton, Z_Construct_UClass_ATDCharacterBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATDCharacterBase.OuterSingleton;
	}
	template<> TDPROJECT_API UClass* StaticClass<ATDCharacterBase>()
	{
		return ATDCharacterBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATDCharacterBase);
	ATDCharacterBase::~ATDCharacterBase() {}
	struct Z_CompiledInDeferFile_FID_Users_acer_Desktop_UnrealPortfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_acer_Desktop_UnrealPortfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATDCharacterBase, ATDCharacterBase::StaticClass, TEXT("ATDCharacterBase"), &Z_Registration_Info_UClass_ATDCharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATDCharacterBase), 1601598449U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_acer_Desktop_UnrealPortfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_2045529706(TEXT("/Script/TDProject"),
		Z_CompiledInDeferFile_FID_Users_acer_Desktop_UnrealPortfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_acer_Desktop_UnrealPortfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
