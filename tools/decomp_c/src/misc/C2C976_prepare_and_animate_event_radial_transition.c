#include "som_c.h"

/* C2C976 prepare_and_animate_event_radial_transition   [class B, 21 bytes, 11 instructions]
 * Source: src/rom/prepare_and_animate_event_radial_transition.s
 * Entry: M=any X=any DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void prepare_and_animate_event_radial_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    r->a = (a >> 8 << 8) | 0x7E;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC97F, 0xC2CB1A); GUARD_JSR(c, sp_call, 0xC97F); } /* prepare_event_radial_window_hdma */
    r->sp += 1;
    r->mf = 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC982, 0xC2CD67); GUARD_JSR(c, sp_call, 0xC982); } /* initialize_event_radial_particle_graphics_and_descriptors */
    r->sp += 1;
    r->mf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC985, 0xC2CB6F); GUARD_JSR(c, sp_call, 0xC985); } /* build_event_radial_curve_lookup */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC988, 0xC2C98B); GUARD_JSR(c, sp_call, 0xC988); } /* animate_event_radial_window_expand_and_contract */
    r->sp += 1;
    uint8_t value = RAM8(0x0000 + sp0);
    r->z = value == 0;
    r->n = value & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->db = value;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2C976, SOM_RTL, "gen", prepare_and_animate_event_radial_transition, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, -1, -1, 21, 11)
