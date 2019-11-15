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



#include "TSIGKey.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {




TSIGKey::TSIGKey()
{
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_Algorithm = utility::conversions::to_string_t("");
    m_AlgorithmIsSet = false;
    m_Key = utility::conversions::to_string_t("");
    m_KeyIsSet = false;
    m_Type = utility::conversions::to_string_t("");
    m_TypeIsSet = false;
}

TSIGKey::~TSIGKey()
{
}

void TSIGKey::validate()
{
    // TODO: implement validation
}

web::json::value TSIGKey::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_NameIsSet)
    {
        val[utility::conversions::to_string_t("name")] = ModelBase::toJson(m_Name);
    }
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t("id")] = ModelBase::toJson(m_Id);
    }
    if(m_AlgorithmIsSet)
    {
        val[utility::conversions::to_string_t("algorithm")] = ModelBase::toJson(m_Algorithm);
    }
    if(m_KeyIsSet)
    {
        val[utility::conversions::to_string_t("key")] = ModelBase::toJson(m_Key);
    }
    if(m_TypeIsSet)
    {
        val[utility::conversions::to_string_t("type")] = ModelBase::toJson(m_Type);
    }

    return val;
}

void TSIGKey::fromJson(const web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("name")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("name"));
        if(!fieldValue.is_null())
        {
            setName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("id")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("id"));
        if(!fieldValue.is_null())
        {
            setId(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("algorithm")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("algorithm"));
        if(!fieldValue.is_null())
        {
            setAlgorithm(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("key")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("key"));
        if(!fieldValue.is_null())
        {
            setKey(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("type")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("type"));
        if(!fieldValue.is_null())
        {
            setType(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void TSIGKey::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("name"), m_Name));
    }
    if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("id"), m_Id));
    }
    if(m_AlgorithmIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("algorithm"), m_Algorithm));
    }
    if(m_KeyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("key"), m_Key));
    }
    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("type"), m_Type));
    }
}

void TSIGKey::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("name"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("id")))
    {
        setId(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("id"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("algorithm")))
    {
        setAlgorithm(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("algorithm"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("key")))
    {
        setKey(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("key"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("type")))
    {
        setType(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("type"))));
    }
}

utility::string_t TSIGKey::getName() const
{
    return m_Name;
}

void TSIGKey::setName(const utility::string_t& value)
{
    m_Name = value;
    m_NameIsSet = true;
}

bool TSIGKey::nameIsSet() const
{
    return m_NameIsSet;
}

void TSIGKey::unsetName()
{
    m_NameIsSet = false;
}

utility::string_t TSIGKey::getId() const
{
    return m_Id;
}

void TSIGKey::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool TSIGKey::idIsSet() const
{
    return m_IdIsSet;
}

void TSIGKey::unsetId()
{
    m_IdIsSet = false;
}

utility::string_t TSIGKey::getAlgorithm() const
{
    return m_Algorithm;
}

void TSIGKey::setAlgorithm(const utility::string_t& value)
{
    m_Algorithm = value;
    m_AlgorithmIsSet = true;
}

bool TSIGKey::algorithmIsSet() const
{
    return m_AlgorithmIsSet;
}

void TSIGKey::unsetAlgorithm()
{
    m_AlgorithmIsSet = false;
}

utility::string_t TSIGKey::getKey() const
{
    return m_Key;
}

void TSIGKey::setKey(const utility::string_t& value)
{
    m_Key = value;
    m_KeyIsSet = true;
}

bool TSIGKey::keyIsSet() const
{
    return m_KeyIsSet;
}

void TSIGKey::unsetKey()
{
    m_KeyIsSet = false;
}

utility::string_t TSIGKey::getType() const
{
    return m_Type;
}

void TSIGKey::setType(const utility::string_t& value)
{
    m_Type = value;
    m_TypeIsSet = true;
}

bool TSIGKey::typeIsSet() const
{
    return m_TypeIsSet;
}

void TSIGKey::unsetType()
{
    m_TypeIsSet = false;
}

}
}
}
}


