#include "som_c.h"

/* C199CB upload_second_hero_auxiliary_tiles   [class D, 948 bytes, 402 instructions]
 * Source: src/rom/upload_second_hero_auxiliary_tiles.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$4300.  Callers read: ABXYCZNV.
 */
static void upload_second_hero_auxiliary_tiles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x4300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0xE284);
    uint8_t a_hi9;
    uint8_t y1;
    if ((uint8_t)value != 0) {
        BUS16_SET(c, 0x002116, 0x7680);
        BUS16_SET(c, 0x004342, RAM16(0x0CB0));
        BUS16_SET(c, 0x004352, RAM16(0x0CB2));
        BUS16_SET(c, 0x004362, RAM16(0x0CB8));
        BUS16_SET(c, 0x004372, RAM16(0x0CBA));
        BUS16_SET(c, 0x004344, 0x207E);
        BUS16_SET(c, 0x004354, 0x207E);
        BUS16_SET(c, 0x004364, 0x207E);
        BUS16_SET(c, 0x004374, 0x207E);
        BUS8_SET(c, 0x00420B, 0xF0);
        BUS16_SET(c, 0x002116, 0x7780);
        BUS16_SET(c, 0x004342, RAM16(0x0CB4));
        BUS16_SET(c, 0x004352, RAM16(0x0CB6));
        BUS16_SET(c, 0x004362, RAM16(0x0CBC));
        uint16_t value9 = RAM16(0x0CBE);
        BUS16_SET(c, 0x004372, value9);
        BUS8_SET(c, 0x004345, 0x20);
        BUS8_SET(c, 0x004355, 0x20);
        BUS8_SET(c, 0x004365, 0x20);
        BUS8_SET(c, 0x004375, 0x20);
        BUS8_SET(c, 0x00420B, 0xF0);
        uint8_t a_hi8;
        if ((uint8_t)((uint8_t)value - 1) != 0) {
            uint8_t a_hi7;
            if ((uint8_t)((uint8_t)value - 2) == 0) {
                a_hi7 = value9 >> 8;
            } else {
                BUS16_SET(c, 0x002116, 0x76C0);
                BUS16_SET(c, 0x004342, RAM16(0x0CC0));
                BUS16_SET(c, 0x004352, RAM16(0x0CC2));
                BUS16_SET(c, 0x004362, RAM16(0x0CC8));
                BUS16_SET(c, 0x004372, RAM16(0x0CCA));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x77C0);
                BUS16_SET(c, 0x004342, RAM16(0x0CC4));
                BUS16_SET(c, 0x004352, RAM16(0x0CC6));
                BUS16_SET(c, 0x004362, RAM16(0x0CCC));
                uint16_t value17 = RAM16(0x0CCE);
                BUS16_SET(c, 0x004372, value17);
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                uint8_t a_hi6;
                if ((uint8_t)((uint8_t)value - 3) != 0) {
                    uint8_t a_hi5;
                    if ((uint8_t)((uint8_t)value - 4) == 0) {
                        a_hi5 = value17 >> 8;
                    } else {
                        BUS16_SET(c, 0x002116, 0x7800);
                        BUS16_SET(c, 0x004342, RAM16(0x0CD0));
                        BUS16_SET(c, 0x004352, RAM16(0x0CD2));
                        BUS16_SET(c, 0x004362, RAM16(0x0CD8));
                        BUS16_SET(c, 0x004372, RAM16(0x0CDA));
                        BUS8_SET(c, 0x004345, 0x20);
                        BUS8_SET(c, 0x004355, 0x20);
                        BUS8_SET(c, 0x004365, 0x20);
                        BUS8_SET(c, 0x004375, 0x20);
                        BUS8_SET(c, 0x00420B, 0xF0);
                        BUS16_SET(c, 0x002116, 0x7900);
                        BUS16_SET(c, 0x004342, RAM16(0x0CD4));
                        BUS16_SET(c, 0x004352, RAM16(0x0CD6));
                        BUS16_SET(c, 0x004362, RAM16(0x0CDC));
                        uint16_t value25 = RAM16(0x0CDE);
                        BUS16_SET(c, 0x004372, value25);
                        BUS8_SET(c, 0x004345, 0x20);
                        BUS8_SET(c, 0x004355, 0x20);
                        BUS8_SET(c, 0x004365, 0x20);
                        BUS8_SET(c, 0x004375, 0x20);
                        BUS8_SET(c, 0x00420B, 0xF0);
                        uint8_t a_hi4;
                        if ((uint8_t)((uint8_t)value - 5) != 0) {
                            uint8_t a_hi3;
                            if ((uint8_t)((uint8_t)value - 6) == 0) {
                                a_hi3 = value25 >> 8;
                            } else {
                                BUS16_SET(c, 0x002116, 0x7840);
                                BUS16_SET(c, 0x004342, RAM16(0x0CE0));
                                BUS16_SET(c, 0x004352, RAM16(0x0CE2));
                                BUS16_SET(c, 0x004362, RAM16(0x0CE8));
                                BUS16_SET(c, 0x004372, RAM16(0x0CEA));
                                BUS8_SET(c, 0x004345, 0x20);
                                BUS8_SET(c, 0x004355, 0x20);
                                BUS8_SET(c, 0x004365, 0x20);
                                BUS8_SET(c, 0x004375, 0x20);
                                BUS8_SET(c, 0x00420B, 0xF0);
                                BUS16_SET(c, 0x002116, 0x7940);
                                BUS16_SET(c, 0x004342, RAM16(0x0CE4));
                                BUS16_SET(c, 0x004352, RAM16(0x0CE6));
                                BUS16_SET(c, 0x004362, RAM16(0x0CEC));
                                uint16_t value33 = RAM16(0x0CEE);
                                BUS16_SET(c, 0x004372, value33);
                                BUS8_SET(c, 0x004345, 0x20);
                                BUS8_SET(c, 0x004355, 0x20);
                                BUS8_SET(c, 0x004365, 0x20);
                                BUS8_SET(c, 0x004375, 0x20);
                                BUS8_SET(c, 0x00420B, 0xF0);
                                uint8_t a_hi2;
                                if ((uint8_t)((uint8_t)value - 7) == 0) {
                                    a_hi2 = value33 >> 8;
                                } else {
                                    uint8_t a_hi1;
                                    if ((uint8_t)((uint8_t)value - 8) == 0) {
                                        a_hi1 = value33 >> 8;
                                    } else {
                                        BUS16_SET(c, 0x002116, 0x7880);
                                        BUS16_SET(c, 0x004342, RAM16(0x0CF0));
                                        BUS16_SET(c, 0x004352, RAM16(0x0CF2));
                                        BUS16_SET(c, 0x004362, RAM16(0x0CF8));
                                        BUS16_SET(c, 0x004372, RAM16(0x0CFA));
                                        BUS8_SET(c, 0x004345, 0x20);
                                        BUS8_SET(c, 0x004355, 0x20);
                                        BUS8_SET(c, 0x004365, 0x20);
                                        BUS8_SET(c, 0x004375, 0x20);
                                        BUS8_SET(c, 0x00420B, 0xF0);
                                        BUS16_SET(c, 0x002116, 0x7980);
                                        BUS16_SET(c, 0x004342, RAM16(0x0CF4));
                                        BUS16_SET(c, 0x004352, RAM16(0x0CF6));
                                        BUS16_SET(c, 0x004362, RAM16(0x0CFC));
                                        uint16_t value41 = RAM16(0x0CFE);
                                        BUS16_SET(c, 0x004372, value41);
                                        BUS8_SET(c, 0x004345, 0x20);
                                        BUS8_SET(c, 0x004355, 0x20);
                                        BUS8_SET(c, 0x004365, 0x20);
                                        BUS8_SET(c, 0x004375, 0x20);
                                        BUS8_SET(c, 0x00420B, 0xF0);
                                        a_hi1 = value41 >> 8;
                                    }
                                    a_hi2 = a_hi1;
                                }
                                a_hi3 = a_hi2;
                            }
                            a_hi4 = a_hi3;
                        } else {
                            a_hi4 = value25 >> 8;
                        }
                        a_hi5 = a_hi4;
                    }
                    a_hi6 = a_hi5;
                } else {
                    a_hi6 = value17 >> 8;
                }
                a_hi7 = a_hi6;
            }
            a_hi8 = a_hi7;
        } else {
            a_hi8 = value9 >> 8;
        }
        a_hi9 = a_hi8;
        y1 = 0xF0;
    } else {
        a_hi9 = value >> 8;
        y1 = y;
    }
    uint16_t value42 = RAM16(0xE28D);
    uint8_t a_hi11;
    uint8_t y3;
    if ((uint8_t)value42 == 0) {
        a_hi11 = value42 >> 8;
        y3 = y1;
    } else {
        RAM16_SET(0xE28D, value42 & 0xFF00);
        uint8_t a_hi10 = (value42 & 0xFF00) >> 8;
        uint8_t y2 = y1;
        for (;;) {
            BUS16_SET(c, 0x002116, 0x7880);
            BUS16_SET(c, 0x004342, RAM16(0x0CF0));
            BUS16_SET(c, 0x004352, RAM16(0x0CF2));
            BUS16_SET(c, 0x004362, RAM16(0x0CF8));
            BUS16_SET(c, 0x004372, RAM16(0x0CFA));
            BUS8_SET(c, 0x004345, 0x20);
            BUS8_SET(c, 0x004355, 0x20);
            BUS8_SET(c, 0x004365, 0x20);
            BUS8_SET(c, 0x004375, 0x20);
            BUS8_SET(c, 0x00420B, 0xF0);
            BUS16_SET(c, 0x002116, 0x7980);
            BUS16_SET(c, 0x004342, RAM16(0x0CF4));
            BUS16_SET(c, 0x004352, RAM16(0x0CF6));
            BUS16_SET(c, 0x004362, RAM16(0x0CFC));
            BUS16_SET(c, 0x004372, RAM16(0x0CFE));
            BUS8_SET(c, 0x004345, 0x20);
            BUS8_SET(c, 0x004355, 0x20);
            BUS8_SET(c, 0x004365, 0x20);
            BUS8_SET(c, 0x004375, 0x20);
            BUS8_SET(c, 0x00420B, 0xF0);
            uint16_t value51 = RAM16(0xE28D);
            if ((uint8_t)value51 != 0) {
                RAM16_SET(0xE28D, value51 & 0xFF00);
                a_hi10 = (value51 & 0xFF00) >> 8;
                y2 = 0xF0;
                continue;
            }
            a_hi10 = value51 >> 8;
            y2 = 0xF0;
            break;
        }
        a_hi11 = a_hi10;
        y3 = y2;
    }
    uint16_t value52 = RAM16(0xE484);
    uint8_t a_hi20;
    uint8_t y4;
    if ((uint8_t)value52 != 0) {
        BUS16_SET(c, 0x002116, 0x78C0);
        BUS16_SET(c, 0x004342, RAM16(0x0D00));
        BUS16_SET(c, 0x004352, RAM16(0x0D02));
        BUS16_SET(c, 0x004362, RAM16(0x0D08));
        BUS16_SET(c, 0x004372, RAM16(0x0D0A));
        BUS16_SET(c, 0x004344, 0x207E);
        BUS16_SET(c, 0x004354, 0x207E);
        BUS16_SET(c, 0x004364, 0x207E);
        BUS16_SET(c, 0x004374, 0x207E);
        BUS8_SET(c, 0x00420B, 0xF0);
        BUS16_SET(c, 0x002116, 0x79C0);
        BUS16_SET(c, 0x004342, RAM16(0x0D04));
        BUS16_SET(c, 0x004352, RAM16(0x0D06));
        BUS16_SET(c, 0x004362, RAM16(0x0D0C));
        uint16_t value60 = RAM16(0x0D0E);
        BUS16_SET(c, 0x004372, value60);
        BUS8_SET(c, 0x004345, 0x20);
        BUS8_SET(c, 0x004355, 0x20);
        BUS8_SET(c, 0x004365, 0x20);
        BUS8_SET(c, 0x004375, 0x20);
        BUS8_SET(c, 0x00420B, 0xF0);
        uint8_t a_hi19;
        if ((uint8_t)((uint8_t)value52 - 1) != 0) {
            uint8_t a_hi18;
            if ((uint8_t)((uint8_t)value52 - 2) == 0) {
                a_hi18 = value60 >> 8;
            } else {
                BUS16_SET(c, 0x002116, 0x7A00);
                BUS16_SET(c, 0x004342, RAM16(0x0D10));
                BUS16_SET(c, 0x004352, RAM16(0x0D12));
                BUS16_SET(c, 0x004362, RAM16(0x0D18));
                BUS16_SET(c, 0x004372, RAM16(0x0D1A));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x7B00);
                BUS16_SET(c, 0x004342, RAM16(0x0D14));
                BUS16_SET(c, 0x004352, RAM16(0x0D16));
                BUS16_SET(c, 0x004362, RAM16(0x0D1C));
                uint16_t value68 = RAM16(0x0D1E);
                BUS16_SET(c, 0x004372, value68);
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                uint8_t a_hi17;
                if ((uint8_t)((uint8_t)value52 - 3) != 0) {
                    uint8_t a_hi16;
                    if ((uint8_t)((uint8_t)value52 - 4) == 0) {
                        a_hi16 = value68 >> 8;
                    } else {
                        BUS16_SET(c, 0x002116, 0x7A40);
                        BUS16_SET(c, 0x004342, RAM16(0x0D20));
                        BUS16_SET(c, 0x004352, RAM16(0x0D22));
                        BUS16_SET(c, 0x004362, RAM16(0x0D28));
                        BUS16_SET(c, 0x004372, RAM16(0x0D2A));
                        BUS8_SET(c, 0x004345, 0x20);
                        BUS8_SET(c, 0x004355, 0x20);
                        BUS8_SET(c, 0x004365, 0x20);
                        BUS8_SET(c, 0x004375, 0x20);
                        BUS8_SET(c, 0x00420B, 0xF0);
                        BUS16_SET(c, 0x002116, 0x7B40);
                        BUS16_SET(c, 0x004342, RAM16(0x0D24));
                        BUS16_SET(c, 0x004352, RAM16(0x0D26));
                        BUS16_SET(c, 0x004362, RAM16(0x0D2C));
                        uint16_t value76 = RAM16(0x0D2E);
                        BUS16_SET(c, 0x004372, value76);
                        BUS8_SET(c, 0x004345, 0x20);
                        BUS8_SET(c, 0x004355, 0x20);
                        BUS8_SET(c, 0x004365, 0x20);
                        BUS8_SET(c, 0x004375, 0x20);
                        BUS8_SET(c, 0x00420B, 0xF0);
                        uint8_t a_hi15;
                        if ((uint8_t)((uint8_t)value52 - 5) != 0) {
                            uint8_t a_hi14;
                            if ((uint8_t)((uint8_t)value52 - 6) == 0) {
                                a_hi14 = value76 >> 8;
                            } else {
                                BUS16_SET(c, 0x002116, 0x7A80);
                                BUS16_SET(c, 0x004342, RAM16(0x0D30));
                                BUS16_SET(c, 0x004352, RAM16(0x0D32));
                                BUS16_SET(c, 0x004362, RAM16(0x0D38));
                                BUS16_SET(c, 0x004372, RAM16(0x0D3A));
                                BUS8_SET(c, 0x004345, 0x20);
                                BUS8_SET(c, 0x004355, 0x20);
                                BUS8_SET(c, 0x004365, 0x20);
                                BUS8_SET(c, 0x004375, 0x20);
                                BUS8_SET(c, 0x00420B, 0xF0);
                                BUS16_SET(c, 0x002116, 0x7B80);
                                BUS16_SET(c, 0x004342, RAM16(0x0D34));
                                BUS16_SET(c, 0x004352, RAM16(0x0D36));
                                BUS16_SET(c, 0x004362, RAM16(0x0D3C));
                                uint16_t value84 = RAM16(0x0D3E);
                                BUS16_SET(c, 0x004372, value84);
                                BUS8_SET(c, 0x004345, 0x20);
                                BUS8_SET(c, 0x004355, 0x20);
                                BUS8_SET(c, 0x004365, 0x20);
                                BUS8_SET(c, 0x004375, 0x20);
                                BUS8_SET(c, 0x00420B, 0xF0);
                                uint8_t a_hi13;
                                if ((uint8_t)((uint8_t)value52 - 7) == 0) {
                                    a_hi13 = value84 >> 8;
                                } else {
                                    uint8_t a_hi12;
                                    if ((uint8_t)((uint8_t)value52 - 8) == 0) {
                                        a_hi12 = value84 >> 8;
                                    } else {
                                        BUS16_SET(c, 0x002116, 0x7AC0);
                                        BUS16_SET(c, 0x004342, RAM16(0x0D40));
                                        BUS16_SET(c, 0x004352, RAM16(0x0D42));
                                        BUS16_SET(c, 0x004362, RAM16(0x0D48));
                                        BUS16_SET(c, 0x004372, RAM16(0x0D4A));
                                        BUS8_SET(c, 0x004345, 0x20);
                                        BUS8_SET(c, 0x004355, 0x20);
                                        BUS8_SET(c, 0x004365, 0x20);
                                        BUS8_SET(c, 0x004375, 0x20);
                                        BUS8_SET(c, 0x00420B, 0xF0);
                                        BUS16_SET(c, 0x002116, 0x7BC0);
                                        BUS16_SET(c, 0x004342, RAM16(0x0D44));
                                        BUS16_SET(c, 0x004352, RAM16(0x0D46));
                                        BUS16_SET(c, 0x004362, RAM16(0x0D4C));
                                        uint16_t value92 = RAM16(0x0D4E);
                                        BUS16_SET(c, 0x004372, value92);
                                        BUS8_SET(c, 0x004345, 0x20);
                                        BUS8_SET(c, 0x004355, 0x20);
                                        BUS8_SET(c, 0x004365, 0x20);
                                        BUS8_SET(c, 0x004375, 0x20);
                                        BUS8_SET(c, 0x00420B, 0xF0);
                                        a_hi12 = value92 >> 8;
                                    }
                                    a_hi13 = a_hi12;
                                }
                                a_hi14 = a_hi13;
                            }
                            a_hi15 = a_hi14;
                        } else {
                            a_hi15 = value76 >> 8;
                        }
                        a_hi16 = a_hi15;
                    }
                    a_hi17 = a_hi16;
                } else {
                    a_hi17 = value68 >> 8;
                }
                a_hi18 = a_hi17;
            }
            a_hi19 = a_hi18;
        } else {
            a_hi19 = value60 >> 8;
        }
        a_hi20 = a_hi19;
        y4 = 0xF0;
    } else {
        a_hi20 = value52 >> 8;
        y4 = y3;
    }
    uint16_t value93 = RAM16(0xE48D);
    uint8_t a2;
    uint8_t a_hi22;
    uint8_t x2;
    uint8_t y6;
    bool zero2;
    bool negative2;
    if ((uint8_t)value93 == 0) {
        a2 = (uint8_t)value93;
        a_hi22 = value93 >> 8;
        x2 = (uint8_t)value93;
        y6 = y4;
        zero2 = (uint8_t)value93 == 0;
        negative2 = (uint8_t)value93 & 0x80;
    } else {
        RAM16_SET(0xE48D, value93 & 0xFF00);
        uint8_t a1 = (uint8_t)(value93 & 0xFF00);
        uint8_t a_hi21 = (value93 & 0xFF00) >> 8;
        uint8_t x1 = 4;
        uint8_t y5 = y4;
        bool zero1 = 0;
        bool negative1 = 0;
        for (;;) {
            BUS16_SET(c, 0x002116, 0x7AC0);
            BUS16_SET(c, 0x004342, RAM16(0x0D40));
            BUS16_SET(c, 0x004352, RAM16(0x0D42));
            BUS16_SET(c, 0x004362, RAM16(0x0D48));
            BUS16_SET(c, 0x004372, RAM16(0x0D4A));
            BUS8_SET(c, 0x004345, 0x20);
            BUS8_SET(c, 0x004355, 0x20);
            BUS8_SET(c, 0x004365, 0x20);
            BUS8_SET(c, 0x004375, 0x20);
            BUS8_SET(c, 0x00420B, 0xF0);
            BUS16_SET(c, 0x002116, 0x7BC0);
            BUS16_SET(c, 0x004342, RAM16(0x0D44));
            BUS16_SET(c, 0x004352, RAM16(0x0D46));
            BUS16_SET(c, 0x004362, RAM16(0x0D4C));
            BUS16_SET(c, 0x004372, RAM16(0x0D4E));
            BUS8_SET(c, 0x004345, 0x20);
            BUS8_SET(c, 0x004355, 0x20);
            BUS8_SET(c, 0x004365, 0x20);
            BUS8_SET(c, 0x004375, 0x20);
            BUS8_SET(c, 0x00420B, 0xF0);
            uint16_t value102 = RAM16(0xE48D);
            if ((uint8_t)value102 != 0) {
                RAM16_SET(0xE48D, value102 & 0xFF00);
                a1 = (uint8_t)(value102 & 0xFF00);
                a_hi21 = (value102 & 0xFF00) >> 8;
                x1 = 4;
                y5 = 0xF0;
                zero1 = 0;
                negative1 = 0;
                continue;
            }
            a1 = (uint8_t)value102;
            a_hi21 = value102 >> 8;
            x1 = (uint8_t)value102;
            y5 = 0xF0;
            zero1 = (uint8_t)value102 == 0;
            negative1 = (uint8_t)value102 & 0x80;
            break;
        }
        a2 = a1;
        a_hi22 = a_hi21;
        x2 = x1;
        y6 = y5;
        zero2 = zero1;
        negative2 = negative1;
    }
    uint8_t value103 = RAM8(0x0000 + sp0 - 1);
    uint8_t value104 = RAM8(0x0000 + sp0);
    r->a = (a_hi22 << 8) | a2;
    r->x = x2;
    r->y = y6;
    r->c = carry;
    r->z = ((value104 << 8) | value103) == 0;
    r->n = ((value104 << 8) | value103) & 0x8000;
    r->v = overflow;
    r->dp = (value104 << 8) | value103;
    r->sp += 2;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC199CB, SOM_RTL, "gen", upload_second_hero_auxiliary_tiles, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 1, 948, 402)
