#include "som_c.h"

/* C1ADFD upload_high_monster_normal_tile_tables   [class D, 566 bytes, 236 instructions]
 * Source: src/rom/upload_high_monster_normal_tile_tables.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$4300.  Callers read: ABXYCZNV.
 */
static void upload_high_monster_normal_tile_tables(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x4300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    const uint8_t y = r->y;
    uint16_t value = RAM16(0xF283);
    uint8_t a_hi3;
    uint8_t y1;
    if ((uint8_t)value != 0) {
        BUS16_SET(c, 0x002116, 0x6A00);
        BUS16_SET(c, 0x004342, RAM16(0x0F20));
        BUS16_SET(c, 0x004352, RAM16(0x0F22));
        BUS16_SET(c, 0x004362, RAM16(0x0F28));
        BUS16_SET(c, 0x004372, RAM16(0x0F2A));
        uint16_t value6 = RAM16(0xF282);
        BUS16_SET(c, 0x004344, (value6 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004354, (value6 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004364, (value6 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004374, (value6 & 0xFF) | 0x2000);
        BUS8_SET(c, 0x00420B, 0xF0);
        BUS16_SET(c, 0x002116, 0x6B00);
        BUS16_SET(c, 0x004342, RAM16(0x0F24));
        BUS16_SET(c, 0x004352, RAM16(0x0F26));
        BUS16_SET(c, 0x004362, RAM16(0x0F2C));
        uint16_t value10 = RAM16(0x0F2E);
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
                BUS16_SET(c, 0x002116, 0x6A40);
                BUS16_SET(c, 0x004342, RAM16(0x0F30));
                BUS16_SET(c, 0x004352, RAM16(0x0F32));
                BUS16_SET(c, 0x004362, RAM16(0x0F38));
                BUS16_SET(c, 0x004372, RAM16(0x0F3A));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x6B40);
                BUS16_SET(c, 0x004342, RAM16(0x0F34));
                BUS16_SET(c, 0x004352, RAM16(0x0F36));
                BUS16_SET(c, 0x004362, RAM16(0x0F3C));
                uint16_t value18 = RAM16(0x0F3E);
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
    uint16_t value19 = RAM16(0xF483);
    uint8_t a_hi6;
    uint8_t y2;
    if ((uint8_t)value19 != 0) {
        BUS16_SET(c, 0x002116, 0x6A80);
        BUS16_SET(c, 0x004342, RAM16(0x0F40));
        BUS16_SET(c, 0x004352, RAM16(0x0F42));
        BUS16_SET(c, 0x004362, RAM16(0x0F48));
        BUS16_SET(c, 0x004372, RAM16(0x0F4A));
        uint16_t value24 = RAM16(0xF482);
        BUS16_SET(c, 0x004344, (value24 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004354, (value24 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004364, (value24 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004374, (value24 & 0xFF) | 0x2000);
        BUS8_SET(c, 0x00420B, 0xF0);
        BUS16_SET(c, 0x002116, 0x6B80);
        BUS16_SET(c, 0x004342, RAM16(0x0F44));
        BUS16_SET(c, 0x004352, RAM16(0x0F46));
        BUS16_SET(c, 0x004362, RAM16(0x0F4C));
        uint16_t value28 = RAM16(0x0F4E);
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
                BUS16_SET(c, 0x002116, 0x6AC0);
                BUS16_SET(c, 0x004342, RAM16(0x0F50));
                BUS16_SET(c, 0x004352, RAM16(0x0F52));
                BUS16_SET(c, 0x004362, RAM16(0x0F58));
                BUS16_SET(c, 0x004372, RAM16(0x0F5A));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x6BC0);
                BUS16_SET(c, 0x004342, RAM16(0x0F54));
                BUS16_SET(c, 0x004352, RAM16(0x0F56));
                BUS16_SET(c, 0x004362, RAM16(0x0F5C));
                uint16_t value36 = RAM16(0x0F5E);
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
    uint16_t value37 = RAM16(0xF683);
    uint8_t a3;
    uint8_t a_hi9;
    uint8_t x2;
    uint8_t y3;
    bool zero3;
    bool negative3;
    if ((uint8_t)value37 != 0) {
        BUS16_SET(c, 0x002116, 0x6C00);
        BUS16_SET(c, 0x004342, RAM16(0x0F60));
        BUS16_SET(c, 0x004352, RAM16(0x0F62));
        BUS16_SET(c, 0x004362, RAM16(0x0F68));
        BUS16_SET(c, 0x004372, RAM16(0x0F6A));
        uint16_t value42 = RAM16(0xF682);
        BUS16_SET(c, 0x004344, (value42 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004354, (value42 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004364, (value42 & 0xFF) | 0x2000);
        BUS16_SET(c, 0x004374, (value42 & 0xFF) | 0x2000);
        BUS8_SET(c, 0x00420B, 0xF0);
        BUS16_SET(c, 0x002116, 0x6D00);
        BUS16_SET(c, 0x004342, RAM16(0x0F64));
        BUS16_SET(c, 0x004352, RAM16(0x0F66));
        BUS16_SET(c, 0x004362, RAM16(0x0F6C));
        uint16_t value46 = RAM16(0x0F6E);
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
                BUS16_SET(c, 0x002116, 0x6C40);
                BUS16_SET(c, 0x004342, RAM16(0x0F70));
                BUS16_SET(c, 0x004352, RAM16(0x0F72));
                BUS16_SET(c, 0x004362, RAM16(0x0F78));
                BUS16_SET(c, 0x004372, RAM16(0x0F7A));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x6D40);
                BUS16_SET(c, 0x004342, RAM16(0x0F74));
                BUS16_SET(c, 0x004352, RAM16(0x0F76));
                BUS16_SET(c, 0x004362, RAM16(0x0F7C));
                uint16_t value54 = RAM16(0x0F7E);
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
SOM_REGISTER(0xC1ADFD, SOM_RTL, "gen", upload_high_monster_normal_tile_tables, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 1, 566, 236)
