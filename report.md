## Lab Report Analysis

# Level 1
	- Cache unfriendly pattern: Accessing memory column by column in an array of arrays
		- [Description] By accessing column by column, instead of row by row, the cache
		does not contain the values that are next to the first value found.
		- [Fix] This was fixed by accessing the memory in the array of arrays consecutively
		by iterating through each row first before continuing to the next row.

# Level 2
	- Cache unfriendly pattern: Accessing memory column by column for specific locations
	in memory
		- [Description] This is similar to above, except that iterating through
		the whole array, we only target specific values.
		- [Fix] By accessing those specific locations in memory, and seeing that
		finding the value could be done in a way that would be adding the values
		in a row first, before proceeding to the next specific location.
		
# Level 3


# Level 4 (Honours)

