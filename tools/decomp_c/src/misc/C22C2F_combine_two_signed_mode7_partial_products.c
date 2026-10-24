#include "som_c.h"

/* C22C2F combine_two_signed_mode7_partial_products   [class D, 98 bytes, 38 instructions]
 * Source: src/rom/combine_two_signed_mode7_partial_products.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void combine_two_signed_mode7_partial_products(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x46));
    BUS8_SET(c, 0x00211B, value);
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp + 0x47));
    BUS8_SET(c, 0x00211B, value2);
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp + 0x4E));
    BUS8_SET(c, 0x00211C, value3);
    uint8_t value4 = BUS8(c, 0x002134);
    BUS8_SET(c, (uint16_t)(dp + 0x56), value4);
    uint8_t value5 = BUS8(c, 0x002135);
    BUS8_SET(c, (uint16_t)(dp + 0x57), value5);
    uint8_t value6 = BUS8(c, 0x002136);
    BUS8_SET(c, (uint16_t)(dp + 0x58), value6);
    BUS8_SET(c, (uint16_t)(dp + 0x59), 0);
    if (value6 & 0x80) {
        BUS8_SET(c, (uint16_t)(dp + 0x59), 0xFF);
    }
    uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 0x46));
    BUS8_SET(c, 0x00211B, value7);
    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp + 0x47));
    BUS8_SET(c, 0x00211B, value8);
    uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp + 0x4F));
    BUS8_SET(c, 0x00211C, value9);
    uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp + 0xC5));
    uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp + 0x56));
    BUS8_SET(c, (uint16_t)(dp + 0x56), (uint8_t)(value10 + value11));
    uint8_t value12 = BUS8(c, 0x002134);
    uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp + 0x57));
    BUS8_SET(c, (uint16_t)(dp + 0x57), (uint8_t)(value12 + value13 + (value10 + value11 > 0xFF)));
    uint8_t value14 = BUS8(c, 0x002135);
    uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 0x58));
    BUS8_SET(c, (uint16_t)(dp + 0x58), (uint8_t)(value14 + value15 + (value12 + value13 + (value10 + value11 > 0xFF) > 0xFF)));
    uint8_t value16 = BUS8(c, 0x002136);
    uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
    BUS8_SET(c, (uint16_t)(dp + 0x59), (uint8_t)(value16 + value17 + (value14 + value15 + (value12 + value13 + (value10 + value11 > 0xFF) > 0xFF) > 0xFF)));
    r->a = (a_hi << 8) | (uint8_t)(value16 + value17 + (value14 + value15 + (value12 + value13 + (value10 + value11 > 0xFF) > 0xFF) > 0xFF));
    r->c = value16 + value17 + (value14 + value15 + (value12 + value13 + (value10 + value11 > 0xFF) > 0xFF) > 0xFF) > 0xFF;
    r->z = (uint8_t)(value16 + value17 + (value14 + value15 + (value12 + value13 + (value10 + value11 > 0xFF) > 0xFF) > 0xFF)) == 0;
    r->n = (uint8_t)(value16 + value17 + (value14 + value15 + (value12 + value13 + (value10 + value11 > 0xFF) > 0xFF) > 0xFF)) & 0x80;
    r->v = ((value16 ^ (uint8_t)(value16 + value17 + (value14 + value15 + (value12 + value13 + (value10 + value11 > 0xFF) > 0xFF) > 0xFF))) & (value17 ^ (uint8_t)(value16 + value17 + (value14 + value15 + (value12 + value13 + (value10 + value11 > 0xFF) > 0xFF) > 0xFF))) & 0x80) != 0;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22C2F, SOM_RTS, "gen", combine_two_signed_mode7_partial_products, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 98, 38)
