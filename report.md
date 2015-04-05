## Lab Report Analysis

# Level 1
	- Cache unfriendly pattern: Accessing memory column by column in an array of arrays
		- [Description] By accessing column by column, instead of row by row, the cache
		does not contain the values that are next to the first value found.
		- [Fix] This was fixed by accessing the memory in the array of arrays consecutively
		by iterating through each row first before continuing to the next row.

# Level 2
	- Cache unfriendly pattern: Accessing memory column by column for specific locations
	in memory (diagonals of the array of arrays)
		- [Description] This is similar to above, except that iterating through
		the whole array, we only target specific values.
		- [Fix] By accessing those specific locations in memory, and seeing that
		finding the value could be done in a way that would be adding the values
		in a row first, before proceeding to the next specific location.
		
# Level 3
	- Cache unfriendly pattern: Swapping positions column by column, and having to shift
	the 0th column up by 1, replacing the 4 bytes after c[][] with c[0][0]
		- [Description] Instead of utilizing spatial locality, the unoptimized
		algorithm would end up shifting by columns.
		- [Fix] By swapping first by indices of the 2nd column until the middle column with
		N - index, we manage to implement a swap that swaps within each row. This allows
		us to harness spatial locality, since each swap is on the same row, and gets closer
		to each other each time.
		
		It should also be noted that since we have to end up shifting everything in
		the 0th column up, there's no getting around using a column shift after the
		row swaps are completed. However, this way we only column swap once, instead
		of a lot more times.

# Level 4 (Honours)

