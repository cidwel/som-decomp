#include "som_c.h"

/* C0DF85 test_map_object_inside_load_window   [class B, 79 bytes, 42 instructions]
 * Source: src/rom/test_map_object_inside_load_window.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void test_map_object_inside_load_window(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    if ((RAM8(0xC80C + y) & 8) != 0) {
        uint8_t value2 = RAM8(0xC80A + y);
        uint8_t value3 = RAM8(0x0006);
        uint8_t a1;
        bool overflow1;
        if ((value2 & 0x7F) >= value3) {
            a1 = (uint8_t)((value2 & 0x7F) - value3);
            overflow1 = (((value2 & 0x7F) ^ value3) & ((value2 & 0x7F) ^ (uint8_t)((value2 & 0x7F) - value3)) & 0x80) != 0;
        } else {
            uint8_t value4 = RAM8(0x009C);
            a1 = (uint8_t)((uint8_t)((value2 & 0x7F) - value3) + value4 + ((value2 & 0x7F) >= value3));
            overflow1 = (((uint8_t)((value2 & 0x7F) - value3) ^ (uint8_t)((uint8_t)((value2 & 0x7F) - value3) + value4 + ((value2 & 0x7F) >= value3))) & (value4 ^ (uint8_t)((uint8_t)((value2 & 0x7F) - value3) + value4 + ((value2 & 0x7F) >= value3))) & 0x80) != 0;
        }
        if (a1 >= RAM8(0x0008)) {
            SET_A8(r, a1);
            r->c = 0;
            r->v = overflow1;
            RETURN_RTS(c);
        }
        uint8_t value6 = RAM8(0xC80B + y);
        uint8_t value7 = RAM8(0x0007);
        uint8_t a2;
        bool overflow2;
        if ((value6 & 0x7F) >= value7) {
            a2 = (uint8_t)((value6 & 0x7F) - value7);
            overflow2 = (((value6 & 0x7F) ^ value7) & ((value6 & 0x7F) ^ (uint8_t)((value6 & 0x7F) - value7)) & 0x80) != 0;
        } else {
            uint8_t value8 = RAM8(0x009D);
            a2 = (uint8_t)((uint8_t)((value6 & 0x7F) - value7) + value8 + ((value6 & 0x7F) >= value7));
            overflow2 = (((uint8_t)((value6 & 0x7F) - value7) ^ (uint8_t)((uint8_t)((value6 & 0x7F) - value7) + value8 + ((value6 & 0x7F) >= value7))) & (value8 ^ (uint8_t)((uint8_t)((value6 & 0x7F) - value7) + value8 + ((value6 & 0x7F) >= value7))) & 0x80) != 0;
        }
        if (a2 >= RAM8(0x0009)) {
            SET_A8(r, a2);
            r->c = 0;
            r->v = overflow2;
            RETURN_RTS(c);
        }
        SET_A8(r, a2);
        r->c = 1;
        r->v = overflow2;
        RETURN_RTS(c);
    }
    uint8_t value10 = RAM8(0xC80A + y);
    uint8_t value11 = RAM8(0x0004);
    uint8_t a3;
    bool overflow3;
    if ((value10 & 0x7F) >= value11) {
        a3 = (uint8_t)((value10 & 0x7F) - value11);
        overflow3 = (((value10 & 0x7F) ^ value11) & ((value10 & 0x7F) ^ (uint8_t)((value10 & 0x7F) - value11)) & 0x80) != 0;
    } else {
        uint8_t value12 = RAM8(0x009C);
        a3 = (uint8_t)((uint8_t)((value10 & 0x7F) - value11) + value12 + ((value10 & 0x7F) >= value11));
        overflow3 = (((uint8_t)((value10 & 0x7F) - value11) ^ (uint8_t)((uint8_t)((value10 & 0x7F) - value11) + value12 + ((value10 & 0x7F) >= value11))) & (value12 ^ (uint8_t)((uint8_t)((value10 & 0x7F) - value11) + value12 + ((value10 & 0x7F) >= value11))) & 0x80) != 0;
    }
    if (a3 >= RAM8(0x0008)) {
        SET_A8(r, a3);
        r->c = 0;
        r->v = overflow3;
        RETURN_RTS(c);
    }
    uint8_t value14 = RAM8(0xC80B + y);
    uint8_t value15 = RAM8(0x0005);
    uint8_t a4;
    bool overflow4;
    if ((value14 & 0x7F) >= value15) {
        a4 = (uint8_t)((value14 & 0x7F) - value15);
        overflow4 = (((value14 & 0x7F) ^ value15) & ((value14 & 0x7F) ^ (uint8_t)((value14 & 0x7F) - value15)) & 0x80) != 0;
    } else {
        uint8_t value16 = RAM8(0x009D);
        a4 = (uint8_t)((uint8_t)((value14 & 0x7F) - value15) + value16 + ((value14 & 0x7F) >= value15));
        overflow4 = (((uint8_t)((value14 & 0x7F) - value15) ^ (uint8_t)((uint8_t)((value14 & 0x7F) - value15) + value16 + ((value14 & 0x7F) >= value15))) & (value16 ^ (uint8_t)((uint8_t)((value14 & 0x7F) - value15) + value16 + ((value14 & 0x7F) >= value15))) & 0x80) != 0;
    }
    if (a4 >= RAM8(0x0009)) {
        SET_A8(r, a4);
        r->c = 0;
        r->v = overflow4;
        RETURN_RTS(c);
    }
    SET_A8(r, a4);
    r->c = 1;
    r->v = overflow4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DF85, SOM_RTS, "gen", test_map_object_inside_load_window, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 79, 42)
