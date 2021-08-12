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

#ifndef NETWORK_MARSHALLING_PROTOCOL_ETHERNET_HPP
#define NETWORK_MARSHALLING_PROTOCOL_ETHERNET_HPP

#include <nil/marshalling/options.hpp>
#include <nil/marshalling/types/array_list.hpp>
#include <nil/marshalling/types/integral.hpp>

#include <nil/network/marshalling/detail/base_detection.hpp>
#include <nil/network/marshalling/message.hpp>
#include <nil/network/marshalling/options.hpp>

namespace nil {
    namespace marshalling {
        namespace types {
            namespace detail {

                template <typename Endianness = nil::marshalling::option::big_endian>
                using mac_addresses_marshalling_type = std::tuple<
                    // Destination MAC Address
                    nil::marshalling::types::array_list<
                        nil::marshalling::field_type<Endianness>,
                        nil::marshalling::types::integral<
                            nil::marshalling::field_type<Endianness>, 
                            std::uint8_t>,
                    nil::marshalling::option::fixed_size_storage<6>>,
                    // Source MAC Address
                    nil::marshalling::types::array_list<
                        nil::marshalling::field_type<Endianness>,
                        nil::marshalling::types::integral<
                            nil::marshalling::field_type<Endianness>, 
                            std::uint8_t>,
                    nil::marshalling::option::fixed_size_storage<6>>>;

                template<typename TOptions = nil::marshalling::option::empty_option>
                struct ethernet_type2_message_interface
                    : public nil::marshalling::message<
                        TOptions,
                        nil::marshalling::option::extra_transport_fields<mac_addresses_marshalling_type>> {
#ifdef MARSHALLING_MUST_DEFINE_BASE
                    using Base
                        = nil::marshalling::message<
                            TOptions, 
                            nil::marshalling::option::extra_transport_fields<mac_addresses_marshalling_type>>;
#endif
                public:
                    MARSHALLING_MSG_TRANSPORT_FIELDS_ACCESS(version);
                };

                template<std::size_t TLen = 4, typename Endianness = nil::marshalling::option::big_endian>
                using checksum_field_type = nil::marshalling::types::integral<
                    nil::marshalling::field_type<Endianness>, 
                    typename nil::marshalling::processing::size_to_type<TLen>::type>;


                // Ether type defines protocol type. Default value is 0x0800 - IPv4
                template<typename Endianness = nil::marshalling::option::big_endian>
                using ether_type = nil::marshalling::types::integral<
                    nil::marshalling::field_type<Endianness>, 
                    std::uint16_t, 
                    nil::marshalling::option::default_num_value<
                        std::conditional<std::is_same<Endianness, nil::marshalling::option::big_endian>, 
                                         0x0800, 
                                         0x0008
                                        >
                    >
                >;
            }    // namespace detail

            template<typename TMessage>
            using ethernet_type2_protocol_stack = nil::marshalling::protocol::checksum_layer<
                checksum_field_type, nil::marshalling::protocol::checksum::crc_32,
                nil::marshalling::protocol::transport_value_layer<
                    typename detail::mac_addresses_marshalling_type, 
                    ethernet_type2_message_interface<>::TransportFieldIdx_mac_addresses,
                    nil::marshalling::protocol::msg_id_layer<ether_type, TMessage, all_messages_type<TMessage>,
                        nil::marshalling::protocol::msg_data_layer<>
                    >
                >
            >;

        }    // namespace types
    }        // namespace marshalling
}    // namespace nil
#endif    // NETWORK_MARSHALLING_PROTOCOL_ETHERNET_HPP
