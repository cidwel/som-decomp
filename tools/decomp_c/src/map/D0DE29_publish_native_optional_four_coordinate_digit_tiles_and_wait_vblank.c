#include "som_c.h"

/* D0DE29 publish_native_optional_four_coordinate_digit_tiles_and_wait_vblank   [class B, 89 bytes, 31 instructions]
 * Source: src/rom/publish_native_optional_four_coordinate_digit_tiles_and_wait_vblank.s
 * Documented in docs/event-menu-coordinates.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void publish_native_optional_four_coordinate_digit_tiles_and_wait_vblank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0xCFF5);
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value & 0xFF) == 0) {
        x_flag = 0;
        a1 = value & 0xFF;
        a_hi1 = 0;
        x1 = x;
        y1 = y;
        carry1 = carry;
        zero1 = (value & 0xFF) == 0;
        negative1 = value & 0xFF & 0x8000;
        overflow1 = overflow;
        data_bank = 0;
        direct_page = 0;
    } else {
        RAM16_SET(0x09FC, 0xB010);
        RAM16_SET(0x09FE, 0x3350);
        uint16_t value2 = RAM16(0xE002);
        r->a = value2;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDE46, 0xD0DEE1); GUARD_JSR(c, sp_call, 0xDE46); } /* split_native_coordinate_word_into_two_digit_selectors */
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        RAM8(0x1880) = (uint8_t)a_all;
        RAM8(0x1881) = (uint8_t)y_ret;
        uint16_t value3 = RAM16(0xE004);
        r->a = value3;
        r->x = (uint8_t)x;
        r->y = (uint8_t)y_ret;
        r->z = value3 == 0;
        r->n = value3 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDE57, 0xD0DEE1); GUARD_JSR(c, sp_call, 0xDE57); } /* split_native_coordinate_word_into_two_digit_selectors */
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        RAM8(0x1882) = (uint8_t)a_all2;
        RAM8(0x1883) = (uint8_t)y_ret2;
        r->a = 0x7500;
        r->x = 0;
        r->y = (uint8_t)y_ret2;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDE6A, 0xD0DE82); GUARD_JSR(c, sp_call, 0xDE6A); } /* expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five */
        r->a = 0x7510;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDE70, 0xD0DE82); GUARD_JSR(c, sp_call, 0xDE70); } /* expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five */
        r->a = 0x7600;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDE76, 0xD0DE82); GUARD_JSR(c, sp_call, 0xDE76); } /* expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five */
        r->a = 0x7610;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDE7C, 0xD0DE82); GUARD_JSR(c, sp_call, 0xDE7C); } /* expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five */
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xDE80, 0xC0693F); GUARD_JSL(c, sp_call, 0xDE80); } /* wait_menu_vblank_through_native_long_wrapper */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool x_ret5 = r->xf;
        uint16_t a_all7 = r->a;
        uint16_t x_ret6 = r->x;
        uint16_t y_ret7 = r->y;
        bool carry_ret7 = r->c;
        bool zero_ret7 = r->z;
        bool negative_ret7 = r->n;
        bool overflow_ret = r->v;
        x_flag = x_ret5;
        a1 = (uint8_t)a_all7;
        a_hi1 = a_all7 >> 8;
        x1 = x_ret6;
        y1 = y_ret7;
        carry1 = carry_ret7;
        zero1 = zero_ret7;
        negative1 = negative_ret7;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0DE29, SOM_RTL, "gen", publish_native_optional_four_coordinate_digit_tiles_and_wait_vblank, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 89, 31)
