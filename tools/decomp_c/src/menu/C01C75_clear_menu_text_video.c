#include "som_c.h"

/* C01C75 clear_menu_text_video   [class D, 73 bytes, 28 instructions]
 * Source: src/rom/clear_menu_text_video.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void clear_menu_text_video(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    if ((RAM8(0xA187) & 1) == 0) {
        RAM8(0x1D04) &= 0x9F;
    }
    RAM8(0x1D04) &= 0xBF;
    RAM8(0x1D11) &= 0xF7;
    BUS16_SET(c, 0x002116, 0x5820);
    RAM16_SET(0x9000, 0);
    BUS16_SET(c, 0x004372, 0x9000);
    BUS16_SET(c, 0x004375, RAM16(0x1D1A));
    BUS8_SET(c, 0x004370, 9);
    BUS8_SET(c, 0x004371, 0x18);
    BUS8_SET(c, 0x004374, 0x7E);
    BUS8_SET(c, 0x00420B, 0x80);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01C75, SOM_RTS, "gen", clear_menu_text_video, 0, 0, 1, 1, 0, 73, 28)
