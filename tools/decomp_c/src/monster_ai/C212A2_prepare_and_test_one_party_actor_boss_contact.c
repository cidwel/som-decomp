#include "som_c.h"

/* C212A2 prepare_and_test_one_party_actor_boss_contact   [class B, 64 bytes, 29 instructions]
 * Source: src/rom/prepare_and_test_one_party_actor_boss_contact.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABY.
 */
static void prepare_and_test_one_party_actor_boss_contact(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    RAM16_SET(0x0295, (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000));
    uint16_t value = RAM16(0x0000 + (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000));
    uint8_t a1;
    uint8_t a_hi1;
    if (value != 1) {
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
    } else {
        RAM16_SET(0x0256, RAM16(0x0002 + (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000)));
        RAM16_SET(0x025E, RAM16(0x0004 + (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000)));
        RAM16_SET(0x025A, RAM16(0x0006 + (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000)));
        uint16_t value5 = RAM16(0x0089 + (uint16_t)((uint16_t)((((uint8_t)y << 8) | (y >> 8)) << 1) + 0xE000));
        uint16_t value6 = BUS16(c, 0xD97F09 + ((value5 & 3) + 1 << 1));
        RAM16_SET(0x0258, value6 & 0xFF);
        uint16_t value7 = BUS16(c, 0xD97F0A + ((value5 & 3) + 1 << 1));
        RAM16_SET(0x0260, value7 & 0xFF);
        r->a = value7 & 0xFF;
        JSR(c, 0x12E0, 0xC212E2); /* merge_boss_contact_direction_flags */
        uint16_t a_all = r->a;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
    }
    r->a = (a_hi1 << 8) | a1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC212A2, SOM_RTS, "gen", prepare_and_test_one_party_actor_boss_contact, 0, L_A | L_B | L_Y, 1, 0, 0, 64, 29)
