/**
 * @file src/fileinfo/file_presentation/getters/iterative_getter/iterative_subtitle_getter/import_table_json_getter.cpp
 * @brief Methods of ImportTableJsonGetter class.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#include "retdec/utils/conversion.h"
#include "retdec/utils/string.h"
#include "retdec/fileformat/utils/conversions.h"
#include "fileinfo/file_presentation/getters/iterative_getter/iterative_subtitle_getter/import_table_json_getter.h"

using namespace retdec::utils;
using namespace fileformat;

namespace fileinfo {

/**
 * Constructor
 * @param fileInfo Information about file
 */
ImportTableJsonGetter::ImportTableJsonGetter(FileInformation &fileInfo) : IterativeSubtitleGetter(fileInfo)
{
	numberOfStructures = 1;
	numberOfStoredRecords.push_back(fileinfo.getNumberOfStoredImports());
	numberOfExtraElements.push_back(0);
	title = "importTable";
	subtitle = "imports";
	commonHeaderElements.push_back("index");
	commonHeaderElements.push_back("name");
	commonHeaderElements.push_back("libraryName");
	commonHeaderElements.push_back("ordinalNumber");
	commonHeaderElements.push_back("address");
}

/**
 * Destructor
 */
ImportTableJsonGetter::~ImportTableJsonGetter()
{

}

std::size_t ImportTableJsonGetter::getBasicInfo(std::size_t structIndex, std::vector<std::string> &desc, std::vector<std::string> &info) const
{
	if(structIndex >= numberOfStructures || !fileinfo.hasImportTableRecords())
	{
		return 0;
	}

	desc.clear();
	info.clear();

	desc.push_back("numberOfImports");
	desc.push_back("crc32");
	desc.push_back("md5");
	desc.push_back("sha256");
	info.push_back(numToStr(fileinfo.getNumberOfStoredImports()));
	info.push_back(fileinfo.getImphashCrc32());
	info.push_back(fileinfo.getImphashMd5());
	info.push_back(fileinfo.getImphashSha256());

	return info.size();
}

bool ImportTableJsonGetter::getRecord(std::size_t structIndex, std::size_t recIndex, std::vector<std::string> &record) const
{
	if(structIndex >= numberOfStructures || recIndex >= numberOfStoredRecords[structIndex])
	{
		return false;
	}

	record.clear();
	record.push_back(numToStr(recIndex));
	record.push_back(replaceNonprintableChars(fileinfo.getImportName(recIndex)));
	record.push_back(replaceNonprintableChars(fileinfo.getImportLibraryName(recIndex)));
	record.push_back(fileinfo.getImportOrdinalNumberStr(recIndex, std::dec));
	record.push_back(fileinfo.getImportAddressStr(recIndex, hexWithPrefix));

	return true;
}

bool ImportTableJsonGetter::getFlags(std::size_t structIndex, std::size_t recIndex, std::string &flagsValue, std::vector<std::string> &desc) const
{
	if(structIndex >= numberOfStructures || recIndex >= numberOfStoredRecords[structIndex])
	{
		return false;
	}

	flagsValue.clear();
	desc.clear();

	return true;
}

} // namespace fileinfo
