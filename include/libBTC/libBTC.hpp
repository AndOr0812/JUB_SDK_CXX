#pragma once

#ifndef __libBTC__
#define __libBTC__

#include "JUB_SDK_BTC.h"
#include "context/ContextBTC.h"

#include "mSIGNA/stdutils/uchar_vector.h"

namespace jub {

namespace btc {

constexpr JUB_UINT32 version1 = 0x01;
constexpr JUB_UINT32 sequence = 0xffffffff;
constexpr JUB_BYTE   marker	  = 0x00;
constexpr JUB_BYTE   flag     = 0x01;

constexpr JUB_BYTE  p2shVersion = 0x05;
constexpr JUB_BYTE p2pkhVersion = 0x00;

constexpr JUB_BYTE  p2shVersion_LTC = 0x32;
constexpr JUB_BYTE p2pkhVersion_LTC = 0x30;

constexpr JUB_BYTE  p2shVersion_DASH = 0x10;
constexpr JUB_BYTE p2pkhVersion_DASH = 0x4c;

constexpr char segwit_hrl[] = "bc";

JUB_RV buildScriptPubFromAddress(const std::string& address, uchar_vector& scriptPub);

//JUB_RV buildScriptPubFromScript(const uchar_vector& redeemScript, uchar_vector& scriptPub);

JUB_RV serializeUnsignedTx(const JUB_BTC_TRANS_TYPE type,
                           const std::vector<INPUT_BTC>& vInputs,
                           const std::vector<OUTPUT_BTC>& vOutputs,
                           const JUB_UINT32 lockTime,
                           uchar_vector& unsignedRaw);

JUB_RV serializePreimage(const JUB_BTC_TRANS_TYPE type,
                         const std::size_t for_sign_input_index,
                         const std::vector<INPUT_BTC>& vInputs,
                         const std::vector<uchar_vector>& vRedeemScript,
                         const std::vector<OUTPUT_BTC>& vOutputs,
                         const JUB_UINT32 lockTime,
                         uchar_vector& preimageRaw);

JUB_RV deserializeTx(const std::string hexTx,
                     std::vector<INPUT_BTC>& vInputs,
                     std::vector<OUTPUT_BTC>& vOutputs,
                     JUB_UINT32_PTR plockTime);
} // namespace btc end

} // namespace jub end

#endif
