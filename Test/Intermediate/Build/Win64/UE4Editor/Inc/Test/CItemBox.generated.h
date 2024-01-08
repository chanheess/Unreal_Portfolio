// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UParticleSystemComponent;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef TEST_CItemBox_generated_h
#error "CItemBox.generated.h already included, missing '#pragma once' in CItemBox.h"
#endif
#define TEST_CItemBox_generated_h

#define Test_Source_Test_Public_CItemBox_h_10_SPARSE_DATA
#define Test_Source_Test_Public_CItemBox_h_10_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnEffectFinished); \
	DECLARE_FUNCTION(execOnCharacterOverlap);


#define Test_Source_Test_Public_CItemBox_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnEffectFinished); \
	DECLARE_FUNCTION(execOnCharacterOverlap);


#define Test_Source_Test_Public_CItemBox_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACItemBox(); \
	friend struct Z_Construct_UClass_ACItemBox_Statics; \
public: \
	DECLARE_CLASS(ACItemBox, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(ACItemBox)


#define Test_Source_Test_Public_CItemBox_h_10_INCLASS \
private: \
	static void StaticRegisterNativesACItemBox(); \
	friend struct Z_Construct_UClass_ACItemBox_Statics; \
public: \
	DECLARE_CLASS(ACItemBox, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(ACItemBox)


#define Test_Source_Test_Public_CItemBox_h_10_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACItemBox(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACItemBox) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACItemBox); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACItemBox); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACItemBox(ACItemBox&&); \
	NO_API ACItemBox(const ACItemBox&); \
public:


#define Test_Source_Test_Public_CItemBox_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACItemBox(ACItemBox&&); \
	NO_API ACItemBox(const ACItemBox&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACItemBox); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACItemBox); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACItemBox)


#define Test_Source_Test_Public_CItemBox_h_10_PRIVATE_PROPERTY_OFFSET
#define Test_Source_Test_Public_CItemBox_h_7_PROLOG
#define Test_Source_Test_Public_CItemBox_h_10_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_Public_CItemBox_h_10_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_Public_CItemBox_h_10_SPARSE_DATA \
	Test_Source_Test_Public_CItemBox_h_10_RPC_WRAPPERS \
	Test_Source_Test_Public_CItemBox_h_10_INCLASS \
	Test_Source_Test_Public_CItemBox_h_10_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Test_Source_Test_Public_CItemBox_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_Public_CItemBox_h_10_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_Public_CItemBox_h_10_SPARSE_DATA \
	Test_Source_Test_Public_CItemBox_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	Test_Source_Test_Public_CItemBox_h_10_INCLASS_NO_PURE_DECLS \
	Test_Source_Test_Public_CItemBox_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEST_API UClass* StaticClass<class ACItemBox>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Test_Source_Test_Public_CItemBox_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
