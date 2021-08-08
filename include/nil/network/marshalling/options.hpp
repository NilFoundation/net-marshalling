//---------------------------------------------------------------------------//
// Copyright (c) 2017-2021 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020-2021 Nikita Kaskov <nbering@nil.foundation>
//
// MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//---------------------------------------------------------------------------//

/// @file
/// Contains definition of all the options used by the @b Marshalling library

#ifndef NETWORK_MARSHALLING_OPTIONS_HPP
#define NETWORK_MARSHALLING_OPTIONS_HPP

#include <tuple>
#include <type_traits>
#include <limits>
#include <ratio>
#include <cstdint>
#include <cstddef>

#include <nil/marshalling/endianness.hpp>
#include <nil/marshalling/units_types.hpp>
#include <nil/marshalling/status_type.hpp>
#include <nil/marshalling/types/optional_mode.hpp>
#include <nil/marshalling/options.hpp>

namespace nil {
    namespace marshalling {
        namespace option {

            /// @brief Option used to specify type of the ID.
            /// @tparam T Type of the message ID.
            /// @headerfile nil/marshalling/options.h
            template<typename T>
            struct msg_id_type { };

            /// @brief Option used to specify type of iterator used for reading.
            /// @tparam TIter Type of the iterator.
            /// @headerfile nil/marshalling/options.h
            template<typename TIter>
            struct read_iterator { };

            /// @brief Option used to specify type of iterator used for writing.
            /// @tparam TIter Type of the iterator.
            /// @headerfile nil/marshalling/options.h
            template<typename TIter>
            struct write_iterator { };

            /// @brief Option used to add @b get_id() function into message interface.
            /// @headerfile nil/marshalling/options.h
            struct id_info_interface { };

            /// @brief Option used to add @b valid() function into message interface.
            /// @headerfile nil/marshalling/options.h
            struct valid_check_interface { };

            /// @brief Option used to add @b length() function into message interface.
            /// @headerfile nil/marshalling/options.h
            struct length_info_interface { };

            /// @brief Option used to add @b refresh() function into message interface.
            /// @headerfile nil/marshalling/options.h
            struct refresh_interface { };

            /// @brief Option used to add @b name() function into message interface.
            /// @headerfile nil/marshalling/options.h
            struct name_interface { };

            /// @brief Option used to specify type of the message handler.
            /// @tparam T Type of the handler.
            /// @headerfile nil/marshalling/options.h
            template<typename T>
            struct handler { };

            /// @brief Option used to specify numeric ID of the message.
            /// @tparam TId Numeric ID value.
            /// @headerfile nil/marshalling/options.h
            template<std::intmax_t TId>
            struct static_num_id_impl { };

            /// @brief Option used to specify that message doesn't have valid ID.
            /// @headerfile nil/marshalling/options.h
            struct no_id_impl { };

            /// @brief Option used to specify actual type of the message.
            /// @headerfile nil/marshalling/options.h
            template<typename TMsg>
            struct msg_type { };

            /// @brief Option used to inhibit default implementation of @b dispatch_impl()
            ///     in nil::marshalling::message_base.
            /// @headerfile nil/marshalling/options.h
            struct no_dispatch_impl { };

            /// @brief Option used to specify some extra fields from transport framing.
            /// @details Some fields from transport framing may influence the way on how
            ///     message fields get read or written. It may also have an influence on
            ///     how message is handled. This option is intended to provide a list
            ///     of such fields, bundled in @b std::tuple, to @ref nil::marshalling::message interface
            ///     class.
            /// @tparam TFields The fields of the message bundled in std::tuple.
            /// @headerfile nil/marshalling/options.h
            template<typename TFields>
            struct extra_transport_fields { };

            /// @brief Option used to specify index of the version field inside
            ///     extra transport fields tuple provided with @ref
            ///     nil::marshalling::option::extra_transport_fields_type option.
            /// @tparam TIdx Index of the field inside the tuple.
            /// @headerfile nil/marshalling/options.h
            template<std::size_t TIdx>
            struct version_in_extra_transport_fields { };

            /// @brief Option used to specify fields of the message and force implementation
            ///     of default read, write, validity check, and length retrieval information
            ///     of the message.
            /// @tparam TFields The fields of the message bundled in std::tuple.
            /// @headerfile nil/marshalling/options.h
            template<typename TFields>
            struct fields_impl;

            /// @cond SKIP_DOC
            template<typename... TFields>
            struct fields_impl<std::tuple<TFields...>> { };
            /// @endcond

            /// @brief Alias to FieldsImpl<std::tuple<> >
            /// @headerfile nil/marshalling/options.h
            using zero_fields_impl = fields_impl<std::tuple<>>;

            /// @brief Option that inhibits implementation of nil::marshalling::message_base::read_impl()
            ///     regardless of other availability conditions.
            /// @headerfile nil/marshalling/options.h
            struct no_read_impl { };

            /// @brief Option that inhibits implementation of nil::marshalling::message_base::write_impl()
            ///     regardless of other availability conditions.
            /// @headerfile nil/marshalling/options.h
            struct no_write_impl { };

            /// @brief Option that inhibits implementation of nil::marshalling::message_base::valid_impl()
            ///     regardless of other availability conditions.
            /// @headerfile nil/marshalling/options.h
            struct no_valid_impl { };

            /// @brief Option that inhibits implementation of nil::marshalling::message_base::length_impl()
            ///     regardless of other availability conditions.
            /// @headerfile nil/marshalling/options.h
            struct no_length_impl { };

            /// @brief Option that inhibits implementation of nil::marshalling::message_base::refresh_impl()
            ///     regardless of other availability conditions.
            /// @headerfile nil/marshalling/options.h
            struct no_refresh_impl { };

            /// @brief Option that notifies nil::marshalling::message_base about existence of
            ///     @b eval_get_id() member function in derived class.
            /// @headerfile nil/marshalling/options.h
            struct has_do_get_id { };

            /// @brief Option that notifies nil::marshalling::message_base about existence of
            ///     access to fields.
            /// @details Can be useful when there is a chain of inheritances from
            ///     nil::marshalling::message_base.
            /// @headerfile nil/marshalling/options.h
            struct assume_fields_existence { };

            /// @brief Option that forces "in place" allocation with placement "new" for
            ///     initialisation, instead of usage of dynamic memory allocation.
            /// @headerfile nil/marshalling/options.h
            struct in_place_allocation { };

            /// @brief Option used to allow @ref nil::marshalling::generic_message generation inside
            ///  @ref nil::marshalling::msg_factory and/or @ref nil::marshalling::protocol::MsgIdLayer classes.
            /// @tparam TGenericMessage Type of message, expected to be a variant of
            ///     @ref nil::marshalling::generic_message.
            template<typename TGenericMessage>
            struct support_generic_message { };

            /// @brief Force the destructor of nil::marshalling::message class to be @b non-virtual,
            ///     even if there are other virtual functions defined.
            /// @headerfile nil/marshalling/options.h
            struct no_virtual_destructor { };

            /// @brief Force nil::marshalling::protocol::checksum_layer and
            ///     nil::marshalling::protocol::ChecksumPrefixLayer, to verify checksum prior to
            ///     forwarding read to the wrapped layer(s).
            /// @headerfile nil/marshalling/options.h
            struct checksum_layer_verify_before_read { };

            /// @brief Option to force @ref nil::marshalling::protocol::ProtocolLayerBase class to
            ///     split read operation "until" and "from" data (payload) layer.
            /// @details Can be used by some layers which require its read operation to be
            ///     fully complete before read is forwared to data layer, i.e. until message
            ///     contents being read.
            /// @headerfile nil/marshalling/options.h
            struct protocol_layer_force_read_until_data_split { };

            /// @brief Disallow usage of @ref ProtocolLayerForceReadUntilDataSplit option in
            ///     earlier (outer wrapping) layers.
            /// @details Some layers, such as @ref nil::marshalling::protocol::checksum_layer cannot
            ///     split their "read" operation to "until" and "from" data layer. They can
            ///     use this option to prevent outer layers from using
            ///     @ref ProtocolLayerForceReadUntilDataSplit one.
            /// @headerfile nil/marshalling/options.h
            struct protocol_layer_disallow_read_until_data_split { };

            /// @brief Mark this class as providing its name information
            /// @headerfile nil/marshalling/options.h
            struct has_name { };

            /// @brief Option that notifies nil::marshalling::message_base about existence of
            ///     custom refresh functionality in derived class.
            /// @details Alias to @ref has_custom_refresh for backward compatibility.
            /// @deprecated Use @ref has_custom_refresh instead.
            /// @headerfile nil/marshalling/options.h
            using has_do_refresh = has_custom_refresh;

            /// @brief Option for @ref nil::marshalling::protocol::TransportValueLayer to
            ///     mark that the handled field is a "pseudo" one, i.e. is not serialized.
            struct pseudo_value { };

        }    // namespace option
    }        // namespace marshalling
}    // namespace nil
#endif    // NETWORK_MARSHALLING_OPTIONS_HPP
