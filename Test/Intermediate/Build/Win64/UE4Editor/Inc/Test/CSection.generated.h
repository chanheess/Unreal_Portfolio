// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEST_CSection_generated_h
#error "CSection.generated.h already included, missing '#pragma once' in CSection.h"
#endif
#define TEST_CSection_generated_h

#define Test_Source_Test_Public_CSection_h_10_SPARSE_DATA
#define Test_Source_Test_Public_CSection_h_10_RPC_WRAPPERS
#define Test_Source_Test_Public_CSection_h_10_RPC_WRAPPERS_NO_PURE_DECLS
#define Test_Source_Test_Public_CSection_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACSection(); \
	friend struct Z_Construct_UClass_ACSection_Statics; \
public: \
	DECLARE_CLASS(ACSection, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(ACSection)


#define Test_Source_Test_Public_CSection_h_10_INCLASS \
private: \
	static void StaticRegisterNativesACSection(); \
	friend struct Z_Construct_UClass_ACSection_Statics; \
public: \
	DECLARE_CLASS(ACSection, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(ACSection)


#define Test_Source_Test_Public_CSection_h_10_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACSection(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACSection) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACSection); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACSection); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACSection(ACSection&&); \
	NO_API ACSection(const ACSection&); \
public:


#define Test_Source_Test_Public_CSection_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACSection(ACSection&&); \
	NO_API ACSection(const ACSection&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACSection); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACSection); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACSection)


#define Test_Source_Test_Public_CSection_h_10_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__GateMeshs() { return STRUCT_OFFSET(ACSection, GateMeshs); }


#define Test_Source_Test_Public_CSection_h_7_PROLOG
#define Test_Source_Test_Public_CSection_h_10_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_Public_CSection_h_10_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_Public_CSection_h_10_SPARSE_DATA \
	Test_Source_Test_Public_CSection_h_10_RPC_WRAPPERS \
	Test_Source_Test_Public_CSection_h_10_INCLASS \
	Test_Source_Test_Public_CSection_h_10_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Test_Source_Test_Public_CSection_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_Public_CSection_h_10_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_Public_CSection_h_10_SPARSE_DATA \
	Test_Source_Test_Public_CSection_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	Test_Source_Test_Public_CSection_h_10_INCLASS_NO_PURE_DECLS \
	Test_Source_Test_Public_CSection_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEST_API UClass* StaticClass<class ACSection>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Test_Source_Test_Public_CSection_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
