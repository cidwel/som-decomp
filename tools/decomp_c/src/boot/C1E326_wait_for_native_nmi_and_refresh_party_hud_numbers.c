#include "som_c.h"
#include "som_hand.h"

/* C1E326 wait_for_native_nmi_and_refresh_party_hud_numbers   [class A, 15 bytes, 9 instructions]
 * Source: src/rom/wait_for_native_nmi_and_refresh_party_hud_numbers.s
 * Documented in docs/graphics.md
 * Entry: M=any X=any DB=$7E D=$0000.  Callers read: BYCV.
 */
static void wait_for_native_nmi_and_refresh_party_hud_numbers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;

    /* SEP #$20, PHB, LDA #$00, PHA, PLB */
    RAM8(sp0) = r->db;
    RAM8((uint16_t)(sp0 - 1)) = 0x00;
    r->a = (r->a & 0xFF00) | 0x00;
    r->mf = 1;
    r->db = 0;
    r->sp = sp0 - 1;
    JSR(c, 0xE32F, 0xC1E0F9); /* request_frame_upload_and_wait_for_native_nmi */
    r->sp = sp0 - 1;
    JSR(c, 0xE332, 0xC1E339); /* write_party_hud_numbers */
    r->sp = sp0 - 1;
    hand_plb(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E326, SOM_RTS, "hand", wait_for_native_nmi_and_refresh_party_hud_numbers, 0, L_B | L_Y | L_C | L_V, 2, -1, -1, 15, 9)
