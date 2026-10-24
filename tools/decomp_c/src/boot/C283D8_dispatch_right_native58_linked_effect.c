#include "som_c.h"

/* C283D8 dispatch_right_native58_linked_effect   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_right_native58_linked_effect.s
 * Documented in docs/boss-native58-linked-effects.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_right_native58_linked_effect(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(OBJECT_PHASE + x);
    r->a = (uint16_t)(value << 1);
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = (uint16_t)(value << 1) == 0;
    r->n = (uint16_t)(value << 1) & 0x8000;
    switch ((uint16_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC283E6, SOM_RTS); /* initialize_right_native58_linked_effect_and_continue */
    case 0x0002: TAIL_CALL_DYN(c, 0xC28403, SOM_RTS); /* follow_parent_and_map_right_child_animation_or_withdraw */
    case 0x0004: TAIL_CALL_DYN(c, 0xC2842C, SOM_RTS); /* terminate_right_linked_effect_after_withdrawal */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x83E0 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC283D8, SOM_RTS, "gen", dispatch_right_native58_linked_effect, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 8, 4)
