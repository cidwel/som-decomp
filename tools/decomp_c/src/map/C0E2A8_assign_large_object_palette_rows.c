#include "som_c.h"

/* C0E2A8 assign_large_object_palette_rows   [class B, 57 bytes, 24 instructions]
 * Source: src/rom/assign_large_object_palette_rows.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void assign_large_object_palette_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0098);
    uint8_t a1;
    if (value == 0) {
        a1 = 0xA2;
    } else {
        a1 = 0x22;
    }
    RAM16_SET(0xE6F8, a1);
    RAM16_SET(0xE8F8, a1 + 0x20);
    RAM16_SET(0xEAF8, a1 + 0x40);
    uint8_t a2;
    if (value == 0) {
        a2 = 0x82;
    } else {
        a2 = 2;
    }
    RAM16_SET(0xE6FA, a2);
    RAM16_SET(0xE8FA, a2 + 0x0A);
    RAM16_SET(0xEAFA, a2 + 0x14);
    r->a = a2 + 0x14;
    r->y = value;
    r->c = a2 + 0x14 > 0xFFFF;
    r->v = ((a2 + 0x0A ^ a2 + 0x14) & (a2 + 0x14 ^ 0x0A) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0E2A8, SOM_RTS, "gen", assign_large_object_palette_rows, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 57, 24)
