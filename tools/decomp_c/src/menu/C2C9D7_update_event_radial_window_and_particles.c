#include "som_c.h"

/* C2C9D7 update_event_radial_window_and_particles   [class B, 33 bytes, 15 instructions]
 * Source: src/rom/update_event_radial_window_and_particles.s
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: BXY.
 */
static void update_event_radial_window_and_particles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC9D9, 0xC2C9E0); GUARD_JSR(c, sp_call, 0xC9D9); } /* update_event_radial_window_and_wait_frame */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC9DC, 0xC2CD55); GUARD_JSR(c, sp_call, 0xC9DC); } /* clear_event_radial_particle_oam */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    BUS16_SET(c, (uint16_t)(dp + 8), 0);
    uint8_t a_hi1 = a_all2 >> 8;
    uint16_t x1 = x_ret2;
    uint16_t y1 = 0;
    for (;;) {
        r->a = (a_hi1 << 8) | (uint8_t)a;
        r->x = x1;
        r->y = y1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = dp;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCBF8, 0xC2CC07); GUARD_JSR(c, sp_call, 0xCBF8); } /* update_and_emit_event_radial_particle */
        uint16_t x_ret3 = r->x;
        uint8_t a_hi1_next = (uint16_t)(y1 + 8) >> 8;
        uint16_t x1_next = x_ret3;
        uint16_t y1_next = (uint16_t)(y1 + 8);
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        if (!(y1 < 0xA0)) break;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = x1;
    r->y = y1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C9D7, SOM_RTS, "gen", update_event_radial_window_and_particles, 0, L_B | L_X | L_Y, 1, -1, 0, 560, 15)
