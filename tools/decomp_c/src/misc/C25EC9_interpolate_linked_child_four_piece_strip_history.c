#include "som_c.h"

/* C25EC9 interpolate_linked_child_four_piece_strip_history   [class B, 151 bytes, 80 instructions]
 * Source: src/rom/interpolate_linked_child_four_piece_strip_history.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void interpolate_linked_child_four_piece_strip_history(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x007A + value);
    RAM16_SET(0x0206, (uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1));
    uint16_t value3 = RAM16(0x00B6 + value);
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value3 - 1) & 0x8000)) {
        a1 = (uint8_t)(value3 - 1);
        a_hi1 = (uint16_t)(value3 - 1) >> 8;
    } else {
        a1 = 0x0F;
        a_hi1 = 0;
    }
    RAM16_SET(0x0208, (uint16_t)(((a_hi1 << 8) | a1) << 2));
    RAM16_SET(0x0200, RAM16(0x00B8 + value));
    uint16_t value5 = RAM16(0x00BA + value);
    RAM16_SET(0x0202, value5);
    RAM16_SET(0x020A, 0);
    uint8_t a_hi2 = value5 >> 8;
    uint16_t x1 = value;
    uint16_t y1 = y;
    bool carry1 = (uint16_t)(((a_hi1 << 8) | a1) << 1) & 0x8000;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value6 = RAM16(0x020A);
        uint8_t a_hi3;
        if ((uint16_t)(value6 + 1) != 4) {
            uint16_t value7 = RAM16(0x0206);
            uint16_t value8 = RAM16(0x0208);
            uint16_t value9 = RAM16(0xF500 + (uint16_t)((uint16_t)(((((uint8_t)(value6 + 1) << 8) | ((uint16_t)(value6 + 1) >> 8)) >> 2) + value7) + value8 + (((((uint8_t)(value6 + 1) << 8) | ((uint16_t)(value6 + 1) >> 8)) >> 2) + value7 > 0xFFFF)));
            uint16_t value10 = RAM16(0x0200);
            r->a = (uint16_t)(value9 + value10);
            r->x = x1;
            r->y = (uint16_t)((uint16_t)(((((uint8_t)(value6 + 1) << 8) | ((uint16_t)(value6 + 1) >> 8)) >> 2) + value7) + value8 + (((((uint8_t)(value6 + 1) << 8) | ((uint16_t)(value6 + 1) >> 8)) >> 2) + value7 > 0xFFFF));
            r->c = value9 + value10 > 0xFFFF;
            r->v = ((value9 ^ (uint16_t)(value9 + value10)) & (value10 ^ (uint16_t)(value9 + value10)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0x0200;
            JSR(c, 0x5F2C, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
            uint16_t a_all = r->a;
            RAM16_SET(0x0200, a_all);
            uint16_t value11 = RAM16(0xF502 + (uint16_t)((uint16_t)(((((uint8_t)(value6 + 1) << 8) | ((uint16_t)(value6 + 1) >> 8)) >> 2) + value7) + value8 + (((((uint8_t)(value6 + 1) << 8) | ((uint16_t)(value6 + 1) >> 8)) >> 2) + value7 > 0xFFFF)));
            uint16_t value12 = RAM16(0x0202);
            r->a = (uint16_t)(value11 + value12);
            r->c = value11 + value12 > 0xFFFF;
            r->v = ((value11 ^ (uint16_t)(value11 + value12)) & (value12 ^ (uint16_t)(value11 + value12)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x5F37, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
            uint16_t a_all2 = r->a;
            RAM16_SET(0x0202, a_all2);
            a_hi3 = a_all2 >> 8;
        } else {
            r->a = RAM16(0x0200);
            r->x = x1;
            r->y = y1;
            r->c = (uint16_t)(value6 + 1) >= 4;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0x0200;
            JSR(c, 0x5F0F, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
            uint16_t a_all3 = r->a;
            RAM16_SET(0x0200, a_all3);
            r->a = RAM16(0x0202);
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x5F16, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
            uint16_t a_all4 = r->a;
            RAM16_SET(0x0202, a_all4);
            a_hi3 = a_all4 >> 8;
        }
        uint16_t value15 = RAM16(0x020A);
        RAM16_SET(0x0204, (((uint8_t)value15 << 8) | (value15 >> 8)) >> 2);
        uint16_t value16 = RAM16(0x00B6 + x1);
        uint16_t value17 = RAM16(0x0204);
        uint16_t value18 = RAM16(0x0206);
        RAM16_SET(0xF500 + (uint16_t)((uint16_t)((uint16_t)(value16 << 2) + value17) + value18 + ((uint16_t)(value16 << 2) + value17 > 0xFFFF)), RAM16(0x0200));
        RAM16_SET(0xF502 + (uint16_t)((uint16_t)((uint16_t)(value16 << 2) + value17) + value18 + ((uint16_t)(value16 << 2) + value17 > 0xFFFF)), RAM16(0x0202));
        RAM16_SET(0x020A, (uint16_t)(RAM16(0x020A) + 1));
        uint16_t value21 = RAM16(0x020A);
        if (value21 != 4) {
            uint16_t value22 = RAM16(0x0206);
            uint16_t value23 = RAM16(0x0208);
            RAM16_SET(0x0200, RAM16(0xF500 + (uint16_t)((uint16_t)(((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22) + value23 + (((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22 > 0xFFFF))));
            uint16_t value25 = RAM16(0xF502 + (uint16_t)((uint16_t)(((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22) + value23 + (((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22 > 0xFFFF)));
            RAM16_SET(0x0202, value25);
            a_hi2 = value25 >> 8;
            y1 = (uint16_t)((uint16_t)(((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22) + value23 + (((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22 > 0xFFFF));
            carry1 = (uint16_t)(((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22) + value23 + (((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22 > 0xFFFF) > 0xFFFF;
            overflow1 = (((uint16_t)(((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22) ^ (uint16_t)((uint16_t)(((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22) + value23 + (((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22 > 0xFFFF))) & (value23 ^ (uint16_t)((uint16_t)(((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22) + value23 + (((((uint8_t)(value21 - 1) << 8) | ((uint16_t)(value21 - 1) >> 8)) >> 2) + value22 > 0xFFFF))) & 0x8000) != 0;
            continue;
        }
        a_hi2 = value21 >> 8;
        y1 = (uint16_t)((uint16_t)((uint16_t)(value16 << 2) + value17) + value18 + ((uint16_t)(value16 << 2) + value17 > 0xFFFF));
        carry1 = value21 >= 4;
        overflow1 = (((uint16_t)((uint16_t)(value16 << 2) + value17) ^ (uint16_t)((uint16_t)((uint16_t)(value16 << 2) + value17) + value18 + ((uint16_t)(value16 << 2) + value17 > 0xFFFF))) & (value18 ^ (uint16_t)((uint16_t)((uint16_t)(value16 << 2) + value17) + value18 + ((uint16_t)(value16 << 2) + value17 > 0xFFFF))) & 0x8000) != 0;
        break;
    }
    r->a = (a_hi2 << 8) | (uint8_t)a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25EC9, SOM_RTS, "gen", interpolate_linked_child_four_piece_strip_history, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 151, 80)
