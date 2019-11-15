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
 * Error.h
 *
 * Returned when the server encounters an error. Either in client input or internally
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_Error_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_Error_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>
#include <vector>

namespace org {
namespace openapitools {
namespace client {
namespace model {


/// <summary>
/// Returned when the server encounters an error. Either in client input or internally
/// </summary>
class  Error
    : public ModelBase
{
public:
    Error();
    virtual ~Error();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Error members

    /// <summary>
    /// A human readable error message
    /// </summary>
    utility::string_t getError() const;
    
    void setError(const utility::string_t& value);

    /// <summary>
    /// Optional array of multiple errors encountered during processing
    /// </summary>
    std::vector<utility::string_t>& getErrors();
    bool errorsIsSet() const;
    void unsetErrors();

    void setErrors(const std::vector<utility::string_t>& value);


protected:
    utility::string_t m_Error;
        std::vector<utility::string_t> m_Errors;
    bool m_ErrorsIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_Error_H_ */
