// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tasks/GASAbilityTask.h"
#include "GASGlobals.h"
#include "GASAbilityTask_PlayMontage.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGASGenericMontageDelegateNoData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGASGenericMontageDelegate);

/**
 *
 */
UCLASS()
class GAMEABILITIES_API UGASAbilityTask_PlayMontage : public UGASAbilityTask
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = true))
		UAnimMontage* Montage;
	FName SectionName;
	float PlayRate;
	/* Represents data from current notify. It's mutable and data changes with each called notify. */
	UPROPERTY(BlueprintReadOnly, Category = "Notify Data")
		FGASAbilityNotifyData DataStart;

	UPROPERTY(BlueprintReadOnly, Category = "Notify Data")
		FGASAbilityNotifyData DataEnd;

	UPROPERTY(BlueprintReadOnly, Category = "Notify Data")
		FGASAbilityNotifyData DataGeneric;

	UPROPERTY(BlueprintAssignable)
		FGASGenericMontageDelegateNoData Played;
	UPROPERTY(BlueprintAssignable)
		FGASGenericMontageDelegate StartNotify;
	UPROPERTY(BlueprintAssignable)
		FGASGenericMontageDelegate EndNotify;
	UPROPERTY(BlueprintAssignable)
		FGASGenericMontageDelegate GenericNotify;
	UPROPERTY(BlueprintAssignable)
		FGASGenericMontageDelegate NotifyStateStart;
	UPROPERTY(BlueprintAssignable)
		FGASGenericMontageDelegate NotifyStateTick;
	UPROPERTY(BlueprintAssignable)
		FGASGenericMontageDelegate NotifyStateEnd;

	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "true"), Category = "Game Abilities | Tasks")
		static UGASAbilityTask_PlayMontage* AbilityPlayMontage(UObject* WorldContextObject, UAnimMontage* MontageIn, FName SectionNameIn, float PlayRateIn);

	virtual void Activate() override;

	void BroadcastStartNotify(const FGASAbilityNotifyData& DataIn);
	void BroadcastEndNotify(const FGASAbilityNotifyData& DataIn);
	void BroadcastGenericNotify(const FGASAbilityNotifyData& DataIn);
	void BroadcastStartNotifyState(const FGASAbilityNotifyData& DataIn);
	void BroadcastEndNotifyState(const FGASAbilityNotifyData& DataIn);
	void BroadcastTickNotifyState(const FGASAbilityNotifyData& DataIn);
};
