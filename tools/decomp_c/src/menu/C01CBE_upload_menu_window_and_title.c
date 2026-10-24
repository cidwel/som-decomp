#include "som_c.h"

/* C01CBE upload_menu_window_and_title   [class B, 32 bytes, 13 instructions]
 * Source: src/rom/upload_menu_window_and_title.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void upload_menu_window_and_title(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x1D11);
    bool x_flag;
    uint8_t a_hi1;
    if ((value & 4) == 0) {
        x_flag = 0;
        a_hi1 = a_hi;
    } else {
        r->a = a_hi << 8 | (value & 4);
        r->z = (value & 4) == 0;
        r->n = value & 4 & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1CC7, 0xC01D52); GUARD_JSR(c, sp_call, 0x1CC7); } /* upload_menu_title_and_padding */
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        x_flag = x_ret;
        a_hi1 = a_all >> 8;
    }
    uint8_t value2 = RAM8(0x1D04);
    bool x_flag2;
    if ((value2 & 2) == 0) {
        x_flag2 = x_flag;
    } else {
        r->a = a_hi1 << 8 | (value2 & 2);
        r->z = (value2 & 2) == 0;
        r->n = value2 & 2 & 0x80;
        r->xf = x_flag;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1CD1, 0xC01CDE); GUARD_JSR(c, sp_call, 0x1CD1); } /* upload_menu_two_row_window */
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1CD4, 0xC01D24); GUARD_JSR(c, sp_call, 0x1CD4); } /* upload_menu_single_window */
        bool x_ret5 = r->xf;
        RAM8(0x1D04) &= 0xF5;
        x_flag2 = x_ret5;
    }
    r->mf = 1;
    r->xf = x_flag2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01CBE, SOM_RTS, "gen", upload_menu_window_and_title, 0, 0, 1, 1, 0, 32, 13)
