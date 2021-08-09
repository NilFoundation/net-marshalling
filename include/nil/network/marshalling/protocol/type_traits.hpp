//---------------------------------------------------------------------------//
// Copyright (c) 2018-2021 Mikhail Komarov <nemo@nil.foundation>
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

#ifndef NETWORK_MARSHALLING_PROTOCOL_TYPE_TRAITS_HPP
#define NETWORK_MARSHALLING_PROTOCOL_TYPE_TRAITS_HPP

namespace nil {
    namespace marshalling {
        namespace protocol {

            namespace detail {
                template<typename T>
                struct checksum_layer_check_helper {
                    static const bool value = false;
                };

                template<typename TField, typename TCalc, typename TNextLayer, typename... TOptions>
                struct checksum_layer_check_helper<checksum_layer<TField, TCalc, TNextLayer, TOptions...>> {
                    static const bool value = true;
                };

            }    // namespace detail

            /// @brief Compile time check of whether the provided type is
            ///     a variant of @ref checksum_layer
            /// @related checksum_layer
            template<typename T>
            constexpr bool is_checksum_layer() {
                return detail::checksum_layer_check_helper<T>::value;
            }

            namespace detail {
                template<typename T>
                struct checksum_prefix_layer_check_helper {
                    static const bool value = false;
                };

                template<typename TField, typename TCalc, typename TNextLayer, typename... TOptions>
                struct checksum_prefix_layer_check_helper<
                    checksum_prefix_layer<TField, TCalc, TNextLayer, TOptions...>> {
                    static const bool value = true;
                };

            }    // namespace detail

            /// @brief Compile time check of whether the provided type is
            ///     a variant of @ref checksum_prefix_layer
            /// @related checksum_layer
            template<typename T>
            constexpr bool is_checksum_prefix_layer() {
                return detail::checksum_prefix_layer_check_helper<T>::value;
            }

            namespace detail {
                template<typename T>
                struct msg_data_layer_check_helper {
                    static const bool value = false;
                };

                template<typename... TExtraOpts>
                struct msg_data_layer_check_helper<msg_data_layer<TExtraOpts...>> {
                    static const bool value = true;
                };

            }    // namespace detail

            /// @brief Compile time check of whether the provided type is
            ///     a variant of @ref msg_data_layer
            /// @related msg_data_layer
            template<typename T>
            constexpr bool is_msg_data_layer() {
                return detail::msg_data_layer_check_helper<T>::value;
            }

            namespace detail {
                template<typename T>
                struct msg_id_layer_check_helper {
                    static const bool value = false;
                };

                template<typename TField, typename TMessage, typename TAllMessages, typename TNextLayer,
                         typename... TOptions>
                struct msg_id_layer_check_helper<
                    msg_id_layer<TField, TMessage, TAllMessages, TNextLayer, TOptions...>> {
                    static const bool value = true;
                };

            }    // namespace detail

            /// @brief Compile time check of whether the provided type is
            ///     a variant of @ref msg_id_layer
            /// @related msg_id_layer
            template<typename T>
            constexpr bool is_msg_id_layer() {
                return detail::msg_id_layer_check_helper<T>::value;
            }

            namespace detail {
                template<typename T>
                struct msg_size_layer_check_helper {
                    static const bool value = false;
                };

                template<typename TField, typename TNextLayer>
                struct msg_size_layer_check_helper<msg_size_layer<TField, TNextLayer>> {
                    static const bool value = true;
                };

            }    // namespace detail

            /// @brief Compile time check of whether the provided type is
            ///     a variant of @ref msg_size_layer
            /// @related msg_size_layer
            template<typename T>
            constexpr bool is_msg_size_layer() {
                return detail::msg_size_layer_check_helper<T>::value;
            }

            namespace detail {
                template<typename T>
                struct sync_prefix_layer_check_helper {
                    static const bool value = false;
                };

                template<typename TField, typename TNextLayer>
                struct sync_prefix_layer_check_helper<sync_prefix_layer<TField, TNextLayer>> {
                    static const bool value = true;
                };

            }    // namespace detail

            /// @brief Compile time check of whether the provided type is
            ///     a variant of @ref sync_prefix_layer
            /// @related sync_prefix_layer
            template<typename T>
            constexpr bool is_sync_prefix_layer() {
                return detail::sync_prefix_layer_check_helper<T>::value;
            }

            namespace detail {
                template<typename T>
                struct transport_value_layer_check_helper {
                    static const bool value = false;
                };

                template<typename TField, std::size_t TIdx, typename TNextLayer>
                struct transport_value_layer_check_helper<transport_value_layer<TField, TIdx, TNextLayer>> {
                    static const bool value = true;
                };

            }    // namespace detail

            /// @brief Compile time check of whether the provided type is
            ///     a variant of @ref transport_value_layer
            /// @related transport_value_layer
            template<typename T>
            constexpr bool is_transport_value_layer() {
                return detail::transport_value_layer_check_helper<T>::value;
            }
        }        // namespace protocol
    }        // namespace marshalling
}    // namespace nil

#endif    // NETWORK_MARSHALLING_PROTOCOL_TYPE_TRAITS_HPP