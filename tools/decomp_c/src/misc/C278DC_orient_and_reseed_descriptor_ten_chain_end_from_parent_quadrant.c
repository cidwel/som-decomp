#include "som_c.h"

/* C278DC orient_and_reseed_descriptor_ten_chain_end_from_parent_quadrant   [class B, 92 bytes, 37 instructions]
 * Source: src/rom/orient_and_reseed_descriptor_ten_chain_end_from_parent_quadrant.s
 * Documented in docs/boss-descriptor-ten-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: V.
 */
static void orient_and_reseed_descriptor_ten_chain_end_from_parent_quadrant(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B0 + x);
    RAM16_SET(0x0246, RAM16(0x002B + x));
    RAM16_SET(0x024E, RAM16(0x0032 + x));
    RAM16_SET(0x0256, RAM16(0x002B + value));
    uint16_t value5 = RAM16(0x0032 + value);
    RAM16_SET(0x025E, value5);
    r->a = value5;
    r->y = value;
    JSR(c, 0x78F5, 0xC22E2A); /* derive_four_way_direction_from_coordinate_pairs */
    uint16_t value6 = RAM16(0x026A);
    uint16_t value7 = RAM16(0x0287);
    RAM16_SET(0x00AB + value7, value6);
    uint16_t value8 = RAM16(0x0042 + value7);
    uint8_t a_hi1;
    uint16_t x1;
    if (value8 != 0) {
        uint16_t value9 = RAM16(0x00AB + value7);
        uint16_t value10 = BUS16(c, 0xDCE59D + (uint16_t)(value9 << 1));
        RAM16_SET(0x0295, value10);
        uint16_t value11 = BUS16(c, 0xDCE5AD + (uint16_t)(value9 << 1));
        uint16_t value12 = RAM16(0x0287);
        r->a = value11;
        r->x = value12;
        r->c = value9 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x792B, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all2 = r->a;
        a_hi1 = a_all2 >> 8;
        x1 = value12;
    } else {
        uint16_t value13 = RAM16(0x00AB + value7);
        uint16_t value14 = BUS16(c, 0xDCE59D + (uint16_t)(value13 << 1));
        RAM16_SET(0x0295, value14);
        uint16_t value15 = BUS16(c, 0xDCE5A5 + (uint16_t)(value13 << 1));
        uint16_t value16 = RAM16(0x0287);
        r->a = value15;
        r->x = value16;
        r->c = value13 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x7915, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all3 = r->a;
        a_hi1 = a_all3 >> 8;
        x1 = value16;
    }
    RAM16_SET(0x0098 + x1, (RAM16(0x0098 + x1) & 0xFF3F) | RAM16(0x0295));
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC278DC, SOM_RTS, "gen", orient_and_reseed_descriptor_ten_chain_end_from_parent_quadrant, 0, L_V, 1, 0, 0, 92, 37)
