// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "Components/SphereComponent.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "KartPawn.generated.h"

class UCameraComponent;

UCLASS()
class MARIOKART_API AKartPawn : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    AKartPawn();
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    UFUNCTION(BlueprintCallable,Category = "Kart")
    void SetCanMove(bool bInCanMove);
    
    UFUNCTION(BlueprintCallable,Category = "Kart")
    bool CanMove() const { return CanMove; };

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    virtual void NotifyControllerChanged() override;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Kart|Components")
    TObjectPtr<USphereComponent> CollisionSphere;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Kart|Components")
    TObjectPtr<UStaticMeshComponent> BodyMesh;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Kart|Components")
    TObjectPtr<UStaticMeshComponent> WheelFrontLeft;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Kart|Components")
    TObjectPtr<UStaticMeshComponent> WheelFrontRight;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Kart|Components")
    TObjectPtr<UStaticMeshComponent> WheelBackLeft;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Kart|Components")
    TObjectPtr<UStaticMeshComponent> WheelBackRight;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Kart|Components")
    TObjectPtr<USpringArmComponent> SpringArm;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Kart|Components")
    TObjectPtr<UCameraComponent> Camera;
    
    UPROPERTY(EditAnywhere, Category = "Kart|Input")
    TObjectPtr<UInputMappingContext> KartMappingContext;
    
    UPROPERTY(EditAnywhere, Category = "Kart|Input")
    TObjectPtr<UInputAction> ThrottlerAction;
    
    UPROPERTY(EditAnywhere, Category = "Kart|Input")
    TObjectPtr<UInputAction> SteerAction;
    
    UPROPERTY(EditAnywhere, Category = "Kart|Input")
    TObjectPtr<UInputAction> DriftAction;
    
    UPROPERTY(EditAnywhere, Category = "Kart|Input")
    TObjectPtr<UInputAction> JumpAction;
    
    UPROPERTY(EditAnywhere, Category = "Kart|Movement")
    float MaxForwardSpeed = 2500.f;
    
    UPROPERTY(EditAnywhere, Category = "Kart|Movement")
    float MaxReverseSpeed = 800.f;
    
    UPROPERTY(EditAnywhere, Category = "Kart|Movement")
    float Acceleration = 1500.f;
    
    UPROPERTY(EditAnywhere, Category = "Kart|Movement")
    float BrakedDeceleration = 3000.f;
    
    UPROPERTY(EditAnywhere, Category = "Kart|Movement")
    float CoastalDeceleration = 800.f;
};
 