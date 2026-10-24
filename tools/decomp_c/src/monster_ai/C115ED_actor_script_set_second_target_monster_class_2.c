#include "som_c.h"

/* C115ED actor_script_set_second_target_monster_class_2   [class A, 18 bytes, 7 instructions]
 * Source: src/rom/actor_script_set_second_target_monster_class_2.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_set_second_target_monster_class_2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    RAM8(0x01AD + y) = 0xFF;
    r->a = (a_hi << 8) | 0xFF;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x15F4, 0xC10DC1); GUARD_JSR(c, sp_call, 0x15F4); } /* find_first_eligible_monster_class_2 */
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    if ((uint8_t)a_all != 0xFF) {
        RAM8(0x01AD + y) = (uint8_t)a_all;
    }
    r->c = (uint8_t)a_all >= 0xFF;
    r->z = (uint8_t)a_all == 0xFF;
    r->n = (uint8_t)((uint8_t)a_all - 0xFF) & 0x80;
    TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
}
SOM_REGISTER(0xC115ED, SOM_RTS, "gen", actor_script_set_second_target_monster_class_2, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 18, 7)
