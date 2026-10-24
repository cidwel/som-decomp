#include "som_c.h"

/* D04EAC select_cast_level_with_grade_eight_progress   [class B, 36 bytes, 18 instructions]
 * Source: src/rom/select_cast_level_with_grade_eight_progress.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BYCV.
 */
static void select_cast_level_with_grade_eight_progress(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    if ((RAM8(ACTOR_KIND_FLAGS + x) & 0xC0) != 0) {
        uint8_t value2 = RAM8(0x039D);
        if (value2 != 8) {
            RAM8(0xE171 + x) = value2;
            r->c = value2 >= 8;
            RETURN_RTS(c);
        }
        r->a = (a_hi << 8) | value2;
        r->c = value2 >= 8;
        r->z = value2 == 8;
        r->n = (uint8_t)(value2 - 8) & 0x80;
        JSL(c, 0x4EC2, 0xC0389C); /* random_byte_long_wrapper */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint8_t value3 = RAM8(0x039E);
        if (((uint8_t)a_all >> 1) + 1 < value3) {
            RAM8(0xE171 + x_ret) = RAM8(0x039D);
            r->c = ((uint8_t)a_all >> 1) + 1 >= value3;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM8(0xE171 + x_ret) = (uint8_t)(RAM8(0x039D) - 1);
        r->c = ((uint8_t)a_all >> 1) + 1 >= value3;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM8(0xE171 + x) = RAM8(0x039D);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD04EAC, SOM_RTS, "gen", select_cast_level_with_grade_eight_progress, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 36, 18)
