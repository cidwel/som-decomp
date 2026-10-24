#include "som_c.h"

/* C2272C boss_loader_reserved_parameter_return   [class A, 1 bytes, 1 instructions]
 * Source: src/rom/boss_loader_reserved_parameter_return.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void boss_loader_reserved_parameter_return(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2272C, SOM_RTS, "gen", boss_loader_reserved_parameter_return, 0, 0, 1, 1, 0, 1, 1)
