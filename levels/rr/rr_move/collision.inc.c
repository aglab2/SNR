const Collision rr_move_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(500, -9, -500),
	COL_VERTEX(-500, -9, -500),
	COL_VERTEX(-500, -9, 500),
	COL_VERTEX(500, -9, 500),
	COL_VERTEX(500, -109, -500),
	COL_VERTEX(500, -109, 500),
	COL_VERTEX(-500, -109, 500),
	COL_VERTEX(-500, -109, -500),
	COL_TRI_INIT(SURFACE_DEFAULT, 12),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(2, 6, 5),
	COL_TRI(2, 5, 3),
	COL_TRI(0, 4, 7),
	COL_TRI(0, 7, 1),
	COL_TRI(1, 7, 6),
	COL_TRI(1, 6, 2),
	COL_TRI(3, 5, 4),
	COL_TRI(3, 4, 0),
	COL_TRI_STOP(),
	COL_END()
};
