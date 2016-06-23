#pragma once

#define XML_ERR -1

class XML {
public:
	enum Version {
		V1_0
	};

	enum Encoding {
		UTF8,
		UTF16,
		ISO10646_UCS2,
		ISO10646_UCS4,
		ISO8859_1,
		ISO8859_2,
		ISO8859_3,
		ISO8859_4,
		ISO8859_5,
		ISO8859_6,
		ISO8859_7,
		ISO8859_8,
		ISO8859_9,
		ISO2022_JP,
		SHIFT_JIS,
		EUC_JP
	};

	enum Standalone {
		NO,
		YES
	};
	
	XML();
	XML(const char* fname);
	~XML();
	
	bool open(const char* fname);
	bool parse();
	
	int getXMLVersion();
	int getXMLEncoding();
	int getXMLStandalone();

protected:
	bool _parseHeader(std::string &sHeader);
	int _parseVersion(std::string &sHeader);
	int _parseEncoding(std::string &sHeader);
	int _parseStandalone(std::string &sHeader);

private:
	bool _isParsed;

	int _version;
	int _encoding;
	int _standalone;

	std::fstream* _fsxml; // TODO: support wide characters (wfstream)
	
	//Node Structure needed
	//std::list<XMLNode*> _nodes;
	
};

class XMLNode {
public:
	XMLNode();
	XMLNode(std::string data, unsigned int level);
	~XMLNode();

	bool parse();

private:
	XMLNode* child;
};
