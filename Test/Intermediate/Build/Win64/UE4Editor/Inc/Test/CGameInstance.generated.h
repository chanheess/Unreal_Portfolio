// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEST_CGameInstance_generated_h
#error "CGameInstance.generated.h already included, missing '#pragma once' in CGameInstance.h"
#endif
#define TEST_CGameInstance_generated_h

#define Test_Source_Test_Public_CGameInstance_h_12_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMyCharacterData_Statics; \
	TEST_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> TEST_API UScriptStruct* StaticStruct<struct FMyCharacterData>();

#define Test_Source_Test_Public_CGameInstance_h_38_SPARSE_DATA
#define Test_Source_Test_Public_CGameInstance_h_38_RPC_WRAPPERS
#define Test_Source_Test_Public_CGameInstance_h_38_RPC_WRAPPERS_NO_PURE_DECLS
#define Test_Source_Test_Public_CGameInstance_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCGameInstance(); \
	friend struct Z_Construct_UClass_UCGameInstance_Statics; \
public: \
	DECLARE_CLASS(UCGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(UCGameInstance)


#define Test_Source_Test_Public_CGameInstance_h_38_INCLASS \
private: \
	static void StaticRegisterNativesUCGameInstance(); \
	friend struct Z_Construct_UClass_UCGameInstance_Statics; \
public: \
	DECLARE_CLASS(UCGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(UCGameInstance)


#define Test_Source_Test_Public_CGameInstance_h_38_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCGameInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCGameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCGameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCGameInstance(UCGameInstance&&); \
	NO_API UCGameInstance(const UCGameInstance&); \
public:


#define Test_Source_Test_Public_CGameInstance_h_38_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCGameInstance(UCGameInstance&&); \
	NO_API UCGameInstance(const UCGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCGameInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCGameInstance)


#define Test_Source_Test_Public_CGameInstance_h_38_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MyCharacterTable() { return STRUCT_OFFSET(UCGameInstance, MyCharacterTable); }


#define Test_Source_Test_Public_CGameInstance_h_35_PROLOG
#define Test_Source_Test_Public_CGameInstance_h_38_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_Public_CGameInstance_h_38_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_Public_CGameInstance_h_38_SPARSE_DATA \
	Test_Source_Test_Public_CGameInstance_h_38_RPC_WRAPPERS \
	Test_Source_Test_Public_CGameInstance_h_38_INCLASS \
	Test_Source_Test_Public_CGameInstance_h_38_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Test_Source_Test_Public_CGameInstance_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_Public_CGameInstance_h_38_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_Public_CGameInstance_h_38_SPARSE_DATA \
	Test_Source_Test_Public_CGameInstance_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	Test_Source_Test_Public_CGameInstance_h_38_INCLASS_NO_PURE_DECLS \
	Test_Source_Test_Public_CGameInstance_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEST_API UClass* StaticClass<class UCGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Test_Source_Test_Public_CGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
