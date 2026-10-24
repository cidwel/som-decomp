#include "som_c.h"

/* C27AD0 finish_descriptor_ten_terminal_when_controllers_unlock_and_event_nonzero   [class B, 36 bytes, 16 instructions]
 * Source: src/rom/finish_descriptor_ten_terminal_when_controllers_unlock_and_event_nonzero.s
 * Documented in docs/boss-descriptor-ten-terminal.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void finish_descriptor_ten_terminal_when_controllers_unlock_and_event_nonzero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x00D9);
    uint16_t value2 = RAM16(0x00DA);
    uint16_t value3 = RAM16(0x00DB);
    if (((value | value2 | value3) & 0x80) != 0) {
        r->a = value | value2 | value3;
        r->x = battle_defence_work;
        r->c = 0;
        r->z = ((value | value2 | value3) & 0x80) == 0;
        r->n = (value | value2 | value3) & 0x8000;
        RETURN_RTS(c);
    }
    uint16_t value4 = RAM16(0x1D04);
    if ((value4 & 0x20) != 0) {
        r->a = value4;
        r->x = battle_defence_work;
        r->c = 0;
        r->z = (value4 & 0x20) == 0;
        r->n = value4 & 0x8000;
        RETURN_RTS(c);
    }
    uint16_t value5 = RAM16(0x0072 + battle_defence_work);
    if (value5 == 0) {
        r->a = value5;
        r->x = battle_defence_work;
        r->c = 0;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
        RETURN_RTS(c);
    }
    r->a = value5;
    r->x = battle_defence_work;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7AEF, 0xC20C11); GUARD_JSR(c, sp_call, 0x7AEF); } /* mark_controller_and_request_numeric_boss_death_event */
    r->c = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27AD0, SOM_RTS, "gen", finish_descriptor_ten_terminal_when_controllers_unlock_and_event_nonzero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 36, 16)
