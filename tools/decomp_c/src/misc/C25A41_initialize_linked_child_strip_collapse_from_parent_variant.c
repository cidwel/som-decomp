#include "som_c.h"

/* C25A41 initialize_linked_child_strip_collapse_from_parent_variant   [class B, 142 bytes, 60 instructions]
 * Source: src/rom/initialize_linked_child_strip_collapse_from_parent_variant.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_linked_child_strip_collapse_from_parent_variant(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0083 + x, (uint16_t)(RAM16(0x0083 + x) - 1));
    RAM16_SET(0x0090 + x, 0);
    RAM16_SET(0x0049 + x, 0);
    RAM16_SET(0x008E + x, 0x5A66);
    uint16_t value3 = RAM16(0x0042 + RAM16(0x00B0 + x));
    uint8_t a_hi1;
    if (value3 != 0) {
        RAM16_SET(0x0015 + x, 0x40);
        a_hi1 = 0;
    } else {
        RAM16_SET(0x0015 + x, 0xFFFF);
        a_hi1 = 0xFF;
    }
    RAM16_SET(0x0200, (uint16_t)(RAM16(0x0049 + x) + 0x1AA4));
    uint16_t value5 = RAM16(0x0289);
    uint8_t a_hi2 = (uint16_t)(value5 + 0x14) >> 8;
    uint16_t x1 = (uint16_t)(value5 + 0x14);
    uint16_t y1 = 6;
    bool carry1 = value5 + 0x14 > 0xFFFF;
    bool overflow1 = ((value5 ^ (uint16_t)(value5 + 0x14)) & ((uint16_t)(value5 + 0x14) ^ 0x14) & 0x8000) != 0;
    for (;;) {
        uint16_t value6 = RAM16(0x0200);
        uint8_t a1;
        uint8_t a_hi3;
        if ((value6 & 0x01FF) < 0xAA) {
            a1 = (uint8_t)value6;
            a_hi3 = value6 >> 8;
        } else {
            a1 = 0xAA;
            a_hi3 = 0x1A;
        }
        RAM16_SET(0x0003 + x1, (a_hi3 << 8) | a1);
        uint16_t value7 = RAM16(0x0200);
        RAM16_SET(0x0200, (uint16_t)(value7 - 2));
        uint8_t a_hi4;
        uint16_t y2;
        if (((uint16_t)(value7 - 2) & 0x01FF) < 0xA4) {
            a_hi4 = ((uint16_t)(value7 - 2) & 0x01FF) >> 8;
            y2 = y1;
        } else {
            if ((uint16_t)(y1 - 1) != 0) {
                a_hi2 = ((uint16_t)(value7 - 2) & 0x01FF) >> 8;
                x1 = (uint16_t)(x1 - 4);
                y1 = (uint16_t)(y1 - 1);
                carry1 = ((uint16_t)(value7 - 2) & 0x01FF) >= 0xA4;
                overflow1 = ((value7 ^ 2) & (value7 ^ (uint16_t)(value7 - 2)) & 0x8000) != 0;
                continue;
            }
            RAM16_SET(0x008E + RAM16(0x0287), 0x5ACF);
            a_hi4 = 0x5A;
            y2 = (uint16_t)(y1 - 1);
        }
        a_hi2 = a_hi4;
        y1 = y2;
        carry1 = ((uint16_t)(value7 - 2) & 0x01FF) >= 0xA4;
        overflow1 = ((value7 ^ 2) & (value7 ^ (uint16_t)(value7 - 2)) & 0x8000) != 0;
        break;
    }
    uint16_t value9 = RAM16(0x0287);
    RAM16_SET(0x0049 + value9, (uint16_t)(RAM16(0x0049 + value9) + 1));
    RAM16_SET(0x0049 + value9, (uint16_t)(RAM16(0x0049 + value9) + 1));
    r->a = 0x15;
    r->x = 0x0F;
    r->y = y1;
    r->c = carry1;
    r->z = 0;
    r->n = 0;
    r->v = overflow1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5ABC, 0xC230E3); GUARD_JSR(c, sp_call, 0x5ABC); } /* request_boss_sound_with_parameter_word */
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    if (x_ret) {
        uint8_t value10 = RAM8(0x0287);
        uint16_t value11 = RAM16(0x0081 + value10);
        uint8_t a2;
        uint8_t a_hi5;
        uint8_t x2;
        uint8_t y3;
        bool zero1;
        bool negative1;
        bool overflow2;
        if (value11 != 4) {
            a2 = (uint8_t)value11;
            a_hi5 = value11 >> 8;
            x2 = value10;
            y3 = (uint8_t)y_ret;
            zero1 = value11 == 4;
            negative1 = (uint16_t)(value11 - 4) & 0x8000;
            overflow2 = overflow_ret;
        } else {
            r->a = value11;
            r->x = value10;
            r->y = (uint8_t)y_ret;
            r->c = value11 >= 4;
            r->z = value11 == 4;
            r->n = (uint16_t)(value11 - 4) & 0x8000;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5AC9, 0xC25E9D); GUARD_JSR(c, sp_call, 0x5AC9); } /* consume_linked_child_request_and_select_native_definition */
            uint16_t a_all2 = r->a;
            uint8_t x_ret3 = r->x;
            uint8_t y_ret2 = r->y;
            bool zero_ret2 = r->z;
            bool negative_ret2 = r->n;
            bool overflow_ret2 = r->v;
            a2 = (uint8_t)a_all2;
            a_hi5 = a_all2 >> 8;
            x2 = x_ret3;
            y3 = y_ret2;
            zero1 = zero_ret2;
            negative1 = negative_ret2;
            overflow2 = overflow_ret2;
        }
        RAM16_SET(0x0081 + x2, 0);
        r->a = (a_hi5 << 8) | a2;
        r->x = x2;
        r->y = y3;
        r->c = 0;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow2;
        r->mf = 0;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint16_t value12 = RAM16(0x0287);
        uint16_t value13 = RAM16(0x0081 + value12);
        uint8_t a3;
        uint8_t a_hi6;
        uint16_t x3;
        uint16_t y4;
        bool zero2;
        bool negative2;
        bool overflow3;
        if (value13 != 4) {
            a3 = (uint8_t)value13;
            a_hi6 = value13 >> 8;
            x3 = value12;
            y4 = y_ret;
            zero2 = value13 == 4;
            negative2 = (uint16_t)(value13 - 4) & 0x8000;
            overflow3 = overflow_ret;
        } else {
            r->a = value13;
            r->x = value12;
            r->c = value13 >= 4;
            r->z = value13 == 4;
            r->n = (uint16_t)(value13 - 4) & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5AC9, 0xC25E9D); GUARD_JSR(c, sp_call, 0x5AC9); } /* consume_linked_child_request_and_select_native_definition */
            uint16_t a_all3 = r->a;
            uint16_t x_ret4 = r->x;
            uint16_t y_ret3 = r->y;
            bool zero_ret3 = r->z;
            bool negative_ret3 = r->n;
            bool overflow_ret3 = r->v;
            a3 = (uint8_t)a_all3;
            a_hi6 = a_all3 >> 8;
            x3 = x_ret4;
            y4 = y_ret3;
            zero2 = zero_ret3;
            negative2 = negative_ret3;
            overflow3 = overflow_ret3;
        }
        RAM16_SET(0x0081 + x3, 0);
        r->a = (a_hi6 << 8) | a3;
        r->x = x3;
        r->y = y4;
        r->c = 0;
        r->z = zero2;
        r->n = negative2;
        r->v = overflow3;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC25A41, SOM_RTS, "gen", initialize_linked_child_strip_collapse_from_parent_variant, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 142, 60)
