#include "som_c.h"

/* C1C162 build_map_graphics_two_tile_alternating_left_frames   [class C, 141 bytes, 62 instructions]
 * Source: src/rom/build_map_graphics_two_tile_alternating_left_frames.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: B.
 */
static void build_map_graphics_two_tile_alternating_left_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t a_hi1 = a_hi;
    uint8_t x1 = 0x0F;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            r->x = x1;
            r->mf = 1;
            r->xf = 1;
            r->db = 0x7F;
            r->dp = 0;
            JSR(c, 0xC168, 0xC1C1EF); /* rotate_map_graphics_two_tile_even_rows_left */
            r->mf = 0;
            r->xf = 1;
            JSR(c, 0xC16B, 0xC1C28B); /* rotate_map_graphics_two_tile_odd_rows_left */
            uint16_t a_all2 = r->a;
            if ((uint8_t)(x1 - 1) != 0) {
                a_hi1 = a_all2 >> 8;
                x1 = (uint8_t)(x1 - 1);
                first_pass = false;
                continue;
            }
            a_hi1 = a_all2 >> 8;
            x1 = (uint8_t)(x1 - 1);
            break;
        } else {
            r->x = x1;
            r->mf = 0;
            r->xf = 1;
            r->db = 0x7F;
            r->dp = 0;
            JSR(c, 0xC168, 0xC1C1EF); /* rotate_map_graphics_two_tile_even_rows_left */
            r->mf = 0;
            r->xf = 1;
            JSR(c, 0xC16B, 0xC1C28B); /* rotate_map_graphics_two_tile_odd_rows_left */
            uint16_t a_all4 = r->a;
            if ((uint8_t)(x1 - 1) != 0) {
                a_hi1 = a_all4 >> 8;
                x1 = (uint8_t)(x1 - 1);
                continue;
            }
            a_hi1 = a_all4 >> 8;
            x1 = (uint8_t)(x1 - 1);
            break;
        }
    }
    r->x = x1;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7F;
    r->dp = 0;
    JSR(c, 0xC171, 0xC1C1EF); /* rotate_map_graphics_two_tile_even_rows_left */
    r->mf = 0;
    r->xf = 1;
    TAIL_CALL(c, 0xC1C486, SOM_RTS); /* advance_map_graphics_two_tile_frame_pointer */
}
SOM_REGISTER(0xC1C162, SOM_RTS, "gen", build_map_graphics_two_tile_alternating_left_frames, 0, L_B, 1, 1, 1, 141, 62)
