#include "stdafx.h"
#include "XML.h"


XML::XML() : _isParsed(false) {
	_fsxml = new std::fstream();
}

XML::XML(const char* fname) : XML() {
	if (open(fname)) {
		if (parse()) {
			_isParsed = true;
		}
	}
}

XML::~XML() {
	delete _fsxml;
}

bool XML::open(const char* fname) {
	
	// Open file for read/write ops
	_fsxml->open(fname, std::fstream::in | std::fstream::out | std::fstream::app);

	if (_fsxml->is_open()) { // Check if file is open or if there was an error
		std::streamoff headstart, headend = 0;
		
		*_fsxml >> std::ws; // Eat up whitespace
		if (_fsxml->peek() == '<') {
			headstart = _fsxml->tellg();
			_fsxml->get();
			
			if (_fsxml->get() != '?') {
				_fsxml->close();
				return false; // Invalid XML
			}
			do {
				char c = _fsxml->get();
				if (c == '?') {
					if (_fsxml->get() == '>') {
						headend = _fsxml->tellg();
						break;
					}
				}
			} while (!_fsxml->eof()); // Loop until end of file is reached.
			
			if (headend == 0) {
				_fsxml->close();
				return false; // Invalid XML
			}
			_fsxml->seekg(headstart); // Reset cursor to beginning of header.
			
			char* header = new char[(uint64_t)(headend - headstart + 1)];
			_fsxml->getline(header, headend - headstart + 1);
			std::string sHeader = header;
			delete[] header;


			_fsxml->close();
			return _parseHeader(sHeader);

			/*
			std::cout << "headstart: " << headstart << " || headend: " << headend << std::endl;
			std::cout << "Header: " << sHeader << std::endl;
			*/

		} else {
			_fsxml->close();
			return false;
		}
		/*
		std::cout << "Stream is at position: " << _fsxml->tellg() << std::endl;
		std::cout << "Next character: '" << (char)_fsxml->peek() << "'" << std::endl;
		*/
	}
	_fsxml->close();
	return false;
}

bool XML::_parseHeader(std::string &sHeader) {
	
	_version = _parseVersion(sHeader);
	_encoding = _parseEncoding(sHeader);
	_standalone = _parseStandalone(sHeader);
	return   (_version != XML_ERR
		   && _encoding != XML_ERR
		   && _standalone != XML_ERR);
}

int XML::_parseVersion(std::string &sHeader) {
	std::string sVersion = sHeader.substr(sHeader.find("version") + std::string("version").length());
	sVersion = sVersion.substr(sVersion.find("\"") + 1);
	sVersion = sVersion.substr(0, sVersion.find("\""));

#ifdef _DEBUG
	OutputDebugString(std::string("XML Version '") + sVersion + std::string("'"));
#endif
	if (sVersion == "1.0") {
		return XML::Version::V1_0;
	}
	return XML_ERR;
}

int XML::_parseEncoding(std::string &sHeader) {
	std::string sEncoding = sHeader.substr(sHeader.find("encoding") + std::string("encoding").length());
	sEncoding = sEncoding.substr(sEncoding.find("\"") + 1);
	sEncoding = sEncoding.substr(0, sEncoding.find("\""));

#ifdef _DEBUG
	OutputDebugString(std::string("XML Encoding '") + sEncoding + std::string("'"));
#endif

	int nEncoding = XML_ERR;
	if (sEncoding == "UTF-8") {
		nEncoding = XML::Encoding::UTF8;
	} else if (sEncoding == "UTF-16") {
		nEncoding = XML::Encoding::UTF16;
	} else if (sEncoding == "ISO-10646-UCS-2") {
		nEncoding = XML::Encoding::ISO10646_UCS2;
	} else if (sEncoding == "ISO-10646-UCS-4") {
		nEncoding = XML::Encoding::ISO10646_UCS4;
	} else if (sEncoding.substr(0, std::string("ISO-8559-").size()) == "ISO-8559-") { // Start here!

	} else if (sEncoding == "ISO-2202-JP") {
		nEncoding = XML::Encoding::ISO2022_JP;
	} else if (sEncoding == "Shift_JIS") {
		nEncoding = XML::Encoding::SHIFT_JIS;
	} else if (sEncoding == "EUC-JP") {
		nEncoding = XML::Encoding::EUC_JP;
	}
	OutputDebugString(std::to_string(nEncoding));
	return nEncoding;
}

int XML::_parseStandalone(std::string &sHeader) {
	return XML_ERR;
}

bool XML::parse() {
	return false;
}

XMLNode::XMLNode() {

}

XMLNode::XMLNode(std::string data, unsigned int level) : XMLNode() {

}

XMLNode::~XMLNode() {

}
