#include "som_c.h"

/* C24865 publish_native54_cast_pose_sine_oscillator_and_auxiliary_control   [class B, 140 bytes, 60 instructions]
 * Source: src/rom/publish_native54_cast_pose_sine_oscillator_and_auxiliary_control.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void publish_native54_cast_pose_sine_oscillator_and_auxiliary_control(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x0299, 0x14);
    uint16_t value = RAM16(0x0098 + x);
    uint8_t a_hi1;
    if ((value & 0x40) == 0) {
        a_hi1 = value >> 8;
    } else {
        RAM16_SET(0x0299, 0x0C);
        a_hi1 = 0;
    }
    uint16_t value2 = RAM16(0x00B4 + x);
    r->a = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x487C, 0xC22A60); GUARD_JSR(c, sp_call, 0x487C); } /* mask_angle_and_derive_native_sine */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    BUS16_SET(c, (uint16_t)(dp_ret + 0x95), a_all);
    if (x_ret) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0xB4 + value3);
        r->a = (uint16_t)(value4 + 0x0200);
        r->x = value3;
        r->y = (uint8_t)y;
        r->c = value4 + 0x0200 > 0xFFFF;
        r->z = (uint16_t)(value4 + 0x0200) == 0;
        r->n = (uint16_t)(value4 + 0x0200) & 0x8000;
        r->v = ((value4 ^ (uint16_t)(value4 + 0x0200)) & ((uint16_t)(value4 + 0x0200) ^ 0x0200) & 0x8000) != 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x488A, 0xC22A60); GUARD_JSR(c, sp_call, 0x488A); } /* mask_angle_and_derive_native_sine */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        BUS16_SET(c, (uint16_t)(dp_ret2 + 0x97), a_all2);
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x95));
        BUS16_SET(c, (uint16_t)(dp_ret2 + 0x46), value5);
        BUS16_SET(c, (uint16_t)(dp_ret2 + 0x4E), 3);
        r->a = 3;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4898, 0xC22B94); GUARD_JSR(c, sp_call, 0x4898); } /* multiply_signed_words_to_double_word */
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x57));
        BUS16_SET(c, (uint16_t)(dp_ret2 + 0x95), (uint16_t)(value6 - 8));
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x97));
        BUS16_SET(c, (uint16_t)(dp_ret2 + 0x46), value7);
        BUS16_SET(c, (uint16_t)(dp_ret2 + 0x4E), 2);
        r->a = 2;
        r->c = value6 >= 8;
        r->z = 0;
        r->n = 0;
        r->v = ((value6 ^ 8) & (value6 ^ (uint16_t)(value6 - 8)) & 0x8000) != 0;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x48AC, 0xC22B94); GUARD_JSR(c, sp_call, 0x48AC); } /* multiply_signed_words_to_double_word */
        bool x_ret6 = r->xf;
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x57));
        uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x99));
        BUS16_SET(c, (uint16_t)(dp_ret2 + 0x97), (uint16_t)(value8 - value9));
        if (x_ret6) {
            uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x87));
            uint16_t value11 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xB4 + value10);
            BUS16_SET(c, (db_ret2 << 0x10) + 0xB4 + value10, (uint16_t)(value11 + 0x40));
            uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x97));
            BUS8_SET(c, (db_ret2 << 0x10) + 0xF811 + (uint8_t)y, value12);
            uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x95));
            BUS8_SET(c, (db_ret2 << 0x10) + 0xF80D + (uint8_t)y, value13);
            uint16_t value14 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x96 + value10);
            if ((value14 & 3) == 0) {
                BUS8_SET(c, (db_ret2 << 0x10) + 0xF813 + (uint8_t)y, 0x44);
            }
            uint16_t value15 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x96 + value10);
            if ((value15 & 7) == 0) {
                BUS8_SET(c, (db_ret2 << 0x10) + 0xF813 + (uint8_t)y, 0x44);
            }
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x87));
            uint16_t value17 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xB4 + value16);
            BUS16_SET(c, (db_ret2 << 0x10) + 0xB4 + value16, (uint16_t)(value17 + 0x40));
            uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x97));
            BUS8_SET(c, (db_ret2 << 0x10) + 0xF811 + (uint8_t)y, value18);
            uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x95));
            BUS8_SET(c, (db_ret2 << 0x10) + 0xF80D + (uint8_t)y, value19);
            uint16_t value20 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x96 + value16);
            if ((value20 & 3) == 0) {
                BUS8_SET(c, (db_ret2 << 0x10) + 0xF813 + (uint8_t)y, 0x44);
            }
            uint16_t value21 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x96 + value16);
            if ((value21 & 7) == 0) {
                BUS8_SET(c, (db_ret2 << 0x10) + 0xF813 + (uint8_t)y, 0x44);
            }
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    } else {
        uint16_t value22 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value23 = BUS16_RDP(c, (db_ret << 0x10) + 0xB4 + value22);
        r->a = (uint16_t)(value23 + 0x0200);
        r->x = value22;
        r->c = value23 + 0x0200 > 0xFFFF;
        r->z = (uint16_t)(value23 + 0x0200) == 0;
        r->n = (uint16_t)(value23 + 0x0200) & 0x8000;
        r->v = ((value23 ^ (uint16_t)(value23 + 0x0200)) & ((uint16_t)(value23 + 0x0200) ^ 0x0200) & 0x8000) != 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x488A, 0xC22A60); GUARD_JSR(c, sp_call, 0x488A); } /* mask_angle_and_derive_native_sine */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t a_all5 = r->a;
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x97), a_all5);
        uint16_t value24 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x95));
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x46), value24);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x4E), 3);
        r->a = 3;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4898, 0xC22B94); GUARD_JSR(c, sp_call, 0x4898); } /* multiply_signed_words_to_double_word */
        uint16_t value25 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x57));
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x95), (uint16_t)(value25 - 8));
        uint16_t value26 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x97));
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x46), value26);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x4E), 2);
        r->a = 2;
        r->c = value25 >= 8;
        r->z = 0;
        r->n = 0;
        r->v = ((value25 ^ 8) & (value25 ^ (uint16_t)(value25 - 8)) & 0x8000) != 0;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x48AC, 0xC22B94); GUARD_JSR(c, sp_call, 0x48AC); } /* multiply_signed_words_to_double_word */
        bool x_ret10 = r->xf;
        uint16_t value27 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x57));
        uint16_t value28 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x99));
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x97), (uint16_t)(value27 - value28));
        if (x_ret10) {
            uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x87));
            uint16_t value30 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xB4 + value29);
            BUS16_SET(c, (db_ret3 << 0x10) + 0xB4 + value29, (uint16_t)(value30 + 0x40));
            uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x97));
            BUS8_SET(c, (db_ret3 << 0x10) + 0xF811 + (uint8_t)y, value31);
            uint8_t value32 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x95));
            BUS8_SET(c, (db_ret3 << 0x10) + 0xF80D + (uint8_t)y, value32);
            uint16_t value33 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x96 + value29);
            if ((value33 & 3) == 0) {
                BUS8_SET(c, (db_ret3 << 0x10) + 0xF813 + (uint8_t)y, 0x44);
            }
            uint16_t value34 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x96 + value29);
            if ((value34 & 7) == 0) {
                BUS8_SET(c, (db_ret3 << 0x10) + 0xF813 + (uint8_t)y, 0x44);
            }
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x87));
            uint16_t value36 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xB4 + value35);
            BUS16_SET(c, (db_ret3 << 0x10) + 0xB4 + value35, (uint16_t)(value36 + 0x40));
            uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x97));
            BUS8_SET(c, (db_ret3 << 0x10) + 0xF811 + y, value37);
            uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x95));
            BUS8_SET(c, (db_ret3 << 0x10) + 0xF80D + y, value38);
            uint16_t value39 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x96 + value35);
            if ((value39 & 3) == 0) {
                BUS8_SET(c, (db_ret3 << 0x10) + 0xF813 + y, 0x44);
            }
            uint16_t value40 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x96 + value35);
            if ((value40 & 7) == 0) {
                BUS8_SET(c, (db_ret3 << 0x10) + 0xF813 + y, 0x44);
            }
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC24865, SOM_RTS, "gen", publish_native54_cast_pose_sine_oscillator_and_auxiliary_control, 0, 0, 1, 0, 0, 140, 60)
