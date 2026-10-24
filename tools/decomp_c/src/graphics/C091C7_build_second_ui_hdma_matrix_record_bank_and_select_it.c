#include "som_c.h"

/* C091C7 build_second_ui_hdma_matrix_record_bank_and_select_it   [class A, 8 bytes, 4 instructions]
 * Source: src/rom/build_second_ui_hdma_matrix_record_bank_and_select_it.s
 * Documented in docs/ui-native-ui-frame-hdma.md
 * Entry: M=any X=8 bit DB=any D=any.  Callers read: BXYCV.
 */
static void build_second_ui_hdma_matrix_record_bank_and_select_it(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 1)) return;
    const uint16_t dp = r->dp;
    JSR(c, 0x91C9, 0xC091CF); /* build_second_ui_hdma_matrix_record_bank */
    RAM8(0x0060 + dp) = 0x84;
    r->x = 0x84;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC091C7, SOM_RTS, "hand", build_second_ui_hdma_matrix_record_bank_and_select_it, 0, L_B | L_X | L_Y | L_C | L_V, 1, -1, 1, 8, 4)
