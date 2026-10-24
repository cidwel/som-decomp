#include "som_c.h"

/* C2CE11 initialize_event_radial_particle_workspace   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/initialize_event_radial_particle_workspace.s
 * Documented in docs/event-menu-effect-preparation.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_event_radial_particle_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0x9E;
    bool zero1 = 0;
    bool negative1 = 0;
    for (;;) {
        uint16_t value = BUS16(c, 0x02CE21 + x1);
        RAM16_SET(0xF640 + x1, value);
        uint8_t a1_next = (uint8_t)value;
        uint8_t a_hi1_next = value >> 8;
        uint16_t x1_next = (uint16_t)(x1 - 1);
        bool zero1_next = (uint16_t)(x1 - 1) == 0;
        bool negative1_next = (uint16_t)(x1 - 1) & 0x8000;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        zero1 = zero1_next;
        negative1 = negative1_next;
        if (!(!negative1)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y;
    r->c = carry;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2CE11, SOM_RTS, "gen", initialize_event_radial_particle_workspace, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 16, 7)
