#include "som_c.h"

/* C278AA orient_descriptor_ten_chain_link_from_parent_quadrant   [class B, 50 bytes, 21 instructions]
 * Source: src/rom/orient_descriptor_ten_chain_link_from_parent_quadrant.s
 * Documented in docs/boss-descriptor-ten-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: V.
 */
static void orient_descriptor_ten_chain_link_from_parent_quadrant(SomCtx *c)
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
    JSR(c, 0x78C3, 0xC22E2A); /* derive_four_way_direction_from_coordinate_pairs */
    uint16_t value7 = BUS16(c, 0xDCE595 + (uint16_t)(RAM16(0x026A) << 1));
    RAM16_SET(0x0295, value7);
    uint16_t value8 = RAM16(0x0287);
    RAM16_SET(0x0098 + value8, (RAM16(0x0098 + value8) & 0xFF3F) | RAM16(0x0295));
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC278AA, SOM_RTS, "gen", orient_descriptor_ten_chain_link_from_parent_quadrant, 0, L_V, 1, 0, 0, 50, 21)
