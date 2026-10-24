#include "som_c.h"

/* C2111C copy_boss_actor_palette_group   [class B, 25 bytes, 14 instructions]
 * Source: src/rom/copy_boss_actor_palette_group.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYV.
 */
static void copy_boss_actor_palette_group(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = y >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)y;
    BUS8_SET(c, (uint16_t)(dp + 0x46), a_hi);
    uint8_t a_hi1 = a;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value = RAM8(0x0018 + x1);
        uint8_t a_hi2;
        uint16_t y2;
        bool overflow2;
        if (value == 0) {
            a_hi2 = a_hi1;
            y2 = y1;
            overflow2 = overflow1;
        } else {
            r->a = (a_hi1 << 8) | value;
            r->x = x1;
            r->y = y1;
            r->z = value == 0;
            r->n = value & 0x80;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = dp;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1127, 0xC21135); GUARD_JSR(c, sp_call, 0x1127); } /* copy_boss_palette_seven_colors */
            r->sp += 2;
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            uint16_t y_ret = r->y;
            bool overflow_ret = r->v;
            if (((uint8_t)(x_ret + 1) & 4) == 0) {
                a_hi1 = a_all >> 8;
                x1 = (uint16_t)(x_ret + 1);
                y1 = y_ret;
                overflow1 = overflow_ret;
                continue;
            }
            a_hi2 = a_all >> 8;
            y2 = y_ret;
            overflow2 = overflow_ret;
        }
        a_hi1 = a_hi2;
        y1 = y2;
        overflow1 = overflow2;
        break;
    }
    RAM8(0x0100 + ((RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1))) = 0;
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    r->a = (a_hi1 << 8) | a;
    r->x = value4;
    r->y = y1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2111C, SOM_RTS, "gen", copy_boss_actor_palette_group, 0, L_B | L_X | L_Y | L_V, 2, 1, 0, 25, 14)
