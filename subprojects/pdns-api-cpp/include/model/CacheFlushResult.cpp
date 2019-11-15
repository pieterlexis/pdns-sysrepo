/**
 * PowerDNS Authoritative HTTP API
 * No description provided (generated by Openapi Generator https://github.com/openapitools/openapi-generator)
 *
 * The version of the OpenAPI document: 0.0.13
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 4.2.1.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */



#include "CacheFlushResult.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {




CacheFlushResult::CacheFlushResult()
{
    m_Count = 0.0;
    m_CountIsSet = false;
    m_Result = utility::conversions::to_string_t("");
    m_ResultIsSet = false;
}

CacheFlushResult::~CacheFlushResult()
{
}

void CacheFlushResult::validate()
{
    // TODO: implement validation
}

web::json::value CacheFlushResult::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_CountIsSet)
    {
        val[utility::conversions::to_string_t("count")] = ModelBase::toJson(m_Count);
    }
    if(m_ResultIsSet)
    {
        val[utility::conversions::to_string_t("result")] = ModelBase::toJson(m_Result);
    }

    return val;
}

void CacheFlushResult::fromJson(const web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("count")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("count"));
        if(!fieldValue.is_null())
        {
            setCount(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("result")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("result"));
        if(!fieldValue.is_null())
        {
            setResult(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void CacheFlushResult::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_CountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("count"), m_Count));
    }
    if(m_ResultIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("result"), m_Result));
    }
}

void CacheFlushResult::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("count")))
    {
        setCount(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("count"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("result")))
    {
        setResult(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("result"))));
    }
}

double CacheFlushResult::getCount() const
{
    return m_Count;
}

void CacheFlushResult::setCount(double value)
{
    m_Count = value;
    m_CountIsSet = true;
}

bool CacheFlushResult::countIsSet() const
{
    return m_CountIsSet;
}

void CacheFlushResult::unsetCount()
{
    m_CountIsSet = false;
}

utility::string_t CacheFlushResult::getResult() const
{
    return m_Result;
}

void CacheFlushResult::setResult(const utility::string_t& value)
{
    m_Result = value;
    m_ResultIsSet = true;
}

bool CacheFlushResult::resultIsSet() const
{
    return m_ResultIsSet;
}

void CacheFlushResult::unsetResult()
{
    m_ResultIsSet = false;
}

}
}
}
}


