#include "som_c.h"
#include "som_hand_d.h"

/* C0F4AB advance_three_hero_animations_and_primary_geometry   [class B, 32 bytes, 15 instructions]
 * Source: src/rom/advance_three_hero_animations_and_primary_geometry.s
 * Documented in docs/actor-animation-step.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_three_hero_animations_and_primary_geometry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 0x7E;
    r->x = 0;
    r->db = 0x7E;
    r->sp -= 1;
    JSR(c, 0xF4B9, 0xC0F4CB); /* advance_actor_animation_and_resume_native_frame_stream */
    r->sp += 1;
    REQUIRE_X16(c); /* the next LDX is assembled for a 16-bit index */
    r->x = 0x0200;
    r->sp -= 1;
    JSR(c, 0xF4BF, 0xC0F4CB); /* advance_actor_animation_and_resume_native_frame_stream */
    r->sp += 1;
    REQUIRE_X16(c);
    r->x = 0x0400;
    r->sp -= 1;
    JSR(c, 0xF4C5, 0xC0F4CB); /* advance_actor_animation_and_resume_native_frame_stream */
    JSR(c, 0xF4C8, 0xC0F1C7); /* publish_primary_hero_frame_geometry */
    r->sp += 1;
    r->db = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0F4AB, SOM_RTS, "hand", advance_three_hero_animations_and_primary_geometry, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 32, 15)
