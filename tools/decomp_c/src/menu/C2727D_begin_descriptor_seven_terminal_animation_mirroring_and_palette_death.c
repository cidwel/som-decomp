#include "som_c.h"

/* C2727D begin_descriptor_seven_terminal_animation_mirroring_and_palette_death   [class B, 68 bytes, 26 instructions]
 * Source: src/rom/begin_descriptor_seven_terminal_animation_mirroring_and_palette_death.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void begin_descriptor_seven_terminal_animation_mirroring_and_palette_death(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = RAM16(0x0060 + value);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi2;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value2 & 0xFF) != 0) {
        m_flag = 0;
        x_flag = 0;
        a1 = value2 & 0xFF;
        a_hi2 = 0;
        x1 = value;
        y1 = y;
        zero1 = (value2 & 0xFF) == 0;
        negative1 = value2 & 0xFF & 0x8000;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = dp;
    } else {
        RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
        r->a = 0x010A;
        r->x = value;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x728F, 0xC21394); GUARD_JSR(c, sp_call, 0x728F); } /* select_boss_animation_and_reset_frame_cursor */
        uint16_t value3 = RAM16(0x007E + value);
        uint8_t a_hi1;
        if (value3 != 0) {
            uint16_t value4 = RAM16(0x0098 + value);
            RAM16_SET(0x0098 + value, (value4 & 0xFB3F) | 0x40);
            a_hi1 = ((value4 & 0xFB3F) | 0x40) >> 8;
        } else {
            uint16_t value5 = RAM16(0x0098 + value);
            RAM16_SET(0x0098 + value, value5 & 0xFB3F);
            a_hi1 = (value5 & 0xFB3F) >> 8;
        }
        uint8_t value6 = RAM8(0x0019 + value);
        RAM8(0x0018 + value) = value6;
        RAM8(0x0019 + value) = 0;
        RAM8(0x001A + value) = 0;
        r->a = (a_hi1 << 8) | value6;
        r->z = value6 == 0;
        r->n = value6 & 0x80;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x72BE, 0xC20B14); GUARD_JSR(c, sp_call, 0x72BE); } /* prepare_boss_death_palettes_graphics_and_selected_actor */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a1 = (uint8_t)a_all2;
        a_hi2 = a_all2 >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a_hi2 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2727D, SOM_RTS, "gen", begin_descriptor_seven_terminal_animation_mirroring_and_palette_death, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 68, 26)
