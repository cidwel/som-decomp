#include "som_c.h"

/* C29E6F move_party_target_toward_parent_offset_with_fixed_point_vector   [class B, 107 bytes, 47 instructions]
 * Source: src/rom/move_party_target_toward_parent_offset_with_fixed_point_vector.s
 * Documented in docs/boss-native-spell-pull-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYV.
 */
static void move_party_target_toward_parent_offset_with_fixed_point_vector(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x00B2 + battle_defence_work);
    RAM16_SET(0x0395, RAM16(0x0002 + value));
    RAM16_SET(0x0399, RAM16(0x0004 + value));
    uint16_t value4 = RAM16(0x00BE + battle_defence_work);
    uint8_t a_hi1;
    uint16_t y1;
    if (value4 != 0) {
        uint16_t value5 = RAM16(0x00B0 + battle_defence_work);
        RAM16_SET(0x039D, (uint16_t)(RAM16(0x002B + value5) + 0x50));
        uint16_t value7 = RAM16(0x0032 + value5);
        RAM16_SET(0x03A1, (uint16_t)(value7 + 0x28));
        a_hi1 = (uint16_t)(value7 + 0x28) >> 8;
        y1 = value5;
    } else {
        uint16_t value8 = RAM16(0x00B0 + battle_defence_work);
        RAM16_SET(0x039D, (uint16_t)(RAM16(0x002B + value8) - 0x50));
        uint16_t value10 = RAM16(0x0032 + value8);
        RAM16_SET(0x03A1, (uint16_t)(value10 + 0x28));
        a_hi1 = (uint16_t)(value10 + 0x28) >> 8;
        y1 = value8;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = battle_defence_work;
    r->y = y1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9EB1, 0xC22F61); GUARD_JSR(c, sp_call, 0x9EB1); } /* normalize_boss_displacement_to_signed_fixed_point */
    uint16_t value11 = RAM16(0x03A5);
    RAM16_SET(0x03A5, (uint16_t)(RAM16(0x03A5) << 1));
    RAM16_SET(0x03A7, (uint16_t)((RAM16(0x03A7) << 1) | (value11 >> 0x0F)));
    uint16_t value13 = RAM16(0x03A5);
    RAM16_SET(0x03A5, (uint16_t)(RAM16(0x03A5) << 1));
    RAM16_SET(0x03A7, (uint16_t)((RAM16(0x03A7) << 1) | (value13 >> 0x0F)));
    uint16_t value15 = RAM16(0x03A9);
    RAM16_SET(0x03A9, (uint16_t)(RAM16(0x03A9) << 1));
    RAM16_SET(0x03AB, (uint16_t)((RAM16(0x03AB) << 1) | (value15 >> 0x0F)));
    uint16_t value17 = RAM16(0x03A9);
    RAM16_SET(0x03A9, (uint16_t)(RAM16(0x03A9) << 1));
    RAM16_SET(0x03AB, (uint16_t)((RAM16(0x03AB) << 1) | (value17 >> 0x0F)));
    uint16_t battle_defence_work2 = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value19 = RAM16(0x00B2 + battle_defence_work2);
    RAM16_SET(0x0002 + value19, (uint16_t)(RAM16(0x03A7) + RAM16(0x0002 + value19)));
    uint16_t value22 = RAM16(0x03AB);
    uint16_t value23 = RAM16(0x0004 + value19);
    RAM16_SET(0x0004 + value19, (uint16_t)(value22 + value23));
    r->a = (uint16_t)(value22 + value23);
    r->x = battle_defence_work2;
    r->y = value19;
    r->v = ((value22 ^ (uint16_t)(value22 + value23)) & (value23 ^ (uint16_t)(value22 + value23)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29E6F, SOM_RTS, "gen", move_party_target_toward_parent_offset_with_fixed_point_vector, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 107, 47)
