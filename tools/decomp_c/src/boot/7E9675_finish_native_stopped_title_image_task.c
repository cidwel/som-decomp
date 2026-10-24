#include "som_c.h"

/* 7E9675 finish_native_stopped_title_image_task   [class A, 24 bytes, 15 instructions]
 * Source: src/boot/finish_native_stopped_title_image_task.s
 * Documented in docs/boot-native-stopped-image-source.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$0500.  Callers read: ABXYCZNV.
 */
static void finish_native_stopped_title_image_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0500) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    r->x = 1;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    JSR(c, 0x9685, 0x7EABE7); /* receive_with_supplied_delay */
    r->sp += 4;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 4;
    JSR(c, 0x9688, 0x7E9660); /* release_colour_resources */
    r->sp += 4;
    r->c = carry;
    r->z = 0;
    r->n = 0;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7F;
    r->dp = 0x0500;
    RETURN_RTL(c);
}
SOM_REGISTER(0x7E9675, SOM_RTL, "gen", finish_native_stopped_title_image_task, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 24, 15)
