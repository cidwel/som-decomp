#include "som_c.h"

/* C01BF7 upload_complete_menu_frame   [class A, 35 bytes, 19 instructions]
 * Source: src/rom/upload_complete_menu_frame.s
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: CV.
 */
static void upload_complete_menu_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t x_entry = r->xf;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = (((((negative << 7) | (overflow << 6) | 0x20) | (x_entry << 4)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = 0;
    r->a = (a_hi << 8) | 0;
    r->z = 1;
    r->n = 0;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1C03, 0xC01CBE); GUARD_JSR(c, sp_call, 0x1C03); } /* upload_menu_window_and_title */
    r->sp += 2;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1C06, 0xC01C1A); GUARD_JSR(c, sp_call, 0x1C06); } /* upload_menu_text_or_clear */
    r->sp += 2;
    if (r->mf != 1) { c->fail = 3; return; }
    uint8_t value = RAM8(0x1D05);
    uint8_t a1;
    if (value != 7) {
        a1 = 0x5E;
    } else {
        a1 = 0x5A;
    }
    RAM8(0x1D04) &= (a1 ^ 0xFF);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->c = value4 & 0x01;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value3;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC01BF7, SOM_RTL, "gen", upload_complete_menu_frame, 0, L_C | L_V, 3, 1, -1, 35, 19)
