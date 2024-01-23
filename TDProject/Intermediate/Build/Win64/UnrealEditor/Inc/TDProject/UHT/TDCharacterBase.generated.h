// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Characters/TDCharacterBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ECharacterState : uint8;
#ifdef TDPROJECT_TDCharacterBase_generated_h
#error "TDCharacterBase.generated.h already included, missing '#pragma once' in TDCharacterBase.h"
#endif
#define TDPROJECT_TDCharacterBase_generated_h

#define FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FFlipbookData_Statics; \
	TDPROJECT_API static class UScriptStruct* StaticStruct();


template<> TDPROJECT_API UScriptStruct* StaticStruct<struct FFlipbookData>();

#define FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_SPARSE_DATA
#define FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateAnimStateMachine); \
	DECLARE_FUNCTION(execCharacterLookAt);


#define FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_ACCESSORS
#define FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATDCharacterBase(); \
	friend struct Z_Construct_UClass_ATDCharacterBase_Statics; \
public: \
	DECLARE_CLASS(ATDCharacterBase, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TDProject"), NO_API) \
	DECLARE_SERIALIZER(ATDCharacterBase)


#define FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATDCharacterBase(ATDCharacterBase&&); \
	NO_API ATDCharacterBase(const ATDCharacterBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATDCharacterBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATDCharacterBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATDCharacterBase) \
	NO_API virtual ~ATDCharacterBase();


#define FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_24_PROLOG
#define FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_SPARSE_DATA \
	FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_ACCESSORS \
	FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_INCLASS_NO_PURE_DECLS \
	FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TDPROJECT_API UClass* StaticClass<class ATDCharacterBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Chanheess_Desktop_Unreal_Portfolio_TDProject_Source_TDProject_Characters_TDCharacterBase_h


#define FOREACH_ENUM_ECHARACTERSTATE(op) \
	op(ECharacterState::Idle) \
	op(ECharacterState::Move) 

enum class ECharacterState : uint8;
template<> struct TIsUEnumClass<ECharacterState> { enum { Value = true }; };
template<> TDPROJECT_API UEnum* StaticEnum<ECharacterState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
