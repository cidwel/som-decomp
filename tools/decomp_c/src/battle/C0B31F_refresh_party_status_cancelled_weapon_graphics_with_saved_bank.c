#include "som_c.h"

/* C0B31F refresh_party_status_cancelled_weapon_graphics_with_saved_bank   [class A, 11 bytes, 7 instructions]
 * Source: src/rom/refresh_party_status_cancelled_weapon_graphics_with_saved_bank.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: A.
 */
static void refresh_party_status_cancelled_weapon_graphics_with_saved_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    r->a = (a_hi << 8) | 0x7E;
    r->z = 0;
    r->n = 0;
    r->db = 0x7E;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xB327, 0x02AFD0); GUARD_JSL(c, sp_call, 0xB327); } /* refresh_all_three_party_status_cancelled_weapons */
    r->sp += 1;
    r->db = RAM8(0x0000 + sp0);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0B31F, SOM_RTS, "gen", refresh_party_status_cancelled_weapon_graphics_with_saved_bank, 0, L_A, 2, 1, 0, 11, 7)
