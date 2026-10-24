#include "som_c.h"

/* C095A0 build_scaled_ui_raster_window_records_and_request_native_publication   [class D, 274 bytes, 140 instructions]
 * Source: src/rom/build_scaled_ui_raster_window_records_and_request_native_publication.s
 * Documented in docs/ui-native-ui-frame-raster.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void build_scaled_ui_raster_window_records_and_request_native_publication(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x00F2);
    if (!(value & 0x80)) {
        uint16_t value2 = RAM16(0x008C);
        if (value2 != 0) {
            r->a = value2;
            r->x = value;
            RETURN_RTS(c);
        }
        uint8_t value3 = RAM8(0x002D);
        if (value3 != 0) {
            r->a = value2;
            r->x = value3;
            RETURN_RTS(c);
        }
        RAM16_SET(0x1821, 0x1830);
        RAM16_SET(0x1824, 0x1830);
        RAM16_SET(0x1827, 0x1832);
        RAM16_SET(0x0012, 0x96E2);
        uint8_t value4 = RAM8(0x0043);
        uint8_t a_hi2;
        bool overflow2;
        if ((value4 & 3) != 0) {
            a_hi2 = 0x96;
            overflow2 = overflow;
        } else {
            uint8_t a_hi1;
            bool overflow1;
            if ((value4 & 0x0C) == 0) {
                a_hi1 = 0x96;
                overflow1 = overflow;
            } else {
                uint16_t value5 = RAM16(0x00F4);
                uint16_t value6 = RAM16(0x0012);
                RAM16_SET(0x0012, (uint16_t)(((uint16_t)(value5 << 2) & 0x20) + value6));
                a_hi1 = (uint16_t)(((uint16_t)(value5 << 2) & 0x20) + value6) >> 8;
                overflow1 = ((((uint16_t)(value5 << 2) & 0x20) ^ (uint16_t)(((uint16_t)(value5 << 2) & 0x20) + value6)) & (value6 ^ (uint16_t)(((uint16_t)(value5 << 2) & 0x20) + value6)) & 0x8000) != 0;
            }
            a_hi2 = a_hi1;
            overflow2 = overflow1;
        }
        uint8_t value7 = RAM8(0x00F8);
        if (value7 >= 0x70) {
            r->a = (r->a & 0x00FF) | (a_hi2 << 8);
            r->x = value3;
            r->c = value7 >= 0x70;
            r->v = overflow2;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t x1;
        if ((uint8_t)((a_hi2 << 8) | (uint8_t)((value7 >> 2) - 4)) < 0x18) {
            x1 = (uint8_t)((a_hi2 << 8) | (uint8_t)((value7 >> 2) - 4));
        } else {
            x1 = 0x17;
        }
        uint8_t value8 = BUS8(c, 0x009722 + x1);
        RAM8(0x004E) = value8;
        uint8_t a1;
        if (x1 < 0x10) {
            a1 = x1;
        } else {
            a1 = 0x0F;
        }
        RAM16_SET(0x000E, (uint16_t)((((a_hi2 << 8) | (uint8_t)(a1 << 4)) & 0xFF) + 0x973A + ((uint8_t)(a1 << 3) >> 7)));
        RAM8(0x004F) = 0;
        RAM8(0x1829) = 0;
        RAM8(0x1826) = 0x91;
        RAM8(0x1820) = 0x7F;
        uint8_t value9 = RAM8(0x004E);
        RAM8(0x1823) = (uint8_t)(value9 - 0x8F);
        BUS8_SET(c, 0x004372, 0x20);
        RAM8(0x002D) = 1;
        uint8_t value10 = RAM8(0x005F);
        bool m_flag;
        uint8_t a_hi3;
        bool overflow3;
        if (value10 != 4) {
            m_flag = 1;
            a_hi3 = (uint16_t)((((a_hi2 << 8) | (uint8_t)(a1 << 4)) & 0xFF) + 0x973A + ((uint8_t)(a1 << 3) >> 7)) >> 8;
            overflow3 = ((value9 ^ 0x8F) & (value9 ^ (uint8_t)(value9 - 0x8F)) & 0x80) != 0;
        } else {
            uint16_t value11 = RAM16(0x0012);
            RAM16_SET(0x0012, (uint16_t)(value11 + 0x10));
            m_flag = 0;
            a_hi3 = (uint16_t)(value11 + 0x10) >> 8;
            overflow3 = ((value11 ^ (uint16_t)(value11 + 0x10)) & ((uint16_t)(value11 + 0x10) ^ 0x10) & 0x8000) != 0;
        }
        uint8_t a3;
        if ((uint8_t)((uint16_t)((((a_hi2 << 8) | (uint8_t)(a1 << 4)) & 0xFF) + 0x973A + ((uint8_t)(a1 << 3) >> 7)) >> 8 << 8 | (value4 & 3)) == 0) {
            a3 = 0xB2;
        } else {
            uint8_t a2;
            if ((uint8_t)((uint16_t)((((a_hi2 << 8) | (uint8_t)(a1 << 4)) & 0xFF) + 0x973A + ((uint8_t)(a1 << 3) >> 7)) >> 8 << 8 | (value4 & 3)) == 2) {
                a2 = 0xC2;
            } else {
                a2 = 0xD2;
            }
            a3 = a2;
        }
        RAM16_SET(0x0010, (0x96 << 8) | a3);
        RAM16_SET(0x000C, 0x1832);
        uint8_t y1 = 0x20;
        for (;;) {
            BUS16_SET(c, RAM16(0x000C) + y1, 1);
            y1 = (uint8_t)(y1 - 2);
            if (!(!(y1 & 0x80))) break;
        }
        RAM16_SET(0x0006, 0);
        uint8_t a_hi4 = 0;
        uint8_t x2 = (uint8_t)((uint16_t)((((a_hi2 << 8) | (uint8_t)(a1 << 4)) & 0xFF) + 0x973A + ((uint8_t)(a1 << 3) >> 7)) >> 8 << 8 | (value4 & 3));
        uint8_t y2 = y1;
        bool carry1 = 0;
        bool overflow4 = overflow3;
        for (;;) {
            uint8_t value12 = RAM8(0x0006);
            uint8_t value13 = BUS8_RDP(c, RAM16(0x000E) + value12);
            uint8_t a_hi5;
            uint8_t x3;
            uint8_t y3;
            bool overflow5;
            if (value13 == 0) {
                a_hi5 = a_hi4;
                x3 = x2;
                y3 = value12;
                overflow5 = overflow4;
            } else {
                uint8_t value14 = BUS8_RDP(c, RAM16(0x0012) + value12);
                BUS8_SET(c, 0x004202, value14);
                BUS8_SET(c, 0x004203, (uint8_t)((a_hi4 << 8) | value13));
                uint8_t value15 = BUS8(c, 0x004216);
                uint8_t value16 = BUS8(c, 0x004217);
                RAM8(0x0000) = (uint8_t)((value16 << 1) | (value15 >> 7));
                uint8_t value17 = BUS8_RDP(c, RAM16(0x0010) + value12);
                uint8_t value18 = BUS8_RDP(c, RAM16(0x0010) + value12);
                uint8_t value19 = RAM8(0x0000);
                BUS16_SET(c, RAM16(0x000C), ((uint8_t)((uint8_t)((value16 << 1) | (value15 >> 7)) + value17) << 8) | (uint8_t)(value18 - value19));
                RAM8(0x000C)++;
                RAM8(0x000C)++;
                a_hi5 = (uint8_t)((uint8_t)((value16 << 1) | (value15 >> 7)) + value17);
                x3 = (uint8_t)((a_hi4 << 8) | value13);
                y3 = 0;
                overflow5 = ((value18 ^ value19) & (value18 ^ (uint8_t)(value18 - value19)) & 0x80) != 0;
            }
            RAM8(0x0006)++;
            uint8_t value20 = RAM8(0x0006);
            a_hi4 = a_hi5;
            x2 = x3;
            y2 = y3;
            carry1 = value20 >= 0x10;
            overflow4 = overflow5;
            if (!(value20 < 0x10)) break;
        }
        r->a = (a_hi4 << 8) | (uint8_t)a;
        r->x = x2;
        r->y = y2;
        r->c = carry1;
        r->v = overflow4;
        r->mf = 1;
        RETURN_RTS(c);
    }
    r->x = value;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC095A0, SOM_RTS, "gen", build_scaled_ui_raster_window_records_and_request_native_publication, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 1, 274, 140)
