#include "som_c.h"

/* C210D2 dispatch_boss_palette_command   [class B, 36 bytes, 16 instructions]
 * Source: src/rom/dispatch_boss_palette_command.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void dispatch_boss_palette_command(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    if (a != 0x80) {
        if (a != 0xB0) {
            if (a != 0xB4) {
                if (a != 0xC0) {
                    if (a != 0xC1) {
                        RETURN_RTS(c);
                    }
                    TAIL_CALL(c, 0xC211EC, SOM_RTS); /* request_boss_actor_cached_palette_reload */
                }
                TAIL_CALL(c, 0xC211C7, SOM_RTS); /* set_boss_actor_palettes_and_advance_command */
            }
            TAIL_CALL(c, 0xC21171, SOM_RTS); /* rotate_boss_actor_palette_group */
        }
        TAIL_CALL(c, 0xC2111C, SOM_RTS); /* copy_boss_actor_palette_group */
    }
    TAIL_CALL(c, 0xC210F6, SOM_RTS); /* reload_boss_actor_cached_palettes */
}
SOM_REGISTER(0xC210D2, SOM_RTS, "gen", dispatch_boss_palette_command, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 36, 16)
