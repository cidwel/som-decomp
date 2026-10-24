#include "som_c.h"

/* C28999 dispatch_native59_child_radius_convergence   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_native59_child_radius_convergence.s
 * Documented in docs/boss-native59-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: YCV.
 */
static void dispatch_native59_child_radius_convergence(SomCtx *c)
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
    case 0x0000: TAIL_CALL_DYN(c, 0xC289A5, SOM_RTS); /* increase_native59_radius_or_clamp_to_parent_target */
    case 0x0002: TAIL_CALL_DYN(c, 0xC289BA, SOM_RTS); /* decrease_native59_radius_or_clamp_to_parent_target */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x89A1 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC28999, SOM_RTS, "gen", dispatch_native59_child_radius_convergence, SOM_UNWINDS, L_Y | L_C | L_V, 1, 0, 0, 8, 4)
