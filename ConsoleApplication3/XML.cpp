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

			/*return*/ _parseHeader(sHeader);

			std::cout << "headstart: " << headstart << " || headend: " << headend << std::endl;
			std::cout << "Header: " << sHeader << std::endl;

		} else {
			_fsxml->close();
			return false;
		}

		std::cout << "Stream is at position: " << _fsxml->tellg() << std::endl;
		std::cout << "Next character: '" << (char)_fsxml->peek() << "'" << std::endl;
	}
	_fsxml->close();
	return false;
}

bool XML::_parseHeader(std::string sHeader) {
	
	_version = _parseVersion(sHeader);
	_encoding = _parseEncoding(sHeader);
	_standalone = _parseStandalone(sHeader);
	return   (_version != XML_ERR
		   && _encoding != XML_ERR
		   && _standalone != XML_ERR);
}

int XML::_parseVersion(std::string sHeader) {
	return XML_ERR;
}

int XML::_parseEncoding(std::string sHeader) {
	return XML_ERR;
}

int XML::_parseStandalone(std::string sHeader) {
	return XML_ERR;
}

bool XML::parse() {
	return false;
}

XMLNode::XMLNode() {

}

XMLNode::XMLNode(XMLNode* parent) : XMLNode() {

}

XMLNode::~XMLNode() {

}
