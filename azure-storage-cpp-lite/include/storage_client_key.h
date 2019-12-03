#pragma once

#include <string>

#include "storage_EXPORTS.h"

namespace microsoft_azure {
    namespace storage {

        class storage_client_key {
        public:

            AZURE_STORAGE_API storage_client_key(const std::string &key, const std::string &key_sha256, const std::string &algorithm);

            std::string key() const {
                return m_encryption_key;
            }

            std::string key_sha256() const {
                return m_encryption_key_sha256;
            }
            std::string algorithm() const {
                return m_encryption_algorithm;
            }

            bool is_valid() const {
                return m_valid_key;
            }

        private:
            bool m_valid_key = false;
            std::string m_encryption_key;
            std::string m_encryption_key_sha256;
            std::string m_encryption_algorithm;
        };

    }
}
