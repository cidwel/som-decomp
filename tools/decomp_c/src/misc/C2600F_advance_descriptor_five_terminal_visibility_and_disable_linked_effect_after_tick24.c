#include "som_c.h"

/* C2600F advance_descriptor_five_terminal_visibility_and_disable_linked_effect_after_tick24   [class A, 30 bytes, 12 instructions]
 * Source: src/rom/advance_descriptor_five_terminal_visibility_and_disable_linked_effect_after_tick24.s
 * Documented in docs/boss-descriptor-five-terminal.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void advance_descriptor_five_terminal_visibility_and_disable_linked_effect_after_tick24(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(OBJECT_AGE + battle_defence_work);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value < 0x18) {
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
        zero1 = value == 0x18;
        negative1 = (uint16_t)(value - 0x18) & 0x8000;
    } else {
        RAM16_SET(OBJECT_AGE + battle_defence_work, 0);
        RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
        uint16_t value2 = RAM16(0x0070 + battle_defence_work);
        RAM16_SET(0x0070 + battle_defence_work, value2 | 4);
        RAM16_SET(0x00A7 + battle_defence_work, 0);
        a1 = (uint8_t)(value2 | 4);
        a_hi1 = (value2 | 4) >> 8;
        zero1 = (value2 | 4) == 0;
        negative1 = (value2 | 4) & 0x8000;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = battle_defence_work;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2600F, SOM_RTS, "gen", advance_descriptor_five_terminal_visibility_and_disable_linked_effect_after_tick24, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 30, 12)
