#include "som_c.h"

/* D0CD35 dim_menu_palette_preserving_first_actor_row_when_requested   [class B, 39 bytes, 16 instructions]
 * Source: src/rom/dim_menu_palette_preserving_first_actor_row_when_requested.s
 * Documented in docs/event-menu-vblank.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void dim_menu_palette_preserving_first_actor_row_when_requested(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint16_t value = BUS16(c, (db << 0x10) + 0x1803);
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    if ((value & 1) != 0) {
        a2 = 1;
        a_hi2 = 0;
        x2 = 0;
    } else {
        r->a = 1;
        r->x = 0;
        r->v = value & 0x4000;
        r->mf = 0;
        JSR(c, 0xCD44, 0xD0CD5C); /* save_and_halve_one_menu_palette_color */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint8_t a1 = (uint8_t)a_all;
        uint8_t a_hi1 = a_all >> 8;
        uint16_t x1 = x_ret;
        for (;;) {
            uint16_t value2 = BUS16(c, (db << 0x10) + 0x0600 + x1);
            RAM16_SET(0x8000 + x1, value2);
            a1 = (uint8_t)value2;
            a_hi1 = value2 >> 8;
            x1 = (uint16_t)(x1 + 2);
            if (!(x1 < 0x20)) break;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
    }
    uint8_t a3 = a2;
    uint8_t a_hi3 = a_hi2;
    uint16_t x3 = x2;
    uint16_t y1 = y;
    bool carry1 = 0;
    bool zero1 = 0;
    bool negative1 = 0;
    bool overflow1 = value & 0x4000;
    for (;;) {
        r->a = (a_hi3 << 8) | a3;
        r->x = x3;
        r->y = y1;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = db;
        r->dp = dp;
        JSR(c, 0xCD55, 0xD0CD5C); /* save_and_halve_one_menu_palette_color */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        a3 = (uint8_t)a_all2;
        a_hi3 = a_all2 >> 8;
        x3 = x_ret2;
        carry1 = x_ret2 >= 0x0100;
        zero1 = x_ret2 == 0x0100;
        negative1 = (uint16_t)(x_ret2 - 0x0100) & 0x8000;
        if (!(x3 < 0x0100)) break;
    }
    r->a = (a_hi3 << 8) | a3;
    r->x = x3;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0CD35, SOM_RTS, "gen", dim_menu_palette_preserving_first_actor_row_when_requested, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 39, 16)
