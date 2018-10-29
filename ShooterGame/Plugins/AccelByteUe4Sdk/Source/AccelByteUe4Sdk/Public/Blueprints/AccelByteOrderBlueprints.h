// Copyright (c) 2018 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#pragma once

#include "CoreMinimal.h"
#include "AccelByteOrderModels.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AccelByteOrderBlueprints.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UAccelByteBlueprintsOrder : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	DECLARE_DYNAMIC_DELEGATE_TwoParams(FBlueprintErrorHandler, int32, ErrorCode, FString, ErrorMessage);
	
	DECLARE_DYNAMIC_DELEGATE_OneParam(FCreateNewOrderSuccess, const FAccelByteModelsOrderInfo&, Result);
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Order | Api ")
	static void CreateNewOrder(const FString& AccessToken, const FString& Namespace, const FString& UserId, const FAccelByteModelsOrderCreate& OrderCreate, const FCreateNewOrderSuccess& OnSuccess, const FBlueprintErrorHandler& OnError);
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Order | Api ")
	static void CreateNewOrderEasy(const FAccelByteModelsOrderCreate& OrderCreate, const FCreateNewOrderSuccess& OnSuccess, const FBlueprintErrorHandler& OnError);

	DECLARE_DYNAMIC_DELEGATE_OneParam(FGetUserOrderSuccess, const FAccelByteModelsOrderInfo&, Result);
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Order | Api ")
	static void GetUserOrder(const FString& AccessToken, const FString& Namespace, const FString& UserId, const FString& OrderNo, const FGetUserOrderSuccess& OnSuccess, const FBlueprintErrorHandler& OnError);
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Order | Api ")
	static void GetUserOrderEasy(const FString& OrderNo, const FGetUserOrderSuccess& OnSuccess, const FBlueprintErrorHandler& OnError);

	DECLARE_DYNAMIC_DELEGATE_OneParam(FGetUserOrdersSuccess, const FAccelByteModelsOrderInfoPaging&, Result);
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Order | Api ")
	static void GetUserOrders(const FString& AccessToken, const FString& Namespace, const FString& UserId, int32 Page, int32 Size, const FGetUserOrdersSuccess& OnSuccess, const FBlueprintErrorHandler& OnError);
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Order | Api ")
	static void GetUserOrdersEasy(int32 Page, int32 Size, const FGetUserOrdersSuccess& OnSuccess, const FBlueprintErrorHandler& OnError);

	DECLARE_DYNAMIC_DELEGATE_OneParam(FFulfillOrderSuccess, const FAccelByteModelsOrderInfo&, Result);
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Order | Api ")
	static void FulfillOrder(const FString& AccessToken, const FString& Namespace, const FString& UserId, const FString& OrderNo, const FFulfillOrderSuccess& OnSuccess, const FBlueprintErrorHandler& OnError);
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Order | Api ")
	static void FulfillOrderEasy(const FString& OrderNo, const FFulfillOrderSuccess& OnSuccess, const FBlueprintErrorHandler& OnError);

	DECLARE_DYNAMIC_DELEGATE_OneParam(FGetUserOrderHistorySuccess, const TArray<FAccelByteModelsOrderHistoryInfo>&, Result);
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Order | Api ")
	static void GetUserOrderHistory(const FString& AccessToken, const FString& Namespace, const FString& UserId, const FString& OrderNo, const FGetUserOrderHistorySuccess& OnSuccess, const FBlueprintErrorHandler& OnError);
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Order | Api ")
	static void GetUserOrderHistoryEasy(const FString& OrderNo, const FGetUserOrderHistorySuccess& OnSuccess, const FBlueprintErrorHandler& OnError);

};