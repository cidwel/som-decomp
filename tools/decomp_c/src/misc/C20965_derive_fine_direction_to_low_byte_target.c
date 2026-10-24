#include "som_c.h"

/* C20965 derive_fine_direction_to_low_byte_target   [class A, 36 bytes, 17 instructions]
 * Source: src/rom/derive_fine_direction_to_low_byte_target.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABYV.
 */
static void derive_fine_direction_to_low_byte_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    RAM16_SET(0x0246, RAM16(0x0002 + (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)));
    RAM16_SET(0x024E, RAM16(0x0004 + (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)));
    uint16_t value3 = RAM16(0x0287);
    RAM16_SET(0x0256, RAM16(0x002B + value3));
    uint16_t value5 = RAM16(0x0032 + value3);
    RAM16_SET(0x025E, value5);
    r->a = value5;
    r->x = value3;
    r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    JSR(c, 0x0987, 0xC22E77); /* derive_fine_direction_from_coordinate_pairs */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20965, SOM_RTS, "gen", derive_fine_direction_to_low_byte_target, 0, L_A | L_B | L_Y | L_V, 1, 0, 0, 36, 17)
