#include "src/game/envfx_snow.h"

const GeoLayout rr_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_render_mirror_mario),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -10798, 85, -14843),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_ow_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rr_dl_ow_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_ow_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rr_dl_ow_003_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_ow_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rr_dl_ow_005_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -13278, 0, -52, 0, -180, 0, rr_dl_ow_006_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, -34012, 0, -52, 0, -180, 0, rr_dl_ow_007_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_ow_008_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rr_dl_ow_009_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_ow_010_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rr_dl_ow_011_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_Plane_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rr_dl_Plane_006_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_Sphere_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_Sphere_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_Sphere_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_Sphere_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_Sphere_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_Sphere_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_Sphere_006_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_Sphere_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rr_dl_Sphere_008_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout rr_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, rr_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
