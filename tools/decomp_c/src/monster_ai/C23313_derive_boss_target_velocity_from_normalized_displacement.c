#include "som_c.h"

/* C23313 derive_boss_target_velocity_from_normalized_displacement   [class B, 95 bytes, 44 instructions]
 * Source: src/rom/derive_boss_target_velocity_from_normalized_displacement.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void derive_boss_target_velocity_from_normalized_displacement(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM16_SET(0x023C, a);
    uint16_t value = RAM16(0x00A9 + x);
    RAM16_SET(0x029D, RAM16(0x0002 + (uint16_t)((uint16_t)((((value & 0xFF) << 8) | 0) << 1) + 0xE000)));
    RAM16_SET(0x02A1, RAM16(0x0004 + (uint16_t)((uint16_t)((((value & 0xFF) << 8) | 0) << 1) + 0xE000)));
    uint16_t value4 = RAM16(0x0287);
    RAM16_SET(0x0295, RAM16(0x002B + value4));
    uint16_t value6 = RAM16(0x0032 + value4);
    RAM16_SET(0x0299, value6);
    r->a = value6;
    r->x = value4;
    JSR(c, 0x333A, 0xC22F61); /* normalize_boss_displacement_to_signed_fixed_point */
    RAM16_SET(0x0246, RAM16(0x02A5));
    RAM16_SET(0x0248, RAM16(0x02A7));
    RAM16_SET(0x0250, RAM16(0x023C));
    RAM16_SET(0x024E, 0);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x334B, 0xC22BC3); /* multiply_signed_double_words_to_quad_word */
    RAM16_SET(0x0295, RAM16(0x025A));
    RAM16_SET(0x0246, RAM16(0x02A9));
    RAM16_SET(0x0248, RAM16(0x02AB));
    RAM16_SET(0x0250, RAM16(0x023C));
    RAM16_SET(0x024E, 0);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3360, 0xC22BC3); /* multiply_signed_double_words_to_quad_word */
    RAM16_SET(0x0297, RAM16(0x025A));
    uint16_t value15 = RAM16(0x0287);
    RAM16_SET(0x003C + value15, RAM16(0x0295));
    RAM16_SET(0x0040 + value15, RAM16(0x0297));
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23313, SOM_RTS, "gen", derive_boss_target_velocity_from_normalized_displacement, 0, 0, 1, 0, 0, 95, 44)
