#include "som_c.h"

/* C01C1A upload_menu_text_or_clear   [class D, 91 bytes, 36 instructions]
 * Source: src/rom/upload_menu_text_or_clear.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void upload_menu_text_or_clear(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    if (RAM8(0x1D05) != 7) {
        uint8_t value2 = RAM8(0x1D11);
        uint8_t a_hi1;
        if ((value2 & 8) == 0) {
            a_hi1 = a_hi;
        } else {
            JSR(c, 0x1C2A, 0xC01C75); /* clear_menu_text_video */
            uint16_t a_all = r->a;
            a_hi1 = a_all >> 8;
        }
        uint8_t value3 = RAM8(0x1D04);
        if ((value3 & 0x40) != 0) {
            uint8_t value4 = RAM8(0x1D11);
            uint16_t x1;
            if ((value4 & 1) == 0) {
                BUS16_SET(c, 0x002116, 0x5820);
                x1 = 0x9C00;
            } else {
                BUS16_SET(c, 0x002116, 0x5800);
                x1 = 0x9400;
            }
            BUS16_SET(c, 0x004372, x1);
            BUS16_SET(c, 0x004375, RAM16(0x1D1A));
            BUS8_SET(c, 0x004370, 1);
            BUS8_SET(c, 0x004371, 0x18);
            BUS8_SET(c, 0x004374, 0x7E);
            RAM8(0x1D04) = value3 & 0xBD;
            BUS8_SET(c, 0x00420B, 0x80);
        }
    }
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01C1A, SOM_RTS, "gen", upload_menu_text_or_clear, 0, 0, 1, 1, 0, 91, 36)
