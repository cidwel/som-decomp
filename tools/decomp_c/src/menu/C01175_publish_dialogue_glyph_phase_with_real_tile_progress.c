#include "som_c.h"

/* C01175 publish_dialogue_glyph_phase_with_real_tile_progress   [class B, 86 bytes, 33 instructions]
 * Source: src/rom/publish_dialogue_glyph_phase_with_real_tile_progress.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void publish_dialogue_glyph_phase_with_real_tile_progress(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x1D05);
    bool x_flag2;
    uint8_t a1;
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    bool carry3;
    bool zero1;
    bool negative1;
    bool overflow3;
    if (value == 7) {
        uint16_t value2 = RAM16(0x1D14);
        RAM8(0x0000 + value2) = 0;
        r->a = value2;
        r->x = value2;
        r->c = value >= 7;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0x11C4, 0xC011CB); GUARD_JSR(c, sp_call, 0x11C4); } /* publish_dialogue_window_rows_and_advance_phase */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        r->a = (a_all >> 8 << 8) | 0x57;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x11C9, 0xC00FFA); GUARD_JSR(c, sp_call, 0x11C9); } /* request_dialogue_transfer_and_conditional_window_flags */
        uint16_t a_all2 = r->a;
        bool carry_ret2 = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        x_flag2 = 0;
        a1 = (uint8_t)a_all2;
        a_hi3 = a_all2 >> 8;
        x3 = x_ret;
        y3 = y_ret;
        carry3 = carry_ret2;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow3 = overflow_ret;
    } else {
        uint8_t value3 = RAM8(0xA162);
        bool x_flag;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if (value3 != 0) {
            r->a = (a_hi << 8) | value3;
            r->c = value >= 7;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1199, 0xC01479); GUARD_JSR(c, sp_call, 0x1199); } /* copy_dialogue_font_page_and_publish_transfer */
            uint16_t a_all3 = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret2 = r->v;
            RAM8(0xA15D)++;
            uint8_t a_hi1 = a_all3 >> 8;
            uint16_t x1 = x_ret2;
            uint16_t y1 = y_ret2;
            bool carry1 = carry_ret3;
            bool overflow1 = overflow_ret2;
            for (;;) {
                r->a = (a_hi1 << 8) | a;
                r->x = x1;
                r->y = y1;
                r->c = carry1;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x119F, 0xC013A0); GUARD_JSR(c, sp_call, 0x119F); } /* advance_dialogue_tile_progress_or_complete_line */
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret3 = r->xf;
                uint16_t a_all4 = r->a;
                uint16_t x_ret4 = r->x;
                uint16_t y_ret3 = r->y;
                bool overflow_ret3 = r->v;
                uint8_t value5 = RAM8(0xA15D);
                if (x_ret3 != 0) { c->fail = 3; return; }
                a_hi1 = a_all4 >> 8;
                x1 = x_ret4;
                y1 = y_ret3;
                carry1 = value5 >= 8;
                overflow1 = overflow_ret3;
                if (!(value5 != 8)) break;
            }
            RAM8(0xA15D)++;
            x_flag = 0;
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
            carry2 = carry1;
            overflow2 = overflow1;
        } else {
            r->a = (a_hi << 8) | value3;
            r->c = value >= 7;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1184, 0xC01431); GUARD_JSR(c, sp_call, 0x1184); } /* publish_single_dialogue_glyph_tile */
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1187, 0xC013A0); GUARD_JSR(c, sp_call, 0x1187); } /* advance_dialogue_tile_progress_or_complete_line */
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret6 = r->xf;
            uint16_t a_all6 = r->a;
            uint16_t x_ret7 = r->x;
            uint16_t y_ret5 = r->y;
            bool overflow_ret5 = r->v;
            RAM8(0xA15D)++;
            uint8_t value6 = RAM8(0xA15D);
            if (value6 != 8) {
                RAM8(0xA15D)--;
            }
            x_flag = x_ret6;
            a_hi2 = a_all6 >> 8;
            x2 = x_ret7;
            y2 = y_ret5;
            carry2 = value6 >= 8;
            overflow2 = overflow_ret5;
        }
        uint8_t value7 = RAM8(0x1D04);
        RAM8(0x1D04) = value7 | 0x66;
        x_flag2 = x_flag;
        a1 = value7 | 0x66;
        a_hi3 = a_hi2;
        x3 = x2;
        y3 = y2;
        carry3 = carry2;
        zero1 = (value7 | 0x66) == 0;
        negative1 = (value7 | 0x66) & 0x80;
        overflow3 = overflow2;
    }
    r->a = (a_hi3 << 8) | a1;
    r->x = x3;
    r->y = y3;
    r->c = carry3;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow3;
    r->mf = 1;
    r->xf = x_flag2;
    r->db = 0x7E;
    r->dp = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01175, SOM_RTS, "gen", publish_dialogue_glyph_phase_with_real_tile_progress, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 86, 33)
