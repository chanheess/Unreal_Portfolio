// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEST_MyCharacterWidget_generated_h
#error "MyCharacterWidget.generated.h already included, missing '#pragma once' in MyCharacterWidget.h"
#endif
#define TEST_MyCharacterWidget_generated_h

#define Test_Source_Test_Public_MyCharacterWidget_h_10_SPARSE_DATA
#define Test_Source_Test_Public_MyCharacterWidget_h_10_RPC_WRAPPERS
#define Test_Source_Test_Public_MyCharacterWidget_h_10_RPC_WRAPPERS_NO_PURE_DECLS
#define Test_Source_Test_Public_MyCharacterWidget_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyCharacterWidget(); \
	friend struct Z_Construct_UClass_UMyCharacterWidget_Statics; \
public: \
	DECLARE_CLASS(UMyCharacterWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(UMyCharacterWidget)


#define Test_Source_Test_Public_MyCharacterWidget_h_10_INCLASS \
private: \
	static void StaticRegisterNativesUMyCharacterWidget(); \
	friend struct Z_Construct_UClass_UMyCharacterWidget_Statics; \
public: \
	DECLARE_CLASS(UMyCharacterWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(UMyCharacterWidget)


#define Test_Source_Test_Public_MyCharacterWidget_h_10_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyCharacterWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyCharacterWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyCharacterWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyCharacterWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyCharacterWidget(UMyCharacterWidget&&); \
	NO_API UMyCharacterWidget(const UMyCharacterWidget&); \
public:


#define Test_Source_Test_Public_MyCharacterWidget_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyCharacterWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyCharacterWidget(UMyCharacterWidget&&); \
	NO_API UMyCharacterWidget(const UMyCharacterWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyCharacterWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyCharacterWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyCharacterWidget)


#define Test_Source_Test_Public_MyCharacterWidget_h_10_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__HpProgressBar() { return STRUCT_OFFSET(UMyCharacterWidget, HpProgressBar); }


#define Test_Source_Test_Public_MyCharacterWidget_h_7_PROLOG
#define Test_Source_Test_Public_MyCharacterWidget_h_10_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_Public_MyCharacterWidget_h_10_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_Public_MyCharacterWidget_h_10_SPARSE_DATA \
	Test_Source_Test_Public_MyCharacterWidget_h_10_RPC_WRAPPERS \
	Test_Source_Test_Public_MyCharacterWidget_h_10_INCLASS \
	Test_Source_Test_Public_MyCharacterWidget_h_10_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Test_Source_Test_Public_MyCharacterWidget_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_Public_MyCharacterWidget_h_10_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_Public_MyCharacterWidget_h_10_SPARSE_DATA \
	Test_Source_Test_Public_MyCharacterWidget_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	Test_Source_Test_Public_MyCharacterWidget_h_10_INCLASS_NO_PURE_DECLS \
	Test_Source_Test_Public_MyCharacterWidget_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEST_API UClass* StaticClass<class UMyCharacterWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Test_Source_Test_Public_MyCharacterWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
