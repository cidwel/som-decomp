#include "som_c.h"

/* C28009 dispatch_native58_right_child_phase   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_native58_right_child_phase.s
 * Documented in docs/boss-native58-right-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_native58_right_child_phase(SomCtx *c)
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
    case 0x0000: TAIL_CALL_DYN(c, 0xC2801B, SOM_RTS); /* initialize_mirrored_right_child_and_linked_grandchild */
    case 0x0002: TAIL_CALL_DYN(c, 0xC2808B, SOM_RTS); /* wait_right_child_initial_sixty_ticks */
    case 0x0004: TAIL_CALL_DYN(c, 0xC280A3, SOM_RTS); /* follow_parent_right_side_and_consume_damage */
    case 0x0006: TAIL_CALL_DYN(c, 0xC280D9, SOM_RTS); /* recover_right_child_after_twenty_four_ticks */
    case 0x0008: TAIL_CALL_DYN(c, 0xC28106, SOM_RTS); /* follow_parent_right_side_while_dead_or_restart */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x8011 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC28009, SOM_RTS, "gen", dispatch_native58_right_child_phase, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 8, 4)
