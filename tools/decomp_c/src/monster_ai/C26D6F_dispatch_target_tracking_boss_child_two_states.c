#include "som_c.h"

/* C26D6F dispatch_target_tracking_boss_child_two_states   [class C, 10 bytes, 5 instructions]
 * Source: src/rom/dispatch_target_tracking_boss_child_two_states.s
 * Documented in docs/boss-native-child-definitions.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_target_tracking_boss_child_two_states(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value2 = BUS8(c, 0x000094 + RAM16(0x0287));
    r->a = (a_hi << 8) | (uint8_t)(value2 << 1);
    r->x = (a_hi << 8) | (uint8_t)(value2 << 1);
    r->c = value2 & 0x80;
    r->z = ((a_hi << 8) | (uint8_t)(value2 << 1)) == 0;
    r->n = ((a_hi << 8) | (uint8_t)(value2 << 1)) & 0x8000;
    switch ((a_hi << 8) | (uint8_t)(value2 << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC26D7D, SOM_RTS); /* initialize_target_tracking_boss_child */
    case 0x0002: TAIL_CALL_DYN(c, 0xC26DAE, SOM_RTS); /* update_target_tracking_boss_child_direction_and_contacts */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x6D79 + ((a_hi << 8) | (uint8_t)(value2 << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC26D6F, SOM_RTS, "gen", dispatch_target_tracking_boss_child_two_states, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 10, 5)
