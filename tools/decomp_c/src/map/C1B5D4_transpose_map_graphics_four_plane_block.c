#include "som_c.h"

/* C1B5D4 transpose_map_graphics_four_plane_block   [class B, 53 bytes, 31 instructions]
 * Source: src/rom/transpose_map_graphics_four_plane_block.s
 * Documented in docs/maps.md
 * Entry: M=any X=8 bit DB=$7F D=$0000.  Callers read: X.
 */
static void transpose_map_graphics_four_plane_block(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->y = 0;
    r->mf = 1;
    JSR(c, 0xB5DA, 0xC1B609); /* transpose_map_graphics_plane */
    uint8_t y_ret = r->y;
    r->y = (uint8_t)(y_ret + 1);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB5DE, 0xC1B609); /* transpose_map_graphics_plane */
    uint16_t a_all2 = r->a;
    uint8_t y_ret2 = r->y;
    r->y = (uint8_t)((a_all2 >> 8 << 8) | (uint8_t)(y_ret2 + 0x0F));
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB5E6, 0xC1B609); /* transpose_map_graphics_plane */
    uint8_t y_ret3 = r->y;
    r->y = (uint8_t)(y_ret3 + 1);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB5EA, 0xC1B609); /* transpose_map_graphics_plane */
    uint16_t a_all4 = r->a;
    uint8_t y_ret4 = r->y;
    r->y = (uint8_t)((a_all4 >> 8 << 8) | (uint8_t)(y_ret4 + 0x0F));
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB5F2, 0xC1B609); /* transpose_map_graphics_plane */
    uint8_t y_ret5 = r->y;
    r->y = (uint8_t)(y_ret5 + 1);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB5F6, 0xC1B609); /* transpose_map_graphics_plane */
    uint16_t a_all6 = r->a;
    uint8_t y_ret6 = r->y;
    r->y = (uint8_t)((a_all6 >> 8 << 8) | (uint8_t)(y_ret6 + 0x0F));
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB5FE, 0xC1B609); /* transpose_map_graphics_plane */
    uint8_t y_ret7 = r->y;
    r->y = (uint8_t)(y_ret7 + 1);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB602, 0xC1B609); /* transpose_map_graphics_plane */
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B5D4, SOM_RTS, "gen", transpose_map_graphics_four_plane_block, 0, L_X, 1, -1, 1, 53, 31)
