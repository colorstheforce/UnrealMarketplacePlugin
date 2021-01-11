//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabInsightsAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::InsightsModels;

UPlayFabInsightsAPI::UPlayFabInsightsAPI() {}

UPlayFabInsightsAPI::~UPlayFabInsightsAPI() {}

int UPlayFabInsightsAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

FString UPlayFabInsightsAPI::GetBuildIdentifier() const
{
    return PlayFabSettings::buildIdentifier;
}


bool UPlayFabInsightsAPI::GetDetails(
    InsightsModels::FInsightsEmptyRequest& request,
    const FGetDetailsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/Insights/GetDetails"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabInsightsAPI::OnGetDetailsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabInsightsAPI::OnGetDetailsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetDetailsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    InsightsModels::FInsightsGetDetailsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabInsightsAPI::GetLimits(
    InsightsModels::FInsightsEmptyRequest& request,
    const FGetLimitsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/Insights/GetLimits"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabInsightsAPI::OnGetLimitsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabInsightsAPI::OnGetLimitsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetLimitsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    InsightsModels::FInsightsGetLimitsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabInsightsAPI::GetOperationStatus(
    InsightsModels::FInsightsGetOperationStatusRequest& request,
    const FGetOperationStatusDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/Insights/GetOperationStatus"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabInsightsAPI::OnGetOperationStatusResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabInsightsAPI::OnGetOperationStatusResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetOperationStatusDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    InsightsModels::FInsightsGetOperationStatusResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabInsightsAPI::GetPendingOperations(
    InsightsModels::FInsightsGetPendingOperationsRequest& request,
    const FGetPendingOperationsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/Insights/GetPendingOperations"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabInsightsAPI::OnGetPendingOperationsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabInsightsAPI::OnGetPendingOperationsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetPendingOperationsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    InsightsModels::FInsightsGetPendingOperationsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabInsightsAPI::SetPerformance(
    InsightsModels::FInsightsSetPerformanceRequest& request,
    const FSetPerformanceDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/Insights/SetPerformance"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabInsightsAPI::OnSetPerformanceResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabInsightsAPI::OnSetPerformanceResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetPerformanceDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    InsightsModels::FInsightsOperationResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabInsightsAPI::SetStorageRetention(
    InsightsModels::FInsightsSetStorageRetentionRequest& request,
    const FSetStorageRetentionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/Insights/SetStorageRetention"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabInsightsAPI::OnSetStorageRetentionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabInsightsAPI::OnSetStorageRetentionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetStorageRetentionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    InsightsModels::FInsightsOperationResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}
