// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BombScapeCharacter.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPLayerReviceDamage, int, currentLife);

UCLASS(config=Game)
class ABombScapeCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camer a behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	ABombScapeCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* SpawnBomb = nullptr;
    
	void GetDamage(int Damage);
	
	UPROPERTY(BlueprintAssignable)
	FOnPLayerReviceDamage OnPLayerReviceDamageC;
	UFUNCTION(BlueprintImplementableEvent)
		void RestartGame();

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int GetCurrentLife(){return life;};

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int GetMaxLife(){return MaxLife;};

	


protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class ATC_Bomb> BombClass; //referencia a la clase de un objeto
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class ATC_Bomb> BombClassHeavy; //referencia a la clase de un objeto
	UFUNCTION()
			void Bomb();
	UFUNCTION()
	void BombHeavy();
	//Vide del jugador
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int life = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxLife = 5;
	UFUNCTION(BlueprintImplementableEvent)
		void BP_GetDamageEvent(int Damage);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

