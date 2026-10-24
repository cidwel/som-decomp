#include "som_c.h"

/* C0C238 upload_map_frame_hud_and_animated_characters   [class D, 500 bytes, 190 instructions]
 * Source: src/rom/upload_map_frame_hud_and_animated_characters.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: CV.
 */
static void upload_map_frame_hud_and_animated_characters(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, 0x002115, 0);
    uint8_t value = RAM8(0x0A55);
    if (value != 0) {
        BUS16_SET(c, 0x002116, (0x5B << 8) | value);
        BUS8_SET(c, 0x002118, RAM8(0x0A56));
        BUS8_SET(c, 0x002118, RAM8(0x0A57));
        BUS8_SET(c, 0x002118, RAM8(0x0A50));
        BUS8_SET(c, 0x002118, RAM8(0x0A51));
        BUS8_SET(c, 0x002118, RAM8(0x0A52));
        BUS8_SET(c, 0x002118, RAM8(0x0A53));
        BUS8_SET(c, 0x002118, RAM8(0x0A54));
    }
    uint8_t value9 = RAM8(0x0A65);
    if (value9 != 0) {
        BUS16_SET(c, 0x002116, (0x5B << 8) | value9);
        BUS8_SET(c, 0x002118, RAM8(0x0A66));
        BUS8_SET(c, 0x002118, RAM8(0x0A67));
        BUS8_SET(c, 0x002118, RAM8(0x0A60));
        BUS8_SET(c, 0x002118, RAM8(0x0A61));
        BUS8_SET(c, 0x002118, RAM8(0x0A62));
        BUS8_SET(c, 0x002118, RAM8(0x0A63));
        BUS8_SET(c, 0x002118, RAM8(0x0A64));
    }
    uint8_t value17 = RAM8(0x0A75);
    if (value17 != 0) {
        BUS16_SET(c, 0x002116, (0x5B << 8) | value17);
        BUS8_SET(c, 0x002118, RAM8(0x0A76));
        BUS8_SET(c, 0x002118, RAM8(0x0A77));
        BUS8_SET(c, 0x002118, RAM8(0x0A70));
        BUS8_SET(c, 0x002118, RAM8(0x0A71));
        BUS8_SET(c, 0x002118, RAM8(0x0A72));
        BUS8_SET(c, 0x002118, RAM8(0x0A73));
        BUS8_SET(c, 0x002118, RAM8(0x0A74));
    }
    if (RAM8(0x0052) != 0) {
        BUS8_SET(c, 0x002115, 0x81);
        BUS16_SET(c, 0x004370, 0x1801);
        BUS8_SET(c, 0x004374, 0x7F);
        BUS16_SET(c, 0x004372, 0xFF00);
        BUS16_SET(c, 0x002116, RAM16(0x0074));
        BUS8_SET(c, 0x004375, 0x18);
        BUS8_SET(c, 0x00420B, 0x80);
    }
    uint8_t value27 = RAM8(0x0090);
    bool m_flag;
    uint8_t a_hi2;
    if (!(value27 & 0x80)) {
        m_flag = 1;
        a_hi2 = 0x5B;
    } else {
        RAM8(0x0090) = value27 & 0x7F;
        BUS8_SET(c, 0x002115, 0x80);
        uint16_t value28 = RAM16(0x0092);
        uint8_t a_hi1;
        if (value28 == 0) {
            a_hi1 = value28 >> 8;
        } else {
            BUS16_SET(c, 0x004372, value28);
            BUS8_SET(c, 0x004374, 0xDC);
            BUS16_SET(c, 0x002116, RAM16(0x0096));
            BUS16_SET(c, 0x004375, 0x80);
            BUS16_SET(c, 0x004370, 0x1801);
            BUS8_SET(c, 0x00420B, 0x80);
            a_hi1 = 0x18;
        }
        m_flag = 0;
        a_hi2 = a_hi1;
    }
    uint8_t value30 = RAM8(0x009A);
    if (value30 & 0x80) {
        RAM8(0x009A) = value30 & 0x0F;
        BUS8_SET(c, 0x004370, 1);
        BUS8_SET(c, 0x004371, 0x18);
        BUS8_SET(c, 0x004374, 0x7F);
        BUS8_SET(c, 0x002115, 0x80);
        uint8_t a_hi3 = a_hi2;
        uint8_t x1 = 0;
        uint8_t y1 = (uint8_t)(a_hi2 << 8 | (value30 & 0x0F));
        bool carry1 = carry;
        bool overflow1 = overflow;
        for (;;) {
            uint8_t value31 = RAM8(0x18200 + x1);
            uint8_t a_hi10;
            if (value31 != 0) {
                uint8_t value32 = RAM8(0x18201 + x1);
                uint8_t a_hi9;
                if (value32 >= 8) {
                    uint8_t a_hi6;
                    if (value32 == 0x0A) {
                        BUS16_SET(c, 0x002116, RAM16(0x18300 + x1));
                        BUS16_SET(c, 0x002118, RAM16(0x18302 + x1));
                        BUS16_SET(c, 0x002116, RAM16(0x18304 + x1));
                        BUS16_SET(c, 0x002118, RAM16(0x18306 + x1));
                        BUS16_SET(c, 0x002116, RAM16(0x18308 + x1));
                        BUS16_SET(c, 0x002118, RAM16(0x1830A + x1));
                        BUS16_SET(c, 0x002116, RAM16(0x1830C + x1));
                        uint16_t value40 = RAM16(0x1830E + x1);
                        BUS16_SET(c, 0x002118, value40);
                        a_hi6 = value40 >> 8;
                    } else {
                        uint8_t a_hi5;
                        if (value32 == 0x0B) {
                            BUS16_SET(c, 0x002116, RAM16(0x18300 + x1));
                            BUS16_SET(c, 0x002118, RAM16(0x18302 + x1));
                            BUS16_SET(c, 0x002116, RAM16(0x18304 + x1));
                            BUS16_SET(c, 0x002118, RAM16(0x18306 + x1));
                            BUS16_SET(c, 0x002116, RAM16(0x18308 + x1));
                            BUS16_SET(c, 0x002118, RAM16(0x1830A + x1));
                            BUS16_SET(c, 0x002116, RAM16(0x1830C + x1));
                            uint16_t value48 = RAM16(0x1830E + x1);
                            BUS16_SET(c, 0x002118, value48);
                            a_hi5 = value48 >> 8;
                        } else {
                            uint8_t a_hi4;
                            if (value32 == 0x0D) {
                                BUS16_SET(c, 0x002116, RAM16(0x18300 + x1));
                                BUS16_SET(c, 0x002118, RAM16(0x18302 + x1));
                                BUS16_SET(c, 0x002116, RAM16(0x18304 + x1));
                                BUS16_SET(c, 0x002118, RAM16(0x18306 + x1));
                                BUS16_SET(c, 0x002116, RAM16(0x18308 + x1));
                                BUS16_SET(c, 0x002118, RAM16(0x1830A + x1));
                                BUS16_SET(c, 0x002116, RAM16(0x1830C + x1));
                                uint16_t value56 = RAM16(0x1830E + x1);
                                BUS16_SET(c, 0x002118, value56);
                                a_hi4 = value56 >> 8;
                            } else {
                                BUS16_SET(c, 0x004372, RAM16(0x1820A + x1));
                                BUS16_SET(c, 0x002116, RAM16(0x1820C + x1));
                                BUS16_SET(c, 0x004375, 0x40);
                                BUS8_SET(c, 0x00420B, 0x80);
                                a_hi4 = 0;
                            }
                            a_hi5 = a_hi4;
                        }
                        a_hi6 = a_hi5;
                    }
                    a_hi9 = a_hi6;
                } else {
                    uint8_t a_hi8;
                    if (value32 < 2) {
                        if (value32 == 4) {
                            BUS16_SET(c, 0x004372, RAM16(0x1820A + x1));
                            BUS16_SET(c, 0x002116, RAM16(0x1820C + x1));
                            BUS16_SET(c, 0x004375, 0x40);
                            BUS8_SET(c, 0x00420B, 0x80);
                        } else {
                            if (value32 == 5) {
                                BUS16_SET(c, 0x004372, RAM16(0x1820A + x1));
                                BUS16_SET(c, 0x002116, RAM16(0x1820C + x1));
                                BUS16_SET(c, 0x004375, 0x40);
                                BUS8_SET(c, 0x00420B, 0x80);
                            } else {
                                BUS16_SET(c, 0x002116, RAM16(0x1820C + x1));
                                BUS16_SET(c, 0x004372, RAM16(0x1820A + x1));
                                BUS16_SET(c, 0x004375, 0x20);
                                BUS8_SET(c, 0x00420B, 0x80);
                            }
                        }
                        a_hi8 = 0;
                    } else {
                        uint8_t a_hi7;
                        if (value32 >= 4) {
                            if (value32 == 4) {
                                BUS16_SET(c, 0x004372, RAM16(0x1820A + x1));
                                BUS16_SET(c, 0x002116, RAM16(0x1820C + x1));
                                BUS16_SET(c, 0x004375, 0x40);
                                BUS8_SET(c, 0x00420B, 0x80);
                            } else {
                                if (value32 == 5) {
                                    BUS16_SET(c, 0x004372, RAM16(0x1820A + x1));
                                    BUS16_SET(c, 0x002116, RAM16(0x1820C + x1));
                                    BUS16_SET(c, 0x004375, 0x40);
                                    BUS8_SET(c, 0x00420B, 0x80);
                                } else {
                                    BUS16_SET(c, 0x002116, RAM16(0x1820C + x1));
                                    BUS16_SET(c, 0x004372, RAM16(0x1820A + x1));
                                    BUS16_SET(c, 0x004375, 0x20);
                                    BUS8_SET(c, 0x00420B, 0x80);
                                }
                            }
                            a_hi7 = 0;
                        } else {
                            BUS16_SET(c, 0x002116, RAM16(0x18300 + x1));
                            BUS16_SET(c, 0x002118, RAM16(0x18302 + x1));
                            BUS16_SET(c, 0x002116, RAM16(0x18304 + x1));
                            uint16_t value74 = RAM16(0x18306 + x1);
                            BUS16_SET(c, 0x002118, value74);
                            a_hi7 = value74 >> 8;
                        }
                        a_hi8 = a_hi7;
                    }
                    a_hi9 = a_hi8;
                }
                a_hi10 = a_hi9;
            } else {
                a_hi10 = a_hi3;
            }
            uint8_t a_hi3_next = a_hi10;
            uint8_t x1_next = (uint8_t)((a_hi10 << 8) | (uint8_t)(x1 + 0x10));
            uint8_t y1_next = (uint8_t)(y1 - 1);
            bool carry1_next = x1 + 0x10 > 0xFF;
            bool overflow1_next = ((x1 ^ (uint8_t)(x1 + 0x10)) & ((uint8_t)(x1 + 0x10) ^ 0x10) & 0x80) != 0;
            a_hi3 = a_hi3_next;
            x1 = x1_next;
            y1 = y1_next;
            carry1 = carry1_next;
            overflow1 = overflow1_next;
            if (!(y1 != 0)) break;
        }
        r->c = carry1;
        r->v = overflow1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C238, SOM_RTS, "gen", upload_map_frame_hud_and_animated_characters, 0, L_C | L_V, 1, 1, 0, 500, 190)
