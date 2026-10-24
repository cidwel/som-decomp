#include "som_c.h"

/* C1376A send_spell_entity_positional_sound   [class B, 67 bytes, 40 instructions]
 * Source: src/rom/send_spell_entity_positional_sound.s
 * Documented in docs/actor-cast-entity-graphics-audio.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void send_spell_entity_positional_sound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = db;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM8(0x0000 + sp0 - 5) = 0;
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    if (a == 0) {
        m_flag = 1;
        x_flag = 0;
        a_hi1 = a_hi;
        x1 = x;
        y1 = y;
    } else {
        RAM8(0x1E01) = a;
        RAM8(0x1E00) = 2;
        RAM8(0x1E02) = 0;
        uint8_t a1;
        if (a_hi + 8 <= 0xFF) {
            a1 = (uint8_t)(a_hi + 8);
        } else {
            a1 = 0xFF;
        }
        uint8_t a2;
        if (a1 >> 4 != 0) {
            a2 = a1 >> 4;
        } else {
            a2 = 1;
        }
        RAM8(0x1E03) = a2;
        uint8_t value = RAM8(0x1E03);
        RAM8(0x1E03) = (uint8_t)(a2 << 4) | value;
        r->a = (uint8_t)(a2 << 4) | value;
        r->c = (uint8_t)(a2 << 3) & 0x80;
        r->z = ((uint8_t)(a2 << 4) | value) == 0;
        r->n = ((uint8_t)(a2 << 4) | value) & 0x80;
        r->v = ((a_hi ^ (uint8_t)(a_hi + 8)) & ((uint8_t)(a_hi + 8) ^ 8) & 0x80) != 0;
        r->db = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x37A8, 0xC30004); GUARD_JSL(c, sp_call, 0x37A8); } /* audio_command_sender_public_jump */
        r->sp += 4;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        m_flag = m_ret;
        x_flag = x_ret;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
    }
    uint8_t value2 = RAM8(0x0000 + sp0 - 3);
    uint8_t value3 = RAM8(0x0000 + sp0 - 2);
    uint8_t value4 = RAM8(0x0000 + sp0 - 1);
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->c = value3 & 0x01;
    r->v = value3 & 0x40;
    r->mf = value3 & 0x20;
    r->xf = value3 & 0x10;
    r->db = value2;
    r->dp = (value5 << 8) | value4;
    r->i = value3 & 0x04;
    r->d = value3 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1376A, SOM_RTS, "gen", send_spell_entity_positional_sound, 0, L_B | L_X | L_Y | L_C | L_V, 6, 1, 0, 67, 40)
