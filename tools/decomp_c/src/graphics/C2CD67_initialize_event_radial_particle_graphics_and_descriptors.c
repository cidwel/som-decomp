#include "som_c.h"

/* C2CD67 initialize_event_radial_particle_graphics_and_descriptors   [class A, 9 bytes, 4 instructions]
 * Source: src/rom/initialize_event_radial_particle_graphics_and_descriptors.s
 * Documented in docs/event-menu-effect-graphics.md
 * Entry: M=8 bit X=any DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void initialize_event_radial_particle_graphics_and_descriptors(SomCtx *c)
{
    Cpu *r = &c->cpu;
    r->xf = false; /* REP: X becomes wide */
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD6B, 0xC2CD70); GUARD_JSR(c, sp_call, 0xCD6B); } /* upload_event_radial_particle_graphics */
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD6E, 0xC2CE11); GUARD_JSR(c, sp_call, 0xCD6E); } /* initialize_event_radial_particle_workspace */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2CD67, SOM_RTS, "hand", initialize_event_radial_particle_graphics_and_descriptors, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, -1, 9, 4)
