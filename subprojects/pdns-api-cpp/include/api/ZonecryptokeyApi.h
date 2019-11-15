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
 * ZonecryptokeyApi.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_API_ZonecryptokeyApi_H_
#define ORG_OPENAPITOOLS_CLIENT_API_ZonecryptokeyApi_H_


#include "../ApiClient.h"

#include "Cryptokey.h"
#include <cpprest/details/basic_types.h>


#include <boost/optional.hpp>

namespace org {
namespace openapitools {
namespace client {
namespace api {

using namespace org::openapitools::client::model;



class  ZonecryptokeyApi 
{
public:

    explicit ZonecryptokeyApi( std::shared_ptr<ApiClient> apiClient );

    virtual ~ZonecryptokeyApi();

    /// <summary>
    /// Creates a Cryptokey
    /// </summary>
    /// <remarks>
    /// This method adds a new key to a zone. The key can either be generated or imported by supplying the content parameter. if content, bits and algo are null, a key will be generated based on the default-ksk-algorithm and default-ksk-size settings for a KSK and the default-zsk-algorithm and default-zsk-size options for a ZSK.
    /// </remarks>
    /// <param name="serverId">The id of the server to retrieve</param>
    /// <param name="zoneId"></param>
    /// <param name="cryptokey">Add a Cryptokey</param>
    pplx::task<std::shared_ptr<Cryptokey>> createCryptokey(
        utility::string_t serverId,
        utility::string_t zoneId,
        std::shared_ptr<Cryptokey> cryptokey
    );
    /// <summary>
    /// This method deletes a key specified by cryptokey_id.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="serverId">The id of the server to retrieve</param>
    /// <param name="zoneId">The id of the zone to retrieve</param>
    /// <param name="cryptokeyId">The id value of the Cryptokey</param>
    pplx::task<void> deleteCryptokey(
        utility::string_t serverId,
        utility::string_t zoneId,
        utility::string_t cryptokeyId
    );
    /// <summary>
    /// Returns all data about the CryptoKey, including the privatekey.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="serverId">The id of the server to retrieve</param>
    /// <param name="zoneId">The id of the zone to retrieve</param>
    /// <param name="cryptokeyId">The id value of the CryptoKey</param>
    pplx::task<std::shared_ptr<Cryptokey>> getCryptokey(
        utility::string_t serverId,
        utility::string_t zoneId,
        utility::string_t cryptokeyId
    );
    /// <summary>
    /// Get all CryptoKeys for a zone, except the privatekey
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="serverId">The id of the server to retrieve</param>
    /// <param name="zoneId">The id of the zone to retrieve</param>
    pplx::task<std::vector<std::shared_ptr<Cryptokey>>> listCryptokeys(
        utility::string_t serverId,
        utility::string_t zoneId
    );
    /// <summary>
    /// This method (de)activates a key from zone_name specified by cryptokey_id
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="serverId">The id of the server to retrieve</param>
    /// <param name="zoneId"></param>
    /// <param name="cryptokeyId">Cryptokey to manipulate</param>
    /// <param name="cryptokey">the Cryptokey</param>
    pplx::task<void> modifyCryptokey(
        utility::string_t serverId,
        utility::string_t zoneId,
        utility::string_t cryptokeyId,
        std::shared_ptr<Cryptokey> cryptokey
    );

protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_API_ZonecryptokeyApi_H_ */

