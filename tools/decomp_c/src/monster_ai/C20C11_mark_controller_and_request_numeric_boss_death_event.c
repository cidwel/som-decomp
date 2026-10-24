#include "som_c.h"

/* C20C11 mark_controller_and_request_numeric_boss_death_event   [class A, 10 bytes, 5 instructions]
 * Source: src/rom/mark_controller_and_request_numeric_boss_death_event.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYCV.
 */
static void mark_controller_and_request_numeric_boss_death_event(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    RAM8(0x0000 + sp0) = a >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)a;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0C14, 0xC20C1B); GUARD_JSR(c, sp_call, 0x0C14); } /* mark_first_nonzero_party_controller_slot_negative */
    r->sp += 2;
    uint8_t value = RAM8(0x0000 + sp0 - 1);
    uint8_t value2 = RAM8(0x0000 + sp0);
    r->a = (value2 << 8) | value;
    r->z = ((value2 << 8) | value) == 0;
    r->n = ((value2 << 8) | value) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x0C19, 0x018000); GUARD_JSL(c, sp_call, 0x0C19); } /* event_command_public_jump */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20C11, SOM_RTS, "gen", mark_controller_and_request_numeric_boss_death_event, 0, L_B | L_Y | L_C | L_V, 2, 0, 0, 10, 5)
