#include "som_c.h"

/* C0BDBB reassign_controller_with_saved_bank   [class A, 10 bytes, 7 instructions]
 * Source: src/rom/reassign_controller_with_saved_bank.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: BXYCV.
 */
static void reassign_controller_with_saved_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = db;
    RAM8(0x0000 + sp0 - 1) = 0;
    r->a = (a_hi << 8) | 0;
    r->db = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBDC2, 0xC0BDC5); GUARD_JSR(c, sp_call, 0xBDC2); } /* reassign_controller_and_update_hud */
    r->sp += 1;
    r->db = RAM8(0x0000 + sp0);
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0BDBB, SOM_RTL, "gen", reassign_controller_with_saved_bank, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 10, 7)
