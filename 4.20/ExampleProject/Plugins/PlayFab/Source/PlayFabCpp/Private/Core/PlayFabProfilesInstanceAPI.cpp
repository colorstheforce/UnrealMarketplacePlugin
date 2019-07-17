//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabProfilesInstanceAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::ProfilesModels;

UPlayFabProfilesInstanceAPI::UPlayFabProfilesInstanceAPI()
{
}

UPlayFabProfilesInstanceAPI::UPlayFabProfilesInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

UPlayFabProfilesInstanceAPI::UPlayFabProfilesInstanceAPI(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabProfilesInstanceAPI::UPlayFabProfilesInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings, TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->settings = MoveTemp(apiSettings);
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabProfilesInstanceAPI::~UPlayFabProfilesInstanceAPI()
{
}

TSharedPtr<UPlayFabAPISettings> UPlayFabProfilesInstanceAPI::GetSettings() const
{
    return this->settings;
}

int UPlayFabProfilesInstanceAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

void UPlayFabProfilesInstanceAPI::SetSettings(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabProfilesInstanceAPI::GetAuthenticationContext() const
{
    return this->authContext;
}

void UPlayFabProfilesInstanceAPI::SetAuthenticationContext(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

void UPlayFabProfilesInstanceAPI::ForgetAllCredentials()
{
    if (!this->authContext.IsValid())
        return;

    this->authContext->ForgetAllCredentials();
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabProfilesInstanceAPI::GetOrCreateAuthenticationContext()
{
    if (!this->authContext.IsValid())
        this->authContext = MakeSharedUObject<UPlayFabAuthenticationContext>();

    return this->authContext;
}

bool UPlayFabProfilesInstanceAPI::GetGlobalPolicy(
    const FGetGlobalPolicyDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{ 
    ProfilesModels::FGetGlobalPolicyRequest emptyRequest = ProfilesModels::FGetGlobalPolicyRequest();
    return UPlayFabProfilesInstanceAPI::GetGlobalPolicy(emptyRequest, SuccessDelegate, ErrorDelegate);
}

bool UPlayFabProfilesInstanceAPI::GetGlobalPolicy(
    ProfilesModels::FGetGlobalPolicyRequest& request,
    const FGetGlobalPolicyDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Profile/GetGlobalPolicy")) : this->settings->GetUrl(TEXT("/Profile/GetGlobalPolicy")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProfilesInstanceAPI::OnGetGlobalPolicyResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProfilesInstanceAPI::OnGetGlobalPolicyResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetGlobalPolicyDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProfilesModels::FGetGlobalPolicyResponse outResult;
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

bool UPlayFabProfilesInstanceAPI::GetProfile(
    ProfilesModels::FGetEntityProfileRequest& request,
    const FGetProfileDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Profile/GetProfile")) : this->settings->GetUrl(TEXT("/Profile/GetProfile")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProfilesInstanceAPI::OnGetProfileResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProfilesInstanceAPI::OnGetProfileResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetProfileDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProfilesModels::FGetEntityProfileResponse outResult;
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

bool UPlayFabProfilesInstanceAPI::GetProfiles(
    ProfilesModels::FGetEntityProfilesRequest& request,
    const FGetProfilesDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Profile/GetProfiles")) : this->settings->GetUrl(TEXT("/Profile/GetProfiles")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProfilesInstanceAPI::OnGetProfilesResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProfilesInstanceAPI::OnGetProfilesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetProfilesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProfilesModels::FGetEntityProfilesResponse outResult;
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

bool UPlayFabProfilesInstanceAPI::GetTitlePlayersFromMasterPlayerAccountIds(
    ProfilesModels::FGetTitlePlayersFromMasterPlayerAccountIdsRequest& request,
    const FGetTitlePlayersFromMasterPlayerAccountIdsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Profile/GetTitlePlayersFromMasterPlayerAccountIds")) : this->settings->GetUrl(TEXT("/Profile/GetTitlePlayersFromMasterPlayerAccountIds")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProfilesInstanceAPI::OnGetTitlePlayersFromMasterPlayerAccountIdsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProfilesInstanceAPI::OnGetTitlePlayersFromMasterPlayerAccountIdsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetTitlePlayersFromMasterPlayerAccountIdsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProfilesModels::FGetTitlePlayersFromMasterPlayerAccountIdsResponse outResult;
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

bool UPlayFabProfilesInstanceAPI::SetGlobalPolicy(
    ProfilesModels::FSetGlobalPolicyRequest& request,
    const FSetGlobalPolicyDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Profile/SetGlobalPolicy")) : this->settings->GetUrl(TEXT("/Profile/SetGlobalPolicy")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProfilesInstanceAPI::OnSetGlobalPolicyResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProfilesInstanceAPI::OnSetGlobalPolicyResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetGlobalPolicyDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProfilesModels::FSetGlobalPolicyResponse outResult;
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

bool UPlayFabProfilesInstanceAPI::SetProfileLanguage(
    ProfilesModels::FSetProfileLanguageRequest& request,
    const FSetProfileLanguageDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Profile/SetProfileLanguage")) : this->settings->GetUrl(TEXT("/Profile/SetProfileLanguage")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProfilesInstanceAPI::OnSetProfileLanguageResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProfilesInstanceAPI::OnSetProfileLanguageResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetProfileLanguageDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProfilesModels::FSetProfileLanguageResponse outResult;
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

bool UPlayFabProfilesInstanceAPI::SetProfilePolicy(
    ProfilesModels::FSetEntityProfilePolicyRequest& request,
    const FSetProfilePolicyDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Profile/SetProfilePolicy")) : this->settings->GetUrl(TEXT("/Profile/SetProfilePolicy")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProfilesInstanceAPI::OnSetProfilePolicyResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProfilesInstanceAPI::OnSetProfilePolicyResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetProfilePolicyDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProfilesModels::FSetEntityProfilePolicyResponse outResult;
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
