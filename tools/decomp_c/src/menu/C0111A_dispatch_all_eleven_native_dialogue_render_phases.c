#include "som_c.h"

/* C0111A dispatch_all_eleven_native_dialogue_render_phases   [class C, 37 bytes, 16 instructions]
 * Source: src/rom/dispatch_all_eleven_native_dialogue_render_phases.s
 * Documented in docs/event-dialogue-render-core.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void dispatch_all_eleven_native_dialogue_render_phases(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x1D00);
    bool m_flag;
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
    if ((value & 0x40) == 0) {
        uint8_t value2 = RAM8(0xA15D);
        r->a = (uint8_t)(value2 << 1);
        r->x = (uint8_t)(value2 << 1);
        r->c = value2 & 0x80;
        r->z = (uint8_t)(value2 << 1) == 0;
        r->n = (uint8_t)(value2 << 1) & 0x8000;
        { const uint16_t sp_call = r->sp;
        switch ((uint8_t)(value2 << 1)) {
        case 0x0000: JSR(c, 0x113D, 0xC0113F); GUARD_JSR(c, sp_call, 0x113D); break; /* decode_dialogue_font_stream_and_advance_phase */
        case 0x0002: JSR(c, 0x113D, 0xC01150); GUARD_JSR(c, sp_call, 0x113D); break; /* load_dialogue_glyph_rows_and_advance_phase */
        case 0x0004: JSR(c, 0x113D, 0xC01157); GUARD_JSR(c, sp_call, 0x113D); break; /* advance_dialogue_glyph_phase_after_no_operation */
        case 0x0006: JSR(c, 0x113D, 0xC0115E); GUARD_JSR(c, sp_call, 0x113D); break; /* expand_dialogue_glyphs_and_advance_phase */
        case 0x0008: JSR(c, 0x113D, 0xC01165); GUARD_JSR(c, sp_call, 0x113D); break; /* merge_shifted_dialogue_glyphs_clear_upload_cursors_and_advance_phase */
        case 0x000A: JSR(c, 0x113D, 0xC014EB); GUARD_JSR(c, sp_call, 0x113D); break; /* compose_dialogue_glyph_planes_and_publish_active_palette */
        case 0x000C: JSR(c, 0x113D, 0xC01175); GUARD_JSR(c, sp_call, 0x113D); break; /* publish_dialogue_glyph_phase_with_real_tile_progress */
        default: JSR(c, 0x113D, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x1A0C + ((uint8_t)(value2 << 1))))); GUARD_JSR(c, sp_call, 0x113D);
        }
        }
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    } else {
        RAM8(0x1D00) = value & 0xBF;
        RAM8(0xA170) = 0x52;
        m_flag = 1;
        x_flag = 0;
        a1 = 0x52;
        a_hi1 = a_hi;
        x1 = x;
        y1 = y;
        carry1 = carry;
        zero1 = 0;
        negative1 = 0;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
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
SOM_REGISTER(0xC0111A, SOM_RTS, "gen", dispatch_all_eleven_native_dialogue_render_phases, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 37, 16)
