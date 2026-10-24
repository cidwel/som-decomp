#include "som_c.h"

/* C2789C terminate_descriptor_ten_chain_when_animation_completes   [class A, 14 bytes, 8 instructions]
 * Source: src/rom/terminate_descriptor_ten_chain_when_animation_completes.s
 * Documented in docs/boss-descriptor-ten-children.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void terminate_descriptor_ten_chain_when_animation_completes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint8_t value = RAM8(0x009E + battle_defence_work);
    if (value != 0) {
        SET_A8(r, value);
        r->x = battle_defence_work;
        r->c = 0;
        r->z = value == 0;
        r->n = value & 0x80;
        RETURN_RTS(c);
    }
    RAM8(0x0000 + battle_defence_work) = 0;
    SET_A8(r, value);
    r->x = battle_defence_work;
    r->c = 1;
    r->z = value == 0;
    r->n = value & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2789C, SOM_RTS, "gen", terminate_descriptor_ten_chain_when_animation_completes, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 14, 8)
