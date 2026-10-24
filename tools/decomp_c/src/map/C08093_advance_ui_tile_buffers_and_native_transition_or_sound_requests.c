#include "som_c.h"

/* C08093 advance_ui_tile_buffers_and_native_transition_or_sound_requests   [class C, 198 bytes, 95 instructions]
 * Source: src/rom/advance_ui_tile_buffers_and_native_transition_or_sound_requests.s
 * Documented in docs/ui-native-ui-frame-lifecycle.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYC.
 */
static void advance_ui_tile_buffers_and_native_transition_or_sound_requests(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x00A2);
    RAM16_SET(0x00A2, (uint16_t)(value + 0x80) | 0xF000);
    RAM16_SET(0x00A4, (((uint16_t)(value + 0x80) | 0xF000) & 0x03FF) + 0x2C00);
    uint8_t value2 = RAM8(0x00E3);
    bool m_flag;
    uint8_t a1;
    uint8_t a_hi1;
    bool carry1;
    if ((value2 & 6) == 0) {
        m_flag = 1;
        a1 = value2 & 6;
        a_hi1 = (((uint16_t)(value + 0x80) | 0xF000) & 0x03FF) + 0x2C00 >> 8;
        carry1 = (((uint16_t)(value + 0x80) | 0xF000) & 0x03FF) + 0x2C00 > 0xFFFF;
    } else {
        uint16_t value3 = RAM16(0x0092);
        RAM16_SET(0x0092, ((uint16_t)(value3 + 0x40) & 0x03FF) | 0xEC00);
        RAM16_SET(0x0094, ((((uint16_t)(value3 + 0x40) & 0x03FF) | 0xEC00) & 0x03FF) + 0x2800);
        m_flag = 0;
        a1 = (uint8_t)(((((uint16_t)(value3 + 0x40) & 0x03FF) | 0xEC00) & 0x03FF) + 0x2800);
        a_hi1 = ((((uint16_t)(value3 + 0x40) & 0x03FF) | 0xEC00) & 0x03FF) + 0x2800 >> 8;
        carry1 = ((((uint16_t)(value3 + 0x40) & 0x03FF) | 0xEC00) & 0x03FF) + 0x2800 > 0xFFFF;
    }
    uint8_t value4 = RAM8(0x00FE);
    if (value4 & 0x80) {
        uint16_t value5 = RAM16(0x00F6);
        RAM16_SET(0x00F6, (uint16_t)(value5 + 0x10) & 0x03FF);
        RAM8(0x00FE) = (uint8_t)(value4 + 1);
        if (((uint8_t)(value4 + 1) & 0x3F) == 0) {
            RAM8(0x00FE) = 0;
            RAM8(0x002D) = 0;
            RAM8(0x00F8) = 0x44;
            RAM8(0x00E2) = 0;
            r->a = (((uint16_t)(value5 + 0x10) & 0x03FF) >> 8 << 8) | 0;
            r->c = value5 + 0x10 > 0xFFFF;
            r->v = ((value5 ^ (uint16_t)(value5 + 0x10)) & ((uint16_t)(value5 + 0x10) ^ 0x10) & 0x8000) != 0;
            r->xf = 0;
            TAIL_CALL(c, 0xC08255, SOM_RTS); /* reset_native_stack_and_jump_from_ui_to_main_map_loop */
        }
        r->a = (r->a & 0x00FF) | ((((uint16_t)(value5 + 0x10) & 0x03FF) >> 8) << 8);
        r->c = value5 + 0x10 > 0xFFFF;
        RETURN_RTS(c);
    }
    if (value4 & 0x40) {
        uint16_t value6 = RAM16(0x00F6);
        RAM16_SET(0x00F6, (uint16_t)(value6 - 0x10) & 0x03FF);
        RAM8(0x00FE) = (uint8_t)(value4 - 1);
        if (((uint8_t)(value4 - 1) & 0x3F) == 0) {
            RAM8(0x00FE) = 0;
            RAM8(0x00CC) |= 0x20;
            uint16_t value8 = RAM16(0x00F6);
            RAM16_SET(0x00F6, (uint16_t)(value8 - 0x10) & 0x03FF);
            r->a = (uint16_t)(value8 - 0x10) & 0x03FF;
            r->c = value8 >= 0x10;
            r->mf = 0;
            RETURN_RTS(c);
        }
        r->a = (r->a & 0x00FF) | ((((uint16_t)(value6 - 0x10) & 0x03FF) >> 8) << 8);
        r->c = value6 >= 0x10;
        RETURN_RTS(c);
    }
    if (!(value2 & 0x40)) {
        r->a = (r->a & 0x00FF) | (a_hi1 << 8);
        r->c = carry1;
        RETURN_RTS(c);
    }
    uint8_t value9 = RAM8(0x00F5);
    if ((value9 & 1) != 0) {
        r->a = (r->a & 0x00FF) | (a_hi1 << 8);
        r->c = carry1;
        RETURN_RTS(c);
    }
    if (RAM8(0x00F4) != 0) {
        r->a = (r->a & 0x00FF) | (a_hi1 << 8);
        r->c = carry1;
        RETURN_RTS(c);
    }
    RAM8(0x1E01) = 0x16;
    RAM8(0x1E00) = 2;
    RAM8(0x1E02) = 0;
    RAM8(0x1E03) = value9;
    r->a = (a_hi1 << 8) | value9;
    r->c = carry1;
    r->z = value9 == 0;
    r->n = value9 & 0x80;
    r->v = value2 & 0x40;
    { const uint16_t sp_call = r->sp; JSL(c, 0x8157, 0xC30004); GUARD_JSL(c, sp_call, 0x8157); } /* audio_command_sender_public_jump */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08093, SOM_RTS, "gen", advance_ui_tile_buffers_and_native_transition_or_sound_requests, 0, L_B | L_X | L_Y | L_C, 1, 1, 1, 198, 95)
