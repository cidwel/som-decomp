#include "som_c.h"

/* C2478F move_auxiliary_record_until_native54_return_animation   [class B, 46 bytes, 20 instructions]
 * Source: src/rom/move_auxiliary_record_until_native54_return_animation.s
 * Documented in docs/boss-native54-motion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void move_auxiliary_record_until_native54_return_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    RAM8(0xF812 + y) = (uint8_t)(RAM8(0xF812 + y) + 2);
    uint8_t value2 = RAM8(0xF80E + y);
    RAM8(0xF80E + y) = (uint8_t)(value2 + 1);
    uint16_t value3 = RAM16(0xF811 + y);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value3 < 0xD800) {
        a1 = (uint8_t)value3;
        a_hi1 = value3 >> 8;
        zero1 = value3 == 0xD800;
        negative1 = (uint16_t)(value3 - 0xD800) & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + battle_defence_work, 8);
        r->a = 0x73;
        r->x = battle_defence_work;
        r->c = value3 >= 0xD800;
        r->v = ((value2 ^ (uint8_t)(value2 + 1)) & ((uint8_t)(value2 + 1) ^ 1) & 0x80) != 0;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x47BA, 0xC21394); GUARD_JSR(c, sp_call, 0x47BA); } /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all = r->a;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        zero1 = zero_ret;
        negative1 = negative_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = battle_defence_work;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = ((value2 ^ (uint8_t)(value2 + 1)) & ((uint8_t)(value2 + 1) ^ 1) & 0x80) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2478F, SOM_RTS, "gen", move_auxiliary_record_until_native54_return_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 46, 20)
