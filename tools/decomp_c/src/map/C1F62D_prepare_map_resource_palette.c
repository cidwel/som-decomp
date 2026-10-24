#include "som_c.h"

/* C1F62D prepare_map_resource_palette   [class B, 110 bytes, 53 instructions]
 * Source: src/rom/prepare_map_resource_palette.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void prepare_map_resource_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool overflow = r->v;
    BUS8_SET(c, 0x004202, RAM8(0x001B) & 0x7F);
    BUS8_SET(c, 0x004203, 0xD2);
    uint8_t x1 = 0;
    for (;;) {
        RAM16_SET(0x0600 + x1, 0);
        x1 = (uint8_t)(x1 + 2);
        if (!(x1 < 0x20)) break;
    }
    RAM16_SET(0x0000, 0x0F);
    uint16_t value2 = BUS16(c, 0x004216);
    uint8_t a_hi1 = 0;
    uint16_t x2 = value2;
    uint16_t y1 = 0x22;
    for (;;) {
        uint16_t value3 = BUS16(c, 0xCC8000 + x2);
        BUS16_SET(c, 0x000600 + y1, value3);
        RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) - 1));
        if (RAM16(0x0000) != 0) {
            a_hi1 = value3 >> 8;
            x2 = (uint16_t)(x2 + 2);
            y1 = (uint16_t)(y1 + 2);
            continue;
        }
        RAM16_SET(0x0000, 0x0F);
        a_hi1 = 0;
        x2 = (uint16_t)(x2 + 2);
        y1 = (uint16_t)(y1 + 4);
        if (!(y1 < 0x0100)) break;
    }
    uint16_t value4 = RAM16(0x00E8);
    if (!(value4 & 0x01)) {
        uint16_t value5 = RAM16(0x010E);
        if (value5 == 0) {
            r->a = value5;
            r->x = x2;
            r->y = y1;
            r->c = value4 & 0x01;
            r->v = overflow;
            r->mf = 0;
            RETURN_RTS(c);
        }
        uint8_t a1 = (uint8_t)value5;
        uint8_t a_hi2 = value5 >> 8;
        uint16_t x3 = 2;
        for (;;) {
            uint16_t value6 = BUS16(c, 0xD27E00 + x3);
            BUS16_SET(c, 0x000604 + x3, value6);
            a1 = (uint8_t)value6;
            a_hi2 = value6 >> 8;
            x3 = (uint16_t)(x3 - 2);
            if (!(!(x3 & 0x8000))) break;
        }
        r->a = (a_hi2 << 8) | a1;
        r->x = x3;
        r->y = y1;
        r->c = value4 & 0x01;
        r->v = overflow;
        r->mf = 0;
        RETURN_RTS(c);
    }
    uint8_t a2 = (uint8_t)(value4 >> 1);
    uint8_t a_hi3 = value4 >> 1 >> 8;
    uint16_t x4 = 0x1E;
    for (;;) {
        uint16_t value7 = BUS16(c, 0xC675B0 + x4);
        BUS16_SET(c, 0x000600 + x4, value7);
        a2 = (uint8_t)value7;
        a_hi3 = value7 >> 8;
        x4 = (uint16_t)(x4 - 2);
        if (!(x4 != 0)) break;
    }
    r->a = (a_hi3 << 8) | a2;
    r->x = x4;
    r->y = y1;
    r->c = value4 & 0x01;
    r->v = overflow;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F62D, SOM_RTS, "gen", prepare_map_resource_palette, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 110, 53)
