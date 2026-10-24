#include "som_c.h"

/* CFFE70 detect_native_multi5_interfaces_from_serial_probes   [class D, 97 bytes, 51 instructions]
 * Source: src/rom/detect_native_multi5_interfaces_from_serial_probes.s
 * Entry: M=8 bit X=16 bit DB=$00 D=any.  Callers read: BXYCV.
 */
static void detect_native_multi5_interfaces_from_serial_probes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, (uint16_t)(dp + 1), 0);
    uint8_t a_hi1 = a_hi;
    for (;;) {
        uint8_t value = BUS8(c, 0x004212);
        if (!((value & 1) != 0)) break;
    }
    BUS8_SET(c, 0x004016, 0);
    BUS8_SET(c, 0x004016, 1);
    uint8_t a_hi2 = a_hi1;
    uint8_t x1 = 8;
    for (;;) {
        uint8_t value2 = BUS8(c, 0x004016);
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp + 0x12));
        BUS8_SET(c, (uint16_t)(dp + 0x12), (uint8_t)(value3 << 1 | ((value2 >> 1) & 1)));
        uint8_t value4 = BUS8(c, 0x004017);
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 0x14));
        BUS8_SET(c, (uint16_t)(dp + 0x14), (uint8_t)(value5 << 1 | ((value4 >> 1) & 1)));
        x1 = (uint8_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    BUS8_SET(c, 0x004016, 0);
    uint8_t a_hi3 = a_hi2;
    uint8_t x2 = 8;
    for (;;) {
        uint8_t value6 = BUS8(c, 0x004016);
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 0x11));
        BUS8_SET(c, (uint16_t)(dp + 0x11), (uint8_t)(value7 << 1 | ((value6 >> 1) & 1)));
        uint8_t value8 = BUS8(c, 0x004017);
        uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp + 0x13));
        BUS8_SET(c, (uint16_t)(dp + 0x13), (uint8_t)(value9 << 1 | ((value8 >> 1) & 1)));
        x2 = (uint8_t)(x2 - 1);
        if (!(x2 != 0)) break;
    }
    uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp + 0x12));
    if (value10 == 0xFF) {
        uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp + 0x11));
        if (value11 != 0xFF) {
            BUS8_SET(c, (uint16_t)(dp + 1), 0x80);
        }
    }
    uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp + 0x14));
    if (value12 == 0xFF) {
        uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp + 0x13));
        if (value13 != 0xFF) {
            uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp + 1));
            BUS8_SET(c, (uint16_t)(dp + 1), value14 | 0x40);
        }
    }
    r->a = (a_hi3 << 8) | a;
    r->x = x2;
    r->y = (uint8_t)y;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xCFFE70, SOM_RTS, "gen", detect_native_multi5_interfaces_from_serial_probes, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 97, 51)
