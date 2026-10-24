#include "som_c.h"

/* C0993C prepare_one_hundred_twenty_eight_ui_column_tiles   [class B, 73 bytes, 40 instructions]
 * Source: src/rom/prepare_one_hundred_twenty_eight_ui_column_tiles.s
 * Entry: M=any X=any DB=any D=any.  Callers read: BXYCV.
 */
static void prepare_one_hundred_twenty_eight_ui_column_tiles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x2F));
    if (value != 0) {
        if (value & 0x80) {
            r->x = value;
            r->y = (uint8_t)y;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        }
        uint8_t a1;
        uint8_t a_hi1;
        if (value != 1) {
            uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0xFA));
            a1 = (uint8_t)((value2 >> 3) - 0x40);
            a_hi1 = (uint16_t)((value2 >> 3) - 0x40) >> 8;
        } else {
            uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp + 0xFA));
            a1 = (uint8_t)((value3 >> 3) + 0x3F);
            a_hi1 = (value3 >> 3) + 0x3F >> 8;
        }
        BUS16_SET(c, dp, ((a_hi1 << 8) | a1) & 0x01FF);
        BUS16_SET(c, (uint16_t)(dp + 0x78), ((a_hi1 << 8) | a1) & 0x7F);
        BUS8_SET(c, (uint16_t)(dp + 2), 0x7F);
        uint8_t a_hi2 = 0;
        uint8_t x1 = 0;
        bool carry1 = 0;
        bool overflow1 = 0;
        for (;;) {
            uint8_t value4 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 2)) << 0x10) + BUS16_RDP(c, dp), BUS8_RDP(c, (uint16_t)(dp + 2)));
            BUS8_SET(c, (db << 0x10) + 0x0B80 + x1, value4);
            uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 1));
            BUS8_SET(c, (uint16_t)(dp + 1), (uint8_t)(value5 + 2));
            x1 = (uint8_t)(x1 + 1);
            carry1 = value5 + 2 > 0xFF;
            overflow1 = ((value5 ^ (uint8_t)(value5 + 2)) & ((uint8_t)(value5 + 2) ^ 2) & 0x80) != 0;
            if (!(!(x1 & 0x80))) break;
        }
        BUS8_SET(c, (uint16_t)(dp + 0x2F), 0xFF);
        r->a = (a_hi2 << 8) | (uint8_t)a;
        r->x = 0xFF;
        r->y = (uint8_t)y;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    r->x = value;
    r->y = (uint8_t)y;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0993C, SOM_RTS, "gen", prepare_one_hundred_twenty_eight_ui_column_tiles, 0, L_B | L_X | L_Y | L_C | L_V, 1, -1, -1, 73, 40)
