#include "som_c.h"

/* C01479 copy_dialogue_font_page_and_publish_transfer   [class B, 77 bytes, 28 instructions]
 * Source: src/rom/copy_dialogue_font_page_and_publish_transfer.s
 * Documented in docs/event-dialogue-render-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void copy_dialogue_font_page_and_publish_transfer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA171) = 0x38;
    r->a = (a_hi << 8) | 0x38;
    r->x = 0x9400;
    r->y = 0x9000;
    JSR(c, 0x1486, 0xC014C6); /* copy_requested_dialogue_rows_to_upload_buffer */
    uint16_t x_ret = r->x;
    RAM16_SET(0x1D06, 0x4910);
    RAM16_SET(0xA18C, 0x4AD0);
    RAM16_SET(0xA18E, 0);
    r->a = 0x0380;
    r->c = 0;
    r->z = 0;
    r->n = 0;
    r->v = 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x14A2, 0xC01936); /* set_dialogue_graphics_transfer_size_preserving_status */
    bool overflow_ret = r->v;
    RAM16_SET(0xA189, 0x9000);
    uint16_t value = RAM16(0xA162);
    uint8_t a_hi1;
    uint16_t x1;
    bool overflow1;
    if ((value & 0xFF) != 2) {
        a_hi1 = 0;
        x1 = x_ret;
        overflow1 = overflow_ret;
    } else {
        RAM16_SET(0x1D06, 0x4F00);
        r->a = 0x0200;
        r->x = 0x4F00;
        r->c = (value & 0xFF) >= 2;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x14BF, 0xC01936); /* set_dialogue_graphics_transfer_size_preserving_status */
        bool overflow_ret2 = r->v;
        a_hi1 = 2;
        x1 = 0x4F00;
        overflow1 = overflow_ret2;
    }
    RAM8(0xA181) = 0;
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01479, SOM_RTS, "gen", copy_dialogue_font_page_and_publish_transfer, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 77, 28)
