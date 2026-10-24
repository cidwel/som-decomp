#include "som_c.h"

/* C2876C dispatch_native59_variant_hp_scaling   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_native59_variant_hp_scaling.s
 * Documented in docs/boss-native59-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABCV.
 */
static void dispatch_native59_variant_hp_scaling(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0042 + x);
    r->a = (uint16_t)(value << 1);
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = (uint16_t)(value << 1) == 0;
    r->n = (uint16_t)(value << 1) & 0x8000;
    switch ((uint16_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC28778, SOM_RTS); /* scale_native59_variant_zero_child_from_missing_hp_fraction */
    case 0x0002: TAIL_CALL_DYN(c, 0xC287C1, SOM_RTS); /* scale_native59_variant_one_child_from_current_hp_fraction */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x8774 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC2876C, SOM_RTS, "gen", dispatch_native59_variant_hp_scaling, SOM_UNWINDS, L_A | L_B | L_C | L_V, 1, 0, 0, 8, 4)
