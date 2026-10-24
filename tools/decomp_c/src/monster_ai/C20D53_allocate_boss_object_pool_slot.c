#include "som_c.h"

/* C20D53 allocate_boss_object_pool_slot   [class B, 95 bytes, 44 instructions]
 * Source: src/rom/allocate_boss_object_pool_slot.s
 * Documented in docs/maps.md
 * Entry: M=any X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void allocate_boss_object_pool_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM16_SET(0x0266, x);
    RAM16_SET(0x0268, y);
    uint8_t value = RAM8(0x0269);
    uint16_t x1;
    if ((value & 0x20) == 0) {
        x1 = 0;
    } else {
        x1 = 3;
    }
    uint8_t a_hi1 = a >> 8;
    uint16_t x2 = x1;
    for (;;) {
        uint8_t value2 = RAM8(0x0E60 + x2);
        if (value2 == 0) {
            RAM8(0x0E60 + x2) = 1;
            RAM16_SET(0x0098 + (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600), RAM16(0x0268));
            uint16_t value4 = RAM16(0x0266);
            RAM16_SET(0x0059 + (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600), 0);
            RAM16_SET(0x008E + (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600), value4);
            RAM16_SET(OBJECT_PHASE + (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600), 0);
            RAM16_SET(OBJECT_AGE + (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600), 0);
            RAM16_SET(0x00AD + (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600), 0);
            RAM16_SET(0x0090 + (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600), 0);
            RAM16_SET(0x0070 + (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600), 0);
            RAM16_SET(0x0062 + (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600), 0);
            RAM16_SET(0x00A3 + (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600), 0);
            RAM16_SET(0x0088 + (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600), 0);
            RAM16_SET(0x0018, 0);
            RAM16_SET(0x001A, 0);
            r->a = x2;
            r->x = (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600);
            r->y = y;
            r->c = 0;
            r->v = (((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600)) & ((uint16_t)((uint16_t)((((uint8_t)x2 << 8) | (x2 >> 8)) << 1) + 0xE600) ^ 0xE600) & 0x8000) != 0;
            r->mf = 0;
            RETURN_RTS(c);
        }
        if ((uint16_t)(x2 + 1) != 9) {
            x2 = (uint16_t)(x2 + 1);
            continue;
        }
        r->a = (a_hi1 << 8) | value2;
        r->x = (uint16_t)(x2 + 1);
        r->y = y;
        r->c = 1;
        r->v = overflow;
        r->mf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC20D53, SOM_RTS, "gen", allocate_boss_object_pool_slot, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, -1, 0, 95, 44)
