#include "som_c.h"

/* C2CB6F build_event_radial_curve_lookup   [class B, 128 bytes, 63 instructions]
 * Source: src/rom/build_event_radial_curve_lookup.s
 * Documented in docs/event-menu-effect-preparation.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void build_event_radial_curve_lookup(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a >> 8;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint16_t value = BUS16(c, 0x00FD22 + y1);
            RAM16_SET(0x0008, value);
            uint16_t value2 = BUS16(c, 0x00FD22 + (uint16_t)((y1 ^ 0x01FE) + 2));
            RAM16_SET(0x000A, value2);
            BUS8_SET(c, 0x004202, 0xFF);
            uint8_t value3 = RAM8(0x0009);
            uint8_t a1;
            if (value3 == 0) {
                BUS8_SET(c, 0x004203, RAM8(0x0008));
                uint8_t value5 = BUS8(c, 0x004217);
                a1 = value5;
            } else {
                a1 = 0xFF;
            }
            RAM8(0x0008) = a1;
            uint8_t value6 = RAM8(0x000B);
            uint8_t a2;
            if (value6 == 0) {
                BUS8_SET(c, 0x004203, RAM8(0x000A));
                uint8_t value8 = BUS8(c, 0x004217);
                a2 = value8;
            } else {
                a2 = 0xFF;
            }
            RAM8(0x000A) = a2;
            RAM8(0xF700 + RAM8(0x0008)) = RAM8(0x000A);
            if ((uint16_t)(y1 + 2) < 0x0200) {
                uint8_t a_hi1_next = 0;
                uint16_t y1_next = (uint16_t)(y1 + 2);
                bool carry1_next = (uint16_t)(y1 + 2) >= 0x0200;
                a_hi1 = a_hi1_next;
                y1 = y1_next;
                carry1 = carry1_next;
                first_pass = false;
                continue;
            }
            uint8_t a_hi1_next2 = 0;
            uint16_t y1_next2 = (uint16_t)(y1 + 2);
            bool carry1_next2 = (uint16_t)(y1 + 2) >= 0x0200;
            a_hi1 = a_hi1_next2;
            y1 = y1_next2;
            carry1 = carry1_next2;
            break;
        } else {
            uint16_t value11 = BUS16(c, 0x00FD22 + y1);
            RAM16_SET(0x0008, value11);
            uint16_t value12 = BUS16(c, 0x00FD22 + (uint16_t)((y1 ^ 0x01FE) + 2));
            RAM16_SET(0x000A, value12);
            BUS8_SET(c, 0x004202, 0xFF);
            uint8_t value13 = RAM8(0x0009);
            uint8_t a3;
            if (value13 == 0) {
                BUS8_SET(c, 0x004203, RAM8(0x0008));
                uint8_t value15 = BUS8(c, 0x004217);
                a3 = value15;
            } else {
                a3 = 0xFF;
            }
            RAM8(0x0008) = a3;
            uint8_t value16 = RAM8(0x000B);
            uint8_t a4;
            if (value16 == 0) {
                BUS8_SET(c, 0x004203, RAM8(0x000A));
                uint8_t value18 = BUS8(c, 0x004217);
                a4 = value18;
            } else {
                a4 = 0xFF;
            }
            RAM8(0x000A) = a4;
            RAM8(0xF700 + RAM8(0x0008)) = RAM8(0x000A);
            if ((uint16_t)(y1 + 2) < 0x0200) {
                uint8_t a_hi1_next3 = 0;
                uint16_t y1_next3 = (uint16_t)(y1 + 2);
                bool carry1_next3 = (uint16_t)(y1 + 2) >= 0x0200;
                a_hi1 = a_hi1_next3;
                y1 = y1_next3;
                carry1 = carry1_next3;
                continue;
            }
            uint8_t a_hi1_next4 = 0;
            uint16_t y1_next4 = (uint16_t)(y1 + 2);
            bool carry1_next4 = (uint16_t)(y1 + 2) >= 0x0200;
            a_hi1 = a_hi1_next4;
            y1 = y1_next4;
            carry1 = carry1_next4;
            break;
        }
    }
    RAM8(0x0008) = 0xFF;
    uint8_t a5 = 0xFF;
    uint8_t a_hi2 = a_hi1;
    uint16_t x1 = 0;
    uint16_t y2 = 0xD0;
    bool zero1 = 0;
    bool negative1 = 1;
    for (;;) {
        uint8_t value21 = RAM8(0xF700 + x1);
        uint8_t a6;
        if (value21 != 0) {
            a6 = value21;
        } else {
            uint8_t value22 = RAM8(0x0008);
            RAM8(0xF700 + x1) = value22;
            a6 = value22;
        }
        RAM8(0x0008) = a6;
        uint8_t a5_next = a6;
        uint16_t x1_next = (uint16_t)(x1 + 1);
        uint16_t y2_next = (uint16_t)(y2 - 1);
        bool zero1_next = (uint16_t)(y2 - 1) == 0;
        bool negative1_next = (uint16_t)(y2 - 1) & 0x8000;
        a5 = a5_next;
        x1 = x1_next;
        y2 = y2_next;
        zero1 = zero1_next;
        negative1 = negative1_next;
        if (!(y2 != 0)) break;
    }
    r->a = (a_hi2 << 8) | a5;
    r->x = x1;
    r->y = y2;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2CB6F, SOM_RTS, "gen", build_event_radial_curve_lookup, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 128, 63)
