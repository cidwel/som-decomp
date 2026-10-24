#include "som_c.h"

/* C24BC5 reset_body_motion_after_retraction_animation   [class A, 39 bytes, 16 instructions]
 * Source: src/rom/reset_body_motion_after_retraction_animation.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void reset_body_motion_after_retraction_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t value = RAM16(0x00B0 + RAM16(BATTLE_DEFENCE_WORK));
    RAM16_SET(0x00BC + value, (uint16_t)(RAM16(0x00BC + value) + 1));
    uint16_t battle_defence_work2 = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value2 = RAM16(0x009E + battle_defence_work2);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value2 != 0) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        zero1 = value2 == 0;
        negative1 = value2 & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + battle_defence_work2, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work2) + 1));
        RAM16_SET(OBJECT_AGE + battle_defence_work2, 0);
        RAM16_SET(0x003C + battle_defence_work2, 0);
        RAM16_SET(0x0040 + battle_defence_work2, 0);
        r->a = 0;
        r->x = battle_defence_work2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4BE6, 0xC21394); GUARD_JSR(c, sp_call, 0x4BE6); } /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all = r->a;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        RAM16_SET(0x001E + battle_defence_work2, 0);
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        zero1 = zero_ret;
        negative1 = negative_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = battle_defence_work2;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24BC5, SOM_RTS, "gen", reset_body_motion_after_retraction_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 39, 16)
