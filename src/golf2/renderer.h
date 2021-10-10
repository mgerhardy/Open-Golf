#ifndef _GOLF_RENDERER_H
#define _GOLF_RENDERER_H

#include "3rd_party/map/map.h"
#include "3rd_party/sokol/sokol_gfx.h"
#include "3rd_party/vec/vec.h"
#include "mcore/maths.h"

typedef struct golf_renderer_texture {
    unsigned char *data;
    int width;
    int height;
    sg_image sg_image;
} golf_renderer_texture_t; 

typedef struct golf_renderer_model {
    char name[1024];
    vec_vec3_t positions;
    vec_vec2_t texcoords;
    vec_vec3_t normals;
    sg_buffer sg_positions_buf;
    sg_buffer sg_normals_buf;
    sg_buffer sg_texcoords_buf;
} golf_renderer_model_t;

typedef struct golf_renderer_font {
    sg_image sg_image[3];
    int image_size[3];
} golf_renderer_font_t;

typedef map_t(golf_renderer_model_t) map_golf_renderer_model_t;
typedef map_t(golf_renderer_texture_t) map_golf_renderer_texture_t;
typedef map_t(golf_renderer_font_t) map_golf_renderer_font_t;
typedef map_t(sg_shader) map_sg_shader_t;
typedef map_t(sg_pipeline) map_sg_pipeline_t;

typedef struct golf_renderer {
    map_sg_shader_t shaders_map;
    map_sg_pipeline_t pipelines_map;
    map_golf_renderer_model_t models_map;
    map_golf_renderer_texture_t textures_map;
    map_golf_renderer_font_t fonts_map;

    mat4 ui_proj_mat;
} golf_renderer_t;

golf_renderer_t *golf_renderer_get(void);
void golf_renderer_init(void);
void golf_renderer_draw(void);

#endif