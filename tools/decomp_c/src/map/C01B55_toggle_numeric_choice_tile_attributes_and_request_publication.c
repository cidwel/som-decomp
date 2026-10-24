#include "som_c.h"

/* C01B55 toggle_numeric_choice_tile_attributes_and_request_publication   [class B, 80 bytes, 37 instructions]
 * Source: src/rom/toggle_numeric_choice_tile_attributes_and_request_publication.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void toggle_numeric_choice_tile_attributes_and_request_publication(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x1B57, 0xC01BAA); GUARD_JSR(c, sp_call, 0x1B57); } /* external */
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0xA200);
    if (x_ret) {
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xA1D7 + value);
        BUS8_SET(c, (db_ret << 0x10) + 0xA173, value2);
        uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0xA1D8 + value);
        uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xA173);
        BUS8_SET(c, (db_ret << 0x10) + 0xA174, 0);
        uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0xA180);
        uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 0xA173);
        uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0xA173);
        uint8_t a_hi1 = (uint16_t)((uint16_t)((((value5 << 8) | 0) >> 1) + 0x44 + value6) + value7 + ((((value5 << 8) | 0) >> 1) + 0x44 + value6 > 0xFFFF)) >> 8;
        uint8_t x1 = (uint8_t)((uint16_t)((((value5 << 8) | 0) >> 1) + 0x44 + value6) + value7 + ((((value5 << 8) | 0) >> 1) + 0x44 + value6 > 0xFFFF));
        uint8_t y1 = (uint8_t)(value3 - value4);
        for (;;) {
            uint8_t value8 = BUS8_RDP(c, (db_ret << 0x10) + 0x9C01 + x1);
            BUS8_SET(c, (db_ret << 0x10) + 0x9C01 + x1, value8 ^ 8);
            uint8_t value9 = BUS8_RDP(c, (db_ret << 0x10) + 0x9C41 + x1);
            BUS8_SET(c, (db_ret << 0x10) + 0x9C41 + x1, value9 ^ 8);
            x1 = (uint8_t)(x1 + 2);
            y1 = (uint8_t)(y1 - 1);
            if (!(y1 != 0)) break;
        }
        uint8_t value10 = RAM8(0x1D04);
        RAM8(0x1D04) = value10 | 0x44;
        r->a = (a_hi1 << 8) | (value10 | 0x44);
        r->x = x1;
        r->y = y1;
        r->v = (((uint16_t)((((value5 << 8) | 0) >> 1) + 0x44 + value6) ^ (uint16_t)((uint16_t)((((value5 << 8) | 0) >> 1) + 0x44 + value6) + value7 + ((((value5 << 8) | 0) >> 1) + 0x44 + value6 > 0xFFFF))) & (value7 ^ (uint16_t)((uint16_t)((((value5 << 8) | 0) >> 1) + 0x44 + value6) + value7 + ((((value5 << 8) | 0) >> 1) + 0x44 + value6 > 0xFFFF))) & 0x8000) != 0;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint8_t value11 = BUS8_RDP(c, (db_ret << 0x10) + 0xA1D7 + value);
        BUS8_SET(c, (db_ret << 0x10) + 0xA173, value11);
        uint8_t value12 = BUS8_RDP(c, (db_ret << 0x10) + 0xA1D8 + value);
        uint8_t value13 = BUS8_RDP(c, (db_ret << 0x10) + 0xA173);
        BUS8_SET(c, (db_ret << 0x10) + 0xA174, 0);
        uint8_t value14 = BUS8_RDP(c, (db_ret << 0x10) + 0xA180);
        uint16_t value15 = BUS16_RDP(c, (db_ret << 0x10) + 0xA173);
        uint16_t value16 = BUS16_RDP(c, (db_ret << 0x10) + 0xA173);
        uint8_t a_hi2 = (uint16_t)((uint16_t)((((value14 << 8) | 0) >> 1) + 0x44 + value15) + value16 + ((((value14 << 8) | 0) >> 1) + 0x44 + value15 > 0xFFFF)) >> 8;
        uint16_t x2 = (uint16_t)((uint16_t)((((value14 << 8) | 0) >> 1) + 0x44 + value15) + value16 + ((((value14 << 8) | 0) >> 1) + 0x44 + value15 > 0xFFFF));
        uint16_t y2 = (uint8_t)(value12 - value13);
        for (;;) {
            uint8_t value17 = BUS8_RDP(c, (db_ret << 0x10) + 0x9C01 + x2);
            BUS8_SET(c, (db_ret << 0x10) + 0x9C01 + x2, value17 ^ 8);
            uint8_t value18 = BUS8_RDP(c, (db_ret << 0x10) + 0x9C41 + x2);
            BUS8_SET(c, (db_ret << 0x10) + 0x9C41 + x2, value18 ^ 8);
            x2 = (uint16_t)(x2 + 2);
            y2 = (uint16_t)(y2 - 1);
            if (!(y2 != 0)) break;
        }
        uint8_t value19 = RAM8(0x1D04);
        RAM8(0x1D04) = value19 | 0x44;
        r->a = (a_hi2 << 8) | (value19 | 0x44);
        r->x = x2;
        r->y = y2;
        r->v = (((uint16_t)((((value14 << 8) | 0) >> 1) + 0x44 + value15) ^ (uint16_t)((uint16_t)((((value14 << 8) | 0) >> 1) + 0x44 + value15) + value16 + ((((value14 << 8) | 0) >> 1) + 0x44 + value15 > 0xFFFF))) & (value16 ^ (uint16_t)((uint16_t)((((value14 << 8) | 0) >> 1) + 0x44 + value15) + value16 + ((((value14 << 8) | 0) >> 1) + 0x44 + value15 > 0xFFFF))) & 0x8000) != 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC01B55, SOM_RTS, "gen", toggle_numeric_choice_tile_attributes_and_request_publication, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 80, 37)
