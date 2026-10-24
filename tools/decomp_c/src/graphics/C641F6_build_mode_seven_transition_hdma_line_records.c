#include "som_c.h"

/* C641F6 build_mode_seven_transition_hdma_line_records   [class B, 143 bytes, 64 instructions]
 * Source: src/rom/build_mode_seven_transition_hdma_line_records.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABYCV.
 */
static void build_mode_seven_transition_hdma_line_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x004A);
    uint16_t x1;
    uint16_t y1;
    if (value >= 0x80) {
        RAM8(0x0000 + 0x1000) = (uint8_t)(value - 0x7F - (value >= 0x80 ^ 1));
        RAM8(0x0000 + 0x1020) = (uint8_t)(value - 0x7F - (value >= 0x80 ^ 1));
        BUS8_SET(c, 0x1001, 0);
        BUS8_SET(c, 0x1002, 0x7F);
        BUS8_SET(c, 0x000003 + 0x1020, 0x7F);
        BUS8_SET(c, 0x1003, 0);
        uint8_t value2 = RAM8(0x0048);
        BUS8_SET(c, 0x000001 + 0x1020, value2);
        BUS8_SET(c, 0x000004 + 0x1020, value2);
        uint8_t value3 = RAM8(0x0049);
        BUS8_SET(c, 0x000002 + 0x1020, value3);
        BUS8_SET(c, 0x000005 + 0x1020, value3);
        x1 = 0x1002;
        y1 = 0x1023;
    } else {
        RAM8(0x0000 + 0x1000) = value;
        RAM8(0x0000 + 0x1020) = value;
        BUS8_SET(c, 0x1001, 0);
        BUS8_SET(c, 0x000001 + 0x1020, RAM8(0x0048));
        BUS8_SET(c, 0x000002 + 0x1020, RAM8(0x0049));
        x1 = 0x1000;
        y1 = 0x1020;
    }
    uint8_t value6 = RAM8(0x004A);
    bool carry1;
    bool overflow1;
    if ((uint8_t)(0xE0 - value6) >= 0x80) {
        BUS8_SET(c, (uint16_t)(x1 + 2), (uint8_t)((uint8_t)(0xE0 - value6) - 0x7F - ((uint8_t)(0xE0 - value6) >= 0x80 ^ 1)));
        BUS8_SET(c, 0x000003 + y1, (uint8_t)((uint8_t)(0xE0 - value6) - 0x7F - ((uint8_t)(0xE0 - value6) >= 0x80 ^ 1)));
        BUS8_SET(c, (uint16_t)(x1 + 3), 0);
        BUS8_SET(c, (uint16_t)(x1 + 4), 0x7F);
        BUS8_SET(c, 0x000006 + y1, 0x7F);
        BUS8_SET(c, (uint16_t)(x1 + 5), 0);
        BUS8_SET(c, 0x000004 + y1, 0);
        BUS8_SET(c, 0x000005 + y1, 0);
        BUS8_SET(c, 0x000007 + y1, 0);
        BUS8_SET(c, 0x000008 + y1, 0);
        BUS8_SET(c, (uint16_t)(x1 + 6), 0);
        BUS8_SET(c, 0x000009 + y1, 0);
        carry1 = (uint8_t)(0xE0 - value6) - 0x7F >= ((uint8_t)(0xE0 - value6) >= 0x80 ^ 1);
        overflow1 = (((uint8_t)(0xE0 - value6) ^ 0x7F) & ((uint8_t)(0xE0 - value6) ^ (uint8_t)((uint8_t)(0xE0 - value6) - 0x7F - ((uint8_t)(0xE0 - value6) >= 0x80 ^ 1))) & 0x80) != 0;
    } else {
        BUS8_SET(c, (uint16_t)(x1 + 2), (uint8_t)(0xE0 - value6));
        BUS8_SET(c, 0x000003 + y1, (uint8_t)(0xE0 - value6));
        BUS8_SET(c, (uint16_t)(x1 + 3), 0);
        BUS8_SET(c, 0x000004 + y1, 0);
        BUS8_SET(c, 0x000005 + y1, 0);
        BUS8_SET(c, (uint16_t)(x1 + 4), 0);
        BUS8_SET(c, 0x000006 + y1, 0);
        carry1 = (uint8_t)(0xE0 - value6) >= 0x80;
        overflow1 = ((value6 ^ 0xE0) & ((uint8_t)(0xE0 - value6) ^ 0xE0) & 0x80) != 0;
    }
    SET_A8(r, 0);
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC641F6, SOM_RTS, "gen", build_mode_seven_transition_hdma_line_records, 0, L_A | L_B | L_Y | L_C | L_V, 1, 1, 0, 143, 64)
