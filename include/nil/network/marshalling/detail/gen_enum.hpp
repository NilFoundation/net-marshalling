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

#ifndef NETWORK_MARSHALLING_GEN_ENUM_HPP
#define NETWORK_MARSHALLING_GEN_ENUM_HPP

#include <nil/marshalling/detail/macro_common.hpp>

#define MARSHALLING_WRAP_ENUM(p_, v_) MARSHALLING_CONCATENATE(p_, v_)

#define MARSHALLING_ENUM_VAL_0(...)
#define MARSHALLING_ENUM_VAL_1(p_, v_) MARSHALLING_WRAP_ENUM(p_, v_)
#define MARSHALLING_ENUM_VAL_2(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_1(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_3(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_2(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_4(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_3(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_5(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_4(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_6(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_5(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_7(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_6(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_8(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_7(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_9(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_8(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_10(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_9(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_11(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_10(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_12(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_11(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_13(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_12(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_14(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_13(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_15(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_14(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_16(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_15(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_17(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_16(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_18(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_17(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_19(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_18(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_20(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_19(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_21(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_20(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_22(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_21(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_23(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_22(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_24(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_23(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_25(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_24(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_26(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_25(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_27(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_26(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_28(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_27(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_29(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_28(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_30(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_29(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_31(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_30(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_32(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_31(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_33(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_32(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_34(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_33(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_35(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_34(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_36(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_35(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_37(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_36(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_38(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_37(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_39(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_38(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_40(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_39(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_41(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_40(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_42(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_41(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_43(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_42(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_44(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_43(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_45(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_44(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_46(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_45(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_47(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_46(p_, __VA_ARGS__))
#define MARSHALLING_ENUM_VAL_48(p_, v_, ...) \
    MARSHALLING_WRAP_ENUM(p_, v_), MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_47(p_, __VA_ARGS__))

#define MARSHALLING_CHOOSE_ENUM_(N, p_, ...) MARSHALLING_EXPAND(MARSHALLING_ENUM_VAL_##N(p_, __VA_ARGS__))
#define MARSHALLING_CHOOSE_ENUM(N, p_, ...) MARSHALLING_EXPAND(MARSHALLING_CHOOSE_ENUM_(N, p_, __VA_ARGS__))
#define MARSHALLING_DO_ENUM(p_, ...) \
    MARSHALLING_EXPAND(MARSHALLING_CHOOSE_ENUM(MARSHALLING_NUM_ARGS(__VA_ARGS__), p_, __VA_ARGS__))

#define MARSHALLING_END_ENUM(p_) MARSHALLING_CONCATENATE(p_, _numOfValues)

#define MARSHALLING_DEFINE_ENUM(p_, ...)                                                      \
    enum p_ {                                                                                 \
        MARSHALLING_EXPAND(MARSHALLING_DO_ENUM(MARSHALLING_CONCATENATE(p_, _), __VA_ARGS__)), \
        MARSHALLING_END_ENUM(p_)                                                              \
    };
#endif    // NETWORK_MARSHALLING_GEN_ENUM_HPP
