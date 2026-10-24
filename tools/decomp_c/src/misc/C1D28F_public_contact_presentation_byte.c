#include "som_c.h"

/* C1D28F public_contact_presentation_byte   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/public_contact_presentation_byte.s
 * Documented in docs/actor-party-map-contacts.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void public_contact_presentation_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xD291, 0xC1D285); /* record_contact_presentation_byte_and_volume */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1D28F, SOM_RTL, "gen", public_contact_presentation_byte, 0, L_B | L_Y | L_V, 1, 1, 0, 4, 2)
