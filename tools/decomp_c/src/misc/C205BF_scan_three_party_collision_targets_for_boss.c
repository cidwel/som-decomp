#include "som_c.h"

/* C205BF scan_three_party_collision_targets_for_boss   [class B, 49 bytes, 23 instructions]
 * Source: src/rom/scan_three_party_collision_targets_for_boss.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void scan_three_party_collision_targets_for_boss(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->x = RAM16(0x0287);
    JSR(c, 0x05C3, 0xC20779); /* prepare_boss_secondary_collision_box */
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    if (carry_ret) {
        uint16_t value2 = RAM16(0x0287);
        r->x = value2;
        r->c = 0;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0224, 0);
    uint8_t a1 = (uint8_t)a_all;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t y1 = y_ret;
    bool carry1 = carry_ret;
    bool overflow1 = overflow_ret;
    for (;;) {
        uint16_t value3 = RAM16(0x0224);
        r->a = (a_hi1 << 8) | a1;
        r->y = value3;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        JSR(c, 0x05CC, 0xC207C7); /* prepare_unmarked_active_party_collision_boxes */
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        if (carry_ret2) {
            RAM16_SET(0x0224, (uint16_t)(RAM16(0x0224) + 1));
            uint16_t value4 = RAM16(0x0224);
            if (value4 < 3) {
                a1 = (uint8_t)value4;
                a_hi1 = value4 >> 8;
                y1 = y_ret2;
                carry1 = value4 >= 3;
                overflow1 = overflow_ret2;
                continue;
            }
            a1 = (uint8_t)value4;
            a_hi1 = value4 >> 8;
            y1 = y_ret2;
            carry1 = value4 >= 3;
            overflow1 = overflow_ret2;
            break;
        }
        r->a = RAM16(0x0224);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x05D3, 0xC206C5); /* test_boss_target_height_with_inverted_flag_pair */
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        if (carry_ret3) {
            RAM16_SET(0x0224, (uint16_t)(RAM16(0x0224) + 1));
            uint16_t value6 = RAM16(0x0224);
            if (value6 < 3) {
                a1 = (uint8_t)value6;
                a_hi1 = value6 >> 8;
                y1 = y_ret3;
                carry1 = value6 >= 3;
                overflow1 = overflow_ret3;
                continue;
            }
            a1 = (uint8_t)value6;
            a_hi1 = value6 >> 8;
            y1 = y_ret3;
            carry1 = value6 >= 3;
            overflow1 = overflow_ret3;
            break;
        }
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x05D8, 0xC20690); /* test_second_collision_box_overlap */
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        if (carry_ret4) {
            RAM16_SET(0x0224, (uint16_t)(RAM16(0x0224) + 1));
            uint16_t value7 = RAM16(0x0224);
            if (value7 < 3) {
                a1 = (uint8_t)value7;
                a_hi1 = value7 >> 8;
                y1 = y_ret3;
                carry1 = value7 >= 3;
                overflow1 = overflow_ret4;
                continue;
            }
            a1 = (uint8_t)value7;
            a_hi1 = value7 >> 8;
            y1 = y_ret3;
            carry1 = value7 >= 3;
            overflow1 = overflow_ret4;
            break;
        }
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x05DD, 0xC205F8); /* test_first_collision_box_overlap */
        bool carry_ret5 = r->c;
        bool overflow_ret5 = r->v;
        if (!carry_ret5) {
            RAM16_SET(0x0224, (uint16_t)(RAM16(0x0224) + 1));
            uint16_t value8 = RAM16(0x0224);
            if (value8 < 3) {
                a1 = (uint8_t)value8;
                a_hi1 = value8 >> 8;
                y1 = y_ret3;
                carry1 = value8 >= 3;
                overflow1 = overflow_ret5;
                continue;
            }
            a1 = (uint8_t)value8;
            a_hi1 = value8 >> 8;
            y1 = y_ret3;
            carry1 = value8 >= 3;
            overflow1 = overflow_ret5;
            break;
        }
        uint16_t value9 = RAM16(0x0287);
        r->x = value9;
        r->z = value9 == 0;
        r->n = value9 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value10 = RAM16(0x0287);
    r->a = (a_hi1 << 8) | a1;
    r->x = value10;
    r->y = y1;
    r->c = 0;
    r->z = value10 == 0;
    r->n = value10 & 0x8000;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC205BF, SOM_RTS, "gen", scan_three_party_collision_targets_for_boss, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 49, 23)
