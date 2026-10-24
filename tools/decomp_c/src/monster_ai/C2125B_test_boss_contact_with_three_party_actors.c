#include "som_c.h"

/* C2125B test_boss_contact_with_three_party_actors   [class B, 71 bytes, 30 instructions]
 * Source: src/rom/test_boss_contact_with_three_party_actors.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: AB.
 */
static void test_boss_contact_with_three_party_actors(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0098 + x);
    uint8_t a4;
    uint8_t a_hi4;
    if ((value & 0x10) == 0) {
        a4 = (uint8_t)value;
        a_hi4 = value >> 8;
    } else {
        uint16_t value2 = RAM16(0x0066 + x);
        uint8_t a3;
        uint8_t a_hi3;
        if (value2 >= 0x40) {
            a3 = (uint8_t)value2;
            a_hi3 = value2 >> 8;
        } else {
            RAM16_SET(0x0246, RAM16(0x002B + x));
            RAM16_SET(0x024E, (uint16_t)(RAM16(0x0032 + x) + RAM16(0x00A5 + x)));
            uint16_t value6 = RAM16(0x001E + x);
            uint8_t a2;
            uint8_t a_hi2;
            if (value6 == 0) {
                a2 = (uint8_t)value6;
                a_hi2 = value6 >> 8;
            } else {
                uint16_t value7 = BUS16(c, 0xD97F09 + (uint16_t)(value6 << 1));
                RAM16_SET(0x0248, value7 & 0xFF);
                uint16_t value8 = BUS16(c, 0xD97F0A + (uint16_t)(value6 << 1));
                RAM16_SET(0x0250, value8 & 0xFF);
                uint8_t a1 = value8 & 0xFF;
                uint8_t a_hi1 = 0;
                uint16_t y1 = 0;
                for (;;) {
                    r->a = (a_hi1 << 8) | a1;
                    r->y = y1;
                    r->mf = 0;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0x0200;
                    JSR(c, 0x1297, 0xC212A2); /* prepare_and_test_one_party_actor_boss_contact */
                    uint16_t a_all = r->a;
                    a1 = (uint8_t)a_all;
                    a_hi1 = a_all >> 8;
                    y1 = (uint16_t)(y1 + 1);
                    if (!(y1 != 3)) break;
                }
                a2 = a1;
                a_hi2 = a_hi1;
            }
            a3 = a2;
            a_hi3 = a_hi2;
        }
        a4 = a3;
        a_hi4 = a_hi3;
    }
    r->a = (a_hi4 << 8) | a4;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2125B, SOM_RTS, "gen", test_boss_contact_with_three_party_actors, 0, L_A | L_B, 1, 0, 0, 71, 30)
