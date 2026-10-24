#include "som_c.h"

/* C24F22 turn_body_heading_one_step_toward_target_with_opposite_rng_tie   [class B, 91 bytes, 44 instructions]
 * Source: src/rom/turn_body_heading_one_step_toward_target_with_opposite_rng_tie.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABX.
 */
static void turn_body_heading_one_step_toward_target_with_opposite_rng_tie(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0295, a);
    RAM16_SET(0x0297, RAM16(0x00BA + value));
    uint16_t value3 = RAM16(0x0295);
    uint16_t value4 = RAM16(0x0297);
    if ((uint16_t)(value3 - value4) == 0) {
        r->a = RAM16(0x00BA + value);
        r->x = value;
        RETURN_RTS(c);
    }
    if ((uint16_t)(value3 - value4) & 0x8000) {
        if ((uint16_t)(value3 - value4) == 0xFFFC) {
            r->a = 1;
            r->x = value;
            r->c = (uint16_t)(value3 - value4) >= 0xFFFC;
            r->v = ((value3 ^ value4) & (value3 ^ (uint16_t)(value3 - value4)) & 0x8000) != 0;
            JSR(c, 0x4F66, 0xC2300B); /* draw_boss_frame_random_number */
            bool zero_ret = r->z;
            if (zero_ret) {
                uint16_t value6 = RAM16(0x0287);
                r->a = (uint16_t)(RAM16(0x00BA + value6) + 1) & 7;
                r->x = value6;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value8 = RAM16(0x0287);
            r->a = (uint16_t)(RAM16(0x00BA + value8) - 1) & 7;
            r->x = value8;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint8_t a_hi1;
        if ((uint16_t)(value3 - value4) >= 0xFFFC) {
            a_hi1 = (uint16_t)(value3 - value4) >> 8;
        } else {
            RAM16_SET(0x0295, (uint16_t)(value3 + 8));
            a_hi1 = (uint16_t)(value3 + 8) >> 8;
        }
        if ((uint16_t)(RAM16(0x0295) - value4) & 0x8000) {
            r->a = (uint16_t)(RAM16(0x00BA + value) - 1) & 7;
            r->x = value;
            RETURN_RTS(c);
        }
        r->a = (uint16_t)(RAM16(0x00BA + value) + 1) & 7;
        r->x = value;
        RETURN_RTS(c);
    }
    if ((uint16_t)(value3 - value4) == 4) {
        r->a = 1;
        r->x = value;
        r->c = (uint16_t)(value3 - value4) >= 4;
        r->v = ((value3 ^ value4) & (value3 ^ (uint16_t)(value3 - value4)) & 0x8000) != 0;
        JSR(c, 0x4F66, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret2 = r->z;
        if (zero_ret2) {
            uint16_t value13 = RAM16(0x0287);
            r->a = (uint16_t)(RAM16(0x00BA + value13) + 1) & 7;
            r->x = value13;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value15 = RAM16(0x0287);
        r->a = (uint16_t)(RAM16(0x00BA + value15) - 1) & 7;
        r->x = value15;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t a_hi2;
    if ((uint16_t)(value3 - value4) < 4) {
        a_hi2 = (uint16_t)(value3 - value4) >> 8;
    } else {
        RAM16_SET(0x0297, (uint16_t)(value4 + 8));
        a_hi2 = (uint16_t)(value4 + 8) >> 8;
    }
    if ((uint16_t)(value3 - RAM16(0x0297)) & 0x8000) {
        r->a = (uint16_t)(RAM16(0x00BA + value) - 1) & 7;
        r->x = value;
        RETURN_RTS(c);
    }
    r->a = (uint16_t)(RAM16(0x00BA + value) + 1) & 7;
    r->x = value;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24F22, SOM_RTS, "gen", turn_body_heading_one_step_toward_target_with_opposite_rng_tie, 0, L_A | L_B | L_X, 1, 0, 0, 91, 44)
