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



#include "Zone.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {




Zone::Zone()
{
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Type = utility::conversions::to_string_t("");
    m_TypeIsSet = false;
    m_Url = utility::conversions::to_string_t("");
    m_UrlIsSet = false;
    m_Kind = utility::conversions::to_string_t("");
    m_KindIsSet = false;
    m_RrsetsIsSet = false;
    m_Serial = 0;
    m_SerialIsSet = false;
    m_Notified_serial = 0;
    m_Notified_serialIsSet = false;
    m_Edited_serial = 0;
    m_Edited_serialIsSet = false;
    m_MastersIsSet = false;
    m_Dnssec = false;
    m_DnssecIsSet = false;
    m_Nsec3param = utility::conversions::to_string_t("");
    m_Nsec3paramIsSet = false;
    m_Nsec3narrow = false;
    m_Nsec3narrowIsSet = false;
    m_Presigned = false;
    m_PresignedIsSet = false;
    m_Soa_edit = utility::conversions::to_string_t("");
    m_Soa_editIsSet = false;
    m_Soa_edit_api = utility::conversions::to_string_t("");
    m_Soa_edit_apiIsSet = false;
    m_Api_rectify = false;
    m_Api_rectifyIsSet = false;
    m_Zone = utility::conversions::to_string_t("");
    m_ZoneIsSet = false;
    m_Account = utility::conversions::to_string_t("");
    m_AccountIsSet = false;
    m_NameserversIsSet = false;
    m_Master_tsig_key_idsIsSet = false;
    m_Slave_tsig_key_idsIsSet = false;
}

Zone::~Zone()
{
}

void Zone::validate()
{
    // TODO: implement validation
}

web::json::value Zone::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t("id")] = ModelBase::toJson(m_Id);
    }
    if(m_NameIsSet)
    {
        val[utility::conversions::to_string_t("name")] = ModelBase::toJson(m_Name);
    }
    if(m_TypeIsSet)
    {
        val[utility::conversions::to_string_t("type")] = ModelBase::toJson(m_Type);
    }
    if(m_UrlIsSet)
    {
        val[utility::conversions::to_string_t("url")] = ModelBase::toJson(m_Url);
    }
    if(m_KindIsSet)
    {
        val[utility::conversions::to_string_t("kind")] = ModelBase::toJson(m_Kind);
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Rrsets )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("rrsets")] = web::json::value::array(jsonArray);
        }
    }
    if(m_SerialIsSet)
    {
        val[utility::conversions::to_string_t("serial")] = ModelBase::toJson(m_Serial);
    }
    if(m_Notified_serialIsSet)
    {
        val[utility::conversions::to_string_t("notified_serial")] = ModelBase::toJson(m_Notified_serial);
    }
    if(m_Edited_serialIsSet)
    {
        val[utility::conversions::to_string_t("edited_serial")] = ModelBase::toJson(m_Edited_serial);
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Masters )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("masters")] = web::json::value::array(jsonArray);
        }
    }
    if(m_DnssecIsSet)
    {
        val[utility::conversions::to_string_t("dnssec")] = ModelBase::toJson(m_Dnssec);
    }
    if(m_Nsec3paramIsSet)
    {
        val[utility::conversions::to_string_t("nsec3param")] = ModelBase::toJson(m_Nsec3param);
    }
    if(m_Nsec3narrowIsSet)
    {
        val[utility::conversions::to_string_t("nsec3narrow")] = ModelBase::toJson(m_Nsec3narrow);
    }
    if(m_PresignedIsSet)
    {
        val[utility::conversions::to_string_t("presigned")] = ModelBase::toJson(m_Presigned);
    }
    if(m_Soa_editIsSet)
    {
        val[utility::conversions::to_string_t("soa_edit")] = ModelBase::toJson(m_Soa_edit);
    }
    if(m_Soa_edit_apiIsSet)
    {
        val[utility::conversions::to_string_t("soa_edit_api")] = ModelBase::toJson(m_Soa_edit_api);
    }
    if(m_Api_rectifyIsSet)
    {
        val[utility::conversions::to_string_t("api_rectify")] = ModelBase::toJson(m_Api_rectify);
    }
    if(m_ZoneIsSet)
    {
        val[utility::conversions::to_string_t("zone")] = ModelBase::toJson(m_Zone);
    }
    if(m_AccountIsSet)
    {
        val[utility::conversions::to_string_t("account")] = ModelBase::toJson(m_Account);
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Nameservers )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("nameservers")] = web::json::value::array(jsonArray);
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Master_tsig_key_ids )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("master_tsig_key_ids")] = web::json::value::array(jsonArray);
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Slave_tsig_key_ids )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("slave_tsig_key_ids")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void Zone::fromJson(const web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("id")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("id"));
        if(!fieldValue.is_null())
        {
            setId(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("name")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("name"));
        if(!fieldValue.is_null())
        {
            setName(ModelBase::stringFromJson(fieldValue));
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
    if(val.has_field(utility::conversions::to_string_t("url")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("url"));
        if(!fieldValue.is_null())
        {
            setUrl(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("kind")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("kind"));
        if(!fieldValue.is_null())
        {
            setKind(ModelBase::stringFromJson(fieldValue));
        }
    }
    {
        m_Rrsets.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("rrsets")))
        {
        for( auto& item : val.at(utility::conversions::to_string_t("rrsets")).as_array() )
        {
            if(item.is_null())
            {
                m_Rrsets.push_back( std::shared_ptr<RRSet>(nullptr) );
            }
            else
            {
                std::shared_ptr<RRSet> newItem(new RRSet());
                newItem->fromJson(item);
                m_Rrsets.push_back( newItem );
            }
        }
        }
    }
    if(val.has_field(utility::conversions::to_string_t("serial")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("serial"));
        if(!fieldValue.is_null())
        {
            setSerial(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("notified_serial")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("notified_serial"));
        if(!fieldValue.is_null())
        {
            setNotifiedSerial(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("edited_serial")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("edited_serial"));
        if(!fieldValue.is_null())
        {
            setEditedSerial(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    {
        m_Masters.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("masters")))
        {
        for( auto& item : val.at(utility::conversions::to_string_t("masters")).as_array() )
        {
            m_Masters.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
    if(val.has_field(utility::conversions::to_string_t("dnssec")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("dnssec"));
        if(!fieldValue.is_null())
        {
            setDnssec(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("nsec3param")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("nsec3param"));
        if(!fieldValue.is_null())
        {
            setNsec3param(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("nsec3narrow")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("nsec3narrow"));
        if(!fieldValue.is_null())
        {
            setNsec3narrow(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("presigned")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("presigned"));
        if(!fieldValue.is_null())
        {
            setPresigned(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("soa_edit")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("soa_edit"));
        if(!fieldValue.is_null())
        {
            setSoaEdit(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("soa_edit_api")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("soa_edit_api"));
        if(!fieldValue.is_null())
        {
            setSoaEditApi(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("api_rectify")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("api_rectify"));
        if(!fieldValue.is_null())
        {
            setApiRectify(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("zone")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("zone"));
        if(!fieldValue.is_null())
        {
            setZone(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("account")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("account"));
        if(!fieldValue.is_null())
        {
            setAccount(ModelBase::stringFromJson(fieldValue));
        }
    }
    {
        m_Nameservers.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("nameservers")))
        {
        for( auto& item : val.at(utility::conversions::to_string_t("nameservers")).as_array() )
        {
            m_Nameservers.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
    {
        m_Master_tsig_key_ids.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("master_tsig_key_ids")))
        {
        for( auto& item : val.at(utility::conversions::to_string_t("master_tsig_key_ids")).as_array() )
        {
            m_Master_tsig_key_ids.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
    {
        m_Slave_tsig_key_ids.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("slave_tsig_key_ids")))
        {
        for( auto& item : val.at(utility::conversions::to_string_t("slave_tsig_key_ids")).as_array() )
        {
            m_Slave_tsig_key_ids.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
}

void Zone::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("id"), m_Id));
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("name"), m_Name));
    }
    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("type"), m_Type));
    }
    if(m_UrlIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("url"), m_Url));
    }
    if(m_KindIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("kind"), m_Kind));
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Rrsets )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("rrsets"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
    if(m_SerialIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("serial"), m_Serial));
    }
    if(m_Notified_serialIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("notified_serial"), m_Notified_serial));
    }
    if(m_Edited_serialIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("edited_serial"), m_Edited_serial));
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Masters )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("masters"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
    if(m_DnssecIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("dnssec"), m_Dnssec));
    }
    if(m_Nsec3paramIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("nsec3param"), m_Nsec3param));
    }
    if(m_Nsec3narrowIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("nsec3narrow"), m_Nsec3narrow));
    }
    if(m_PresignedIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("presigned"), m_Presigned));
    }
    if(m_Soa_editIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("soa_edit"), m_Soa_edit));
    }
    if(m_Soa_edit_apiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("soa_edit_api"), m_Soa_edit_api));
    }
    if(m_Api_rectifyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("api_rectify"), m_Api_rectify));
    }
    if(m_ZoneIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("zone"), m_Zone));
    }
    if(m_AccountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("account"), m_Account));
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Nameservers )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("nameservers"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Master_tsig_key_ids )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("master_tsig_key_ids"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Slave_tsig_key_ids )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("slave_tsig_key_ids"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
}

void Zone::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("id")))
    {
        setId(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("id"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("name"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("type")))
    {
        setType(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("type"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("url")))
    {
        setUrl(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("url"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("kind")))
    {
        setKind(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("kind"))));
    }
    {
        m_Rrsets.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("rrsets")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("rrsets"))));
        for( auto& item : jsonArray.as_array() )
        {
            if(item.is_null())
            {
                m_Rrsets.push_back( std::shared_ptr<RRSet>(nullptr) );
            }
            else
            {
                std::shared_ptr<RRSet> newItem(new RRSet());
                newItem->fromJson(item);
                m_Rrsets.push_back( newItem );
            }
        }
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("serial")))
    {
        setSerial(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("serial"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("notified_serial")))
    {
        setNotifiedSerial(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("notified_serial"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("edited_serial")))
    {
        setEditedSerial(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("edited_serial"))));
    }
    {
        m_Masters.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("masters")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("masters"))));
        for( auto& item : jsonArray.as_array() )
        {
            m_Masters.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("dnssec")))
    {
        setDnssec(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("dnssec"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("nsec3param")))
    {
        setNsec3param(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("nsec3param"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("nsec3narrow")))
    {
        setNsec3narrow(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("nsec3narrow"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("presigned")))
    {
        setPresigned(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("presigned"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("soa_edit")))
    {
        setSoaEdit(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("soa_edit"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("soa_edit_api")))
    {
        setSoaEditApi(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("soa_edit_api"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("api_rectify")))
    {
        setApiRectify(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("api_rectify"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("zone")))
    {
        setZone(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("zone"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("account")))
    {
        setAccount(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("account"))));
    }
    {
        m_Nameservers.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("nameservers")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("nameservers"))));
        for( auto& item : jsonArray.as_array() )
        {
            m_Nameservers.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
    {
        m_Master_tsig_key_ids.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("master_tsig_key_ids")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("master_tsig_key_ids"))));
        for( auto& item : jsonArray.as_array() )
        {
            m_Master_tsig_key_ids.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
    {
        m_Slave_tsig_key_ids.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("slave_tsig_key_ids")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("slave_tsig_key_ids"))));
        for( auto& item : jsonArray.as_array() )
        {
            m_Slave_tsig_key_ids.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
}

utility::string_t Zone::getId() const
{
    return m_Id;
}

void Zone::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool Zone::idIsSet() const
{
    return m_IdIsSet;
}

void Zone::unsetId()
{
    m_IdIsSet = false;
}

utility::string_t Zone::getName() const
{
    return m_Name;
}

void Zone::setName(const utility::string_t& value)
{
    m_Name = value;
    m_NameIsSet = true;
}

bool Zone::nameIsSet() const
{
    return m_NameIsSet;
}

void Zone::unsetName()
{
    m_NameIsSet = false;
}

utility::string_t Zone::getType() const
{
    return m_Type;
}

void Zone::setType(const utility::string_t& value)
{
    m_Type = value;
    m_TypeIsSet = true;
}

bool Zone::typeIsSet() const
{
    return m_TypeIsSet;
}

void Zone::unsetType()
{
    m_TypeIsSet = false;
}

utility::string_t Zone::getUrl() const
{
    return m_Url;
}

void Zone::setUrl(const utility::string_t& value)
{
    m_Url = value;
    m_UrlIsSet = true;
}

bool Zone::urlIsSet() const
{
    return m_UrlIsSet;
}

void Zone::unsetUrl()
{
    m_UrlIsSet = false;
}

utility::string_t Zone::getKind() const
{
    return m_Kind;
}

void Zone::setKind(const utility::string_t& value)
{
    m_Kind = value;
    m_KindIsSet = true;
}

bool Zone::kindIsSet() const
{
    return m_KindIsSet;
}

void Zone::unsetKind()
{
    m_KindIsSet = false;
}

std::vector<std::shared_ptr<RRSet>>& Zone::getRrsets()
{
    return m_Rrsets;
}

void Zone::setRrsets(const std::vector<std::shared_ptr<RRSet>>& value)
{
    m_Rrsets = value;
    m_RrsetsIsSet = true;
}

bool Zone::rrsetsIsSet() const
{
    return m_RrsetsIsSet;
}

void Zone::unsetRrsets()
{
    m_RrsetsIsSet = false;
}

int32_t Zone::getSerial() const
{
    return m_Serial;
}

void Zone::setSerial(int32_t value)
{
    m_Serial = value;
    m_SerialIsSet = true;
}

bool Zone::serialIsSet() const
{
    return m_SerialIsSet;
}

void Zone::unsetSerial()
{
    m_SerialIsSet = false;
}

int32_t Zone::getNotifiedSerial() const
{
    return m_Notified_serial;
}

void Zone::setNotifiedSerial(int32_t value)
{
    m_Notified_serial = value;
    m_Notified_serialIsSet = true;
}

bool Zone::notifiedSerialIsSet() const
{
    return m_Notified_serialIsSet;
}

void Zone::unsetNotified_serial()
{
    m_Notified_serialIsSet = false;
}

int32_t Zone::getEditedSerial() const
{
    return m_Edited_serial;
}

void Zone::setEditedSerial(int32_t value)
{
    m_Edited_serial = value;
    m_Edited_serialIsSet = true;
}

bool Zone::editedSerialIsSet() const
{
    return m_Edited_serialIsSet;
}

void Zone::unsetEdited_serial()
{
    m_Edited_serialIsSet = false;
}

std::vector<utility::string_t>& Zone::getMasters()
{
    return m_Masters;
}

void Zone::setMasters(const std::vector<utility::string_t>& value)
{
    m_Masters = value;
    m_MastersIsSet = true;
}

bool Zone::mastersIsSet() const
{
    return m_MastersIsSet;
}

void Zone::unsetMasters()
{
    m_MastersIsSet = false;
}

bool Zone::isDnssec() const
{
    return m_Dnssec;
}

void Zone::setDnssec(bool value)
{
    m_Dnssec = value;
    m_DnssecIsSet = true;
}

bool Zone::dnssecIsSet() const
{
    return m_DnssecIsSet;
}

void Zone::unsetDnssec()
{
    m_DnssecIsSet = false;
}

utility::string_t Zone::getNsec3param() const
{
    return m_Nsec3param;
}

void Zone::setNsec3param(const utility::string_t& value)
{
    m_Nsec3param = value;
    m_Nsec3paramIsSet = true;
}

bool Zone::nsec3paramIsSet() const
{
    return m_Nsec3paramIsSet;
}

void Zone::unsetNsec3param()
{
    m_Nsec3paramIsSet = false;
}

bool Zone::isNsec3narrow() const
{
    return m_Nsec3narrow;
}

void Zone::setNsec3narrow(bool value)
{
    m_Nsec3narrow = value;
    m_Nsec3narrowIsSet = true;
}

bool Zone::nsec3narrowIsSet() const
{
    return m_Nsec3narrowIsSet;
}

void Zone::unsetNsec3narrow()
{
    m_Nsec3narrowIsSet = false;
}

bool Zone::isPresigned() const
{
    return m_Presigned;
}

void Zone::setPresigned(bool value)
{
    m_Presigned = value;
    m_PresignedIsSet = true;
}

bool Zone::presignedIsSet() const
{
    return m_PresignedIsSet;
}

void Zone::unsetPresigned()
{
    m_PresignedIsSet = false;
}

utility::string_t Zone::getSoaEdit() const
{
    return m_Soa_edit;
}

void Zone::setSoaEdit(const utility::string_t& value)
{
    m_Soa_edit = value;
    m_Soa_editIsSet = true;
}

bool Zone::soaEditIsSet() const
{
    return m_Soa_editIsSet;
}

void Zone::unsetSoa_edit()
{
    m_Soa_editIsSet = false;
}

utility::string_t Zone::getSoaEditApi() const
{
    return m_Soa_edit_api;
}

void Zone::setSoaEditApi(const utility::string_t& value)
{
    m_Soa_edit_api = value;
    m_Soa_edit_apiIsSet = true;
}

bool Zone::soaEditApiIsSet() const
{
    return m_Soa_edit_apiIsSet;
}

void Zone::unsetSoa_edit_api()
{
    m_Soa_edit_apiIsSet = false;
}

bool Zone::isApiRectify() const
{
    return m_Api_rectify;
}

void Zone::setApiRectify(bool value)
{
    m_Api_rectify = value;
    m_Api_rectifyIsSet = true;
}

bool Zone::apiRectifyIsSet() const
{
    return m_Api_rectifyIsSet;
}

void Zone::unsetApi_rectify()
{
    m_Api_rectifyIsSet = false;
}

utility::string_t Zone::getZone() const
{
    return m_Zone;
}

void Zone::setZone(const utility::string_t& value)
{
    m_Zone = value;
    m_ZoneIsSet = true;
}

bool Zone::zoneIsSet() const
{
    return m_ZoneIsSet;
}

void Zone::unsetZone()
{
    m_ZoneIsSet = false;
}

utility::string_t Zone::getAccount() const
{
    return m_Account;
}

void Zone::setAccount(const utility::string_t& value)
{
    m_Account = value;
    m_AccountIsSet = true;
}

bool Zone::accountIsSet() const
{
    return m_AccountIsSet;
}

void Zone::unsetAccount()
{
    m_AccountIsSet = false;
}

std::vector<utility::string_t>& Zone::getNameservers()
{
    return m_Nameservers;
}

void Zone::setNameservers(const std::vector<utility::string_t>& value)
{
    m_Nameservers = value;
    m_NameserversIsSet = true;
}

bool Zone::nameserversIsSet() const
{
    return m_NameserversIsSet;
}

void Zone::unsetNameservers()
{
    m_NameserversIsSet = false;
}

std::vector<utility::string_t>& Zone::getMasterTsigKeyIds()
{
    return m_Master_tsig_key_ids;
}

void Zone::setMasterTsigKeyIds(const std::vector<utility::string_t>& value)
{
    m_Master_tsig_key_ids = value;
    m_Master_tsig_key_idsIsSet = true;
}

bool Zone::masterTsigKeyIdsIsSet() const
{
    return m_Master_tsig_key_idsIsSet;
}

void Zone::unsetMaster_tsig_key_ids()
{
    m_Master_tsig_key_idsIsSet = false;
}

std::vector<utility::string_t>& Zone::getSlaveTsigKeyIds()
{
    return m_Slave_tsig_key_ids;
}

void Zone::setSlaveTsigKeyIds(const std::vector<utility::string_t>& value)
{
    m_Slave_tsig_key_ids = value;
    m_Slave_tsig_key_idsIsSet = true;
}

bool Zone::slaveTsigKeyIdsIsSet() const
{
    return m_Slave_tsig_key_idsIsSet;
}

void Zone::unsetSlave_tsig_key_ids()
{
    m_Slave_tsig_key_idsIsSet = false;
}

}
}
}
}


