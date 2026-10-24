#include "som_c.h"

/* C27C5F dispatch_native58_body_part_order   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_native58_body_part_order.s
 * Documented in docs/boss-native58-parent-actions.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: X.
 */
static void dispatch_native58_body_part_order(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B0 + x);
    r->a = (uint16_t)(value << 1);
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = (uint16_t)(value << 1) == 0;
    r->n = (uint16_t)(value << 1) & 0x8000;
    switch ((uint16_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC27C9D, SOM_RTS); /* dispatch_native58_variant_action */
    case 0x0002: TAIL_CALL_DYN(c, 0xC27C6D, SOM_RTS); /* publish_left_arm_random_order */
    case 0x0004: TAIL_CALL_DYN(c, 0xC27C85, SOM_RTS); /* publish_right_arm_random_order */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x7C67 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC27C5F, SOM_RTS, "gen", dispatch_native58_body_part_order, SOM_UNWINDS, L_X, 1, 0, 0, 8, 4)
