#include "som_c.h"

/* C057C9 advance_native_party_message_queue_and_dialogue   [class B, 230 bytes, 115 instructions]
 * Source: src/rom/advance_native_party_message_queue_and_dialogue.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_native_party_message_queue_and_dialogue(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x1D13) = 1;
    r->a = (a_hi << 8) | 1;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x57D3, 0xC00092); GUARD_JSL(c, sp_call, 0x57D3); } /* run_native_dialogue_public_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    bool overflow_ret = r->v;
    RAM8(0x0000 + sp0) = dp_ret >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp_ret;
    RAM8(0x0000 + sp0 - 2) = db_ret;
    RAM8(0x0000 + sp0 - 3) = ((((((negative_ret << 7) | (overflow_ret << 6)) | (m_ret << 5)) | (x_ret << 4)) | (d_entry << 3)) | (i_entry << 2)) | (zero_ret << 1) | carry_ret;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    r->a = 0x037E;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0300;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x57E5, 0xC038A0); GUARD_JSR(c, sp_call, 0x57E5); } /* advance_additive_random_generator */
    r->sp += 4;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t x_ret4 = r->x;
    if (RAM8(0x0380) & 0x80) {
        uint8_t value2 = RAM8(0x0000 + sp0 - 3);
        uint8_t value3 = RAM8(0x0000 + sp0 - 2);
        uint8_t value4 = RAM8(0x0000 + sp0 - 1);
        uint8_t value5 = RAM8(0x0000 + sp0);
        r->c = value2 & 0x01;
        r->v = value2 & 0x40;
        r->mf = value2 & 0x20;
        r->xf = value2 & 0x10;
        r->db = value3;
        r->dp = (value5 << 8) | value4;
        r->i = value2 & 0x04;
        r->d = value2 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
    if ((RAM8(0x1D04) & 1) == 0) {
        if (RAM8(0x03A0) == 0) {
            BUS8_SET(c, 0x004202, RAM8(0x03A2));
            BUS8_SET(c, 0x004203, 0x1E);
            uint16_t value9 = BUS16(c, 0x004216);
            if (x_ret3) {
                if (RAM8(0xFE00 + (uint8_t)value9) != 0) {
                    uint8_t value11 = RAM8(0x1D12);
                    if ((value11 & 0x20) != 0) {
                        RAM8(0x03A2)++;
                        if (RAM8(0x03A2) == 0x0C) {
                            RAM8(0x03A2) = 0;
                        }
                        uint8_t value13 = RAM8(0xFE00 + (uint8_t)value9);
                        uint8_t a_hi2;
                        if (!(value13 & 0x80)) {
                            a_hi2 = value9 >> 8;
                        } else {
                            RAM8(0xFE00 + (uint8_t)value9) = 0x60;
                            uint8_t value14 = RAM8(0x03A3);
                            uint8_t a_hi1;
                            if (value14 == 0) {
                                a_hi1 = value9 >> 8;
                            } else {
                                uint16_t value15 = RAM16(0xFE10 + (uint8_t)value9);
                                uint16_t value16 = RAM16(0xFE12 + (uint8_t)value9);
                                if ((value16 & RAM16(ACTOR_STATUS + (uint8_t)value15)) == 0) {
                                    RAM8(0xFE01 + (uint8_t)value9) = 0;
                                }
                                a_hi1 = value16 >> 8;
                            }
                            a_hi2 = a_hi1;
                        }
                        RAM8(0x03A3)++;
                        RAM8(0x1D03) = 0x7E;
                        c->fail = 3; /* operand size does not fit the register width on this path */
                        return;
                    }
                    r->a = (value9 >> 8 << 8) | value11;
                    r->x = (uint8_t)x_ret4;
                    r->y = (uint8_t)value9;
                    r->z = (value11 & 0x20) == 0;
                    r->n = value11 & 0x80;
                    r->xf = 1;
                    r->sp -= 4;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x5827, 0xC05BEA); GUARD_JSR(c, sp_call, 0x5827); } /* request_native_party_message_suspend_script */
                    r->sp += 4;
                    uint8_t value18 = RAM8(0x0000 + sp0 - 3);
                    uint8_t value19 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value20 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value21 = RAM8(0x0000 + sp0);
                    r->c = value18 & 0x01;
                    r->v = value18 & 0x40;
                    r->mf = value18 & 0x20;
                    r->xf = value18 & 0x10;
                    r->db = value19;
                    r->dp = (value21 << 8) | value20;
                    r->i = value18 & 0x04;
                    r->d = value18 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTL(c);
                }
                uint8_t value22 = RAM8(0x1D12);
                uint8_t a_hi3;
                uint8_t y1;
                if ((value22 & 0x20) == 0) {
                    a_hi3 = value9 >> 8;
                    y1 = (uint8_t)value9;
                } else {
                    r->a = (value9 >> 8 << 8) | value22;
                    r->x = (uint8_t)x_ret4;
                    r->y = (uint8_t)value9;
                    r->z = (value22 & 0x20) == 0;
                    r->n = value22 & 0x80;
                    r->xf = 1;
                    r->sp -= 4;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x58AA, 0xC05BF8); GUARD_JSR(c, sp_call, 0x58AA); } /* request_native_party_message_resume_script */
                    r->sp += 4;
                    uint16_t a_all4 = r->a;
                    uint8_t y_ret4 = r->y;
                    a_hi3 = a_all4 >> 8;
                    y1 = y_ret4;
                }
                uint8_t value23 = RAM8(0x0000 + sp0 - 3);
                uint8_t value24 = RAM8(0x0000 + sp0 - 2);
                uint8_t value25 = RAM8(0x0000 + sp0 - 1);
                uint8_t value26 = RAM8(0x0000 + sp0);
                r->a = (a_hi3 << 8) | a;
                r->x = (uint8_t)x_ret4;
                r->y = y1;
                r->c = value23 & 0x01;
                r->v = value23 & 0x40;
                r->mf = value23 & 0x20;
                r->xf = value23 & 0x10;
                r->db = value24;
                r->dp = (value26 << 8) | value25;
                r->i = value23 & 0x04;
                r->d = value23 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTL(c);
            } else {
                if (RAM8(0xFE00 + value9) != 0) {
                    uint8_t value28 = RAM8(0x1D12);
                    if ((value28 & 0x20) != 0) {
                        RAM8(0x03A2)++;
                        if (RAM8(0x03A2) == 0x0C) {
                            RAM8(0x03A2) = 0;
                        }
                        uint8_t value30 = RAM8(0xFE00 + value9);
                        uint8_t a_hi5;
                        if (!(value30 & 0x80)) {
                            a_hi5 = value9 >> 8;
                        } else {
                            RAM8(0xFE00 + value9) = 0x60;
                            uint8_t value31 = RAM8(0x03A3);
                            uint8_t a_hi4;
                            if (value31 == 0) {
                                a_hi4 = value9 >> 8;
                            } else {
                                uint16_t value32 = RAM16(0xFE10 + value9);
                                uint16_t value33 = RAM16(0xFE12 + value9);
                                if ((value33 & RAM16(ACTOR_STATUS + value32)) == 0) {
                                    RAM8(0xFE01 + value9) = 0;
                                }
                                a_hi4 = value33 >> 8;
                            }
                            a_hi5 = a_hi4;
                        }
                        RAM8(0x03A3)++;
                        RAM8(0x1D03) = 0x7E;
                        RAM16_SET(0x1D01, 0xFF69);
                        RAM8(0x0000 + sp0 - 4) = value9 >> 8;
                        RAM8(0x0000 + sp0 - 5) = (uint8_t)value9;
                        RAM8(BATTLE_TEMP_A4) = 0x1E;
                        uint8_t a_hi6 = a_hi5;
                        uint16_t x1 = 0xFF69;
                        uint16_t y2 = value9;
                        do {
                            RAM8(0x0000 + x1) = RAM8(0xFE01 + y2);
                            RAM8(BATTLE_TEMP_A4)--;
                            x1 = (uint16_t)(x1 + 1);
                            y2 = (uint16_t)(y2 + 1);
                        } while (RAM8(BATTLE_TEMP_A4) != 0);
                        uint8_t value36 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value37 = RAM8(0x0000 + sp0 - 4);
                        RAM8(0x039F)--;
                        BUS8_SET(c, 0x004202, (uint8_t)(RAM8(0x039F) << 3) ^ 0xFF);
                        BUS8_SET(c, 0x004203, RAM8(0xFE00 + ((value37 << 8) | value36)));
                        uint8_t value40 = BUS8(c, 0x004217);
                        RAM8(0x03A0) = value40;
                        RAM8(0xFE00 + ((value37 << 8) | value36)) = 0;
                        uint8_t value41 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value42 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value43 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value44 = RAM8(0x0000 + sp0);
                        r->a = (a_hi6 << 8) | 0;
                        r->x = x1;
                        r->y = (value37 << 8) | value36;
                        r->c = value41 & 0x01;
                        r->v = value41 & 0x40;
                        r->mf = value41 & 0x20;
                        r->xf = value41 & 0x10;
                        r->db = value42;
                        r->dp = (value44 << 8) | value43;
                        r->i = value41 & 0x04;
                        r->d = value41 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTL(c);
                    }
                    r->a = (value9 >> 8 << 8) | value28;
                    r->y = value9;
                    r->z = (value28 & 0x20) == 0;
                    r->n = value28 & 0x80;
                    r->xf = 0;
                    r->sp -= 4;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x5827, 0xC05BEA); GUARD_JSR(c, sp_call, 0x5827); } /* request_native_party_message_suspend_script */
                    r->sp += 4;
                    uint8_t value45 = RAM8(0x0000 + sp0 - 3);
                    uint8_t value46 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value47 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value48 = RAM8(0x0000 + sp0);
                    r->c = value45 & 0x01;
                    r->v = value45 & 0x40;
                    r->mf = value45 & 0x20;
                    r->xf = value45 & 0x10;
                    r->db = value46;
                    r->dp = (value48 << 8) | value47;
                    r->i = value45 & 0x04;
                    r->d = value45 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTL(c);
                }
                uint8_t value49 = RAM8(0x1D12);
                uint8_t a_hi7;
                uint16_t y3;
                if ((value49 & 0x20) == 0) {
                    a_hi7 = value9 >> 8;
                    y3 = value9;
                } else {
                    r->a = (value9 >> 8 << 8) | value49;
                    r->y = value9;
                    r->z = (value49 & 0x20) == 0;
                    r->n = value49 & 0x80;
                    r->xf = 0;
                    r->sp -= 4;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x58AA, 0xC05BF8); GUARD_JSR(c, sp_call, 0x58AA); } /* request_native_party_message_resume_script */
                    r->sp += 4;
                    uint16_t a_all6 = r->a;
                    uint16_t y_ret6 = r->y;
                    a_hi7 = a_all6 >> 8;
                    y3 = y_ret6;
                }
                uint8_t value50 = RAM8(0x0000 + sp0 - 3);
                uint8_t value51 = RAM8(0x0000 + sp0 - 2);
                uint8_t value52 = RAM8(0x0000 + sp0 - 1);
                uint8_t value53 = RAM8(0x0000 + sp0);
                r->a = (a_hi7 << 8) | a;
                r->y = y3;
                r->c = value50 & 0x01;
                r->v = value50 & 0x40;
                r->mf = value50 & 0x20;
                r->xf = value50 & 0x10;
                r->db = value51;
                r->dp = (value53 << 8) | value52;
                r->i = value50 & 0x04;
                r->d = value50 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTL(c);
            }
        }
        RAM8(0x03A0)--;
        uint8_t value54 = RAM8(0x0000 + sp0 - 3);
        uint8_t value55 = RAM8(0x0000 + sp0 - 2);
        uint8_t value56 = RAM8(0x0000 + sp0 - 1);
        uint8_t value57 = RAM8(0x0000 + sp0);
        r->c = value54 & 0x01;
        r->v = value54 & 0x40;
        r->mf = value54 & 0x20;
        r->xf = value54 & 0x10;
        r->db = value55;
        r->dp = (value57 << 8) | value56;
        r->i = value54 & 0x04;
        r->d = value54 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
    uint8_t value58 = RAM8(0x0000 + sp0 - 3);
    uint8_t value59 = RAM8(0x0000 + sp0 - 2);
    uint8_t value60 = RAM8(0x0000 + sp0 - 1);
    uint8_t value61 = RAM8(0x0000 + sp0);
    r->c = value58 & 0x01;
    r->v = value58 & 0x40;
    r->mf = value58 & 0x20;
    r->xf = value58 & 0x10;
    r->db = value59;
    r->dp = (value61 << 8) | value60;
    r->i = value58 & 0x04;
    r->d = value58 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC057C9, SOM_RTL, "gen", advance_native_party_message_queue_and_dialogue, 0, L_B | L_X | L_Y | L_C | L_V, 6, 1, 0, 230, 115)
