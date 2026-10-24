#include "som_c.h"

/* C22D2E divide_signed_bytes_with_signed_remainder   [class B, 59 bytes, 35 instructions]
 * Source: src/rom/divide_signed_bytes_with_signed_remainder.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void divide_signed_bytes_with_signed_remainder(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x46));
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp + 0x4E));
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp + 0x46));
    bool carry1;
    bool overflow1;
    if (!(value3 & 0x80)) {
        carry1 = carry;
        overflow1 = overflow;
    } else {
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp + 0xC5));
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 0x46));
        BUS8_SET(c, (uint16_t)(dp + 0x46), (uint8_t)(value4 - value5));
        carry1 = value4 >= value5;
        overflow1 = ((value4 ^ value5) & (value4 ^ (uint8_t)(value4 - value5)) & 0x80) != 0;
    }
    uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp + 0x4E));
    bool carry2;
    bool zero1;
    bool overflow2;
    if (!(value6 & 0x80)) {
        carry2 = carry1;
        zero1 = value6 == 0;
        overflow2 = overflow1;
    } else {
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 0xC5));
        uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp + 0x4E));
        BUS8_SET(c, (uint16_t)(dp + 0x4E), (uint8_t)(value7 - value8));
        carry2 = value7 >= value8;
        zero1 = (uint8_t)(value7 - value8) == 0;
        overflow2 = ((value7 ^ value8) & (value7 ^ (uint8_t)(value7 - value8)) & 0x80) != 0;
    }
    r->c = carry2;
    r->z = zero1;
    r->v = overflow2;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2D4C, 0xC22C91); GUARD_JSR(c, sp_call, 0x2D4C); } /* divide_unsigned_byte_through_cpu_ports */
    r->sp += 2;
    bool zero_ret = r->z;
    if (!zero_ret) {
        SET_A8(r, 0xFF);
        r->z = 0;
        r->n = 1;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    bool carry3;
    bool overflow3;
    if (!((value ^ value2) & 0x80)) {
        carry3 = carry2;
        overflow3 = overflow2;
    } else {
        uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp + 0xC5));
        uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp + 0x56));
        BUS8_SET(c, (uint16_t)(dp + 0x56), (uint8_t)(value9 - value10));
        carry3 = value9 >= value10;
        overflow3 = ((value9 ^ value10) & (value9 ^ (uint8_t)(value9 - value10)) & 0x80) != 0;
    }
    uint8_t a1;
    bool carry4;
    bool zero2;
    bool negative1;
    bool overflow4;
    if (!(value & 0x80)) {
        a1 = value;
        carry4 = carry3;
        zero2 = value == 0;
        negative1 = value & 0x80;
        overflow4 = overflow3;
    } else {
        uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp + 0xC5));
        uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp + 0x5E));
        BUS8_SET(c, (uint16_t)(dp + 0x5E), (uint8_t)(value11 - value12));
        a1 = (uint8_t)(value11 - value12);
        carry4 = value11 >= value12;
        zero2 = (uint8_t)(value11 - value12) == 0;
        negative1 = (uint8_t)(value11 - value12) & 0x80;
        overflow4 = ((value11 ^ value12) & (value11 ^ (uint8_t)(value11 - value12)) & 0x80) != 0;
    }
    SET_A8(r, a1);
    r->c = carry4;
    r->z = zero2;
    r->n = negative1;
    r->v = overflow4;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22D2E, SOM_RTS, "gen", divide_signed_bytes_with_signed_remainder, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 59, 35)
