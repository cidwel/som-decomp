#include "som_c.h"

/* C0A615 clear_world_map_picker_image_and_prepare_matrix   [class D, 35 bytes, 16 instructions]
 * Source: src/rom/clear_world_map_picker_image_and_prepare_matrix.s
 * Entry: M=8 bit X=8 bit DB=any D=any.  Callers read: BXYCV.
 */
static void clear_world_map_picker_image_and_prepare_matrix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 1)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
    BUS8_SET(c, (uint16_t)(dp + 0x1E), (uint8_t)(value + 1));
    BUS8_SET(c, (db << 0x10) + 0x2181, 0);
    BUS8_SET(c, (db << 0x10) + 0x2182, 0);
    BUS8_SET(c, (db << 0x10) + 0x2183, 1);
    uint8_t x1 = 0x40;
    uint8_t y1 = 0;
    for (;;) {
        BUS8_SET(c, (db << 0x10) + 0x2180, 0xC0);
        if ((uint8_t)(y1 + 1) != 0) {
            y1 = (uint8_t)(y1 + 1);
            continue;
        }
        x1 = (uint8_t)(x1 - 1);
        y1 = (uint8_t)(y1 + 1);
        if (!(x1 != 0)) break;
    }
    r->a = (a_hi << 8) | 0xC0;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->v = overflow;
    TAIL_CALL(c, 0xC0A9E1, SOM_RTS); /* prepare_world_map_picker_scaled_matrix_coefficients */
}
SOM_REGISTER(0xC0A615, SOM_RTS, "gen", clear_world_map_picker_image_and_prepare_matrix, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 35, 16)
