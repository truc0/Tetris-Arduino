int convert(int row, int col)
{
	/**
     * convert a coordination to an integer,
     * which is the corresponding number in
     * LED array
     *
     * @param row, col: shows a coordination
     * 
     * Notice that the coordination starts
     * from 0
	 */

	 row = 17 - row; 

	 if (row % 2 == 1) {
	 	col = 7 - col;
	 }

	 return row*8+col;
}