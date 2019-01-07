#ifndef AUXILLARY_H
#define AUXILLARY_H
#include <vector>
// this file defines enums used by the rest of the program
// SavedStates enums out each potential save state that a book can be in
//	Note: SAVING, while currently useless, could provide more support for multi-threading later
// SeachCriteria is an enum that lists a tag for every type of field the user can input into the search. Those fields which can be sorted by are used from here as well
enum SavedStates{SAVED = 0, UNSAVED, SAVING};
enum SearchCriteria{LAST_NAME = 0, PHONE, FIRST_NAME, ADDRESS1, ADDRESS2, CITY, STATE, ZIP};
extern SearchCriteria sortCriteria;
extern std::vector<SearchCriteria> searchCriteria;
#endif
