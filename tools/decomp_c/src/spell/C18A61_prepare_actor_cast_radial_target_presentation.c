#include "som_c.h"

/* C18A61 prepare_actor_cast_radial_target_presentation   [class B, 473 bytes, 200 instructions]
 * Source: src/rom/prepare_actor_cast_radial_target_presentation.s
 * Documented in docs/actor-cast-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void prepare_actor_cast_radial_target_presentation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    if (RAM8(0xE137 + x) == RAM8(0xE117 + x)) {
        RAM8(0xE130 + x) = 0;
    }
    if (RAM8(0xE127 + x) == RAM8(0xE117 + x)) {
        RAM8(0xE120 + x) = 0;
    }
    uint16_t value5 = RAM16(0xE110 + x);
    RAM16_SET(0xE120 + x, value5);
    RAM16_SET(0xE130 + x, value5);
    RAM16_SET(0xE12E + x, 0);
    RAM16_SET(0xE11E + x, 0);
    RAM16_SET(0xE13C + x, 0);
    RAM16_SET(0xE12C + x, 8);
    RAM16_SET(0xE11C + x, 0x10);
    RAM16_SET(0xE112 + x, 0);
    RAM16_SET(0xE122 + x, 0x0404);
    RAM16_SET(0xE132 + x, 0x0404);
    RAM16_SET(0xE124 + x, 0);
    uint16_t value6 = RAM16(0xE118 + x);
    RAM16_SET(0xE128 + x, value6);
    RAM16_SET(0xE138 + x, value6);
    RAM16_SET(0xE11A + x, RAM16(0xE12A + x));
    RAM16_SET(0x0300, 0x10);
    uint16_t y1 = x >> 1;
    do {
        RAM16_SET(0xC060 + y1, 0xCB00);
        RAM16_SET(0x0300, (uint16_t)(RAM16(0x0300) - 1));
        y1 = (uint16_t)(y1 + 2);
    } while (RAM16(0x0300) != 0);
    uint8_t value8 = RAM8(0xE010 + x);
    uint8_t a_hi3;
    bool overflow3;
    if (value8 == 0) {
        uint16_t value9 = RAM16(0xE11A + x);
        RAM16_SET(0xE12A + x, (uint16_t)(value9 - 0x0C));
        RAM16_SET(0xE13A + x, (uint16_t)(value9 - 0x1E));
        a_hi3 = (uint16_t)(value9 - 0x1E) >> 8;
        overflow3 = (((uint16_t)(value9 - 0x0C) ^ 0x12) & ((uint16_t)(value9 - 0x0C) ^ (uint16_t)(value9 - 0x1E)) & 0x8000) != 0;
    } else {
        uint8_t a_hi2;
        bool overflow2;
        if (value8 & 0x80) {
            uint16_t value10 = RAM16(0xE118 + x);
            RAM16_SET(0xE128 + x, (uint16_t)(value10 - 0x0C));
            RAM16_SET(0xE138 + x, (uint16_t)(value10 - 0x1E));
            a_hi2 = (uint16_t)(value10 - 0x1E) >> 8;
            overflow2 = (((uint16_t)(value10 - 0x0C) ^ 0x12) & ((uint16_t)(value10 - 0x0C) ^ (uint16_t)(value10 - 0x1E)) & 0x8000) != 0;
        } else {
            uint8_t a_hi1;
            bool overflow1;
            if ((uint16_t)(value8 - 1) == 0) {
                uint16_t value11 = RAM16(0xE11A + x);
                RAM16_SET(0xE12A + x, (uint16_t)(value11 + 0x0C));
                RAM16_SET(0xE13A + x, (uint16_t)(value11 + 0x1E));
                a_hi1 = (uint16_t)(value11 + 0x1E) >> 8;
                overflow1 = (((uint16_t)(value11 + 0x0C) ^ (uint16_t)(value11 + 0x1E)) & ((uint16_t)(value11 + 0x1E) ^ 0x12) & 0x8000) != 0;
            } else {
                uint16_t value12 = RAM16(0xE118 + x);
                RAM16_SET(0xE128 + x, (uint16_t)(value12 + 0x0C));
                RAM16_SET(0xE138 + x, (uint16_t)(value12 + 0x1E));
                a_hi1 = (uint16_t)(value12 + 0x1E) >> 8;
                overflow1 = (((uint16_t)(value12 + 0x0C) ^ (uint16_t)(value12 + 0x1E)) & ((uint16_t)(value12 + 0x1E) ^ 0x12) & 0x8000) != 0;
            }
            a_hi2 = a_hi1;
            overflow2 = overflow1;
        }
        a_hi3 = a_hi2;
        overflow3 = overflow2;
    }
    r->a = (a_hi3 << 8) | a;
    r->x = x;
    r->y = y1;
    r->c = 1;
    r->v = overflow3;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18A61, SOM_RTS, "gen", prepare_actor_cast_radial_target_presentation, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 565, 200)
