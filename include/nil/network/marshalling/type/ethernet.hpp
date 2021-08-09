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

namespace nil {
    namespace marshalling {
        namespace types {

            template <typename Endianness = nil::marshalling::option::little_endian>
            using mac_header = nil::marshalling::types::bundle<
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
                nil::marshalling::option::fixed_size_storage<6>>,
                // EtherType
                nil::marshalling::types::integral<
                    nil::marshalling::field_type<Endianness>, 
                    std::uint16_t>>;

            template<typename TSyncField, typename TChecksumField, typename TSizeField, typename TIdField, typename TMessage>
            struct ethernet_type2_frame
                : public nil::marshalling::protocol::sync_prefix_layer<
                      TSyncField,
                      nil::marshalling::protocol::checksum_layer<
                          TChecksumField, nil::marshalling::protocol::checksum::crc_32,
                          nil::marshalling::protocol::msg_size_layer<
                              TSizeField,
                              nil::marshalling::protocol::msg_id_layer<TIdField, TMessage, all_messages_type<TMessage>,
                                                                       nil::marshalling::protocol::msg_data_layer<>>>>> {
            #ifdef MARSHALLING_MUST_DEFINE_BASE
                using Base = nil::marshalling::protocol::sync_prefix_layer<
                    TSyncField,
                    nil::marshalling::protocol::checksum_layer<
                        TChecksumField, nil::marshalling::protocol::checksum::crc_32,
                        nil::marshalling::protocol::msg_size_layer<
                            TSizeField, nil::marshalling::protocol::msg_id_layer<TIdField, TMessage, all_messages_type<TMessage>,
                                                                                 nil::marshalling::protocol::msg_data_layer<>>>>>;
            #endif
            public:
                MARSHALLING_PROTOCOL_LAYERS_ACCESS_OUTER(sync, checksum, size, id, payload);
            };

        }    // namespace types
    }        // namespace marshalling
}    // namespace nil
#endif    // NETWORK_MARSHALLING_PROTOCOL_ETHERNET_HPP
