#include "som_c.h"

/* C26C9F dispatch_position_height_boss_child_two_states   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_position_height_boss_child_two_states.s
 * Documented in docs/boss-native-child-definitions.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_position_height_boss_child_two_states(SomCtx *c)
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
    case 0x0000: TAIL_CALL_DYN(c, 0xC26CAB, SOM_RTS); /* initialize_position_height_boss_child */
    case 0x0002: TAIL_CALL_DYN(c, 0xC26CC2, SOM_RTS); /* finish_position_height_boss_child_at_counter_26 */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x6CA7 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC26C9F, SOM_RTS, "gen", dispatch_position_height_boss_child_two_states, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 8, 4)
