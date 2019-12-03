#include "storage_client_key.h"

#include "constants.h"
#include <syslog.h>

namespace microsoft_azure {
    namespace storage {

        // TODO: Clean up table queue and file services
        storage_client_key::storage_client_key(const std::string &key, const std::string &key_sha256, const std::string &algorithm)
            : m_encryption_key(key), m_encryption_key_sha256(key_sha256), m_encryption_algorithm(algorithm) {

                // TODO: check SHA256 matches the key's
                if(algorithm == constants::header_value_encryption_algorithm_aes256) {
                    if (key.length()==44 && key_sha256.length()==44) {
                        m_valid_key=true;
                    } else {
                        syslog(LOG_WARNING, "The key length (%lu) or the SHA256 length (%lu) is invalid", key.length(), key_sha256.length());
                    }
                } else {
                    syslog(LOG_WARNING, "The CPK algorithm is not 'AES_256': %s", algorithm.c_str());
                }

                if (!m_valid_key) {
                    syslog(LOG_WARNING, "The Customer Provided Key configuration will not be used.");
                }

        }


    }
}
