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
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	TDPROJECT_API UClass* Z_Construct_UClass_ATDCharacterBase();
	TDPROJECT_API UClass* Z_Construct_UClass_ATDCharacterBase_NoRegister();
	TDPROJECT_API UEnum* Z_Construct_UEnum_TDProject_ECharacterState();
	TDPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FFlipbookData();
	UPackage* Z_Construct_UPackage__Script_TDProject();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECharacterState;
	static UEnum* ECharacterState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ECharacterState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ECharacterState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_TDProject_ECharacterState, (UObject*)Z_Construct_UPackage__Script_TDProject(), TEXT("ECharacterState"));
		}
		return Z_Registration_Info_UEnum_ECharacterState.OuterSingleton;
	}
	template<> TDPROJECT_API UEnum* StaticEnum<ECharacterState>()
	{
		return ECharacterState_StaticEnum();
	}
	struct Z_Construct_UEnum_TDProject_ECharacterState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_TDProject_ECharacterState_Statics::Enumerators[] = {
		{ "ECharacterState::Idle", (int64)ECharacterState::Idle },
		{ "ECharacterState::Move", (int64)ECharacterState::Move },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_TDProject_ECharacterState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Idle.Name", "ECharacterState::Idle" },
		{ "ModuleRelativePath", "Characters/TDCharacterBase.h" },
		{ "Move.Name", "ECharacterState::Move" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_TDProject_ECharacterState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_TDProject,
		nullptr,
		"ECharacterState",
		"ECharacterState",
		Z_Construct_UEnum_TDProject_ECharacterState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_TDProject_ECharacterState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_TDProject_ECharacterState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_TDProject_ECharacterState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_TDProject_ECharacterState()
	{
		if (!Z_Registration_Info_UEnum_ECharacterState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECharacterState.InnerSingleton, Z_Construct_UEnum_TDProject_ECharacterState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ECharacterState.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FlipbookData;
class UScriptStruct* FFlipbookData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FlipbookData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FlipbookData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFlipbookData, (UObject*)Z_Construct_UPackage__Script_TDProject(), TEXT("FlipbookData"));
	}
	return Z_Registration_Info_UScriptStruct_FlipbookData.OuterSingleton;
}
template<> TDPROJECT_API UScriptStruct* StaticStruct<FFlipbookData>()
{
	return FFlipbookData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FFlipbookData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimData_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFlipbookData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Characters/TDCharacterBase.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FFlipbookData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFlipbookData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFlipbookData_Statics::NewProp_AnimData_MetaData[] = {
		{ "Category", "FlipbookData" },
		{ "ModuleRelativePath", "Characters/TDCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FFlipbookData_Statics::NewProp_AnimData = { "AnimData", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFlipbookData, AnimData), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlipbookData_Statics::NewProp_AnimData_MetaData), Z_Construct_UScriptStruct_FFlipbookData_Statics::NewProp_AnimData_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFlipbookData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFlipbookData_Statics::NewProp_AnimData,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFlipbookData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_TDProject,
		nullptr,
		&NewStructOps,
		"FlipbookData",
		Z_Construct_UScriptStruct_FFlipbookData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlipbookData_Statics::PropPointers),
		sizeof(FFlipbookData),
		alignof(FFlipbookData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlipbookData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFlipbookData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlipbookData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FFlipbookData()
	{
		if (!Z_Registration_Info_UScriptStruct_FlipbookData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FlipbookData.InnerSingleton, Z_Construct_UScriptStruct_FFlipbookData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_FlipbookData.InnerSingleton;
	}
	DEFINE_FUNCTION(ATDCharacterBase::execUpdateAnimStateMachine)
	{
		P_GET_ENUM(ECharacterState,Z_Param_InputAnim);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateAnimStateMachine(ECharacterState(Z_Param_InputAnim));
		P_NATIVE_END;
	}
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
			{ "UpdateAnimStateMachine", &ATDCharacterBase::execUpdateAnimStateMachine },
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
	struct Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics
	{
		struct TDCharacterBase_eventUpdateAnimStateMachine_Parms
		{
			ECharacterState InputAnim;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_InputAnim_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_InputAnim;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::NewProp_InputAnim_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::NewProp_InputAnim = { "InputAnim", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TDCharacterBase_eventUpdateAnimStateMachine_Parms, InputAnim), Z_Construct_UEnum_TDProject_ECharacterState, METADATA_PARAMS(0, nullptr) }; // 1288616508
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::NewProp_InputAnim_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::NewProp_InputAnim,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Characters/TDCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDCharacterBase, nullptr, "UpdateAnimStateMachine", nullptr, nullptr, Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::TDCharacterBase_eventUpdateAnimStateMachine_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::TDCharacterBase_eventUpdateAnimStateMachine_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine_Statics::FuncParams);
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
		static const UECodeGen_Private::FBytePropertyParams NewProp_CharacterState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CharacterState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CharacterState;
		static const UECodeGen_Private::FStructPropertyParams NewProp_AnimFlipbooks_ValueProp;
		static const UECodeGen_Private::FBytePropertyParams NewProp_AnimFlipbooks_Key_KeyProp_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_AnimFlipbooks_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimFlipbooks_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_AnimFlipbooks;
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
		{ &Z_Construct_UFunction_ATDCharacterBase_UpdateAnimStateMachine, "UpdateAnimStateMachine" }, // 1338788999
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
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CharacterState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CharacterState_MetaData[] = {
		{ "Category", "TDCharacterBase" },
		{ "ModuleRelativePath", "Characters/TDCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CharacterState = { "CharacterState", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATDCharacterBase, CharacterState), Z_Construct_UEnum_TDProject_ECharacterState, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CharacterState_MetaData), Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CharacterState_MetaData) }; // 1288616508
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_AnimFlipbooks_ValueProp = { "AnimFlipbooks", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FFlipbookData, METADATA_PARAMS(0, nullptr) }; // 1961880693
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_AnimFlipbooks_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_AnimFlipbooks_Key_KeyProp = { "AnimFlipbooks_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_TDProject_ECharacterState, METADATA_PARAMS(0, nullptr) }; // 1288616508
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_AnimFlipbooks_MetaData[] = {
		{ "Category", "TDCharacterBase" },
		{ "ModuleRelativePath", "Characters/TDCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_AnimFlipbooks = { "AnimFlipbooks", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATDCharacterBase, AnimFlipbooks), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_AnimFlipbooks_MetaData), Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_AnimFlipbooks_MetaData) }; // 1288616508 1961880693
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATDCharacterBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_TopDownCameraComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_DefaultRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_TurnRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CharacterState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_CharacterState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_AnimFlipbooks_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_AnimFlipbooks_Key_KeyProp_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_AnimFlipbooks_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDCharacterBase_Statics::NewProp_AnimFlipbooks,
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
	struct Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics::EnumInfo[] = {
		{ ECharacterState_StaticEnum, TEXT("ECharacterState"), &Z_Registration_Info_UEnum_ECharacterState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1288616508U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics::ScriptStructInfo[] = {
		{ FFlipbookData::StaticStruct, Z_Construct_UScriptStruct_FFlipbookData_Statics::NewStructOps, TEXT("FlipbookData"), &Z_Registration_Info_UScriptStruct_FlipbookData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFlipbookData), 1961880693U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATDCharacterBase, ATDCharacterBase::StaticClass, TEXT("ATDCharacterBase"), &Z_Registration_Info_UClass_ATDCharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATDCharacterBase), 2768156525U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_3956838777(TEXT("/Script/TDProject"),
		Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
