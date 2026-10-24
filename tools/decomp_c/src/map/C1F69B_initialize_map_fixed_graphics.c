#include "som_c.h"

/* C1F69B initialize_map_fixed_graphics   [class D, 103 bytes, 41 instructions]
 * Source: src/rom/initialize_map_fixed_graphics.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void initialize_map_fixed_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x0000, 0);
    BUS16_SET(c, 0x004372, 0);
    BUS8_SET(c, 0x004374, 0);
    BUS16_SET(c, 0x004370, 0x1809);
    BUS16_SET(c, 0x004375, 0x1000);
    BUS8_SET(c, 0x002115, 0x80);
    BUS16_SET(c, 0x002116, 0x5800);
    BUS8_SET(c, 0x00420B, 0x80);
    r->xf = 1;
    JSR(c, 0xF6CD, 0xC1F767); /* upload_map_expanded_pattern_sets */
    uint8_t value = RAM8(0x00E8);
    if (value & 0x01) {
        BUS16_SET(c, 0x004372, 0x6C00);
        BUS16_SET(c, 0x004370, 0x1801);
        BUS16_SET(c, 0x004375, 0x0800);
        BUS8_SET(c, 0x004374, 0xC6);
        BUS8_SET(c, 0x002115, 0x80);
        BUS16_SET(c, 0x002116, 0x4900);
        BUS8_SET(c, 0x00420B, 0x80);
        r->a = 0x4900;
        r->x = 0x80;
        r->c = value & 0x01;
        r->mf = 0;
        r->xf = 1;
        RETURN_RTS(c);
    }
    SET_A8(r, value >> 1);
    r->c = value & 0x01;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F69B, SOM_RTS, "gen", initialize_map_fixed_graphics, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 103, 41)
