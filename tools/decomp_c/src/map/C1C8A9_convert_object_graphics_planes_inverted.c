#include "som_c.h"

/* C1C8A9 convert_object_graphics_planes_inverted   [class B, 328 bytes, 110 instructions]
 * Source: src/rom/convert_object_graphics_planes_inverted.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$D4 D=$0000.  Callers read: ABXYCV.
 */
static void convert_object_graphics_planes_inverted(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0xD4, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value = BUS8(c, 0xD40001 + y1);
        uint8_t value2 = BUS8(c, 0xD40002 + y1);
        RAM8(0x2011 + x1) = (value & value2) ^ 0xFF;
        uint8_t value3 = BUS8(c, 0xD40000 + y1);
        RAM8(0x2000 + x1) = ((value & value2) ^ 0xFF) & value3;
        uint8_t value4 = BUS8(c, 0xD40001 + y1);
        RAM8(0x2001 + x1) = value4 ^ 0xFF;
        uint8_t value5 = BUS8(c, 0xD40001 + y1);
        uint8_t value6 = BUS8(c, 0xD40002 + y1);
        RAM8(0x2010 + x1) = value5 ^ value6;
        uint8_t value7 = BUS8(c, 0xD40004 + y1);
        uint8_t value8 = BUS8(c, 0xD40005 + y1);
        RAM8(0x2013 + x1) = (value7 & value8) ^ 0xFF;
        uint8_t value9 = BUS8(c, 0xD40003 + y1);
        RAM8(0x2002 + x1) = ((value7 & value8) ^ 0xFF) & value9;
        uint8_t value10 = BUS8(c, 0xD40004 + y1);
        RAM8(0x2003 + x1) = value10 ^ 0xFF;
        uint8_t value11 = BUS8(c, 0xD40004 + y1);
        uint8_t value12 = BUS8(c, 0xD40005 + y1);
        RAM8(0x2012 + x1) = value11 ^ value12;
        uint8_t value13 = BUS8(c, 0xD40007 + y1);
        uint8_t value14 = BUS8(c, 0xD40008 + y1);
        RAM8(0x2015 + x1) = (value13 & value14) ^ 0xFF;
        uint8_t value15 = BUS8(c, 0xD40006 + y1);
        RAM8(0x2004 + x1) = ((value13 & value14) ^ 0xFF) & value15;
        uint8_t value16 = BUS8(c, 0xD40007 + y1);
        RAM8(0x2005 + x1) = value16 ^ 0xFF;
        uint8_t value17 = BUS8(c, 0xD40007 + y1);
        uint8_t value18 = BUS8(c, 0xD40008 + y1);
        RAM8(0x2014 + x1) = value17 ^ value18;
        uint8_t value19 = BUS8(c, 0xD4000A + y1);
        uint8_t value20 = BUS8(c, 0xD4000B + y1);
        RAM8(0x2017 + x1) = (value19 & value20) ^ 0xFF;
        uint8_t value21 = BUS8(c, 0xD40009 + y1);
        RAM8(0x2006 + x1) = ((value19 & value20) ^ 0xFF) & value21;
        uint8_t value22 = BUS8(c, 0xD4000A + y1);
        RAM8(0x2007 + x1) = value22 ^ 0xFF;
        uint8_t value23 = BUS8(c, 0xD4000A + y1);
        uint8_t value24 = BUS8(c, 0xD4000B + y1);
        RAM8(0x2016 + x1) = value23 ^ value24;
        uint8_t value25 = BUS8(c, 0xD4000D + y1);
        uint8_t value26 = BUS8(c, 0xD4000E + y1);
        RAM8(0x2019 + x1) = (value25 & value26) ^ 0xFF;
        uint8_t value27 = BUS8(c, 0xD4000C + y1);
        RAM8(0x2008 + x1) = ((value25 & value26) ^ 0xFF) & value27;
        uint8_t value28 = BUS8(c, 0xD4000D + y1);
        RAM8(0x2009 + x1) = value28 ^ 0xFF;
        uint8_t value29 = BUS8(c, 0xD4000D + y1);
        uint8_t value30 = BUS8(c, 0xD4000E + y1);
        RAM8(0x2018 + x1) = value29 ^ value30;
        uint8_t value31 = BUS8(c, 0xD40010 + y1);
        uint8_t value32 = BUS8(c, 0xD40011 + y1);
        RAM8(0x201B + x1) = (value31 & value32) ^ 0xFF;
        uint8_t value33 = BUS8(c, 0xD4000F + y1);
        RAM8(0x200A + x1) = ((value31 & value32) ^ 0xFF) & value33;
        uint8_t value34 = BUS8(c, 0xD40010 + y1);
        RAM8(0x200B + x1) = value34 ^ 0xFF;
        uint8_t value35 = BUS8(c, 0xD40010 + y1);
        uint8_t value36 = BUS8(c, 0xD40011 + y1);
        RAM8(0x201A + x1) = value35 ^ value36;
        uint8_t value37 = BUS8(c, 0xD40013 + y1);
        uint8_t value38 = BUS8(c, 0xD40014 + y1);
        RAM8(0x201D + x1) = (value37 & value38) ^ 0xFF;
        uint8_t value39 = BUS8(c, 0xD40012 + y1);
        RAM8(0x200C + x1) = ((value37 & value38) ^ 0xFF) & value39;
        uint8_t value40 = BUS8(c, 0xD40013 + y1);
        RAM8(0x200D + x1) = value40 ^ 0xFF;
        uint8_t value41 = BUS8(c, 0xD40013 + y1);
        uint8_t value42 = BUS8(c, 0xD40014 + y1);
        RAM8(0x201C + x1) = value41 ^ value42;
        uint8_t value43 = BUS8(c, 0xD40016 + y1);
        uint8_t value44 = BUS8(c, 0xD40017 + y1);
        RAM8(0x201F + x1) = (value43 & value44) ^ 0xFF;
        uint8_t value45 = BUS8(c, 0xD40015 + y1);
        RAM8(0x200E + x1) = ((value43 & value44) ^ 0xFF) & value45;
        uint8_t value46 = BUS8(c, 0xD40016 + y1);
        RAM8(0x200F + x1) = value46 ^ 0xFF;
        uint8_t value47 = BUS8(c, 0xD40016 + y1);
        uint8_t value48 = BUS8(c, 0xD40017 + y1);
        RAM8(0x201E + x1) = value47 ^ value48;
        RAM8(0x0008)--;
        if (RAM8(0x0008) != 0) {
            uint8_t a1_next = (uint8_t)(y1 + 0x18);
            uint8_t a_hi1_next = (uint16_t)(y1 + 0x18) >> 8;
            uint16_t x1_next = (uint16_t)(x1 + 0x20);
            uint16_t y1_next = (uint16_t)(y1 + 0x18);
            bool carry1_next = y1 + 0x18 > 0xFFFF;
            bool overflow1_next = ((y1 ^ (uint16_t)(y1 + 0x18)) & ((uint16_t)(y1 + 0x18) ^ 0x18) & 0x8000) != 0;
            a1 = a1_next;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            y1 = y1_next;
            carry1 = carry1_next;
            overflow1 = overflow1_next;
            continue;
        }
        uint8_t a1_next2 = (uint8_t)(y1 + 0x18);
        uint8_t a_hi1_next2 = (uint16_t)(y1 + 0x18) >> 8;
        uint16_t x1_next2 = (uint16_t)(x1 + 0x20);
        uint16_t y1_next2 = (uint16_t)(y1 + 0x18);
        bool carry1_next2 = y1 + 0x18 > 0xFFFF;
        bool overflow1_next2 = ((y1 ^ (uint16_t)(y1 + 0x18)) & ((uint16_t)(y1 + 0x18) ^ 0x18) & 0x8000) != 0;
        a1 = a1_next2;
        a_hi1 = a_hi1_next2;
        x1 = x1_next2;
        y1 = y1_next2;
        carry1 = carry1_next2;
        overflow1 = overflow1_next2;
        break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1C8A9, SOM_RTS, "gen", convert_object_graphics_planes_inverted, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 328, 110)
