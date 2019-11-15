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

/*
 * Zone.h
 *
 * This represents an authoritative DNS Zone.
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_Zone_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_Zone_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>
#include <vector>
#include "RRSet.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {


/// <summary>
/// This represents an authoritative DNS Zone.
/// </summary>
class  Zone
    : public ModelBase
{
public:
    Zone();
    virtual ~Zone();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Zone members

    /// <summary>
    /// Opaque zone id (string), assigned by the server, should not be interpreted by the application. Guaranteed to be safe for embedding in URLs.
    /// </summary>
    utility::string_t getId() const;
    bool idIsSet() const;
    void unsetId();

    void setId(const utility::string_t& value);

    /// <summary>
    /// Name of the zone (e.g. “example.com.”) MUST have a trailing dot
    /// </summary>
    utility::string_t getName() const;
    bool nameIsSet() const;
    void unsetName();

    void setName(const utility::string_t& value);

    /// <summary>
    /// Set to “Zone”
    /// </summary>
    utility::string_t getType() const;
    bool typeIsSet() const;
    void unsetType();

    void setType(const utility::string_t& value);

    /// <summary>
    /// API endpoint for this zone
    /// </summary>
    utility::string_t getUrl() const;
    bool urlIsSet() const;
    void unsetUrl();

    void setUrl(const utility::string_t& value);

    /// <summary>
    /// Zone kind, one of “Native”, “Master”, “Slave”
    /// </summary>
    utility::string_t getKind() const;
    bool kindIsSet() const;
    void unsetKind();

    void setKind(const utility::string_t& value);

    /// <summary>
    /// RRSets in this zone
    /// </summary>
    std::vector<std::shared_ptr<RRSet>>& getRrsets();
    bool rrsetsIsSet() const;
    void unsetRrsets();

    void setRrsets(const std::vector<std::shared_ptr<RRSet>>& value);

    /// <summary>
    /// The SOA serial number
    /// </summary>
    int32_t getSerial() const;
    bool serialIsSet() const;
    void unsetSerial();

    void setSerial(int32_t value);

    /// <summary>
    /// The SOA serial notifications have been sent out for
    /// </summary>
    int32_t getNotifiedSerial() const;
    bool notifiedSerialIsSet() const;
    void unsetNotified_serial();

    void setNotifiedSerial(int32_t value);

    /// <summary>
    /// The SOA serial as seen in query responses. Calculated using the SOA-EDIT metadata, default-soa-edit and default-soa-edit-signed settings
    /// </summary>
    int32_t getEditedSerial() const;
    bool editedSerialIsSet() const;
    void unsetEdited_serial();

    void setEditedSerial(int32_t value);

    /// <summary>
    ///  List of IP addresses configured as a master for this zone (“Slave” type zones only)
    /// </summary>
    std::vector<utility::string_t>& getMasters();
    bool mastersIsSet() const;
    void unsetMasters();

    void setMasters(const std::vector<utility::string_t>& value);

    /// <summary>
    /// Whether or not this zone is DNSSEC signed (inferred from presigned being true XOR presence of at least one cryptokey with active being true)
    /// </summary>
    bool isDnssec() const;
    bool dnssecIsSet() const;
    void unsetDnssec();

    void setDnssec(bool value);

    /// <summary>
    /// The NSEC3PARAM record
    /// </summary>
    utility::string_t getNsec3param() const;
    bool nsec3paramIsSet() const;
    void unsetNsec3param();

    void setNsec3param(const utility::string_t& value);

    /// <summary>
    /// Whether or not the zone uses NSEC3 narrow
    /// </summary>
    bool isNsec3narrow() const;
    bool nsec3narrowIsSet() const;
    void unsetNsec3narrow();

    void setNsec3narrow(bool value);

    /// <summary>
    /// Whether or not the zone is pre-signed
    /// </summary>
    bool isPresigned() const;
    bool presignedIsSet() const;
    void unsetPresigned();

    void setPresigned(bool value);

    /// <summary>
    /// The SOA-EDIT metadata item
    /// </summary>
    utility::string_t getSoaEdit() const;
    bool soaEditIsSet() const;
    void unsetSoa_edit();

    void setSoaEdit(const utility::string_t& value);

    /// <summary>
    /// The SOA-EDIT-API metadata item
    /// </summary>
    utility::string_t getSoaEditApi() const;
    bool soaEditApiIsSet() const;
    void unsetSoa_edit_api();

    void setSoaEditApi(const utility::string_t& value);

    /// <summary>
    ///  Whether or not the zone will be rectified on data changes via the API
    /// </summary>
    bool isApiRectify() const;
    bool apiRectifyIsSet() const;
    void unsetApi_rectify();

    void setApiRectify(bool value);

    /// <summary>
    /// MAY contain a BIND-style zone file when creating a zone
    /// </summary>
    utility::string_t getZone() const;
    bool zoneIsSet() const;
    void unsetZone();

    void setZone(const utility::string_t& value);

    /// <summary>
    /// MAY be set. Its value is defined by local policy
    /// </summary>
    utility::string_t getAccount() const;
    bool accountIsSet() const;
    void unsetAccount();

    void setAccount(const utility::string_t& value);

    /// <summary>
    /// MAY be sent in client bodies during creation, and MUST NOT be sent by the server. Simple list of strings of nameserver names, including the trailing dot. Not required for slave zones.
    /// </summary>
    std::vector<utility::string_t>& getNameservers();
    bool nameserversIsSet() const;
    void unsetNameservers();

    void setNameservers(const std::vector<utility::string_t>& value);

    /// <summary>
    /// The id of the TSIG keys used for master operation in this zone
    /// </summary>
    std::vector<utility::string_t>& getMasterTsigKeyIds();
    bool masterTsigKeyIdsIsSet() const;
    void unsetMaster_tsig_key_ids();

    void setMasterTsigKeyIds(const std::vector<utility::string_t>& value);

    /// <summary>
    /// The id of the TSIG keys used for slave operation in this zone
    /// </summary>
    std::vector<utility::string_t>& getSlaveTsigKeyIds();
    bool slaveTsigKeyIdsIsSet() const;
    void unsetSlave_tsig_key_ids();

    void setSlaveTsigKeyIds(const std::vector<utility::string_t>& value);


protected:
    utility::string_t m_Id;
    bool m_IdIsSet;
    utility::string_t m_Name;
    bool m_NameIsSet;
    utility::string_t m_Type;
    bool m_TypeIsSet;
    utility::string_t m_Url;
    bool m_UrlIsSet;
    utility::string_t m_Kind;
    bool m_KindIsSet;
    std::vector<std::shared_ptr<RRSet>> m_Rrsets;
    bool m_RrsetsIsSet;
    int32_t m_Serial;
    bool m_SerialIsSet;
    int32_t m_Notified_serial;
    bool m_Notified_serialIsSet;
    int32_t m_Edited_serial;
    bool m_Edited_serialIsSet;
    std::vector<utility::string_t> m_Masters;
    bool m_MastersIsSet;
    bool m_Dnssec;
    bool m_DnssecIsSet;
    utility::string_t m_Nsec3param;
    bool m_Nsec3paramIsSet;
    bool m_Nsec3narrow;
    bool m_Nsec3narrowIsSet;
    bool m_Presigned;
    bool m_PresignedIsSet;
    utility::string_t m_Soa_edit;
    bool m_Soa_editIsSet;
    utility::string_t m_Soa_edit_api;
    bool m_Soa_edit_apiIsSet;
    bool m_Api_rectify;
    bool m_Api_rectifyIsSet;
    utility::string_t m_Zone;
    bool m_ZoneIsSet;
    utility::string_t m_Account;
    bool m_AccountIsSet;
    std::vector<utility::string_t> m_Nameservers;
    bool m_NameserversIsSet;
    std::vector<utility::string_t> m_Master_tsig_key_ids;
    bool m_Master_tsig_key_idsIsSet;
    std::vector<utility::string_t> m_Slave_tsig_key_ids;
    bool m_Slave_tsig_key_idsIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_Zone_H_ */
