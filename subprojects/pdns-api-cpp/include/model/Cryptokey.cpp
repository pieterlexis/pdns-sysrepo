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



#include "Cryptokey.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {




Cryptokey::Cryptokey()
{
    m_Type = utility::conversions::to_string_t("");
    m_TypeIsSet = false;
    m_Id = 0;
    m_IdIsSet = false;
    m_Keytype = utility::conversions::to_string_t("");
    m_KeytypeIsSet = false;
    m_Active = false;
    m_ActiveIsSet = false;
    m_Dnskey = utility::conversions::to_string_t("");
    m_DnskeyIsSet = false;
    m_DsIsSet = false;
    m_Privatekey = utility::conversions::to_string_t("");
    m_PrivatekeyIsSet = false;
    m_Algorithm = utility::conversions::to_string_t("");
    m_AlgorithmIsSet = false;
    m_Bits = 0;
    m_BitsIsSet = false;
}

Cryptokey::~Cryptokey()
{
}

void Cryptokey::validate()
{
    // TODO: implement validation
}

web::json::value Cryptokey::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_TypeIsSet)
    {
        val[utility::conversions::to_string_t("type")] = ModelBase::toJson(m_Type);
    }
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t("id")] = ModelBase::toJson(m_Id);
    }
    if(m_KeytypeIsSet)
    {
        val[utility::conversions::to_string_t("keytype")] = ModelBase::toJson(m_Keytype);
    }
    if(m_ActiveIsSet)
    {
        val[utility::conversions::to_string_t("active")] = ModelBase::toJson(m_Active);
    }
    if(m_DnskeyIsSet)
    {
        val[utility::conversions::to_string_t("dnskey")] = ModelBase::toJson(m_Dnskey);
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Ds )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("ds")] = web::json::value::array(jsonArray);
        }
    }
    if(m_PrivatekeyIsSet)
    {
        val[utility::conversions::to_string_t("privatekey")] = ModelBase::toJson(m_Privatekey);
    }
    if(m_AlgorithmIsSet)
    {
        val[utility::conversions::to_string_t("algorithm")] = ModelBase::toJson(m_Algorithm);
    }
    if(m_BitsIsSet)
    {
        val[utility::conversions::to_string_t("bits")] = ModelBase::toJson(m_Bits);
    }

    return val;
}

void Cryptokey::fromJson(const web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("type")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("type"));
        if(!fieldValue.is_null())
        {
            setType(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("id")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("id"));
        if(!fieldValue.is_null())
        {
            setId(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("keytype")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("keytype"));
        if(!fieldValue.is_null())
        {
            setKeytype(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("active")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("active"));
        if(!fieldValue.is_null())
        {
            setActive(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("dnskey")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("dnskey"));
        if(!fieldValue.is_null())
        {
            setDnskey(ModelBase::stringFromJson(fieldValue));
        }
    }
    {
        m_Ds.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("ds")))
        {
        for( auto& item : val.at(utility::conversions::to_string_t("ds")).as_array() )
        {
            m_Ds.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
    if(val.has_field(utility::conversions::to_string_t("privatekey")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("privatekey"));
        if(!fieldValue.is_null())
        {
            setPrivatekey(ModelBase::stringFromJson(fieldValue));
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
    if(val.has_field(utility::conversions::to_string_t("bits")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("bits"));
        if(!fieldValue.is_null())
        {
            setBits(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void Cryptokey::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("type"), m_Type));
    }
    if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("id"), m_Id));
    }
    if(m_KeytypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("keytype"), m_Keytype));
    }
    if(m_ActiveIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("active"), m_Active));
    }
    if(m_DnskeyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("dnskey"), m_Dnskey));
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Ds )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ds"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
    if(m_PrivatekeyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("privatekey"), m_Privatekey));
    }
    if(m_AlgorithmIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("algorithm"), m_Algorithm));
    }
    if(m_BitsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("bits"), m_Bits));
    }
}

void Cryptokey::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("type")))
    {
        setType(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("type"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("id")))
    {
        setId(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("id"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("keytype")))
    {
        setKeytype(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("keytype"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("active")))
    {
        setActive(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("active"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("dnskey")))
    {
        setDnskey(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("dnskey"))));
    }
    {
        m_Ds.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("ds")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ds"))));
        for( auto& item : jsonArray.as_array() )
        {
            m_Ds.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("privatekey")))
    {
        setPrivatekey(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("privatekey"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("algorithm")))
    {
        setAlgorithm(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("algorithm"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("bits")))
    {
        setBits(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("bits"))));
    }
}

utility::string_t Cryptokey::getType() const
{
    return m_Type;
}

void Cryptokey::setType(const utility::string_t& value)
{
    m_Type = value;
    m_TypeIsSet = true;
}

bool Cryptokey::typeIsSet() const
{
    return m_TypeIsSet;
}

void Cryptokey::unsetType()
{
    m_TypeIsSet = false;
}

int32_t Cryptokey::getId() const
{
    return m_Id;
}

void Cryptokey::setId(int32_t value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool Cryptokey::idIsSet() const
{
    return m_IdIsSet;
}

void Cryptokey::unsetId()
{
    m_IdIsSet = false;
}

utility::string_t Cryptokey::getKeytype() const
{
    return m_Keytype;
}

void Cryptokey::setKeytype(const utility::string_t& value)
{
    m_Keytype = value;
    m_KeytypeIsSet = true;
}

bool Cryptokey::keytypeIsSet() const
{
    return m_KeytypeIsSet;
}

void Cryptokey::unsetKeytype()
{
    m_KeytypeIsSet = false;
}

bool Cryptokey::isActive() const
{
    return m_Active;
}

void Cryptokey::setActive(bool value)
{
    m_Active = value;
    m_ActiveIsSet = true;
}

bool Cryptokey::activeIsSet() const
{
    return m_ActiveIsSet;
}

void Cryptokey::unsetActive()
{
    m_ActiveIsSet = false;
}

utility::string_t Cryptokey::getDnskey() const
{
    return m_Dnskey;
}

void Cryptokey::setDnskey(const utility::string_t& value)
{
    m_Dnskey = value;
    m_DnskeyIsSet = true;
}

bool Cryptokey::dnskeyIsSet() const
{
    return m_DnskeyIsSet;
}

void Cryptokey::unsetDnskey()
{
    m_DnskeyIsSet = false;
}

std::vector<utility::string_t>& Cryptokey::getDs()
{
    return m_Ds;
}

void Cryptokey::setDs(const std::vector<utility::string_t>& value)
{
    m_Ds = value;
    m_DsIsSet = true;
}

bool Cryptokey::dsIsSet() const
{
    return m_DsIsSet;
}

void Cryptokey::unsetDs()
{
    m_DsIsSet = false;
}

utility::string_t Cryptokey::getPrivatekey() const
{
    return m_Privatekey;
}

void Cryptokey::setPrivatekey(const utility::string_t& value)
{
    m_Privatekey = value;
    m_PrivatekeyIsSet = true;
}

bool Cryptokey::privatekeyIsSet() const
{
    return m_PrivatekeyIsSet;
}

void Cryptokey::unsetPrivatekey()
{
    m_PrivatekeyIsSet = false;
}

utility::string_t Cryptokey::getAlgorithm() const
{
    return m_Algorithm;
}

void Cryptokey::setAlgorithm(const utility::string_t& value)
{
    m_Algorithm = value;
    m_AlgorithmIsSet = true;
}

bool Cryptokey::algorithmIsSet() const
{
    return m_AlgorithmIsSet;
}

void Cryptokey::unsetAlgorithm()
{
    m_AlgorithmIsSet = false;
}

int32_t Cryptokey::getBits() const
{
    return m_Bits;
}

void Cryptokey::setBits(int32_t value)
{
    m_Bits = value;
    m_BitsIsSet = true;
}

bool Cryptokey::bitsIsSet() const
{
    return m_BitsIsSet;
}

void Cryptokey::unsetBits()
{
    m_BitsIsSet = false;
}

}
}
}
}


