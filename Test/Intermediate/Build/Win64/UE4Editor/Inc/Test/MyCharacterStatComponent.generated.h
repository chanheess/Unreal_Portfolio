// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEST_MyCharacterStatComponent_generated_h
#error "MyCharacterStatComponent.generated.h already included, missing '#pragma once' in MyCharacterStatComponent.h"
#endif
#define TEST_MyCharacterStatComponent_generated_h

#define Test_Source_Test_Public_MyCharacterStatComponent_h_13_SPARSE_DATA
#define Test_Source_Test_Public_MyCharacterStatComponent_h_13_RPC_WRAPPERS
#define Test_Source_Test_Public_MyCharacterStatComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define Test_Source_Test_Public_MyCharacterStatComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyCharacterStatComponent(); \
	friend struct Z_Construct_UClass_UMyCharacterStatComponent_Statics; \
public: \
	DECLARE_CLASS(UMyCharacterStatComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(UMyCharacterStatComponent)


#define Test_Source_Test_Public_MyCharacterStatComponent_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUMyCharacterStatComponent(); \
	friend struct Z_Construct_UClass_UMyCharacterStatComponent_Statics; \
public: \
	DECLARE_CLASS(UMyCharacterStatComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(UMyCharacterStatComponent)


#define Test_Source_Test_Public_MyCharacterStatComponent_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyCharacterStatComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyCharacterStatComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyCharacterStatComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyCharacterStatComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyCharacterStatComponent(UMyCharacterStatComponent&&); \
	NO_API UMyCharacterStatComponent(const UMyCharacterStatComponent&); \
public:


#define Test_Source_Test_Public_MyCharacterStatComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyCharacterStatComponent(UMyCharacterStatComponent&&); \
	NO_API UMyCharacterStatComponent(const UMyCharacterStatComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyCharacterStatComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyCharacterStatComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMyCharacterStatComponent)


#define Test_Source_Test_Public_MyCharacterStatComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Level() { return STRUCT_OFFSET(UMyCharacterStatComponent, Level); } \
	FORCEINLINE static uint32 __PPO__CurrentHp() { return STRUCT_OFFSET(UMyCharacterStatComponent, CurrentHp); }


#define Test_Source_Test_Public_MyCharacterStatComponent_h_10_PROLOG
#define Test_Source_Test_Public_MyCharacterStatComponent_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_Public_MyCharacterStatComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_Public_MyCharacterStatComponent_h_13_SPARSE_DATA \
	Test_Source_Test_Public_MyCharacterStatComponent_h_13_RPC_WRAPPERS \
	Test_Source_Test_Public_MyCharacterStatComponent_h_13_INCLASS \
	Test_Source_Test_Public_MyCharacterStatComponent_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Test_Source_Test_Public_MyCharacterStatComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_Public_MyCharacterStatComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_Public_MyCharacterStatComponent_h_13_SPARSE_DATA \
	Test_Source_Test_Public_MyCharacterStatComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Test_Source_Test_Public_MyCharacterStatComponent_h_13_INCLASS_NO_PURE_DECLS \
	Test_Source_Test_Public_MyCharacterStatComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEST_API UClass* StaticClass<class UMyCharacterStatComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Test_Source_Test_Public_MyCharacterStatComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
