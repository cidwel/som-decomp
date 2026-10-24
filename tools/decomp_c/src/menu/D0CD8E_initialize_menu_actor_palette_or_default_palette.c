#include "som_c.h"

/* D0CD8E initialize_menu_actor_palette_or_default_palette   [class C, 107 bytes, 50 instructions]
 * Source: src/rom/initialize_menu_actor_palette_or_default_palette.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_menu_actor_palette_or_default_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    if ((RAM16(0x1847) & 0xFF) != 0) {
        uint8_t value3 = RAM8(0xE180 + RAM16(0x183E));
        RAM8(0x185B) = value3;
        BUS8_SET(c, 0x00211B, value3);
        BUS8_SET(c, 0x00211B, 0);
        BUS8_SET(c, 0x00211C, 0x1E);
        uint16_t value4 = BUS16(c, 0x002134);
        BUS8_SET(c, 0x00211C, 0x1E);
        r->a = 0;
        r->x = value4;
        r->z = 1;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xCDD9, 0xC070DF); GUARD_JSL(c, sp_call, 0xCDD9); } /* select_event_menu_palette_slot_long */
        uint16_t a_all = r->a;
        bool overflow_ret = r->v;
        uint8_t a1 = 0x10;
        uint8_t a_hi1 = 0;
        uint16_t x1 = value4;
        uint16_t y1 = (uint16_t)((((a_all & 0xFF) << 8) | 0) << 1);
        bool zero1 = 0;
        bool negative1 = 0;
        for (;;) {
            RAM8(0x0000 + sp0) = a_hi1;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi1 << 8) | a1);
            uint16_t value5 = BUS16(c, 0xC81000 + x1);
            RAM8(0x0000 + sp0 - 2) = x1 >> 8;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)x1;
            BUS16_SET(c, 0x000702 + y1, value5);
            uint8_t value6 = RAM8(0x0000 + sp0 - 3);
            uint8_t value7 = RAM8(0x0000 + sp0 - 2);
            uint8_t value8 = RAM8(0x0000 + sp0 - 1);
            uint8_t value9 = RAM8(0x0000 + sp0);
            a1 = (uint8_t)(((value9 << 8) | value8) - 1);
            a_hi1 = (uint16_t)(((value9 << 8) | value8) - 1) >> 8;
            x1 = (uint16_t)(((value7 << 8) | value6) + 2);
            y1 = (uint16_t)(y1 + 2);
            zero1 = (uint16_t)(((value9 << 8) | value8) - 1) == 0;
            negative1 = (uint16_t)(((value9 << 8) | value8) - 1) & 0x8000;
            if (!((uint16_t)(((value9 << 8) | value8) - 1) != 0)) break;
        }
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = (((a_all & 0xFF) << 8) | 0) & 0x8000;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow_ret;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t a_hi2 = 0;
    uint16_t x2 = 0;
    bool carry1 = carry;
    for (;;) {
        uint16_t value10 = BUS16(c, 0xC81E6A + x2);
        BUS16_SET(c, 0x000702 + x2, value10);
        uint8_t a_hi2_next = value10 >> 8;
        uint16_t x2_next = (uint16_t)(x2 + 2);
        bool carry1_next = (uint16_t)(x2 + 2) >= 0x1E;
        a_hi2 = a_hi2_next;
        x2 = x2_next;
        carry1 = carry1_next;
        if (!(x2 < 0x1E)) break;
    }
    uint8_t value11 = RAM8(0x00EC);
    RAM8(0x00EC) |= 4;
    r->a = (a_hi2 << 8) | 4;
    r->x = x2;
    r->y = y;
    r->c = carry1;
    r->z = (value11 & 4) == 0;
    r->n = 0;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0CD8E, SOM_RTS, "gen", initialize_menu_actor_palette_or_default_palette, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 0, 0, 107, 50)
