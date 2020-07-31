#include "list_blobs_request_base.h"

#include "constants.h"
#include "utility.h"

namespace azure {  namespace storage_lite {

<<<<<<< HEAD:azure-storage-cpp-lite/src/list_blobs_request_base.cpp
void list_blobs_request_base::build_request(const storage_account &a, http_base &h, const storage_client_key &k) const {
=======
void list_blobs_request_base::build_request(const storage_account &a, http_base &h) const
{
>>>>>>> 8c4db0fdc03a29fc9c5e18711fa05fa0d4cdb04d:cpplite/src/list_blobs_request_base.cpp
    const auto &r = *this;

    h.set_absolute_timeout(30L);

    h.set_method(http_base::http_method::get);

    storage_url url = a.get_url(storage_account::service::blob);
    url.append_path(r.container());

    url.add_query(constants::query_restype, constants::query_restype_container);
    url.add_query(constants::query_comp, constants::query_comp_list);
    add_optional_query(url, constants::query_prefix, r.prefix());
    add_optional_query(url, constants::query_delimiter, r.delimiter());
    add_optional_query(url, constants::query_marker, r.marker());
    add_optional_query(url, constants::query_maxresults, r.maxresults());
    std::string include(",");
    if (r.includes() & list_blobs_request_base::include::snapshots)
    {
        include.append(",").append(constants::query_include_snapshots);
    }
    if (r.includes() & list_blobs_request_base::include::metadata)
    {
        include.append(",").append(constants::query_include_metadata);
    }
    if (r.includes() & list_blobs_request_base::include::uncommittedblobs)
    {
        include.append(",").append(constants::query_include_uncommittedblobs);
    }
    if (r.includes() & list_blobs_request_base::include::copy)
    {
        include.append(",").append(constants::query_include_copy);
    }
    add_optional_query(url, constants::query_include, include.substr(1));
    add_optional_query(url, constants::query_timeout, r.timeout());
    h.set_url(url.to_string());

    storage_headers headers;
    add_ms_header(h, headers, constants::header_ms_client_request_id, r.ms_client_request_id(), true);

    h.add_header(constants::header_user_agent, constants::header_value_user_agent);
    add_ms_header(h, headers, constants::header_ms_date, get_ms_date(date_format::rfc_1123));
<<<<<<< HEAD:azure-storage-cpp-lite/src/list_blobs_request_base.cpp
    add_ms_header(h, headers, constants::header_ms_version, constants::header_value_storage_version);
    add_customer_provided_key_headers(h, headers, k);
=======
    add_ms_header(h, headers, constants::header_ms_version, constants::header_value_storage_blob_version);
>>>>>>> 8c4db0fdc03a29fc9c5e18711fa05fa0d4cdb04d:cpplite/src/list_blobs_request_base.cpp

    a.credential()->sign_request(r, h, url, headers);
}

<<<<<<< HEAD:azure-storage-cpp-lite/src/list_blobs_request_base.cpp
void list_blobs_hierarchical_request_base::build_request(const storage_account &a, http_base &h, const storage_client_key &k) const {
=======
void list_blobs_segmented_request_base::build_request(const storage_account &a, http_base &h) const
{
>>>>>>> 8c4db0fdc03a29fc9c5e18711fa05fa0d4cdb04d:cpplite/src/list_blobs_request_base.cpp
    const auto &r = *this;

    h.set_absolute_timeout(30L);

    h.set_method(http_base::http_method::get);

    storage_url url = a.get_url(storage_account::service::blob);
    url.append_path(r.container());

    url.add_query(constants::query_restype, constants::query_restype_container);
    url.add_query(constants::query_comp, constants::query_comp_list);
    if(r.prefix().length() > 0)
    {
        add_optional_query(url, constants::query_prefix, r.prefix());
    }
    if(r.delimiter().length() > 0)
    {
        add_optional_query(url, constants::query_delimiter, r.delimiter());
    }
    if(r.marker().length() > 0)
    {
        add_optional_query(url, constants::query_marker, r.marker());
    }
    if(r.maxresults() != 0)
    {
        add_optional_query(url, constants::query_maxresults, r.maxresults());
    }
    std::string include("");
    if (r.includes() & list_blobs_request_base::include::snapshots)
    {
        include.append(",").append(constants::query_include_snapshots);
    }
    if (r.includes() & list_blobs_request_base::include::metadata)
    {
        include.append(",").append(constants::query_include_metadata);
    }
    if (r.includes() & list_blobs_request_base::include::uncommittedblobs)
    {
        include.append(",").append(constants::query_include_uncommittedblobs);
    }
    if (r.includes() & list_blobs_request_base::include::copy)
    {
        include.append(",").append(constants::query_include_copy);
    }
    add_optional_query(url, constants::query_include, include.substr(1));
    add_optional_query(url, constants::query_timeout, r.timeout());
    h.set_url(url.to_string());

    storage_headers headers;
    add_ms_header(h, headers, constants::header_ms_client_request_id, r.ms_client_request_id(), true);

    h.add_header(constants::header_user_agent, constants::header_value_user_agent);
    add_ms_header(h, headers, constants::header_ms_date, get_ms_date(date_format::rfc_1123));
<<<<<<< HEAD:azure-storage-cpp-lite/src/list_blobs_request_base.cpp
    add_ms_header(h, headers, constants::header_ms_version, constants::header_value_storage_version);
    add_customer_provided_key_headers(h, headers, k);
=======
    add_ms_header(h, headers, constants::header_ms_version, constants::header_value_storage_blob_version);
>>>>>>> 8c4db0fdc03a29fc9c5e18711fa05fa0d4cdb04d:cpplite/src/list_blobs_request_base.cpp

    a.credential()->sign_request(r, h, url, headers);
}
}}  // azure::storage_lite
