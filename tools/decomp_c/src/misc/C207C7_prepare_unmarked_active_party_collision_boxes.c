#include "som_c.h"

/* C207C7 prepare_unmarked_active_party_collision_boxes   [class B, 142 bytes, 74 instructions]
 * Source: src/rom/prepare_unmarked_active_party_collision_boxes.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYCV.
 */
static void prepare_unmarked_active_party_collision_boxes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0000 + (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000));
    if ((value & 0xFF) != 1) {
        r->a = value & 0xFF;
        r->y = (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000);
        r->c = 1;
        r->v = (((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint8_t value3 = BUS8(c, 0xC205F0 + RAM16(0x0224));
    uint8_t value5 = RAM8(0x005A + RAM16(0x0287));
    if ((value3 & value5) != 0) {
        r->a = value3 & value5;
        r->y = (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000);
        r->c = 1;
        r->v = (((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x025E, RAM16(0x0002 + (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000)));
    RAM16_SET(0x0260, RAM16(0x0004 + (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000)));
    uint16_t value8 = RAM16(0x0045 + (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000));
    RAM16_SET(0x0262, (uint16_t)(value8 << 1));
    RAM8(0x0000 + sp0) = (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000) >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000);
    uint8_t a_hi1 = (uint16_t)(value8 << 1) >> 8;
    uint16_t x1 = 0;
    uint16_t y1 = (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000);
    for (;;) {
        uint8_t value9 = RAM8(0x00C8 + y1);
        BUS8_SET(c, (uint16_t)(x1 + 0x0246), value9);
        if (!(value9 & 0x80)) {
            BUS8_SET(c, (uint16_t)(x1 + 0x0247), 0);
        } else {
            BUS8_SET(c, (uint16_t)(x1 + 0x0247), 0xFF);
        }
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 1);
        if (!(x1 != 8)) break;
    }
    uint8_t value10 = RAM8(0x0000 + sp0 - 1);
    uint8_t value11 = RAM8(0x0000 + sp0);
    uint8_t a_hi2 = a_hi1;
    uint16_t x2 = 0;
    uint16_t y2 = (value11 << 8) | value10;
    for (;;) {
        uint8_t value12 = RAM8(0x00CC + y2);
        BUS8_SET(c, (uint16_t)(x2 + 0x024E), value12);
        if (!(value12 & 0x80)) {
            BUS8_SET(c, (uint16_t)(x2 + 0x024F), 0);
        } else {
            BUS8_SET(c, (uint16_t)(x2 + 0x024F), 0xFF);
        }
        x2 = (uint16_t)(x2 + 2);
        y2 = (uint16_t)(y2 + 1);
        if (!(x2 != 8)) break;
    }
    uint16_t value13 = RAM16(0x025E);
    RAM16_SET(0x0246, (uint16_t)(value13 + RAM16(0x0246)));
    uint16_t value15 = RAM16(0x0260);
    RAM16_SET(0x0248, (uint16_t)(value15 + RAM16(0x0248)));
    RAM16_SET(0x024E, (uint16_t)(value13 + RAM16(0x024E)));
    uint16_t value18 = RAM16(0x0250);
    RAM16_SET(0x0250, (uint16_t)(value15 + value18));
    r->a = (uint16_t)(value15 + value18);
    r->y = y2;
    r->c = 0;
    r->v = ((value15 ^ (uint16_t)(value15 + value18)) & (value18 ^ (uint16_t)(value15 + value18)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC207C7, SOM_RTS, "gen", prepare_unmarked_active_party_collision_boxes, 0, L_B | L_Y | L_C | L_V, 2, 0, 0, 142, 74)
