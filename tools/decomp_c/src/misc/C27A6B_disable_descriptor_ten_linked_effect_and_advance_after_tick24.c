#include "som_c.h"

/* C27A6B disable_descriptor_ten_linked_effect_and_advance_after_tick24   [class A, 23 bytes, 11 instructions]
 * Source: src/rom/disable_descriptor_ten_linked_effect_and_advance_after_tick24.s
 * Documented in docs/boss-descriptor-ten-terminal.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void disable_descriptor_ten_linked_effect_and_advance_after_tick24(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(OBJECT_AGE + battle_defence_work);
    if (value >= 0x18) {
        RAM16_SET(0x00A7 + battle_defence_work, 0);
        RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
        r->a = value;
        r->x = battle_defence_work;
        r->c = 0;
        r->z = RAM16(OBJECT_PHASE + battle_defence_work) == 0;
        r->n = RAM16(OBJECT_PHASE + battle_defence_work) & 0x8000;
        RETURN_RTS(c);
    }
    r->a = value;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7A77, 0xC20C89); GUARD_JSR(c, sp_call, 0x7A77); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27A6B, SOM_RTS, "gen", disable_descriptor_ten_linked_effect_and_advance_after_tick24, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 23, 11)
