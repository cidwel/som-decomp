#include "som_c.h"

/* C7507F store_entered_hero_name_and_initialize_party_record   [class B, 97 bytes, 52 instructions]
 * Source: src/rom/store_entered_hero_name_and_initialize_party_record.s
 * Documented in docs/actor-hero-initialize.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BV.
 */
static void store_entered_hero_name_and_initialize_party_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0xA1CC);
    uint16_t value2 = RAM16(0xA22B);
    RAM16_SET(0xA173, (uint16_t)(value2 << 2));
    uint16_t value3 = RAM16(0xA173);
    uint8_t a1 = 0x0C;
    uint8_t a_hi1 = (uint16_t)((uint16_t)(value2 << 3) + value3) >> 8;
    uint16_t x1 = (uint16_t)((uint16_t)(value2 << 3) + value3);
    for (;;) {
        RAM8(0xCC00 + x1) = 0;
        a1 = (uint8_t)(a1 - 1);
        x1 = (uint16_t)(x1 + 1);
        if (!(a1 != 0)) break;
    }
    RAM8(0xA1CD) = 0;
    uint8_t a_hi2 = a_hi1;
    uint16_t x2 = 0xD2;
    uint16_t y1 = (uint16_t)((uint16_t)(value2 << 3) + value3);
    bool overflow1 = (((uint16_t)(value2 << 3) ^ (uint16_t)((uint16_t)(value2 << 3) + value3)) & (value3 ^ (uint16_t)((uint16_t)(value2 << 3) + value3)) & 0x8000) != 0;
    do {
        uint16_t value4 = RAM16(0x9000 + x2);
        uint8_t value5 = BUS8(c, 0xC774B2 + ((uint16_t)(value4 - 0x2058) >> 1));
        RAM8(0xCC00 + y1) = value5;
        RAM16_SET(0xA1CC, (uint16_t)(RAM16(0xA1CC) - 1));
        a_hi2 = (uint16_t)(value4 - 0x2058) >> 1 >> 8;
        x2 = (uint16_t)(x2 + 2);
        y1 = (uint16_t)(y1 + 1);
        overflow1 = ((value4 ^ 0x2058) & (value4 ^ (uint16_t)(value4 - 0x2058)) & 0x8000) != 0;
    } while (RAM16(0xA1CC) != 0);
    RAM8(0xA1CC) = value;
    uint16_t value6 = RAM16(0xA22B);
    r->a = (uint16_t)((((value6 & 0xFF) << 8) | 0) << 1);
    r->x = (uint16_t)((((value6 & 0xFF) << 8) | 0) << 1);
    r->c = (((value6 & 0xFF) << 8) | 0) & 0x8000;
    r->z = (uint16_t)((((value6 & 0xFF) << 8) | 0) << 1) == 0;
    r->n = (uint16_t)((((value6 & 0xFF) << 8) | 0) << 1) & 0x8000;
    r->v = overflow1;
    r->sp -= 1;
    JSL(c, 0x50DD, 0xC00039); /* initialize_hero_record_public_jump */
    r->sp += 1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC7507F, SOM_RTL, "gen", store_entered_hero_name_and_initialize_party_record, 0, L_B | L_V, 3, 1, 0, 97, 52)
