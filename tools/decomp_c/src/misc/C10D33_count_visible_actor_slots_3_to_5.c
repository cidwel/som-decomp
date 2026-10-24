#include "som_c.h"

/* C10D33 count_visible_actor_slots_3_to_5   [class B, 48 bytes, 29 instructions]
 * Source: src/rom/count_visible_actor_slots_3_to_5.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: AYV.
 */
static void count_visible_actor_slots_3_to_5(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0001 + (uint16_t)(sp0 - 5)) = 3;
    RAM8(0x0002 + (uint16_t)(sp0 - 5)) = 0;
    uint8_t a_hi1 = (uint16_t)(sp0 - 5) >> 8;
    uint16_t x1 = 0xE600;
    uint16_t y1 = y;
    bool zero1 = 0;
    bool overflow1 = overflow;
    uint16_t direct_page = (uint16_t)(sp0 - 5);
    for (;;) {
        r->a = (a_hi1 << 8) | a;
        r->x = x1;
        r->y = y1;
        r->z = zero1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = direct_page;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0D47, 0xC10526); GUARD_JSR(c, sp_call, 0x0D47); } /* test_actor_on_screen */
        r->sp += 5;
        uint16_t dp_ret = r->dp;
        if (r->xf != 0) { c->fail = 3; return; }
        bool zero_ret = r->z;
        if (!zero_ret) {
            uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value - 1));
            if ((uint8_t)(value - 1) != 0) {
                uint8_t a_hi1_next = (uint16_t)(x1 + 0x0200) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 0x0200);
                bool zero1_next = (uint8_t)(value - 1) == 0;
                bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x0200)) & ((uint16_t)(x1 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                uint16_t direct_page_next = dp_ret;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                zero1 = zero1_next;
                overflow1 = overflow1_next;
                direct_page = direct_page_next;
                continue;
            }
            uint8_t a_hi1_next3 = (uint16_t)(x1 + 0x0200) >> 8;
            uint16_t x1_next3 = (uint16_t)(x1 + 0x0200);
            bool zero1_next3 = (uint8_t)(value - 1) == 0;
            bool overflow1_next3 = ((x1 ^ (uint16_t)(x1 + 0x0200)) & ((uint16_t)(x1 + 0x0200) ^ 0x0200) & 0x8000) != 0;
            uint16_t direct_page_next3 = dp_ret;
            a_hi1 = a_hi1_next3;
            x1 = x1_next3;
            zero1 = zero1_next3;
            overflow1 = overflow1_next3;
            direct_page = direct_page_next3;
            break;
        }
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
        BUS8_SET(c, (uint16_t)(dp_ret + 2), (uint8_t)(value2 + 1));
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value3 - 1));
        if ((uint8_t)(value3 - 1) != 0) {
            uint8_t a_hi1_next2 = (uint16_t)(x1 + 0x0200) >> 8;
            uint16_t x1_next2 = (uint16_t)(x1 + 0x0200);
            bool zero1_next2 = (uint8_t)(value3 - 1) == 0;
            bool overflow1_next2 = ((x1 ^ (uint16_t)(x1 + 0x0200)) & ((uint16_t)(x1 + 0x0200) ^ 0x0200) & 0x8000) != 0;
            uint16_t direct_page_next2 = dp_ret;
            a_hi1 = a_hi1_next2;
            x1 = x1_next2;
            zero1 = zero1_next2;
            overflow1 = overflow1_next2;
            direct_page = direct_page_next2;
            continue;
        }
        uint8_t a_hi1_next4 = (uint16_t)(x1 + 0x0200) >> 8;
        uint16_t x1_next4 = (uint16_t)(x1 + 0x0200);
        bool zero1_next4 = (uint8_t)(value3 - 1) == 0;
        bool overflow1_next4 = ((x1 ^ (uint16_t)(x1 + 0x0200)) & ((uint16_t)(x1 + 0x0200) ^ 0x0200) & 0x8000) != 0;
        uint16_t direct_page_next4 = dp_ret;
        a_hi1 = a_hi1_next4;
        x1 = x1_next4;
        zero1 = zero1_next4;
        overflow1 = overflow1_next4;
        direct_page = direct_page_next4;
        break;
    }
    uint8_t value4 = BUS8_RDP(c, (uint16_t)(direct_page + 2));
    RAM8(0x0000 + sp0 - 3) = value4;
    uint8_t value6 = RAM8(0x0000 + sp0 - 3);
    uint8_t value7 = RAM8(0x0000 + sp0 - 2);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value6;
    r->y = y1;
    r->v = value7 & 0x40;
    r->mf = value7 & 0x20;
    r->xf = value7 & 0x10;
    r->db = 0x7E;
    r->dp = (value9 << 8) | value8;
    r->i = value7 & 0x04;
    r->d = value7 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10D33, SOM_RTS, "gen", count_visible_actor_slots_3_to_5, 0, L_A | L_Y | L_V, 5, 1, 0, 48, 29)
