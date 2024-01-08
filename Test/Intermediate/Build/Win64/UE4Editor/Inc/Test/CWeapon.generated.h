// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEST_CWeapon_generated_h
#error "CWeapon.generated.h already included, missing '#pragma once' in CWeapon.h"
#endif
#define TEST_CWeapon_generated_h

#define Test_Source_Test_Public_CWeapon_h_10_SPARSE_DATA
#define Test_Source_Test_Public_CWeapon_h_10_RPC_WRAPPERS
#define Test_Source_Test_Public_CWeapon_h_10_RPC_WRAPPERS_NO_PURE_DECLS
#define Test_Source_Test_Public_CWeapon_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACWeapon(); \
	friend struct Z_Construct_UClass_ACWeapon_Statics; \
public: \
	DECLARE_CLASS(ACWeapon, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(ACWeapon)


#define Test_Source_Test_Public_CWeapon_h_10_INCLASS \
private: \
	static void StaticRegisterNativesACWeapon(); \
	friend struct Z_Construct_UClass_ACWeapon_Statics; \
public: \
	DECLARE_CLASS(ACWeapon, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(ACWeapon)


#define Test_Source_Test_Public_CWeapon_h_10_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACWeapon(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACWeapon) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACWeapon); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACWeapon(ACWeapon&&); \
	NO_API ACWeapon(const ACWeapon&); \
public:


#define Test_Source_Test_Public_CWeapon_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACWeapon(ACWeapon&&); \
	NO_API ACWeapon(const ACWeapon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACWeapon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACWeapon)


#define Test_Source_Test_Public_CWeapon_h_10_PRIVATE_PROPERTY_OFFSET
#define Test_Source_Test_Public_CWeapon_h_7_PROLOG
#define Test_Source_Test_Public_CWeapon_h_10_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_Public_CWeapon_h_10_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_Public_CWeapon_h_10_SPARSE_DATA \
	Test_Source_Test_Public_CWeapon_h_10_RPC_WRAPPERS \
	Test_Source_Test_Public_CWeapon_h_10_INCLASS \
	Test_Source_Test_Public_CWeapon_h_10_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Test_Source_Test_Public_CWeapon_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_Public_CWeapon_h_10_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_Public_CWeapon_h_10_SPARSE_DATA \
	Test_Source_Test_Public_CWeapon_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	Test_Source_Test_Public_CWeapon_h_10_INCLASS_NO_PURE_DECLS \
	Test_Source_Test_Public_CWeapon_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEST_API UClass* StaticClass<class ACWeapon>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Test_Source_Test_Public_CWeapon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
