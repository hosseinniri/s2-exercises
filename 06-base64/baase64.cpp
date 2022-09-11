
#include <string>
#include <vector>

#include <fstream>
#include <iostream>

static const char kEncodeLookup[] =
	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const char kPadCharacter = '=';

std::string base64_encode(const std::string input)
{

	std::string encoded;
	encoded.reserve(((input.size() / 3) + (input.size() % 3 > 0)) * 4);

	unsigned int temp{};
	auto it = input.begin();

	for (std::size_t i = 0; i < input.size() / 3; ++i)
	{
		temp = (*it++) << 16;
		temp += (*it++) << 8;
		temp += (*it++);
		encoded.append(1, kEncodeLookup[(temp & 0x00FC0000) >> 18]);
		encoded.append(1, kEncodeLookup[(temp & 0x0003F000) >> 12]);
		encoded.append(1, kEncodeLookup[(temp & 0x00000FC0) >> 6]);
		encoded.append(1, kEncodeLookup[(temp & 0x0000003F)]);
	}

	switch (input.size() % 3)
	{
	case 1:
		temp = (*it++) << 16;
		encoded.append(1, kEncodeLookup[(temp & 0x00FC0000) >> 18]);
		encoded.append(1, kEncodeLookup[(temp & 0x0003F000) >> 12]);
		encoded.append(2, kPadCharacter);
		break;
	case 2:
		temp = (*it++) << 16;
		temp += (*it++) << 8;
		encoded.append(1, kEncodeLookup[(temp & 0x00FC0000) >> 18]);
		encoded.append(1, kEncodeLookup[(temp & 0x0003F000) >> 12]);
		encoded.append(1, kEncodeLookup[(temp & 0x00000FC0) >> 6]);
		encoded.append(1, kPadCharacter);
		break;
	}

	return encoded;
}

std::vector<char> base64_decode(const std::string input)
{
	if (input.length() % 4)
		throw std::runtime_error("Invalid base64 length!");

	std::size_t padding{};

	if (input.length())
	{
		if (input[input.length() - 1] == kPadCharacter)
			padding++;
		if (input[input.length() - 2] == kPadCharacter)
			padding++;
	}

	std::vector<char> decoded;
	decoded.reserve(((input.length() / 4) * 3) - padding);

	unsigned int temp{};
	auto it = input.begin();

	while (it < input.end())
	{
		for (std::size_t i = 0; i < 4; ++i)
		{
			temp <<= 6;
			if (*it >= 0x41 && *it <= 0x5A)
				temp |= *it - 0x41;
			else if (*it >= 0x61 && *it <= 0x7A)
				temp |= *it - 0x47;
			else if (*it >= 0x30 && *it <= 0x39)
				temp |= *it + 0x04;
			else if (*it == 0x2B)
				temp |= 0x3E;
			else if (*it == 0x2F)
				temp |= 0x3F;
			else if (*it == kPadCharacter)
			{
				switch (input.end() - it)
				{
				case 1:
					decoded.push_back((temp >> 16) & 0x000000FF);
					decoded.push_back((temp >> 8) & 0x000000FF);
					return decoded;
				case 2:
					decoded.push_back((temp >> 10) & 0x000000FF);
					return decoded;
				default:
					throw std::runtime_error("Invalid padding in base64!");
				}
			}
			else
				throw std::runtime_error("Invalid character in base64!");

			++it;
		}

		decoded.push_back((temp >> 16) & 0x000000FF);
		decoded.push_back((temp >> 8) & 0x000000FF);
		decoded.push_back((temp)&0x000000FF);
	}

	return decoded;
}

int main(int argc, char const *argv[])
{
	if (argc < 4)
		return -1;
	try
	{
		std::string mode{argv[1]};
		std::string input_path{argv[2]};
		std::string output_path{argv[3]};

		std::string input_content;
		std::string encode_mode{"enc"};
		std::string decode_mode{"dec"};

		if (mode.compare(encode_mode) == 0)
		{
			std::ifstream input_file(input_path);
			input_content.assign((std::istreambuf_iterator<char>(input_file)),
								 (std::istreambuf_iterator<char>()));

			std::string coded_content = base64_encode(input_content);

			std ::ofstream output_file;
			output_file.open(output_path);
			output_file << coded_content;

			std ::cout << "codded output :\n ";
			std ::cout << coded_content << "\n";
		}

		else if (mode.compare(decode_mode) == 0)
		{
			std::ifstream input_file(input_path);
			input_content.assign((std::istreambuf_iterator<char>(input_file)),
								 (std::istreambuf_iterator<char>()));

			std::vector<char> decoded_content = base64_decode(input_content);
			std::string decoded_content_string(decoded_content.begin(), decoded_content.end());
			std ::ofstream output_file;
			output_file.open(output_path);
			output_file << decoded_content_string;

			std ::cout << "decodded output :\n ";
			for (auto v : decoded_content_string)
			{
				std ::cout << v;
			}

			std ::cout << "\n";
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
