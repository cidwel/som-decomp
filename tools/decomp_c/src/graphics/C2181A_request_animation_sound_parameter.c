#include "som_c.h"
#include "som_hand_b.h"

/* C2181A request_animation_sound_parameter   [class A, 13 bytes, 7 instructions]
 * Source: src/rom/request_animation_sound_parameter.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void request_animation_sound_parameter(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const uint32_t src = (uint32_t)((RAM8(0x0278) << 0x10) + RAM16(0x0276) + y);
    if (!hand_rd_ok(src) || !hand_rd_ok(src + 1)) { c->fail = 3; return; } /* open bus: out of contract */
    uint16_t value = BUS16(c, src);
    r->a = value;
    r->x = 0x0F;
    r->y = (uint16_t)(y + 2);
    JSR(c, 0x1823, 0xC230E3); /* request_boss_sound_with_parameter_word */
    uint16_t value2 = RAM16(0x0287);
    r->x = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0; /* request_boss_sound_with_parameter_word leaves the accumulator 16 bit */
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2181A, SOM_RTS, "hand", request_animation_sound_parameter, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 13, 7)
