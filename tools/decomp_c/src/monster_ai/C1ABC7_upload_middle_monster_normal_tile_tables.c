#include "som_c.h"

/* C1ABC7 upload_middle_monster_normal_tile_tables   [class D, 566 bytes, 236 instructions]
 * Source: src/rom/upload_middle_monster_normal_tile_tables.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$4300.  Callers read: ABXYCZNV.
 */
static void upload_middle_monster_normal_tile_tables(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x4300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    const uint8_t y = r->y;
    uint16_t value = RAM16(0xEC83);
    uint8_t a_hi3;
    uint8_t y1;
    if ((uint8_t)value != 0) {
        BUS16_SET(c, 0x002116, 0x6680);
        BUS16_SET(c, 0x004342, RAM16(0x0EC0));
        BUS16_SET(c, 0x004352, RAM16(0x0EC2));
        BUS16_SET(c, 0x004362, RAM16(0x0EC8));
        BUS16_SET(c, 0x004372, RAM16(0x0ECA));
        uint16_t value6 = RAM16(0xEC82);
        BUS16_SET(c, 0x004344, (value6 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004354, (value6 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004364, (value6 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004374, (value6 & 0xFF) | 0x2000);
        BUS8_SET(c, 0x00420B, 0xF0);
        BUS16_SET(c, 0x002116, 0x6780);
        BUS16_SET(c, 0x004342, RAM16(0x0EC4));
        BUS16_SET(c, 0x004352, RAM16(0x0EC6));
        BUS16_SET(c, 0x004362, RAM16(0x0ECC));
        uint16_t value10 = RAM16(0x0ECE);
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
                BUS16_SET(c, 0x002116, 0x66C0);
                BUS16_SET(c, 0x004342, RAM16(0x0ED0));
                BUS16_SET(c, 0x004352, RAM16(0x0ED2));
                BUS16_SET(c, 0x004362, RAM16(0x0ED8));
                BUS16_SET(c, 0x004372, RAM16(0x0EDA));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x67C0);
                BUS16_SET(c, 0x004342, RAM16(0x0ED4));
                BUS16_SET(c, 0x004352, RAM16(0x0ED6));
                BUS16_SET(c, 0x004362, RAM16(0x0EDC));
                uint16_t value18 = RAM16(0x0EDE);
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
    uint16_t value19 = RAM16(0xEE83);
    uint8_t a_hi6;
    uint8_t y2;
    if ((uint8_t)value19 != 0) {
        BUS16_SET(c, 0x002116, 0x6800);
        BUS16_SET(c, 0x004342, RAM16(0x0EE0));
        BUS16_SET(c, 0x004352, RAM16(0x0EE2));
        BUS16_SET(c, 0x004362, RAM16(0x0EE8));
        BUS16_SET(c, 0x004372, RAM16(0x0EEA));
        uint16_t value24 = RAM16(0xEE82);
        BUS16_SET(c, 0x004344, (value24 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004354, (value24 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004364, (value24 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004374, (value24 & 0xFF) | 0x2000);
        BUS8_SET(c, 0x00420B, 0xF0);
        BUS16_SET(c, 0x002116, 0x6900);
        BUS16_SET(c, 0x004342, RAM16(0x0EE4));
        BUS16_SET(c, 0x004352, RAM16(0x0EE6));
        BUS16_SET(c, 0x004362, RAM16(0x0EEC));
        uint16_t value28 = RAM16(0x0EEE);
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
                BUS16_SET(c, 0x002116, 0x6840);
                BUS16_SET(c, 0x004342, RAM16(0x0EF0));
                BUS16_SET(c, 0x004352, RAM16(0x0EF2));
                BUS16_SET(c, 0x004362, RAM16(0x0EF8));
                BUS16_SET(c, 0x004372, RAM16(0x0EFA));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x6940);
                BUS16_SET(c, 0x004342, RAM16(0x0EF4));
                BUS16_SET(c, 0x004352, RAM16(0x0EF6));
                BUS16_SET(c, 0x004362, RAM16(0x0EFC));
                uint16_t value36 = RAM16(0x0EFE);
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
    uint16_t value37 = RAM16(0xF083);
    uint8_t a3;
    uint8_t a_hi9;
    uint8_t x2;
    uint8_t y3;
    bool zero3;
    bool negative3;
    if ((uint8_t)value37 != 0) {
        BUS16_SET(c, 0x002116, 0x6880);
        BUS16_SET(c, 0x004342, RAM16(0x0F00));
        BUS16_SET(c, 0x004352, RAM16(0x0F02));
        BUS16_SET(c, 0x004362, RAM16(0x0F08));
        BUS16_SET(c, 0x004372, RAM16(0x0F0A));
        uint16_t value42 = RAM16(0xF082);
        BUS16_SET(c, 0x004344, (value42 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004354, (value42 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004364, (value42 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004374, (value42 & 0xFF) | 0x2000);
        BUS8_SET(c, 0x00420B, 0xF0);
        BUS16_SET(c, 0x002116, 0x6980);
        BUS16_SET(c, 0x004342, RAM16(0x0F04));
        BUS16_SET(c, 0x004352, RAM16(0x0F06));
        BUS16_SET(c, 0x004362, RAM16(0x0F0C));
        uint16_t value46 = RAM16(0x0F0E);
        BUS16_SET(c, 0x004372, value46);
        BUS8_SET(c, 0x004345, 0x20);
        BUS8_SET(c, 0x004355, 0x20);
        BUS8_SET(c, 0x004365, 0x20);
        BUS8_SET(c, 0x004375, 0x20);
        BUS8_SET(c, 0x00420B, 0xF0);
        uint8_t a2;
        uint8_t a_hi8;
        uint8_t x1;
        bool zero2;
        bool negative2;
        if ((uint8_t)((uint8_t)value37 - 1) == 0) {
            a2 = (uint8_t)value46;
            a_hi8 = value46 >> 8;
            x1 = (uint8_t)((uint8_t)value37 - 1);
            zero2 = (uint8_t)((uint8_t)value37 - 1) == 0;
            negative2 = (uint8_t)((uint8_t)value37 - 1) & 0x80;
        } else {
            uint8_t a1;
            uint8_t a_hi7;
            bool zero1;
            bool negative1;
            if ((uint8_t)((uint8_t)value37 - 2) == 0) {
                a1 = (uint8_t)value46;
                a_hi7 = value46 >> 8;
                zero1 = (uint8_t)((uint8_t)value37 - 2) == 0;
                negative1 = (uint8_t)((uint8_t)value37 - 2) & 0x80;
            } else {
                BUS16_SET(c, 0x002116, 0x68C0);
                BUS16_SET(c, 0x004342, RAM16(0x0F10));
                BUS16_SET(c, 0x004352, RAM16(0x0F12));
                BUS16_SET(c, 0x004362, RAM16(0x0F18));
                BUS16_SET(c, 0x004372, RAM16(0x0F1A));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x69C0);
                BUS16_SET(c, 0x004342, RAM16(0x0F14));
                BUS16_SET(c, 0x004352, RAM16(0x0F16));
                BUS16_SET(c, 0x004362, RAM16(0x0F1C));
                uint16_t value54 = RAM16(0x0F1E);
                BUS16_SET(c, 0x004372, value54);
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                a1 = (uint8_t)value54;
                a_hi7 = value54 >> 8;
                zero1 = 0;
                negative1 = 1;
            }
            a2 = a1;
            a_hi8 = a_hi7;
            x1 = (uint8_t)((uint8_t)value37 - 2);
            zero2 = zero1;
            negative2 = negative1;
        }
        a3 = a2;
        a_hi9 = a_hi8;
        x2 = x1;
        y3 = 0xF0;
        zero3 = zero2;
        negative3 = negative2;
    } else {
        a3 = (uint8_t)value37;
        a_hi9 = value37 >> 8;
        x2 = (uint8_t)value37;
        y3 = y2;
        zero3 = (uint8_t)value37 == 0;
        negative3 = (uint8_t)value37 & 0x80;
    }
    uint8_t value55 = RAM8(0x0000 + sp0 - 1);
    uint8_t value56 = RAM8(0x0000 + sp0);
    r->a = (a_hi9 << 8) | a3;
    r->x = x2;
    r->y = y3;
    r->z = ((value56 << 8) | value55) == 0;
    r->n = ((value56 << 8) | value55) & 0x8000;
    r->dp = (value56 << 8) | value55;
    r->sp += 2;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1ABC7, SOM_RTL, "gen", upload_middle_monster_normal_tile_tables, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 1, 566, 236)
