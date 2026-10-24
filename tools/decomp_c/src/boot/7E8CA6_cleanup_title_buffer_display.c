#include "som_c.h"

/* 7E8CA6 cleanup_title_buffer_display   [class B, 116 bytes, 46 instructions]
 * Source: src/boot/cleanup_title_buffer_display.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$0600.  Callers read: XYCZNV.
 */
static void cleanup_title_buffer_display(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0600) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x1003A);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->sp -= 3;
    JSR(c, 0x8CB1, 0x7E9066); /* release_transfer_descriptor */
    r->sp += 3;
    r->x = 0x4A;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8CB7, 0x7E88CF); /* release_title_auxiliary_hdma */
    r->sp += 3;
    r->x = 0x46;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8CBD, 0x7E88CF); /* release_title_auxiliary_hdma */
    r->sp += 3;
    r->x = 0x42;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8CC3, 0x7E88CF); /* release_title_auxiliary_hdma */
    r->sp += 3;
    uint16_t value2 = RAM16(0x10040);
    r->x = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8CC9, 0x7E9066); /* release_transfer_descriptor */
    r->sp += 3;
    uint16_t value3 = RAM16(0x1003E);
    r->x = value3;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8CCF, 0x7E9066); /* release_transfer_descriptor */
    r->sp += 3;
    uint16_t value4 = RAM16(0x1003C);
    r->x = value4;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8CD5, 0x7E9066); /* release_transfer_descriptor */
    r->sp += 3;
    uint16_t a_all7 = r->a;
    r->a = (a_all7 >> 8 << 8) | 0x26;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8CDA, 0x7EC030); /* allocate_ppu_register_entry */
    r->sp += 3;
    uint16_t x_ret8 = r->x;
    RAM8(0x10002 + x_ret8) = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8CE2, 0x7EC097); /* append_oneshot_ppu_entry */
    r->sp += 3;
    uint16_t a_all9 = r->a;
    r->a = (a_all9 >> 8 << 8) | 0x30;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8CE7, 0x7EC030); /* allocate_ppu_register_entry */
    r->sp += 3;
    uint16_t x_ret9 = r->x;
    RAM8(0x10002 + x_ret9) = 0x30;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8CEF, 0x7EC097); /* append_oneshot_ppu_entry */
    r->sp += 3;
    uint16_t a_all11 = r->a;
    r->a = (a_all11 >> 8 << 8) | 0x31;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8CF4, 0x7EC030); /* allocate_ppu_register_entry */
    r->sp += 3;
    uint16_t x_ret10 = r->x;
    RAM8(0x10002 + x_ret10) = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8CFC, 0x7EC097); /* append_oneshot_ppu_entry */
    r->sp += 3;
    uint16_t a_all13 = r->a;
    r->a = (a_all13 >> 8 << 8) | 0x2E;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8D01, 0x7EC030); /* allocate_ppu_register_entry */
    r->sp += 3;
    uint16_t x_ret11 = r->x;
    RAM8(0x10002 + x_ret11) = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8D09, 0x7EC097); /* append_oneshot_ppu_entry */
    r->sp += 3;
    uint16_t a_all15 = r->a;
    r->a = (a_all15 >> 8 << 8) | 0x23;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8D0E, 0x7EC030); /* allocate_ppu_register_entry */
    r->sp += 3;
    uint16_t x_ret12 = r->x;
    RAM8(0x10002 + x_ret12) = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x8D16, 0x7EC097); /* append_oneshot_ppu_entry */
    r->sp += 3;
    r->c = carry;
    r->z = 0;
    r->n = 0;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E8CA6, SOM_RTS, "gen", cleanup_title_buffer_display, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 116, 46)
