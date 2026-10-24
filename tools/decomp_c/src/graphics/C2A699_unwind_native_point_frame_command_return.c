#include "som_c.h"

/* C2A699 unwind_native_point_frame_command_return   [class C, 44 bytes, 24 instructions]
 * Source: src/rom/unwind_native_point_frame_command_return.s
 * Documented in docs/actor-visual-effect-point-producer.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXY.
 */
static void unwind_native_point_frame_command_return(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    r->y = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
    r->sp += 2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A699, SOM_RTS, "gen", unwind_native_point_frame_command_return, SOM_UNWINDS, L_B | L_X | L_Y, 2, 1, 0, 44, 24)
