#include "som_c.h"

/* C195BC upload_three_hero_normal_tile_tables   [class D, 1039 bytes, 436 instructions]
 * Source: src/rom/upload_three_hero_normal_tile_tables.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$4300.  Callers read: ABXYCZNV.
 */
static void upload_three_hero_normal_tile_tables(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x4300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0xE083);
    uint8_t a_hi3;
    uint8_t y1;
    if ((uint8_t)value != 0) {
        BUS16_SET(c, 0x002116, 0x7C00);
        BUS16_SET(c, 0x004342, RAM16(0x0C00));
        BUS16_SET(c, 0x004352, RAM16(0x0C02));
        BUS16_SET(c, 0x004362, RAM16(0x0C08));
        BUS16_SET(c, 0x004372, RAM16(0x0C0A));
        uint16_t value6 = RAM16(0xE082);
        BUS16_SET(c, 0x004344, (value6 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004354, (value6 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004364, (value6 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004374, (value6 & 0xFF) | 0x2000);
        BUS8_SET(c, 0x00420B, 0xF0);
        BUS16_SET(c, 0x002116, 0x7D00);
        BUS16_SET(c, 0x004342, RAM16(0x0C04));
        BUS16_SET(c, 0x004352, RAM16(0x0C06));
        BUS16_SET(c, 0x004362, RAM16(0x0C0C));
        uint16_t value10 = RAM16(0x0C0E);
        BUS16_SET(c, 0x004372, value10);
        BUS8_SET(c, 0x004345, 0x20);
        BUS8_SET(c, 0x004355, 0x20);
        BUS8_SET(c, 0x004365, 0x20);
        BUS8_SET(c, 0x004375, 0x20);
        BUS8_SET(c, 0x00420B, 0xF0);
        uint8_t a_hi2;
        if ((uint8_t)((uint8_t)value - 1) == 0) {
            a_hi2 = value10 >> 8;
        } else {
            uint8_t a_hi1;
            if ((uint8_t)((uint8_t)value - 2) == 0) {
                a_hi1 = value10 >> 8;
            } else {
                BUS16_SET(c, 0x002116, 0x7C40);
                BUS16_SET(c, 0x004342, RAM16(0x0C10));
                BUS16_SET(c, 0x004352, RAM16(0x0C12));
                BUS16_SET(c, 0x004362, RAM16(0x0C18));
                BUS16_SET(c, 0x004372, RAM16(0x0C1A));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x7D40);
                BUS16_SET(c, 0x004342, RAM16(0x0C14));
                BUS16_SET(c, 0x004352, RAM16(0x0C16));
                BUS16_SET(c, 0x004362, RAM16(0x0C1C));
                uint16_t value18 = RAM16(0x0C1E);
                BUS16_SET(c, 0x004372, value18);
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                a_hi1 = value18 >> 8;
            }
            a_hi2 = a_hi1;
        }
        a_hi3 = a_hi2;
        y1 = 0xF0;
    } else {
        a_hi3 = value >> 8;
        y1 = y;
    }
    uint16_t value19 = RAM16(0xE283);
    uint8_t a_hi6;
    uint8_t y2;
    if ((uint8_t)value19 != 0) {
        BUS16_SET(c, 0x002116, 0x7C80);
        BUS16_SET(c, 0x004342, RAM16(0x0C20));
        BUS16_SET(c, 0x004352, RAM16(0x0C22));
        BUS16_SET(c, 0x004362, RAM16(0x0C28));
        BUS16_SET(c, 0x004372, RAM16(0x0C2A));
        uint16_t value24 = RAM16(0xE282);
        BUS16_SET(c, 0x004344, (value24 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004354, (value24 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004364, (value24 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004374, (value24 & 0xFF) | 0x2000);
        BUS8_SET(c, 0x00420B, 0xF0);
        BUS16_SET(c, 0x002116, 0x7D80);
        BUS16_SET(c, 0x004342, RAM16(0x0C24));
        BUS16_SET(c, 0x004352, RAM16(0x0C26));
        BUS16_SET(c, 0x004362, RAM16(0x0C2C));
        uint16_t value28 = RAM16(0x0C2E);
        BUS16_SET(c, 0x004372, value28);
        BUS8_SET(c, 0x004345, 0x20);
        BUS8_SET(c, 0x004355, 0x20);
        BUS8_SET(c, 0x004365, 0x20);
        BUS8_SET(c, 0x004375, 0x20);
        BUS8_SET(c, 0x00420B, 0xF0);
        uint8_t a_hi5;
        if ((uint8_t)((uint8_t)value19 - 1) == 0) {
            a_hi5 = value28 >> 8;
        } else {
            uint8_t a_hi4;
            if ((uint8_t)((uint8_t)value19 - 2) == 0) {
                a_hi4 = value28 >> 8;
            } else {
                BUS16_SET(c, 0x002116, 0x7CC0);
                BUS16_SET(c, 0x004342, RAM16(0x0C30));
                BUS16_SET(c, 0x004352, RAM16(0x0C32));
                BUS16_SET(c, 0x004362, RAM16(0x0C38));
                BUS16_SET(c, 0x004372, RAM16(0x0C3A));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x7DC0);
                BUS16_SET(c, 0x004342, RAM16(0x0C34));
                BUS16_SET(c, 0x004352, RAM16(0x0C36));
                BUS16_SET(c, 0x004362, RAM16(0x0C3C));
                uint16_t value36 = RAM16(0x0C3E);
                BUS16_SET(c, 0x004372, value36);
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                a_hi4 = value36 >> 8;
            }
            a_hi5 = a_hi4;
        }
        a_hi6 = a_hi5;
        y2 = 0xF0;
    } else {
        a_hi6 = value19 >> 8;
        y2 = y1;
    }
    uint16_t value37 = RAM16(0xE483);
    uint8_t a_hi9;
    uint8_t y3;
    if ((uint8_t)value37 != 0) {
        BUS16_SET(c, 0x002116, 0x7E00);
        BUS16_SET(c, 0x004342, RAM16(0x0C40));
        BUS16_SET(c, 0x004352, RAM16(0x0C42));
        BUS16_SET(c, 0x004362, RAM16(0x0C48));
        BUS16_SET(c, 0x004372, RAM16(0x0C4A));
        uint16_t value42 = RAM16(0xE482);
        BUS16_SET(c, 0x004344, (value42 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004354, (value42 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004364, (value42 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004374, (value42 & 0xFF) | 0x2000);
        BUS8_SET(c, 0x00420B, 0xF0);
        BUS16_SET(c, 0x002116, 0x7F00);
        BUS16_SET(c, 0x004342, RAM16(0x0C44));
        BUS16_SET(c, 0x004352, RAM16(0x0C46));
        BUS16_SET(c, 0x004362, RAM16(0x0C4C));
        uint16_t value46 = RAM16(0x0C4E);
        BUS16_SET(c, 0x004372, value46);
        BUS8_SET(c, 0x004345, 0x20);
        BUS8_SET(c, 0x004355, 0x20);
        BUS8_SET(c, 0x004365, 0x20);
        BUS8_SET(c, 0x004375, 0x20);
        BUS8_SET(c, 0x00420B, 0xF0);
        uint8_t a_hi8;
        if ((uint8_t)((uint8_t)value37 - 1) == 0) {
            a_hi8 = value46 >> 8;
        } else {
            uint8_t a_hi7;
            if ((uint8_t)((uint8_t)value37 - 2) == 0) {
                a_hi7 = value46 >> 8;
            } else {
                BUS16_SET(c, 0x002116, 0x7E40);
                BUS16_SET(c, 0x004342, RAM16(0x0C50));
                BUS16_SET(c, 0x004352, RAM16(0x0C52));
                BUS16_SET(c, 0x004362, RAM16(0x0C58));
                BUS16_SET(c, 0x004372, RAM16(0x0C5A));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x7F40);
                BUS16_SET(c, 0x004342, RAM16(0x0C54));
                BUS16_SET(c, 0x004352, RAM16(0x0C56));
                BUS16_SET(c, 0x004362, RAM16(0x0C5C));
                uint16_t value54 = RAM16(0x0C5E);
                BUS16_SET(c, 0x004372, value54);
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                a_hi7 = value54 >> 8;
            }
            a_hi8 = a_hi7;
        }
        a_hi9 = a_hi8;
        y3 = 0xF0;
    } else {
        a_hi9 = value37 >> 8;
        y3 = y2;
    }
    uint16_t value55 = RAM16(0xE084);
    uint8_t a_hi18;
    uint8_t y4;
    if ((uint8_t)value55 != 0) {
        BUS16_SET(c, 0x002116, 0x7440);
        BUS16_SET(c, 0x004342, RAM16(0x0C60));
        BUS16_SET(c, 0x004352, RAM16(0x0C62));
        BUS16_SET(c, 0x004362, RAM16(0x0C68));
        BUS16_SET(c, 0x004372, RAM16(0x0C6A));
        BUS16_SET(c, 0x004344, 0x207E);
        BUS16_SET(c, 0x004354, 0x207E);
        BUS16_SET(c, 0x004364, 0x207E);
        BUS16_SET(c, 0x004374, 0x207E);
        BUS8_SET(c, 0x00420B, 0xF0);
        BUS16_SET(c, 0x002116, 0x7540);
        BUS16_SET(c, 0x004342, RAM16(0x0C64));
        BUS16_SET(c, 0x004352, RAM16(0x0C66));
        BUS16_SET(c, 0x004362, RAM16(0x0C6C));
        uint16_t value63 = RAM16(0x0C6E);
        BUS16_SET(c, 0x004372, value63);
        BUS8_SET(c, 0x004345, 0x20);
        BUS8_SET(c, 0x004355, 0x20);
        BUS8_SET(c, 0x004365, 0x20);
        BUS8_SET(c, 0x004375, 0x20);
        BUS8_SET(c, 0x00420B, 0xF0);
        uint8_t a_hi17;
        if ((uint8_t)((uint8_t)value55 - 1) != 0) {
            uint8_t a_hi16;
            if ((uint8_t)((uint8_t)value55 - 2) == 0) {
                a_hi16 = value63 >> 8;
            } else {
                BUS16_SET(c, 0x002116, 0x7480);
                BUS16_SET(c, 0x004342, RAM16(0x0C70));
                BUS16_SET(c, 0x004352, RAM16(0x0C72));
                BUS16_SET(c, 0x004362, RAM16(0x0C78));
                BUS16_SET(c, 0x004372, RAM16(0x0C7A));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x7580);
                BUS16_SET(c, 0x004342, RAM16(0x0C74));
                BUS16_SET(c, 0x004352, RAM16(0x0C76));
                BUS16_SET(c, 0x004362, RAM16(0x0C7C));
                uint16_t value71 = RAM16(0x0C7E);
                BUS16_SET(c, 0x004372, value71);
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                uint8_t a_hi15;
                if ((uint8_t)((uint8_t)value55 - 3) != 0) {
                    uint8_t a_hi14;
                    if ((uint8_t)((uint8_t)value55 - 4) == 0) {
                        a_hi14 = value71 >> 8;
                    } else {
                        BUS16_SET(c, 0x002116, 0x74C0);
                        BUS16_SET(c, 0x004342, RAM16(0x0C80));
                        BUS16_SET(c, 0x004352, RAM16(0x0C82));
                        BUS16_SET(c, 0x004362, RAM16(0x0C88));
                        BUS16_SET(c, 0x004372, RAM16(0x0C8A));
                        BUS8_SET(c, 0x004345, 0x20);
                        BUS8_SET(c, 0x004355, 0x20);
                        BUS8_SET(c, 0x004365, 0x20);
                        BUS8_SET(c, 0x004375, 0x20);
                        BUS8_SET(c, 0x00420B, 0xF0);
                        BUS16_SET(c, 0x002116, 0x75C0);
                        BUS16_SET(c, 0x004342, RAM16(0x0C84));
                        BUS16_SET(c, 0x004352, RAM16(0x0C86));
                        BUS16_SET(c, 0x004362, RAM16(0x0C8C));
                        uint16_t value79 = RAM16(0x0C8E);
                        BUS16_SET(c, 0x004372, value79);
                        BUS8_SET(c, 0x004345, 0x20);
                        BUS8_SET(c, 0x004355, 0x20);
                        BUS8_SET(c, 0x004365, 0x20);
                        BUS8_SET(c, 0x004375, 0x20);
                        BUS8_SET(c, 0x00420B, 0xF0);
                        uint8_t a_hi13;
                        if ((uint8_t)((uint8_t)value55 - 5) != 0) {
                            uint8_t a_hi12;
                            if ((uint8_t)((uint8_t)value55 - 6) == 0) {
                                a_hi12 = value79 >> 8;
                            } else {
                                BUS16_SET(c, 0x002116, 0x7600);
                                BUS16_SET(c, 0x004342, RAM16(0x0C90));
                                BUS16_SET(c, 0x004352, RAM16(0x0C92));
                                BUS16_SET(c, 0x004362, RAM16(0x0C98));
                                BUS16_SET(c, 0x004372, RAM16(0x0C9A));
                                BUS8_SET(c, 0x004345, 0x20);
                                BUS8_SET(c, 0x004355, 0x20);
                                BUS8_SET(c, 0x004365, 0x20);
                                BUS8_SET(c, 0x004375, 0x20);
                                BUS8_SET(c, 0x00420B, 0xF0);
                                BUS16_SET(c, 0x002116, 0x7700);
                                BUS16_SET(c, 0x004342, RAM16(0x0C94));
                                BUS16_SET(c, 0x004352, RAM16(0x0C96));
                                BUS16_SET(c, 0x004362, RAM16(0x0C9C));
                                uint16_t value87 = RAM16(0x0C9E);
                                BUS16_SET(c, 0x004372, value87);
                                BUS8_SET(c, 0x004345, 0x20);
                                BUS8_SET(c, 0x004355, 0x20);
                                BUS8_SET(c, 0x004365, 0x20);
                                BUS8_SET(c, 0x004375, 0x20);
                                BUS8_SET(c, 0x00420B, 0xF0);
                                uint8_t a_hi11;
                                if ((uint8_t)((uint8_t)value55 - 7) == 0) {
                                    a_hi11 = value87 >> 8;
                                } else {
                                    uint8_t a_hi10;
                                    if ((uint8_t)((uint8_t)value55 - 8) == 0) {
                                        a_hi10 = value87 >> 8;
                                    } else {
                                        BUS16_SET(c, 0x002116, 0x7640);
                                        BUS16_SET(c, 0x004342, RAM16(0x0CA0));
                                        BUS16_SET(c, 0x004352, RAM16(0x0CA2));
                                        BUS16_SET(c, 0x004362, RAM16(0x0CA8));
                                        BUS16_SET(c, 0x004372, RAM16(0x0CAA));
                                        BUS8_SET(c, 0x004345, 0x20);
                                        BUS8_SET(c, 0x004355, 0x20);
                                        BUS8_SET(c, 0x004365, 0x20);
                                        BUS8_SET(c, 0x004375, 0x20);
                                        BUS8_SET(c, 0x00420B, 0xF0);
                                        BUS16_SET(c, 0x002116, 0x7740);
                                        BUS16_SET(c, 0x004342, RAM16(0x0CA4));
                                        BUS16_SET(c, 0x004352, RAM16(0x0CA6));
                                        BUS16_SET(c, 0x004362, RAM16(0x0CAC));
                                        uint16_t value95 = RAM16(0x0CAE);
                                        BUS16_SET(c, 0x004372, value95);
                                        BUS8_SET(c, 0x004345, 0x20);
                                        BUS8_SET(c, 0x004355, 0x20);
                                        BUS8_SET(c, 0x004365, 0x20);
                                        BUS8_SET(c, 0x004375, 0x20);
                                        BUS8_SET(c, 0x00420B, 0xF0);
                                        a_hi10 = value95 >> 8;
                                    }
                                    a_hi11 = a_hi10;
                                }
                                a_hi12 = a_hi11;
                            }
                            a_hi13 = a_hi12;
                        } else {
                            a_hi13 = value79 >> 8;
                        }
                        a_hi14 = a_hi13;
                    }
                    a_hi15 = a_hi14;
                } else {
                    a_hi15 = value71 >> 8;
                }
                a_hi16 = a_hi15;
            }
            a_hi17 = a_hi16;
        } else {
            a_hi17 = value63 >> 8;
        }
        a_hi18 = a_hi17;
        y4 = 0xF0;
    } else {
        a_hi18 = value55 >> 8;
        y4 = y3;
    }
    uint16_t value96 = RAM16(0xE08D);
    uint8_t a2;
    uint8_t a_hi20;
    uint8_t x2;
    uint8_t y6;
    bool zero2;
    bool negative2;
    if ((uint8_t)value96 == 0) {
        a2 = (uint8_t)value96;
        a_hi20 = value96 >> 8;
        x2 = (uint8_t)value96;
        y6 = y4;
        zero2 = (uint8_t)value96 == 0;
        negative2 = (uint8_t)value96 & 0x80;
    } else {
        RAM16_SET(0xE08D, value96 & 0xFF00);
        uint8_t a1 = (uint8_t)(value96 & 0xFF00);
        uint8_t a_hi19 = (value96 & 0xFF00) >> 8;
        uint8_t x1 = 4;
        uint8_t y5 = y4;
        bool zero1 = 0;
        bool negative1 = 0;
        for (;;) {
            BUS16_SET(c, 0x002116, 0x7640);
            BUS16_SET(c, 0x004342, RAM16(0x0CA0));
            BUS16_SET(c, 0x004352, RAM16(0x0CA2));
            BUS16_SET(c, 0x004362, RAM16(0x0CA8));
            BUS16_SET(c, 0x004372, RAM16(0x0CAA));
            BUS8_SET(c, 0x004345, 0x20);
            BUS8_SET(c, 0x004355, 0x20);
            BUS8_SET(c, 0x004365, 0x20);
            BUS8_SET(c, 0x004375, 0x20);
            BUS8_SET(c, 0x00420B, 0xF0);
            BUS16_SET(c, 0x002116, 0x7740);
            BUS16_SET(c, 0x004342, RAM16(0x0CA4));
            BUS16_SET(c, 0x004352, RAM16(0x0CA6));
            BUS16_SET(c, 0x004362, RAM16(0x0CAC));
            BUS16_SET(c, 0x004372, RAM16(0x0CAE));
            BUS8_SET(c, 0x004345, 0x20);
            BUS8_SET(c, 0x004355, 0x20);
            BUS8_SET(c, 0x004365, 0x20);
            BUS8_SET(c, 0x004375, 0x20);
            BUS8_SET(c, 0x00420B, 0xF0);
            uint16_t value105 = RAM16(0xE08D);
            if ((uint8_t)value105 != 0) {
                RAM16_SET(0xE08D, value105 & 0xFF00);
                a1 = (uint8_t)(value105 & 0xFF00);
                a_hi19 = (value105 & 0xFF00) >> 8;
                x1 = 4;
                y5 = 0xF0;
                zero1 = 0;
                negative1 = 0;
                continue;
            }
            a1 = (uint8_t)value105;
            a_hi19 = value105 >> 8;
            x1 = (uint8_t)value105;
            y5 = 0xF0;
            zero1 = (uint8_t)value105 == 0;
            negative1 = (uint8_t)value105 & 0x80;
            break;
        }
        a2 = a1;
        a_hi20 = a_hi19;
        x2 = x1;
        y6 = y5;
        zero2 = zero1;
        negative2 = negative1;
    }
    uint8_t value106 = RAM8(0x0000 + sp0 - 1);
    uint8_t value107 = RAM8(0x0000 + sp0);
    r->a = (a_hi20 << 8) | a2;
    r->x = x2;
    r->y = y6;
    r->c = carry;
    r->z = ((value107 << 8) | value106) == 0;
    r->n = ((value107 << 8) | value106) & 0x8000;
    r->v = overflow;
    r->dp = (value107 << 8) | value106;
    r->sp += 2;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC195BC, SOM_RTL, "gen", upload_three_hero_normal_tile_tables, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 1, 1039, 436)
