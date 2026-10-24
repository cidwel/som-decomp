#include "som_c.h"

/* C185D8 load_object_weapon_palette_from_field_04f   [class A, 12 bytes, 5 instructions]
 * Source: src/rom/load_object_weapon_palette_from_field_04f.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void load_object_weapon_palette_from_field_04f(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint16_t value = RAM16(0x0014);
    r->a = (a_hi << 8) | RAM8(0xE04F + value);
    r->x = value;
    TAIL_CALL(c, 0xC1859B, SOM_RTS); /* copy_object_weapon_palette */
}
SOM_REGISTER(0xC185D8, SOM_RTS, "gen", load_object_weapon_palette_from_field_04f, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 12, 5)
