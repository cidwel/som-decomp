#include "som_c.h"

/* C21723 test_animation_movement_against_three_active_party_actors   [class B, 134 bytes, 59 instructions]
 * Source: src/rom/test_animation_movement_against_three_active_party_actors.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYC.
 */
static void test_animation_movement_against_three_active_party_actors(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0098 + x);
    if ((value & 0x10) == 0) {
        r->a = value;
        r->c = 0;
        RETURN_RTS(c);
    }
    uint16_t value2 = RAM16(0x0066 + x);
    if (value2 >= 0x40) {
        r->a = value2;
        r->c = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0246, RAM16(0x002B + x));
    RAM16_SET(0x024E, (uint16_t)(RAM16(0x0032 + x) + RAM16(0x00A5 + x)));
    uint16_t value6 = RAM16(0x001E + x);
    uint16_t value7 = BUS16(c, 0xD97F09 + (uint16_t)(value6 << 1));
    RAM16_SET(0x0248, value7 & 0xFF);
    uint16_t value8 = BUS16(c, 0xD97F0A + (uint16_t)(value6 << 1));
    RAM16_SET(0x0250, value8 & 0xFF);
    uint8_t a_hi1 = 0;
    uint16_t y1 = 0;
    for (;;) {
        uint16_t value9 = RAM16(0x0000 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
        if (value9 != 1) {
            if ((uint16_t)(y1 + 1) != 3) {
                a_hi1 = value9 >> 8;
                y1 = (uint16_t)(y1 + 1);
                continue;
            }
            a_hi1 = value9 >> 8;
            y1 = (uint16_t)(y1 + 1);
            break;
        }
        uint16_t value10 = RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
        if ((value10 & 0x8000) != 0) {
            if ((uint16_t)(y1 + 1) != 3) {
                a_hi1 = value10 >> 8;
                y1 = (uint16_t)(y1 + 1);
                continue;
            }
            a_hi1 = value10 >> 8;
            y1 = (uint16_t)(y1 + 1);
            break;
        }
        RAM16_SET(0x0256, RAM16(0x0002 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)));
        RAM16_SET(0x025E, RAM16(0x0004 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)));
        uint16_t value13 = RAM16(0x0089 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
        uint16_t value14 = BUS16(c, 0xD97F09 + ((value13 & 3) + 1 << 1));
        RAM16_SET(0x0258, value14 & 0xFF);
        uint16_t value15 = BUS16(c, 0xD97F0A + ((value13 & 3) + 1 << 1));
        RAM16_SET(0x0260, value15 & 0xFF);
        r->a = value15 & 0xFF;
        r->x = (value13 & 3) + 1 << 1;
        r->y = y1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        JSR(c, 0x179A, 0xC217A9); /* test_animation_party_radii_and_mark_contact_slot */
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        if (!carry_ret) {
            if ((uint16_t)(y1 + 1) != 3) {
                a_hi1 = a_all >> 8;
                y1 = (uint16_t)(y1 + 1);
                continue;
            }
            a_hi1 = a_all >> 8;
            y1 = (uint16_t)(y1 + 1);
            break;
        }
        r->c = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value16 = RAM16(0x0287);
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = value16;
    r->y = y1;
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21723, SOM_RTS, "gen", test_animation_movement_against_three_active_party_actors, 0, L_B | L_X | L_Y | L_C, 1, 0, 0, 134, 59)
