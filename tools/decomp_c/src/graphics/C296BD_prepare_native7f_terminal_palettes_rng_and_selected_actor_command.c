#include "som_c.h"

/* C296BD prepare_native7f_terminal_palettes_rng_and_selected_actor_command   [class B, 59 bytes, 27 instructions]
 * Source: src/rom/prepare_native7f_terminal_palettes_rng_and_selected_actor_command.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XYCV.
 */
static void prepare_native7f_terminal_palettes_rng_and_selected_actor_command(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x0060 + x) = 0x20;
    RAM16_SET(OBJECT_AGE + x, 0);
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = RAM16(0x0018 + x1);
        uint8_t a_hi2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if ((value & 0xFF) == 0) {
            a_hi2 = 0;
            y2 = y1;
            carry2 = carry1;
            overflow2 = overflow1;
        } else {
            RAM8(0x0000 + sp0) = x1 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)x1;
            RAM8(0x0000 + sp0 - 2) = y1 >> 8;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)y1;
            r->a = 0x87;
            r->x = value & 0xFF;
            r->y = y1;
            r->c = carry1;
            r->z = 0;
            r->n = 0;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0x0300;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x96DC, 0xC226F9); GUARD_JSR(c, sp_call, 0x96DC); } /* copy_boss_palette_with_cpu_words */
            r->sp += 4;
            uint16_t a_all = r->a;
            bool overflow_ret = r->v;
            uint8_t value2 = RAM8(0x0000 + sp0 - 3);
            uint8_t value3 = RAM8(0x0000 + sp0 - 2);
            uint8_t value4 = RAM8(0x0000 + sp0 - 1);
            uint8_t value5 = RAM8(0x0000 + sp0);
            if ((uint16_t)(((value3 << 8) | value2) + 1) < 4) {
                a_hi1 = a_all >> 8;
                x1 = (uint16_t)(((value5 << 8) | value4) + 1);
                y1 = (uint16_t)(((value3 << 8) | value2) + 1);
                carry1 = (uint16_t)(((value3 << 8) | value2) + 1) >= 4;
                overflow1 = overflow_ret;
                continue;
            }
            a_hi2 = a_all >> 8;
            y2 = (uint16_t)(((value3 << 8) | value2) + 1);
            carry2 = (uint16_t)(((value3 << 8) | value2) + 1) >= 4;
            overflow2 = overflow_ret;
        }
        a_hi1 = a_hi2;
        y1 = y2;
        carry1 = carry2;
        overflow1 = overflow2;
        break;
    }
    r->a = 0x27;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = 0;
    r->n = 0;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0300;
    { const uint16_t sp_call = r->sp; JSR(c, 0x96EB, 0xC224C3); GUARD_JSR(c, sp_call, 0x96EB); } /* prepare_boss_loader_resource_expansion */
    r->a = 0x8B00;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x96F1, 0xC23963); GUARD_JSR(c, sp_call, 0x96F1); } /* boss_external_actor_command_if_selected */
    uint16_t dp_ret = r->dp;
    uint16_t y_ret3 = r->y;
    { const uint16_t sp_call = r->sp; JSR(c, 0x96F4, 0xC20B4F); GUARD_JSR(c, sp_call, 0x96F4); } /* boss_death_initialization_reserved_return */
    bool x_ret5 = r->xf;
    if (x_ret5) {
        uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        r->x = value6;
        r->y = (uint8_t)y_ret3;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        r->x = value7;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC296BD, SOM_RTS, "gen", prepare_native7f_terminal_palettes_rng_and_selected_actor_command, 0, L_X | L_Y | L_C | L_V, 4, 1, 0, 59, 27)
