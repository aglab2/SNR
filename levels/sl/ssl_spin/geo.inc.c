#include "src/game/envfx_snow.h"

const GeoLayout ssl_spin_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ssl_spin_Circle_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
