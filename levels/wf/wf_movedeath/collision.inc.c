const Collision wf_movedeath_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(10),
	COL_VERTEX(-500, 0, -500),
	COL_VERTEX(0, -372, 0),
	COL_VERTEX(-500, 0, 500),
	COL_VERTEX(-500, 204, 500),
	COL_VERTEX(0, 204, 0),
	COL_VERTEX(-500, 204, -500),
	COL_VERTEX(500, 0, 500),
	COL_VERTEX(500, 0, -500),
	COL_VERTEX(500, 204, -500),
	COL_VERTEX(500, 204, 500),
	COL_TRI_INIT(SURFACE_INSTANT_QUICKSAND, 16),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 4, 5),
	COL_TRI(6, 7, 8),
	COL_TRI(6, 8, 9),
	COL_TRI(0, 5, 8),
	COL_TRI(0, 8, 7),
	COL_TRI(6, 9, 3),
	COL_TRI(6, 3, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(0, 3, 5),
	COL_TRI(6, 1, 7),
	COL_TRI(8, 5, 4),
	COL_TRI(0, 7, 1),
	COL_TRI(6, 2, 1),
	COL_TRI(8, 4, 9),
	COL_TRI(3, 9, 4),
	COL_TRI_STOP(),
	COL_END()
};
