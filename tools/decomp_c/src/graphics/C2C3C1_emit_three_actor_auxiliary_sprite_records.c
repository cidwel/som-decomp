#include "som_c.h"

/* C2C3C1 emit_three_actor_auxiliary_sprite_records   [class B, 36 bytes, 23 instructions]
 * Source: src/rom/emit_three_actor_auxiliary_sprite_records.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void emit_three_actor_auxiliary_sprite_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    r->a = (x >> 3) + 0x10;
    r->y = x >> 3;
    r->c = (x >> 3) + 0x10 > 0xFFFF;
    r->v = (((x >> 3) ^ (x >> 3) + 0x10) & ((x >> 3) + 0x10 ^ 0x10) & 0x8000) != 0;
    r->mf = false;
    r->sp -= 4;
    JSR(c, 0xC3D0, 0xC2C3E5); /* emit_one_actor_auxiliary_sprite_record */
    r->sp += 4;
    r->a = (x >> 3) + 0x20;
    r->y = (x >> 3) + 0x10;
    r->c = (x >> 3) + 0x20 > 0xFFFF;
    r->v = (((x >> 3) + 0x10 ^ (x >> 3) + 0x20) & ((x >> 3) + 0x20 ^ 0x10) & 0x8000) != 0;
    r->mf = false;
    r->xf = false;
    r->sp -= 4;
    JSR(c, 0xC3DC, 0xC2C3E5); /* emit_one_actor_auxiliary_sprite_record */
    r->sp += 4;
    r->y = (x >> 3) + 0x20;
    r->mf = false;
    r->xf = false;
    r->sp -= 2;
    JSR(c, 0xC3E2, 0xC2C3E5); /* emit_one_actor_auxiliary_sprite_record */
    r->sp += 2;
    r->x = x;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2C3C1, SOM_RTL, "hand", emit_three_actor_auxiliary_sprite_records, 0, L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 36, 23)
