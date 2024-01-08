// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Test/Public/CSection.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCSection() {}
// Cross Module References
	TEST_API UClass* Z_Construct_UClass_ACSection_NoRegister();
	TEST_API UClass* Z_Construct_UClass_ACSection();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Test();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void ACSection::StaticRegisterNativesACSection()
	{
	}
	UClass* Z_Construct_UClass_ACSection_NoRegister()
	{
		return ACSection::StaticClass();
	}
	struct Z_Construct_UClass_ACSection_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GateMeshs_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_GateMeshs;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GateMeshs_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACSection_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Test,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACSection_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CSection.h" },
		{ "ModuleRelativePath", "Public/CSection.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACSection_Statics::NewProp_GateMeshs_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CSection.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACSection_Statics::NewProp_GateMeshs = { "GateMeshs", nullptr, (EPropertyFlags)0x0040008000020009, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACSection, GateMeshs), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ACSection_Statics::NewProp_GateMeshs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACSection_Statics::NewProp_GateMeshs_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACSection_Statics::NewProp_GateMeshs_Inner = { "GateMeshs", nullptr, (EPropertyFlags)0x00000000000a0008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACSection_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACSection_Statics::NewProp_GateMeshs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACSection_Statics::NewProp_GateMeshs_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACSection_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACSection>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACSection_Statics::ClassParams = {
		&ACSection::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACSection_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACSection_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACSection_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACSection_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACSection()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACSection_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACSection, 3398329638);
	template<> TEST_API UClass* StaticClass<ACSection>()
	{
		return ACSection::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACSection(Z_Construct_UClass_ACSection, &ACSection::StaticClass, TEXT("/Script/Test"), TEXT("ACSection"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACSection);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
