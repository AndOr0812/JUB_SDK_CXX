#include <context/ContextBTC.h>
#include <token/TokenManager.hpp>
#include <JUB_SDK.h>
#include <utility/Singleton.h>
#include <utility/util.hpp>
#include <utility/uchar_vector.h>
#include <libBTC/libBTC.hpp>


namespace jub {


	JUB_RV ContextBTC::getHDNode(int index, std::string& xpub)
	{
		auto token = Singleton<jub::TokenManager>::GetInstance()->getToken(_deviceID);
		return JUBR_OK;
	}

	JUB_RV ContextBTC::signTX(std::vector<INPUT_BTC> inputs, std::vector<OUTPUT_BTC> outputs, JUB_UINT32 locktime, std::string& raw)
	{

		auto token = Singleton<jub::TokenManager>::GetInstance()->getToken(_deviceID);
		JUB_CHECK_NULL(token);

		//deal inputs
		std::vector<JUB_UINT64> vinput_amount;
		std::vector<std::string> vinput_path;
		for (auto input : inputs)
		{
			vinput_amount.push_back(input.amount);
			vinput_path.push_back(_main_path + "/0/" + std::to_string(input.addressIndex));
		}


		//deal outputs
		std::vector<JUB_UINT16> vchange_index;
		std::vector<std::string> vchange_path;
		for (std::size_t i = 0, e = outputs.size(); i != e; ++i)
		{ 
			if (outputs[i].change)
			{
				vchange_index.push_back((JUB_UINT16)i);
				vchange_path.push_back(outputs[i].path);
			}
		}

		//build unsinged transaction
		uchar_vector unsigned_trans;
		jub::btc::serializeTX_p2pkh(_type,inputs, outputs,locktime, unsigned_trans);

		token->signTX_BTC(_type, (JUB_UINT16)inputs.size(), vinput_amount, vinput_path, vchange_index, vchange_path, unsigned_trans);

		return JUBR_OK;

	}


}