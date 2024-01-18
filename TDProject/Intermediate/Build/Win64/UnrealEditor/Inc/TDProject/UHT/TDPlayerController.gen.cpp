// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TDProject/TDPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTDPlayerController() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	TDPROJECT_API UClass* Z_Construct_UClass_ATDPlayerController();
	TDPROJECT_API UClass* Z_Construct_UClass_ATDPlayerController_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TDProject();
// End Cross Module References
	DEFINE_FUNCTION(ATDPlayerController::execLookMouseCursor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LookMouseCursor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDPlayerController::execMoveRight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_InAxis);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveRight(Z_Param_InAxis);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDPlayerController::execMoveForward)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_InAxis);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveForward(Z_Param_InAxis);
		P_NATIVE_END;
	}
	void ATDPlayerController::StaticRegisterNativesATDPlayerController()
	{
		UClass* Class = ATDPlayerController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "LookMouseCursor", &ATDPlayerController::execLookMouseCursor },
			{ "MoveForward", &ATDPlayerController::execMoveForward },
			{ "MoveRight", &ATDPlayerController::execMoveRight },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATDPlayerController_LookMouseCursor_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDPlayerController_LookMouseCursor_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TDPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDPlayerController_LookMouseCursor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDPlayerController, nullptr, "LookMouseCursor", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATDPlayerController_LookMouseCursor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATDPlayerController_LookMouseCursor_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ATDPlayerController_LookMouseCursor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDPlayerController_LookMouseCursor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics
	{
		struct TDPlayerController_eventMoveForward_Parms
		{
			float InAxis;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InAxis;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::NewProp_InAxis = { "InAxis", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TDPlayerController_eventMoveForward_Parms, InAxis), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::NewProp_InAxis,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Move\n" },
#endif
		{ "ModuleRelativePath", "TDPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDPlayerController, nullptr, "MoveForward", nullptr, nullptr, Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::TDPlayerController_eventMoveForward_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::TDPlayerController_eventMoveForward_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ATDPlayerController_MoveForward()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDPlayerController_MoveForward_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics
	{
		struct TDPlayerController_eventMoveRight_Parms
		{
			float InAxis;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InAxis;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::NewProp_InAxis = { "InAxis", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TDPlayerController_eventMoveRight_Parms, InAxis), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::NewProp_InAxis,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TDPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDPlayerController, nullptr, "MoveRight", nullptr, nullptr, Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::TDPlayerController_eventMoveRight_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::TDPlayerController_eventMoveRight_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ATDPlayerController_MoveRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDPlayerController_MoveRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATDPlayerController);
	UClass* Z_Construct_UClass_ATDPlayerController_NoRegister()
	{
		return ATDPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_ATDPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATDPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_TDProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATDPlayerController_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ATDPlayerController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATDPlayerController_LookMouseCursor, "LookMouseCursor" }, // 3387841251
		{ &Z_Construct_UFunction_ATDPlayerController_MoveForward, "MoveForward" }, // 3293224806
		{ &Z_Construct_UFunction_ATDPlayerController_MoveRight, "MoveRight" }, // 4019928500
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATDPlayerController_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "TDPlayerController.h" },
		{ "ModuleRelativePath", "TDPlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATDPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATDPlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATDPlayerController_Statics::ClassParams = {
		&ATDPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATDPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ATDPlayerController_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ATDPlayerController()
	{
		if (!Z_Registration_Info_UClass_ATDPlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATDPlayerController.OuterSingleton, Z_Construct_UClass_ATDPlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATDPlayerController.OuterSingleton;
	}
	template<> TDPROJECT_API UClass* StaticClass<ATDPlayerController>()
	{
		return ATDPlayerController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATDPlayerController);
	ATDPlayerController::~ATDPlayerController() {}
	struct Z_CompiledInDeferFile_FID_Users_acer_Desktop_UnrealPortfolio_TDProject_Source_TDProject_TDPlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_acer_Desktop_UnrealPortfolio_TDProject_Source_TDProject_TDPlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATDPlayerController, ATDPlayerController::StaticClass, TEXT("ATDPlayerController"), &Z_Registration_Info_UClass_ATDPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATDPlayerController), 1905920798U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_acer_Desktop_UnrealPortfolio_TDProject_Source_TDProject_TDPlayerController_h_4204319748(TEXT("/Script/TDProject"),
		Z_CompiledInDeferFile_FID_Users_acer_Desktop_UnrealPortfolio_TDProject_Source_TDProject_TDPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_acer_Desktop_UnrealPortfolio_TDProject_Source_TDProject_TDPlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
