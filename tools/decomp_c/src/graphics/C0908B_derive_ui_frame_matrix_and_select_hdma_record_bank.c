#include "som_c.h"

/* C0908B derive_ui_frame_matrix_and_select_hdma_record_bank   [class B, 111 bytes, 53 instructions]
 * Source: src/rom/derive_ui_frame_matrix_and_select_hdma_record_bank.s
 * Documented in docs/ui-native-ui-frame-hdma.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void derive_ui_frame_matrix_and_select_hdma_record_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->a = RAM16(0x00F6);
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9091, 0xC09368); GUARD_JSR(c, sp_call, 0x9091); } /* derive_world_map_ui_curve_coefficients_and_fraction_bytes */
    r->mf = 0;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9094, 0xC09332); GUARD_JSR(c, sp_call, 0x9094); } /* derive_world_map_ui_quadrant_offsets */
    uint16_t a_all2 = r->a;
    uint8_t value2 = RAM8(0x00F2);
    if (!(value2 & 0x80)) {
        BUS8_SET(c, 0x004204, 0);
        BUS8_SET(c, 0x004205, 0x0F);
        uint8_t value3 = RAM8(0x00F8);
        BUS8_SET(c, 0x004206, value3 >> 2);
        RAM8(0x0006) = 0;
        uint8_t value4 = RAM8(0x00FC);
        RAM8(0x0007) = (uint8_t)(value4 - 0x28);
        RAM8(0x0008) = (uint8_t)((RAM8(0x00FD) & 3) - 1 - (value4 >= 0x28 ^ 1));
        uint8_t value6 = BUS8(c, 0x004214);
        RAM8(0x0004) = value6;
        uint8_t value7 = BUS8(c, 0x004215);
        RAM8(0x0005) = value7;
        BUS8_SET(c, 0x004204, 0);
        BUS8_SET(c, 0x004205, value3 >> 2);
        RAM8(0x0000) = (value3 >> 2) + 1;
        BUS8_SET(c, 0x004206, (value3 >> 2) + 1);
        uint8_t a1;
        if ((value3 >> 2) + 1 >= 0x18) {
            a1 = (uint8_t)((value3 >> 2) - 0x17);
        } else {
            a1 = 0;
        }
        RAM8(0x0010) = a1;
        uint8_t value8 = RAM8(0x0060);
        if ((value8 & 4) != 0) {
            r->a = (a_all2 >> 8 << 8) | 4;
            r->x = 2;
            r->c = (value3 >> 2) + 1 >= 0x18;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x90F4, 0xC090FA); GUARD_JSR(c, sp_call, 0x90F4); } /* build_first_ui_hdma_matrix_record_bank */
            RAM8(0x0060) = 0x80;
            r->x = 0x80;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        }
        r->a = (a_all2 >> 8 << 8) | 4;
        r->x = 2;
        r->y = 0;
        r->c = (value3 >> 2) + 1 >= 0x18;
        r->v = value8 & 0x40;
        r->mf = 0;
        r->xf = 1;
        TAIL_CALL(c, 0xC091C7, SOM_RTS); /* build_second_ui_hdma_matrix_record_bank_and_select_it */
    }
    r->v = value2 & 0x40;
    r->mf = 1;
    r->xf = 1;
    TAIL_CALL(c, 0xC0929C, SOM_RTS); /* derive_ui_affine_or_automatic_motion_scale_coefficients */
}
SOM_REGISTER(0xC0908B, SOM_RTS, "gen", derive_ui_frame_matrix_and_select_hdma_record_bank, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, -1, 111, 53)
