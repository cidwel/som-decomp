#include "som_c.h"

/* C0B313 restore_actor_attack_palette_with_saved_bank   [class A, 12 bytes, 8 instructions]
 * Source: src/rom/restore_actor_attack_palette_with_saved_bank.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void restore_actor_attack_palette_with_saved_bank(SomCtx *c)
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
    r->c = 1;
    r->z = 0;
    r->n = 0;
    r->db = 0x7E;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xB31C, 0x01CA04); GUARD_JSL(c, sp_call, 0xB31C); } /* prepare_or_restore_actor_attack_palette */
    r->sp += 1;
    r->db = RAM8(0x0000 + sp0);
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0B313, SOM_RTS, "gen", restore_actor_attack_palette_with_saved_bank, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 12, 8)
