#include "som_c.h"

/* C2272D allocate_boss_palette_transition_object   [class C, 31 bytes, 18 instructions]
 * Source: src/rom/allocate_boss_palette_transition_object.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void allocate_boss_palette_transition_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    r->x = 0x274C;
    r->y = 0x6000;
    r->sp -= 6;
    JSR(c, 0x2738, 0xC20D53); /* allocate_boss_object_pool_slot */
    r->sp += 6;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    if (carry_ret) {
        r->a = a;
        r->x = x;
        r->y = y;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x009E + x_ret, y);
    RAM16_SET(0x009C + x_ret, x);
    RAM16_SET(0x009A + x_ret, a);
    r->a = a;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2272D, SOM_RTS, "gen", allocate_boss_palette_transition_object, 0, L_B | L_X | L_Y | L_C | L_V, 6, 0, 0, 31, 18)
