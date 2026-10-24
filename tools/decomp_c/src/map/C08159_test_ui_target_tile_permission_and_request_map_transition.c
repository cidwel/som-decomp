#include "som_c.h"

/* C08159 test_ui_target_tile_permission_and_request_map_transition   [class C, 245 bytes, 133 instructions]
 * Source: src/rom/test_ui_target_tile_permission_and_request_map_transition.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCV.
 */
static void test_ui_target_tile_permission_and_request_map_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
    BUS8_SET(c, dp, value & 0x0C);
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
    uint8_t value3 = BUS8_RDP(c, dp);
    BUS8_SET(c, dp, (uint8_t)((((value2 >> 2) & 3) | value3) << 3));
    uint8_t value4 = BUS8_RDP(c, dp);
    BUS16_SET(c, dp, (((uint8_t)((a_hi << 1) | ((uint8_t)((((value2 >> 2) & 3) | value3) << 4) + value4 > 0xFF)) & 1) << 8) | (uint8_t)((uint8_t)((((value2 >> 2) & 3) | value3) << 4) + value4));
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 0xFA));
    BUS16_SET(c, (uint16_t)(dp + 2), (value5 >> 3) & 0x01FF);
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 0xFC));
    uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp + 2));
    uint16_t value8 = BUS16(c, 0x7F0000 + ((((value6 >> 2) & 0xFE) << 8) | 0 | value7));
    if ((value8 & 0xFF) < 0xA0) {
        BUS16_SET(c, (uint16_t)(dp + 2), value8 & 0xFF);
        uint16_t value9 = BUS16_RDP(c, dp);
        uint8_t value10 = BUS8(c, 0xC67600 + (uint16_t)(((value8 & 0xFF) >> 3) + value9));
        BUS8_SET(c, dp, value10);
        uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp + 2));
        uint8_t value12 = BUS8_RDP(c, dp);
        uint8_t a2;
        uint8_t a_hi2;
        uint8_t x2;
        bool carry2;
        if ((uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value9) >> 8 << 8 | (value11 & 7)) == 0) {
            a2 = value12;
            a_hi2 = (uint16_t)(((value8 & 0xFF) >> 3) + value9) >> 8;
            x2 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value9) >> 8 << 8 | (value11 & 7));
            carry2 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value9) >> 8 << 8 | (value11 & 7)) >= 0;
        } else {
            uint8_t a1 = value12;
            uint8_t a_hi1 = (uint16_t)(((value8 & 0xFF) >> 3) + value9) >> 8;
            uint8_t x1 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value9) >> 8 << 8 | (value11 & 7));
            bool carry1 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value9) >> 8 << 8 | (value11 & 7)) >= 0;
            for (;;) {
                uint8_t a1_next = a1 >> 1;
                uint8_t x1_next = (uint8_t)(x1 - 1);
                bool carry1_next = a1 & 0x01;
                a1 = a1_next;
                x1 = x1_next;
                carry1 = carry1_next;
                if (!(x1 != 0)) break;
            }
            a2 = a1;
            a_hi2 = a_hi1;
            x2 = x1;
            carry2 = carry1;
        }
        if ((a2 & 1) == 0) {
            uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
            if ((value13 & 3) == 0) {
                uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
                if (!(value14 & 0x80)) {
                    BUS8_SET(c, (uint16_t)(dp + 0xF2), value14 | 1);
                }
                BUS8_SET(c, (uint16_t)(dp + 0xFE), 0x80);
                BUS8_SET(c, (uint16_t)(dp + 0xE8), 1);
                uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
                BUS8_SET(c, dp, value15 & 0x0C);
                uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
                uint8_t value17 = BUS8_RDP(c, dp);
                BUS8_SET(c, dp, (uint8_t)((((value16 & 0x0C) >> 2) | value17) << 4));
                BUS8_SET(c, (uint16_t)(dp + 1), 0);
                uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
                BUS8_SET(c, (uint16_t)(dp + 2), (value18 & 3) << 1 << 1);
                uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
                uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp + 2));
                uint16_t value21 = BUS16_RDP(c, dp);
                BUS16_SET(c, dp, (uint16_t)((((a_hi2 << 8) | ((value19 & 3) | value20)) & 0xFF) + value21));
                uint16_t value22 = BUS16_RDP(c, dp);
                uint16_t value23 = BUS16_RDP(c, dp);
                uint16_t value24 = BUS16(c, 0xC67780 + (uint16_t)((uint16_t)(value22 << 1) + value23 + (value22 >> 0x0F)));
                BUS16_SET(c, (uint16_t)(dp + 0xDC), value24 & 0x01FF);
                BUS16_SET(c, (db << 0x10) + 0x010E, (value24 & 0x01FF) | 0x8000);
                uint8_t value25 = BUS8(c, 0xC67781 + (uint16_t)((uint16_t)(value22 << 1) + value23 + (value22 >> 0x0F)));
                BUS8_SET(c, (uint16_t)(dp + 0xDE), value25 >> 1);
                uint8_t value26 = BUS8(c, 0xC67782 + (uint16_t)((uint16_t)(value22 << 1) + value23 + (value22 >> 0x0F)));
                BUS8_SET(c, (uint16_t)(dp + 0xDF), value26);
                BUS8_SET(c, (uint16_t)(dp + 0xE0), 0xE0);
                r->a = (((value24 & 0x01FF) | 0x8000) >> 8 << 8) | 0xE0;
                r->x = (uint16_t)((uint16_t)(value22 << 1) + value23 + (value22 >> 0x0F));
                r->y = (uint8_t)y;
                r->c = value25 & 0x01;
                r->v = (((uint16_t)(value22 << 1) ^ (uint16_t)((uint16_t)(value22 << 1) + value23 + (value22 >> 0x0F))) & (value23 ^ (uint16_t)((uint16_t)(value22 << 1) + value23 + (value22 >> 0x0F))) & 0x8000) != 0;
                RETURN_RTS(c);
            }
            uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
            BUS8_SET(c, (uint16_t)(dp + 0xCC), value27 | 0x10);
            r->a = (a_hi2 << 8) | 0x10;
            r->x = x2;
            r->y = (uint8_t)y;
            r->c = carry2;
            r->v = value13 & 0x40;
            r->xf = 1;
            RETURN_RTS(c);
        }
        r->a = a_hi2 << 8 | (a2 & 1);
        r->x = x2;
        r->y = (uint8_t)y;
        r->c = carry2;
        r->v = ((((value8 & 0xFF) >> 3) ^ (uint16_t)(((value8 & 0xFF) >> 3) + value9)) & (value9 ^ (uint16_t)(((value8 & 0xFF) >> 3) + value9)) & 0x8000) != 0;
        r->xf = 1;
        RETURN_RTS(c);
    }
    if ((value8 & 0xFF) != 0xAF) {
        if ((value8 & 0xFF) >= 0xAF) {
            BUS16_SET(c, (uint16_t)(dp + 2), value8 & 0xFF);
            uint16_t value28 = BUS16_RDP(c, dp);
            uint8_t value29 = BUS8(c, 0xC67600 + (uint16_t)(((value8 & 0xFF) >> 3) + value28));
            BUS8_SET(c, dp, value29);
            uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp + 2));
            uint8_t value31 = BUS8_RDP(c, dp);
            uint8_t a4;
            uint8_t a_hi4;
            uint8_t x4;
            bool carry4;
            if ((uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value28) >> 8 << 8 | (value30 & 7)) == 0) {
                a4 = value31;
                a_hi4 = (uint16_t)(((value8 & 0xFF) >> 3) + value28) >> 8;
                x4 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value28) >> 8 << 8 | (value30 & 7));
                carry4 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value28) >> 8 << 8 | (value30 & 7)) >= 0;
            } else {
                uint8_t a3 = value31;
                uint8_t a_hi3 = (uint16_t)(((value8 & 0xFF) >> 3) + value28) >> 8;
                uint8_t x3 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value28) >> 8 << 8 | (value30 & 7));
                bool carry3 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value28) >> 8 << 8 | (value30 & 7)) >= 0;
                for (;;) {
                    uint8_t a3_next = a3 >> 1;
                    uint8_t x3_next = (uint8_t)(x3 - 1);
                    bool carry3_next = a3 & 0x01;
                    a3 = a3_next;
                    x3 = x3_next;
                    carry3 = carry3_next;
                    if (!(x3 != 0)) break;
                }
                a4 = a3;
                a_hi4 = a_hi3;
                x4 = x3;
                carry4 = carry3;
            }
            if ((a4 & 1) == 0) {
                uint8_t value32 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
                if ((value32 & 3) == 0) {
                    uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
                    if (!(value33 & 0x80)) {
                        BUS8_SET(c, (uint16_t)(dp + 0xF2), value33 | 1);
                    }
                    BUS8_SET(c, (uint16_t)(dp + 0xFE), 0x80);
                    BUS8_SET(c, (uint16_t)(dp + 0xE8), 1);
                    uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
                    BUS8_SET(c, dp, value34 & 0x0C);
                    uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
                    uint8_t value36 = BUS8_RDP(c, dp);
                    BUS8_SET(c, dp, (uint8_t)((((value35 & 0x0C) >> 2) | value36) << 4));
                    BUS8_SET(c, (uint16_t)(dp + 1), 0);
                    uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
                    BUS8_SET(c, (uint16_t)(dp + 2), (value37 & 3) << 1 << 1);
                    uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
                    uint8_t value39 = BUS8_RDP(c, (uint16_t)(dp + 2));
                    uint16_t value40 = BUS16_RDP(c, dp);
                    BUS16_SET(c, dp, (uint16_t)((((a_hi4 << 8) | ((value38 & 3) | value39)) & 0xFF) + value40));
                    uint16_t value41 = BUS16_RDP(c, dp);
                    uint16_t value42 = BUS16_RDP(c, dp);
                    uint16_t value43 = BUS16(c, 0xC67780 + (uint16_t)((uint16_t)(value41 << 1) + value42 + (value41 >> 0x0F)));
                    BUS16_SET(c, (uint16_t)(dp + 0xDC), value43 & 0x01FF);
                    BUS16_SET(c, (db << 0x10) + 0x010E, (value43 & 0x01FF) | 0x8000);
                    uint8_t value44 = BUS8(c, 0xC67781 + (uint16_t)((uint16_t)(value41 << 1) + value42 + (value41 >> 0x0F)));
                    BUS8_SET(c, (uint16_t)(dp + 0xDE), value44 >> 1);
                    uint8_t value45 = BUS8(c, 0xC67782 + (uint16_t)((uint16_t)(value41 << 1) + value42 + (value41 >> 0x0F)));
                    BUS8_SET(c, (uint16_t)(dp + 0xDF), value45);
                    BUS8_SET(c, (uint16_t)(dp + 0xE0), 0xE0);
                    r->a = (((value43 & 0x01FF) | 0x8000) >> 8 << 8) | 0xE0;
                    r->x = (uint16_t)((uint16_t)(value41 << 1) + value42 + (value41 >> 0x0F));
                    r->y = (uint8_t)y;
                    r->c = value44 & 0x01;
                    r->v = (((uint16_t)(value41 << 1) ^ (uint16_t)((uint16_t)(value41 << 1) + value42 + (value41 >> 0x0F))) & (value42 ^ (uint16_t)((uint16_t)(value41 << 1) + value42 + (value41 >> 0x0F))) & 0x8000) != 0;
                    RETURN_RTS(c);
                }
                uint8_t value46 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
                BUS8_SET(c, (uint16_t)(dp + 0xCC), value46 | 0x10);
                r->a = (a_hi4 << 8) | 0x10;
                r->x = x4;
                r->y = (uint8_t)y;
                r->c = carry4;
                r->v = value32 & 0x40;
                r->xf = 1;
                RETURN_RTS(c);
            }
            r->a = a_hi4 << 8 | (a4 & 1);
            r->x = x4;
            r->y = (uint8_t)y;
            r->c = carry4;
            r->v = ((((value8 & 0xFF) >> 3) ^ (uint16_t)(((value8 & 0xFF) >> 3) + value28)) & (value28 ^ (uint16_t)(((value8 & 0xFF) >> 3) + value28)) & 0x8000) != 0;
            r->xf = 1;
            RETURN_RTS(c);
        }
        uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp + 0xE2));
        if (!(value47 & 0x8000)) {
            r->a = value8 & 0xFF;
            r->x = (((value6 >> 2) & 0xFE) << 8) | 0 | value7;
            r->y = (uint8_t)y;
            r->c = (value8 & 0xFF) >= 0xAF;
            r->v = value47 & 0x4000;
            r->mf = 0;
            RETURN_RTS(c);
        }
        BUS16_SET(c, (uint16_t)(dp + 2), value8 & 0xFF);
        uint16_t value48 = BUS16_RDP(c, dp);
        uint8_t value49 = BUS8(c, 0xC67600 + (uint16_t)(((value8 & 0xFF) >> 3) + value48));
        BUS8_SET(c, dp, value49);
        uint8_t value50 = BUS8_RDP(c, (uint16_t)(dp + 2));
        uint8_t value51 = BUS8_RDP(c, dp);
        uint8_t a6;
        uint8_t a_hi6;
        uint8_t x6;
        bool carry6;
        if ((uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value48) >> 8 << 8 | (value50 & 7)) == 0) {
            a6 = value51;
            a_hi6 = (uint16_t)(((value8 & 0xFF) >> 3) + value48) >> 8;
            x6 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value48) >> 8 << 8 | (value50 & 7));
            carry6 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value48) >> 8 << 8 | (value50 & 7)) >= 0;
        } else {
            uint8_t a5 = value51;
            uint8_t a_hi5 = (uint16_t)(((value8 & 0xFF) >> 3) + value48) >> 8;
            uint8_t x5 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value48) >> 8 << 8 | (value50 & 7));
            bool carry5 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value48) >> 8 << 8 | (value50 & 7)) >= 0;
            for (;;) {
                uint8_t a5_next = a5 >> 1;
                uint8_t x5_next = (uint8_t)(x5 - 1);
                bool carry5_next = a5 & 0x01;
                a5 = a5_next;
                x5 = x5_next;
                carry5 = carry5_next;
                if (!(x5 != 0)) break;
            }
            a6 = a5;
            a_hi6 = a_hi5;
            x6 = x5;
            carry6 = carry5;
        }
        if ((a6 & 1) == 0) {
            uint8_t value52 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
            if ((value52 & 3) == 0) {
                uint8_t value53 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
                if (!(value53 & 0x80)) {
                    BUS8_SET(c, (uint16_t)(dp + 0xF2), value53 | 1);
                }
                BUS8_SET(c, (uint16_t)(dp + 0xFE), 0x80);
                BUS8_SET(c, (uint16_t)(dp + 0xE8), 1);
                uint8_t value54 = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
                BUS8_SET(c, dp, value54 & 0x0C);
                uint8_t value55 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
                uint8_t value56 = BUS8_RDP(c, dp);
                BUS8_SET(c, dp, (uint8_t)((((value55 & 0x0C) >> 2) | value56) << 4));
                BUS8_SET(c, (uint16_t)(dp + 1), 0);
                uint8_t value57 = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
                BUS8_SET(c, (uint16_t)(dp + 2), (value57 & 3) << 1 << 1);
                uint8_t value58 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
                uint8_t value59 = BUS8_RDP(c, (uint16_t)(dp + 2));
                uint16_t value60 = BUS16_RDP(c, dp);
                BUS16_SET(c, dp, (uint16_t)((((a_hi6 << 8) | ((value58 & 3) | value59)) & 0xFF) + value60));
                uint16_t value61 = BUS16_RDP(c, dp);
                uint16_t value62 = BUS16_RDP(c, dp);
                uint16_t value63 = BUS16(c, 0xC67780 + (uint16_t)((uint16_t)(value61 << 1) + value62 + (value61 >> 0x0F)));
                BUS16_SET(c, (uint16_t)(dp + 0xDC), value63 & 0x01FF);
                BUS16_SET(c, (db << 0x10) + 0x010E, (value63 & 0x01FF) | 0x8000);
                uint8_t value64 = BUS8(c, 0xC67781 + (uint16_t)((uint16_t)(value61 << 1) + value62 + (value61 >> 0x0F)));
                BUS8_SET(c, (uint16_t)(dp + 0xDE), value64 >> 1);
                uint8_t value65 = BUS8(c, 0xC67782 + (uint16_t)((uint16_t)(value61 << 1) + value62 + (value61 >> 0x0F)));
                BUS8_SET(c, (uint16_t)(dp + 0xDF), value65);
                BUS8_SET(c, (uint16_t)(dp + 0xE0), 0xE0);
                r->a = (((value63 & 0x01FF) | 0x8000) >> 8 << 8) | 0xE0;
                r->x = (uint16_t)((uint16_t)(value61 << 1) + value62 + (value61 >> 0x0F));
                r->y = (uint8_t)y;
                r->c = value64 & 0x01;
                r->v = (((uint16_t)(value61 << 1) ^ (uint16_t)((uint16_t)(value61 << 1) + value62 + (value61 >> 0x0F))) & (value62 ^ (uint16_t)((uint16_t)(value61 << 1) + value62 + (value61 >> 0x0F))) & 0x8000) != 0;
                RETURN_RTS(c);
            }
            uint8_t value66 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
            BUS8_SET(c, (uint16_t)(dp + 0xCC), value66 | 0x10);
            r->a = (a_hi6 << 8) | 0x10;
            r->x = x6;
            r->y = (uint8_t)y;
            r->c = carry6;
            r->v = value52 & 0x40;
            r->xf = 1;
            RETURN_RTS(c);
        }
        r->a = a_hi6 << 8 | (a6 & 1);
        r->x = x6;
        r->y = (uint8_t)y;
        r->c = carry6;
        r->v = ((((value8 & 0xFF) >> 3) ^ (uint16_t)(((value8 & 0xFF) >> 3) + value48)) & (value48 ^ (uint16_t)(((value8 & 0xFF) >> 3) + value48)) & 0x8000) != 0;
        r->xf = 1;
        RETURN_RTS(c);
    }
    uint16_t value67 = BUS16_RDP(c, (uint16_t)(dp + 0xE2));
    if (!(value67 & 0x4000)) {
        r->a = value8 & 0xFF;
        r->x = (((value6 >> 2) & 0xFE) << 8) | 0 | value7;
        r->y = (uint8_t)y;
        r->c = (value8 & 0xFF) >= 0xAF;
        r->v = value67 & 0x4000;
        r->mf = 0;
        RETURN_RTS(c);
    }
    if (value67 & 0x4000) {
        BUS16_SET(c, (uint16_t)(dp + 2), value8 & 0xFF);
        uint16_t value68 = BUS16_RDP(c, dp);
        uint8_t value69 = BUS8(c, 0xC67600 + (uint16_t)(((value8 & 0xFF) >> 3) + value68));
        BUS8_SET(c, dp, value69);
        uint8_t value70 = BUS8_RDP(c, (uint16_t)(dp + 2));
        uint8_t value71 = BUS8_RDP(c, dp);
        uint8_t a8;
        uint8_t a_hi8;
        uint8_t x8;
        bool carry8;
        if ((uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value68) >> 8 << 8 | (value70 & 7)) == 0) {
            a8 = value71;
            a_hi8 = (uint16_t)(((value8 & 0xFF) >> 3) + value68) >> 8;
            x8 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value68) >> 8 << 8 | (value70 & 7));
            carry8 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value68) >> 8 << 8 | (value70 & 7)) >= 0;
        } else {
            uint8_t a7 = value71;
            uint8_t a_hi7 = (uint16_t)(((value8 & 0xFF) >> 3) + value68) >> 8;
            uint8_t x7 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value68) >> 8 << 8 | (value70 & 7));
            bool carry7 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value68) >> 8 << 8 | (value70 & 7)) >= 0;
            for (;;) {
                uint8_t a7_next = a7 >> 1;
                uint8_t x7_next = (uint8_t)(x7 - 1);
                bool carry7_next = a7 & 0x01;
                a7 = a7_next;
                x7 = x7_next;
                carry7 = carry7_next;
                if (!(x7 != 0)) break;
            }
            a8 = a7;
            a_hi8 = a_hi7;
            x8 = x7;
            carry8 = carry7;
        }
        if ((a8 & 1) == 0) {
            uint8_t value72 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
            if ((value72 & 3) == 0) {
                uint8_t value73 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
                if (!(value73 & 0x80)) {
                    BUS8_SET(c, (uint16_t)(dp + 0xF2), value73 | 1);
                }
                BUS8_SET(c, (uint16_t)(dp + 0xFE), 0x80);
                BUS8_SET(c, (uint16_t)(dp + 0xE8), 1);
                uint8_t value74 = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
                BUS8_SET(c, dp, value74 & 0x0C);
                uint8_t value75 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
                uint8_t value76 = BUS8_RDP(c, dp);
                BUS8_SET(c, dp, (uint8_t)((((value75 & 0x0C) >> 2) | value76) << 4));
                BUS8_SET(c, (uint16_t)(dp + 1), 0);
                uint8_t value77 = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
                BUS8_SET(c, (uint16_t)(dp + 2), (value77 & 3) << 1 << 1);
                uint8_t value78 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
                uint8_t value79 = BUS8_RDP(c, (uint16_t)(dp + 2));
                uint16_t value80 = BUS16_RDP(c, dp);
                BUS16_SET(c, dp, (uint16_t)((((a_hi8 << 8) | ((value78 & 3) | value79)) & 0xFF) + value80));
                uint16_t value81 = BUS16_RDP(c, dp);
                uint16_t value82 = BUS16_RDP(c, dp);
                uint16_t value83 = BUS16(c, 0xC67780 + (uint16_t)((uint16_t)(value81 << 1) + value82 + (value81 >> 0x0F)));
                BUS16_SET(c, (uint16_t)(dp + 0xDC), value83 & 0x01FF);
                BUS16_SET(c, (db << 0x10) + 0x010E, (value83 & 0x01FF) | 0x8000);
                uint8_t value84 = BUS8(c, 0xC67781 + (uint16_t)((uint16_t)(value81 << 1) + value82 + (value81 >> 0x0F)));
                BUS8_SET(c, (uint16_t)(dp + 0xDE), value84 >> 1);
                uint8_t value85 = BUS8(c, 0xC67782 + (uint16_t)((uint16_t)(value81 << 1) + value82 + (value81 >> 0x0F)));
                BUS8_SET(c, (uint16_t)(dp + 0xDF), value85);
                BUS8_SET(c, (uint16_t)(dp + 0xE0), 0xE0);
                r->a = (((value83 & 0x01FF) | 0x8000) >> 8 << 8) | 0xE0;
                r->x = (uint16_t)((uint16_t)(value81 << 1) + value82 + (value81 >> 0x0F));
                r->y = (uint8_t)y;
                r->c = value84 & 0x01;
                r->v = (((uint16_t)(value81 << 1) ^ (uint16_t)((uint16_t)(value81 << 1) + value82 + (value81 >> 0x0F))) & (value82 ^ (uint16_t)((uint16_t)(value81 << 1) + value82 + (value81 >> 0x0F))) & 0x8000) != 0;
                RETURN_RTS(c);
            }
            uint8_t value86 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
            BUS8_SET(c, (uint16_t)(dp + 0xCC), value86 | 0x10);
            r->a = (a_hi8 << 8) | 0x10;
            r->x = x8;
            r->y = (uint8_t)y;
            r->c = carry8;
            r->v = value72 & 0x40;
            r->xf = 1;
            RETURN_RTS(c);
        }
        r->a = a_hi8 << 8 | (a8 & 1);
        r->x = x8;
        r->y = (uint8_t)y;
        r->c = carry8;
        r->v = ((((value8 & 0xFF) >> 3) ^ (uint16_t)(((value8 & 0xFF) >> 3) + value68)) & (value68 ^ (uint16_t)(((value8 & 0xFF) >> 3) + value68)) & 0x8000) != 0;
        r->xf = 1;
        RETURN_RTS(c);
    }
    if ((value8 & 0xFF) >= 0xAF) {
        BUS16_SET(c, (uint16_t)(dp + 2), value8 & 0xFF);
        uint16_t value87 = BUS16_RDP(c, dp);
        uint8_t value88 = BUS8(c, 0xC67600 + (uint16_t)(((value8 & 0xFF) >> 3) + value87));
        BUS8_SET(c, dp, value88);
        uint8_t value89 = BUS8_RDP(c, (uint16_t)(dp + 2));
        uint8_t value90 = BUS8_RDP(c, dp);
        uint8_t a10;
        uint8_t a_hi10;
        uint8_t x10;
        bool carry10;
        if ((uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value87) >> 8 << 8 | (value89 & 7)) == 0) {
            a10 = value90;
            a_hi10 = (uint16_t)(((value8 & 0xFF) >> 3) + value87) >> 8;
            x10 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value87) >> 8 << 8 | (value89 & 7));
            carry10 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value87) >> 8 << 8 | (value89 & 7)) >= 0;
        } else {
            uint8_t a9 = value90;
            uint8_t a_hi9 = (uint16_t)(((value8 & 0xFF) >> 3) + value87) >> 8;
            uint8_t x9 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value87) >> 8 << 8 | (value89 & 7));
            bool carry9 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value87) >> 8 << 8 | (value89 & 7)) >= 0;
            for (;;) {
                uint8_t a9_next = a9 >> 1;
                uint8_t x9_next = (uint8_t)(x9 - 1);
                bool carry9_next = a9 & 0x01;
                a9 = a9_next;
                x9 = x9_next;
                carry9 = carry9_next;
                if (!(x9 != 0)) break;
            }
            a10 = a9;
            a_hi10 = a_hi9;
            x10 = x9;
            carry10 = carry9;
        }
        if ((a10 & 1) == 0) {
            uint8_t value91 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
            if ((value91 & 3) == 0) {
                uint8_t value92 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
                if (!(value92 & 0x80)) {
                    BUS8_SET(c, (uint16_t)(dp + 0xF2), value92 | 1);
                }
                BUS8_SET(c, (uint16_t)(dp + 0xFE), 0x80);
                BUS8_SET(c, (uint16_t)(dp + 0xE8), 1);
                uint8_t value93 = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
                BUS8_SET(c, dp, value93 & 0x0C);
                uint8_t value94 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
                uint8_t value95 = BUS8_RDP(c, dp);
                BUS8_SET(c, dp, (uint8_t)((((value94 & 0x0C) >> 2) | value95) << 4));
                BUS8_SET(c, (uint16_t)(dp + 1), 0);
                uint8_t value96 = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
                BUS8_SET(c, (uint16_t)(dp + 2), (value96 & 3) << 1 << 1);
                uint8_t value97 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
                uint8_t value98 = BUS8_RDP(c, (uint16_t)(dp + 2));
                uint16_t value99 = BUS16_RDP(c, dp);
                BUS16_SET(c, dp, (uint16_t)((((a_hi10 << 8) | ((value97 & 3) | value98)) & 0xFF) + value99));
                uint16_t value100 = BUS16_RDP(c, dp);
                uint16_t value101 = BUS16_RDP(c, dp);
                uint16_t value102 = BUS16(c, 0xC67780 + (uint16_t)((uint16_t)(value100 << 1) + value101 + (value100 >> 0x0F)));
                BUS16_SET(c, (uint16_t)(dp + 0xDC), value102 & 0x01FF);
                BUS16_SET(c, (db << 0x10) + 0x010E, (value102 & 0x01FF) | 0x8000);
                uint8_t value103 = BUS8(c, 0xC67781 + (uint16_t)((uint16_t)(value100 << 1) + value101 + (value100 >> 0x0F)));
                BUS8_SET(c, (uint16_t)(dp + 0xDE), value103 >> 1);
                uint8_t value104 = BUS8(c, 0xC67782 + (uint16_t)((uint16_t)(value100 << 1) + value101 + (value100 >> 0x0F)));
                BUS8_SET(c, (uint16_t)(dp + 0xDF), value104);
                BUS8_SET(c, (uint16_t)(dp + 0xE0), 0xE0);
                r->a = (((value102 & 0x01FF) | 0x8000) >> 8 << 8) | 0xE0;
                r->x = (uint16_t)((uint16_t)(value100 << 1) + value101 + (value100 >> 0x0F));
                r->y = (uint8_t)y;
                r->c = value103 & 0x01;
                r->v = (((uint16_t)(value100 << 1) ^ (uint16_t)((uint16_t)(value100 << 1) + value101 + (value100 >> 0x0F))) & (value101 ^ (uint16_t)((uint16_t)(value100 << 1) + value101 + (value100 >> 0x0F))) & 0x8000) != 0;
                RETURN_RTS(c);
            }
            uint8_t value105 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
            BUS8_SET(c, (uint16_t)(dp + 0xCC), value105 | 0x10);
            r->a = (a_hi10 << 8) | 0x10;
            r->x = x10;
            r->y = (uint8_t)y;
            r->c = carry10;
            r->v = value91 & 0x40;
            r->xf = 1;
            RETURN_RTS(c);
        }
        r->a = a_hi10 << 8 | (a10 & 1);
        r->x = x10;
        r->y = (uint8_t)y;
        r->c = carry10;
        r->v = ((((value8 & 0xFF) >> 3) ^ (uint16_t)(((value8 & 0xFF) >> 3) + value87)) & (value87 ^ (uint16_t)(((value8 & 0xFF) >> 3) + value87)) & 0x8000) != 0;
        r->xf = 1;
        RETURN_RTS(c);
    }
    uint16_t value106 = BUS16_RDP(c, (uint16_t)(dp + 0xE2));
    if (!(value106 & 0x8000)) {
        r->a = value8 & 0xFF;
        r->x = (((value6 >> 2) & 0xFE) << 8) | 0 | value7;
        r->y = (uint8_t)y;
        r->c = (value8 & 0xFF) >= 0xAF;
        r->v = value106 & 0x4000;
        r->mf = 0;
        RETURN_RTS(c);
    }
    BUS16_SET(c, (uint16_t)(dp + 2), value8 & 0xFF);
    uint16_t value107 = BUS16_RDP(c, dp);
    uint8_t value108 = BUS8(c, 0xC67600 + (uint16_t)(((value8 & 0xFF) >> 3) + value107));
    BUS8_SET(c, dp, value108);
    uint8_t value109 = BUS8_RDP(c, (uint16_t)(dp + 2));
    uint8_t value110 = BUS8_RDP(c, dp);
    uint8_t a12;
    uint8_t a_hi12;
    uint8_t x12;
    bool carry12;
    if ((uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value107) >> 8 << 8 | (value109 & 7)) == 0) {
        a12 = value110;
        a_hi12 = (uint16_t)(((value8 & 0xFF) >> 3) + value107) >> 8;
        x12 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value107) >> 8 << 8 | (value109 & 7));
        carry12 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value107) >> 8 << 8 | (value109 & 7)) >= 0;
    } else {
        uint8_t a11 = value110;
        uint8_t a_hi11 = (uint16_t)(((value8 & 0xFF) >> 3) + value107) >> 8;
        uint8_t x11 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value107) >> 8 << 8 | (value109 & 7));
        bool carry11 = (uint8_t)((uint16_t)(((value8 & 0xFF) >> 3) + value107) >> 8 << 8 | (value109 & 7)) >= 0;
        for (;;) {
            uint8_t a11_next = a11 >> 1;
            uint8_t x11_next = (uint8_t)(x11 - 1);
            bool carry11_next = a11 & 0x01;
            a11 = a11_next;
            x11 = x11_next;
            carry11 = carry11_next;
            if (!(x11 != 0)) break;
        }
        a12 = a11;
        a_hi12 = a_hi11;
        x12 = x11;
        carry12 = carry11;
    }
    if ((a12 & 1) == 0) {
        uint8_t value111 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
        if ((value111 & 3) == 0) {
            uint8_t value112 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
            if (!(value112 & 0x80)) {
                BUS8_SET(c, (uint16_t)(dp + 0xF2), value112 | 1);
            }
            BUS8_SET(c, (uint16_t)(dp + 0xFE), 0x80);
            BUS8_SET(c, (uint16_t)(dp + 0xE8), 1);
            uint8_t value113 = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
            BUS8_SET(c, dp, value113 & 0x0C);
            uint8_t value114 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
            uint8_t value115 = BUS8_RDP(c, dp);
            BUS8_SET(c, dp, (uint8_t)((((value114 & 0x0C) >> 2) | value115) << 4));
            BUS8_SET(c, (uint16_t)(dp + 1), 0);
            uint8_t value116 = BUS8_RDP(c, (uint16_t)(dp + 0xFD));
            BUS8_SET(c, (uint16_t)(dp + 2), (value116 & 3) << 1 << 1);
            uint8_t value117 = BUS8_RDP(c, (uint16_t)(dp + 0xFB));
            uint8_t value118 = BUS8_RDP(c, (uint16_t)(dp + 2));
            uint16_t value119 = BUS16_RDP(c, dp);
            BUS16_SET(c, dp, (uint16_t)((((a_hi12 << 8) | ((value117 & 3) | value118)) & 0xFF) + value119));
            uint16_t value120 = BUS16_RDP(c, dp);
            uint16_t value121 = BUS16_RDP(c, dp);
            uint16_t value122 = BUS16(c, 0xC67780 + (uint16_t)((uint16_t)(value120 << 1) + value121 + (value120 >> 0x0F)));
            BUS16_SET(c, (uint16_t)(dp + 0xDC), value122 & 0x01FF);
            BUS16_SET(c, (db << 0x10) + 0x010E, (value122 & 0x01FF) | 0x8000);
            uint8_t value123 = BUS8(c, 0xC67781 + (uint16_t)((uint16_t)(value120 << 1) + value121 + (value120 >> 0x0F)));
            BUS8_SET(c, (uint16_t)(dp + 0xDE), value123 >> 1);
            uint8_t value124 = BUS8(c, 0xC67782 + (uint16_t)((uint16_t)(value120 << 1) + value121 + (value120 >> 0x0F)));
            BUS8_SET(c, (uint16_t)(dp + 0xDF), value124);
            BUS8_SET(c, (uint16_t)(dp + 0xE0), 0xE0);
            r->a = (((value122 & 0x01FF) | 0x8000) >> 8 << 8) | 0xE0;
            r->x = (uint16_t)((uint16_t)(value120 << 1) + value121 + (value120 >> 0x0F));
            r->y = (uint8_t)y;
            r->c = value123 & 0x01;
            r->v = (((uint16_t)(value120 << 1) ^ (uint16_t)((uint16_t)(value120 << 1) + value121 + (value120 >> 0x0F))) & (value121 ^ (uint16_t)((uint16_t)(value120 << 1) + value121 + (value120 >> 0x0F))) & 0x8000) != 0;
            RETURN_RTS(c);
        }
        uint8_t value125 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
        BUS8_SET(c, (uint16_t)(dp + 0xCC), value125 | 0x10);
        r->a = (a_hi12 << 8) | 0x10;
        r->x = x12;
        r->y = (uint8_t)y;
        r->c = carry12;
        r->v = value111 & 0x40;
        r->xf = 1;
        RETURN_RTS(c);
    }
    r->a = a_hi12 << 8 | (a12 & 1);
    r->x = x12;
    r->y = (uint8_t)y;
    r->c = carry12;
    r->v = ((((value8 & 0xFF) >> 3) ^ (uint16_t)(((value8 & 0xFF) >> 3) + value107)) & (value107 ^ (uint16_t)(((value8 & 0xFF) >> 3) + value107)) & 0x8000) != 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08159, SOM_RTS, "gen", test_ui_target_tile_permission_and_request_map_transition, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 245, 133)
