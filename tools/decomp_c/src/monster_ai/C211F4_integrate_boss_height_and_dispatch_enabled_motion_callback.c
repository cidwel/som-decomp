#include "som_c.h"

/* C211F4 integrate_boss_height_and_dispatch_enabled_motion_callback   [class C, 50 bytes, hand written]
 * docs/graphics.md.  Per-frame boss motion: integrates the vertical position when flag 0 of the object status word
 * ($0070,X) is set, then, unless motion is suppressed, jumps through the object's motion callback ($0090,X).
 * Motion is suppressed while bit 0 of the global word 7E:CFFF is set, while bit 6 of $1D04 is set, or when the high object
 * flag byte $0060,X equals $C0, and a zero callback pointer means "none".  The callback (bank C2) is entered with its
 * pointer in $0276 (D=$0200), and its RTS returns to the caller.
 * Entry: M=16 bit, DB=$7E, D=$0200, X = object.
 */
static void integrate_boss_height_and_dispatch_enabled_motion_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, -1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    a_lda(r, RAM16(0x0070 + x));
    a_biti(r, 0x0001);
    if (!r->z)
        JSR(c, 0x11FD, 0xC21226); /* integrate_boss_vertical_position_and_velocity */
    a_lda(r, RAM16(0xCFFF));
    a_biti(r, 0x0001);
    if (r->z) {
        a_lda(r, RAM16(0x1D04));
        a_biti(r, 0x0040);
        if (r->z) {
            a_lda(r, RAM16(0x0060 + x));
            a_and(r, 0x00FF);
            a_cmp(r, 0x00C0);
            if (!r->z) {
                a_lda(r, RAM16(0x0090 + x));
                if (!r->z) {
                    RAM16_SET(0x0276, r->a); /* STA $76 */
                    TAIL_CALL(c, 0xC20000 | r->a, SOM_RTS); /* JMP ($0276) */
                }
            }
        }
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC211F4, SOM_RTS, "hand", integrate_boss_height_and_dispatch_enabled_motion_callback, 0, L_ALL, 16, 0, -1, 50, 23)
