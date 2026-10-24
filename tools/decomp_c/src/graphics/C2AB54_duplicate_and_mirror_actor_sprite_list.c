#include "som_c.h"

/* C2AB54 duplicate_and_mirror_actor_sprite_list   [class B, 85 bytes, 48 instructions]
 * Source: src/rom/duplicate_and_mirror_actor_sprite_list.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYV.
 */
static void duplicate_and_mirror_actor_sprite_list(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = x >> 1 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)(x >> 1);
    RAM8(0x0000 + sp0 - 2) = y >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)y;
    r->x = x >> 1;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAB5D, 0xC2ABA9); GUARD_JSR(c, sp_call, 0xAB5D); } /* copy_actor_sprite_list_to_workspace */
    r->sp += 4;
    r->y = (RAM8(0x0000 + sp0 - 2) << 8) | RAM8(0x0000 + sp0 - 3);
    r->mf = 0;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAB61, 0xC2ABA9); GUARD_JSR(c, sp_call, 0xAB61); } /* copy_actor_sprite_list_to_workspace */
    r->sp += 2;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    RAM8(0x0000 + sp0) = value4;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((value4 << 8) | value3);
    uint8_t value5 = RAM8(0x0002);
    RAM8(0x0002) <<= 1;
    uint8_t a1 = value5;
    uint8_t a_hi1 = a_all2 >> 8;
    uint16_t x1 = (value4 << 8) | value3;
    bool overflow1 = overflow;
    for (;;) {
        RAM8(0x0000 + sp0 - 2) = a1;
        uint8_t value8 = RAM8(0xC000 + x1);
        uint8_t a3;
        if (value8 & 0x80) {
            a3 = value8;
        } else {
            uint8_t a2;
            if (value8 < 0x71) {
                a2 = value8;
            } else {
                a2 = 0x70;
            }
            a3 = a2;
        }
        RAM8(0xC000 + x1) = (uint8_t)(a3 + 0x0F) ^ 0xFF;
        uint8_t value9 = RAM8(0xC001 + x1);
        uint8_t a5;
        if (value9 & 0x80) {
            a5 = value9;
        } else {
            uint8_t a4;
            if (value9 < 0x71) {
                a4 = value9;
            } else {
                a4 = 0x70;
            }
            a5 = a4;
        }
        RAM8(0xC001 + x1) = (uint8_t)(a5 + 0x0F) ^ 0xFF;
        RAM8(0xC003 + x1) ^= 0xC0;
        a1 = (uint8_t)(RAM8(0x0000 + sp0 - 2) - 1);
        x1 = (uint16_t)(x1 + 4);
        overflow1 = ((a5 ^ (uint8_t)(a5 + 0x0F)) & ((uint8_t)(a5 + 0x0F) ^ 0x0F) & 0x80) != 0;
        if (!(a1 != 0)) break;
    }
    uint8_t value12 = RAM8(0x0000 + sp0 - 1);
    uint8_t value13 = RAM8(0x0000 + sp0);
    r->a = (value13 << 8) | value12 | 0xC000;
    r->x = (value13 << 8) | value12 | 0xC000;
    r->y = y_ret2;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2AB54, SOM_RTL, "gen", duplicate_and_mirror_actor_sprite_list, 0, L_A | L_B | L_X | L_Y | L_V, 4, 0, 0, 85, 48)
