//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabLocalizationInstanceAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::LocalizationModels;

UPlayFabLocalizationInstanceAPI::UPlayFabLocalizationInstanceAPI()
{
}

UPlayFabLocalizationInstanceAPI::UPlayFabLocalizationInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

UPlayFabLocalizationInstanceAPI::UPlayFabLocalizationInstanceAPI(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabLocalizationInstanceAPI::UPlayFabLocalizationInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings, TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->settings = MoveTemp(apiSettings);
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabLocalizationInstanceAPI::~UPlayFabLocalizationInstanceAPI()
{
}

TSharedPtr<UPlayFabAPISettings> UPlayFabLocalizationInstanceAPI::GetSettings() const
{
    return this->settings;
}

int UPlayFabLocalizationInstanceAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

void UPlayFabLocalizationInstanceAPI::SetSettings(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabLocalizationInstanceAPI::GetAuthenticationContext() const
{
    return this->authContext;
}

void UPlayFabLocalizationInstanceAPI::SetAuthenticationContext(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

void UPlayFabLocalizationInstanceAPI::ForgetAllCredentials()
{
    if (!this->authContext.IsValid())
        return;

    this->authContext->ForgetAllCredentials();
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabLocalizationInstanceAPI::GetOrCreateAuthenticationContext()
{
    if (!this->authContext.IsValid())
        this->authContext = TSharedPtr<UPlayFabAuthenticationContext>(NewObject<UPlayFabAuthenticationContext>((UObject*)GetTransientPackage(), NAME_None, RF_Standalone));

    return this->authContext;
}

bool UPlayFabLocalizationInstanceAPI::GetLanguageList(
    const FGetLanguageListDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{ 
    LocalizationModels::FGetLanguageListRequest emptyRequest = LocalizationModels::FGetLanguageListRequest();
    return UPlayFabLocalizationInstanceAPI::GetLanguageList(emptyRequest, SuccessDelegate, ErrorDelegate);
}

bool UPlayFabLocalizationInstanceAPI::GetLanguageList(
    LocalizationModels::FGetLanguageListRequest& request,
    const FGetLanguageListDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Locale/GetLanguageList")) : this->settings->GetUrl(TEXT("/Locale/GetLanguageList")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabLocalizationInstanceAPI::OnGetLanguageListResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabLocalizationInstanceAPI::OnGetLanguageListResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetLanguageListDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    LocalizationModels::FGetLanguageListResponse outResult;
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
