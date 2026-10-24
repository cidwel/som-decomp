#include "som_c.h"

/* C11FB3 actor_script_call_selected_effect_preserving_context   [class A, 21 bytes, 15 instructions]
 * Source: src/rom/actor_script_call_selected_effect_preserving_context.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: Y.
 */
static void actor_script_call_selected_effect_preserving_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = y >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)y;
    r->a = (a_hi << 8) | 0x7E;
    r->z = 0;
    r->n = 0;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSL(c, 0x1FC2, 0xC00024); GUARD_JSL(c, sp_call, 0x1FC2); } /* actor_selected_effect_public_jump */
    r->sp += 6;
    bool x_ret = r->xf;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        uint8_t value6 = RAM8(0x0000 + sp0 - 5);
        uint8_t value7 = RAM8(0x0000 + sp0 - 4);
        uint8_t value8 = RAM8(0x0000 + sp0 - 3);
        uint8_t value9 = RAM8(0x0000 + sp0 - 2);
        uint8_t value10 = RAM8(0x0000 + sp0 - 1);
        uint8_t value11 = RAM8(0x0000 + sp0);
        r->y = (value7 << 8) | value6;
        r->mf = value9 & 0x20;
        r->xf = value9 & 0x10;
        r->db = value8;
        r->dp = (value11 << 8) | value10;
        r->i = value9 & 0x04;
        r->d = value9 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC11FB3, SOM_RTS, "gen", actor_script_call_selected_effect_preserving_context, 0, L_Y, 6, 1, 0, 21, 15)
