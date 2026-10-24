#include "som_c.h"

/* C00C2A publish_native_dialogue_frame_side_pairs   [class C, 295 bytes, 122 instructions]
 * Source: src/rom/publish_native_dialogue_frame_side_pairs.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void publish_native_dialogue_frame_side_pairs(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t a_0c31 = 0;
    uint8_t a_hi_0c31 = 0;
    uint16_t y_0c31 = 0;
    uint8_t a_0ccc = 0;
    uint8_t a_hi_0ccc = 0;
    uint16_t y_0ccc = 0;
    bool overflow_0ccc = 0;
    uint16_t direct_page_0ccc = 0;
    uint8_t data_bank_0ccc = 0;
    uint8_t value = RAM8(0xA16C);
    if (!(value & 0x01)) {
        a_0c31 = value >> 1;
        a_hi_0c31 = a_hi;
        y_0c31 = y;
        goto shared_0C31;
    }
    a_0c31 = (value >> 1) + 1;
    a_hi_0c31 = a_hi;
    y_0c31 = y;
    shared_0C31:;
    RAM8(0xA164) = a_0c31;
    RAM8(0xA157) = RAM8(0xA166);
    RAM8(0xA156) = RAM8(0xA165);
    uint8_t value4 = RAM8(0xA24E);
    uint16_t value5 = RAM16(0xA171);
    uint8_t value6 = BUS8(c, 0xC77259 + (uint16_t)((value4 << 1 << 1 << 1) + value5));
    uint8_t value7 = BUS8(c, 0xC77259 + (uint16_t)((uint16_t)((value4 << 1 << 1 << 1) + value5) + 1));
    RAM8(0x0000 + sp0) = value7;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((value7 << 8) | value6);
    r->a = (value7 << 8) | value6;
    r->x = (value7 << 8) | value6;
    r->y = y_0c31;
    r->c = (value4 << 1 << 1 << 1) + value5 > 0xFFFF;
    r->z = ((value7 << 8) | value6) == 0;
    r->n = ((value7 << 8) | value6) & 0x8000;
    r->v = (((value4 << 1 << 1 << 1) ^ (uint16_t)((value4 << 1 << 1 << 1) + value5)) & (value5 ^ (uint16_t)((value4 << 1 << 1 << 1) + value5)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0C61, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0C61); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    r->sp += 2;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint8_t value8 = BUS8_RDP(c, (db_ret << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret << 0x10) + 0xA156, (uint8_t)(value8 - 1));
    r->z = (uint8_t)(value8 - 1) == 0;
    r->n = (uint8_t)(value8 - 1) & 0x80;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0C67, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0C67); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    r->sp += 2;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    uint8_t value9 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA157);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA157, (uint8_t)(value9 + 1));
    uint8_t value10 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA156, (uint8_t)(value10 + 1));
    uint8_t a_hi1 = a_all2 >> 8;
    uint16_t y1 = y_ret2;
    bool carry1 = carry_ret2;
    bool overflow1 = overflow_ret2;
    uint8_t data_bank = db_ret2;
    uint16_t direct_page = dp_ret2;
    for (;;) {
        r->a = (a_hi1 << 8) | a;
        r->x = 0x0118;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0C73, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0C73); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        r->sp += 2;
        uint8_t db_ret3 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint8_t value11 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA156, (uint8_t)(value11 - 1));
        r->z = (uint8_t)(value11 - 1) == 0;
        r->n = (uint8_t)(value11 - 1) & 0x80;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0C79, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0C79); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        r->sp += 2;
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all4 = r->a;
        uint16_t y_ret4 = r->y;
        bool overflow_ret4 = r->v;
        uint8_t value12 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA164);
        if (value12 != 1) {
            uint8_t value13 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA157);
            BUS8_SET(c, (db_ret4 << 0x10) + 0xA157, (uint8_t)(value13 + 1));
            uint8_t value14 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA156);
            BUS8_SET(c, (db_ret4 << 0x10) + 0xA156, (uint8_t)(value14 + 1));
            r->a = (a_all4 >> 8 << 8) | value12;
            r->x = 0x0118;
            r->c = value12 >= 1;
            r->z = 0;
            r->n = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0C92, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0C92); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            r->sp += 2;
            uint8_t db_ret5 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            uint8_t value15 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA156);
            BUS8_SET(c, (db_ret5 << 0x10) + 0xA156, (uint8_t)(value15 - 1));
            r->z = (uint8_t)(value15 - 1) == 0;
            r->n = (uint8_t)(value15 - 1) & 0x80;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0C98, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0C98); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            r->sp += 2;
            uint16_t dp_ret6 = r->dp;
            uint8_t db_ret6 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all6 = r->a;
            uint16_t y_ret6 = r->y;
            bool carry_ret6 = r->c;
            bool overflow_ret6 = r->v;
            uint8_t value16 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA157);
            BUS8_SET(c, (db_ret6 << 0x10) + 0xA157, (uint8_t)(value16 + 1));
            uint8_t value17 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA156);
            BUS8_SET(c, (db_ret6 << 0x10) + 0xA156, (uint8_t)(value17 + 1));
            uint8_t value18 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA164);
            BUS8_SET(c, (db_ret6 << 0x10) + 0xA164, (uint8_t)(value18 - 1));
            if ((uint8_t)(value18 - 1) != 0) {
                a_hi1 = a_all6 >> 8;
                y1 = y_ret6;
                carry1 = carry_ret6;
                overflow1 = overflow_ret6;
                data_bank = db_ret6;
                direct_page = dp_ret6;
                continue;
            }
            a_hi1 = a_all6 >> 8;
            y1 = y_ret6;
            carry1 = carry_ret6;
            overflow1 = overflow_ret6;
            data_bank = db_ret6;
            direct_page = dp_ret6;
            break;
        }
        uint8_t value19 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA16C);
        if (value19 & 0x01) {
            uint8_t value20 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA157);
            BUS8_SET(c, (db_ret4 << 0x10) + 0xA157, (uint8_t)(value20 + 1));
            uint8_t value21 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA156);
            BUS8_SET(c, (db_ret4 << 0x10) + 0xA156, (uint8_t)(value21 + 1));
            uint8_t value22 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA164);
            BUS8_SET(c, (db_ret4 << 0x10) + 0xA164, (uint8_t)(value22 - 1));
            if ((uint8_t)(value22 - 1) != 0) {
                a_hi1 = a_all4 >> 8;
                y1 = y_ret4;
                carry1 = value19 & 0x01;
                overflow1 = overflow_ret4;
                data_bank = db_ret4;
                direct_page = dp_ret4;
                continue;
            }
            a_hi1 = a_all4 >> 8;
            y1 = y_ret4;
            carry1 = value19 & 0x01;
            overflow1 = overflow_ret4;
            data_bank = db_ret4;
            direct_page = dp_ret4;
            break;
        }
        uint8_t value23 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA157, (uint8_t)(value23 + 1));
        uint8_t value24 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA156, (uint8_t)(value24 + 1));
        r->a = (a_all4 >> 8 << 8) | (value19 >> 1);
        r->x = 0x0118;
        r->c = value19 & 0x01;
        r->z = 0;
        r->n = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0C92, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0C92); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        r->sp += 2;
        uint8_t db_ret7 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint8_t value25 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret7 << 0x10) + 0xA156, (uint8_t)(value25 - 1));
        r->z = (uint8_t)(value25 - 1) == 0;
        r->n = (uint8_t)(value25 - 1) & 0x80;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0C98, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0C98); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        r->sp += 2;
        uint16_t dp_ret8 = r->dp;
        uint8_t db_ret8 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all8 = r->a;
        uint16_t y_ret8 = r->y;
        bool carry_ret8 = r->c;
        bool overflow_ret8 = r->v;
        uint8_t value26 = BUS8_RDP(c, (db_ret8 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret8 << 0x10) + 0xA157, (uint8_t)(value26 + 1));
        uint8_t value27 = BUS8_RDP(c, (db_ret8 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret8 << 0x10) + 0xA156, (uint8_t)(value27 + 1));
        uint8_t value28 = BUS8_RDP(c, (db_ret8 << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret8 << 0x10) + 0xA164, (uint8_t)(value28 - 1));
        if ((uint8_t)(value28 - 1) != 0) {
            a_hi1 = a_all8 >> 8;
            y1 = y_ret8;
            carry1 = carry_ret8;
            overflow1 = overflow_ret8;
            data_bank = db_ret8;
            direct_page = dp_ret8;
            continue;
        }
        a_hi1 = a_all8 >> 8;
        y1 = y_ret8;
        carry1 = carry_ret8;
        overflow1 = overflow_ret8;
        data_bank = db_ret8;
        direct_page = dp_ret8;
        break;
    }
    uint8_t value29 = RAM8(0x0000 + sp0 - 1);
    uint8_t value30 = RAM8(0x0000 + sp0);
    RAM8(0x0000 + sp0) = value30;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((value30 << 8) | value29);
    r->a = ((value30 << 8) | value29) ^ 0x4000;
    r->x = ((value30 << 8) | value29) ^ 0x4000;
    r->y = y1;
    r->c = carry1;
    r->z = (((value30 << 8) | value29) ^ 0x4000) == 0;
    r->n = (((value30 << 8) | value29) ^ 0x4000) & 0x8000;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0CB0, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0CB0); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    r->sp += 2;
    uint8_t db_ret9 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint8_t value31 = BUS8_RDP(c, (db_ret9 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret9 << 0x10) + 0xA156, (uint8_t)(value31 - 1));
    r->z = (uint8_t)(value31 - 1) == 0;
    r->n = (uint8_t)(value31 - 1) & 0x80;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0CB6, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0CB6); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    r->sp += 2;
    uint16_t dp_ret10 = r->dp;
    uint8_t db_ret10 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all10 = r->a;
    uint16_t y_ret10 = r->y;
    bool overflow_ret10 = r->v;
    uint8_t value32 = BUS8_RDP(c, (db_ret10 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret10 << 0x10) + 0xA165, value32);
    uint8_t value33 = BUS8_RDP(c, (db_ret10 << 0x10) + 0xA163);
    BUS8_SET(c, (db_ret10 << 0x10) + 0xA163, (uint8_t)(value33 - 1));
    if ((uint8_t)(value33 - 1) != 0) {
        uint8_t value34 = BUS8_RDP(c, (db_ret10 << 0x10) + 0xA16C);
        if (!(value34 & 0x01)) {
            a_0ccc = value34 >> 1;
            a_hi_0ccc = a_all10 >> 8;
            y_0ccc = y_ret10;
            overflow_0ccc = overflow_ret10;
            direct_page_0ccc = dp_ret10;
            data_bank_0ccc = db_ret10;
            goto shared_0CCC;
        }
        a_0ccc = (value34 >> 1) + 1;
        a_hi_0ccc = a_all10 >> 8;
        y_0ccc = y_ret10;
        overflow_0ccc = overflow_ret10;
        direct_page_0ccc = dp_ret10;
        data_bank_0ccc = db_ret10;
        goto shared_0CCC;
    }
    uint8_t value35 = BUS8_RDP(c, (db_ret10 << 0x10) + 0xA15C);
    BUS8_SET(c, (db_ret10 << 0x10) + 0xA15C, (uint8_t)(value35 + 1));
    uint8_t value36 = BUS8_RDP(c, (db_ret10 << 0x10) + 0xA171);
    BUS8_SET(c, (db_ret10 << 0x10) + 0xA171, (uint8_t)(value36 + 1));
    uint8_t value37 = BUS8_RDP(c, (db_ret10 << 0x10) + 0xA171);
    BUS8_SET(c, (db_ret10 << 0x10) + 0xA171, (uint8_t)(value37 + 1));
    uint8_t value38 = RAM8(0x0000 + sp0 - 1);
    uint8_t value39 = RAM8(0x0000 + sp0);
    r->a = (a_all10 >> 8 << 8) | value32;
    r->z = (uint8_t)(value37 + 1) == 0;
    r->n = (uint8_t)(value37 + 1) & 0x80;
    TAIL_CALL_DYN(c, 0xC00000 | (uint16_t)(((value39 << 8) | value38) + 1), SOM_RTS); /* jump through a pushed address */
    shared_0CCC:;
    BUS8_SET(c, (data_bank_0ccc << 0x10) + 0xA164, a_0ccc);
    uint8_t value40 = BUS8_RDP(c, (data_bank_0ccc << 0x10) + 0xA167);
    BUS8_SET(c, (data_bank_0ccc << 0x10) + 0xA156, value40);
    uint8_t value41 = BUS8_RDP(c, (data_bank_0ccc << 0x10) + 0xA166);
    BUS8_SET(c, (data_bank_0ccc << 0x10) + 0xA157, value41);
    uint8_t value42 = RAM8(0x0000 + sp0 - 1);
    uint8_t value43 = RAM8(0x0000 + sp0);
    RAM8(0x0000 + sp0) = (((value43 << 8) | value42) ^ 0x8000) >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)(((value43 << 8) | value42) ^ 0x8000);
    r->a = ((value43 << 8) | value42) ^ 0x8000;
    r->x = ((value43 << 8) | value42) ^ 0x8000;
    r->y = y_0ccc;
    r->z = (((value43 << 8) | value42) ^ 0x8000) == 0;
    r->n = (((value43 << 8) | value42) ^ 0x8000) & 0x8000;
    r->v = overflow_0ccc;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_0ccc;
    r->dp = direct_page_0ccc;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0CE7, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0CE7); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    r->sp += 2;
    uint8_t db_ret11 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint8_t value44 = BUS8_RDP(c, (db_ret11 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret11 << 0x10) + 0xA156, (uint8_t)(value44 + 1));
    r->z = (uint8_t)(value44 + 1) == 0;
    r->n = (uint8_t)(value44 + 1) & 0x80;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0CED, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0CED); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    r->sp += 2;
    uint16_t dp_ret12 = r->dp;
    uint8_t db_ret12 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all12 = r->a;
    uint16_t y_ret12 = r->y;
    bool carry_ret12 = r->c;
    bool overflow_ret12 = r->v;
    uint8_t value45 = BUS8_RDP(c, (db_ret12 << 0x10) + 0xA157);
    BUS8_SET(c, (db_ret12 << 0x10) + 0xA157, (uint8_t)(value45 + 1));
    uint8_t value46 = BUS8_RDP(c, (db_ret12 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret12 << 0x10) + 0xA156, (uint8_t)(value46 - 1));
    uint8_t a_hi2 = a_all12 >> 8;
    uint16_t y2 = y_ret12;
    bool carry2 = carry_ret12;
    bool overflow2 = overflow_ret12;
    uint8_t data_bank2 = db_ret12;
    uint16_t direct_page2 = dp_ret12;
    for (;;) {
        r->a = (a_hi2 << 8) | a;
        r->x = 0x0118;
        r->y = y2;
        r->c = carry2;
        r->z = 0;
        r->n = 0;
        r->v = overflow2;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank2;
        r->dp = direct_page2;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0CF9, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0CF9); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        r->sp += 2;
        uint8_t db_ret13 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint8_t value47 = BUS8_RDP(c, (db_ret13 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret13 << 0x10) + 0xA156, (uint8_t)(value47 + 1));
        r->z = (uint8_t)(value47 + 1) == 0;
        r->n = (uint8_t)(value47 + 1) & 0x80;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0CFF, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0CFF); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        r->sp += 2;
        uint16_t dp_ret14 = r->dp;
        uint8_t db_ret14 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all14 = r->a;
        uint16_t y_ret14 = r->y;
        bool overflow_ret14 = r->v;
        uint8_t value48 = BUS8_RDP(c, (db_ret14 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret14 << 0x10) + 0xA157, (uint8_t)(value48 + 1));
        uint8_t value49 = BUS8_RDP(c, (db_ret14 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret14 << 0x10) + 0xA156, (uint8_t)(value49 - 1));
        uint8_t value50 = BUS8_RDP(c, (db_ret14 << 0x10) + 0xA164);
        if (value50 != 1) {
            r->a = (a_all14 >> 8 << 8) | value50;
            r->x = 0x0118;
            r->c = value50 >= 1;
            r->z = 0;
            r->n = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0D18, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0D18); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            r->sp += 2;
            uint8_t db_ret15 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            uint8_t value51 = BUS8_RDP(c, (db_ret15 << 0x10) + 0xA156);
            BUS8_SET(c, (db_ret15 << 0x10) + 0xA156, (uint8_t)(value51 + 1));
            r->z = (uint8_t)(value51 + 1) == 0;
            r->n = (uint8_t)(value51 + 1) & 0x80;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0D1E, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0D1E); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            r->sp += 2;
            uint16_t dp_ret16 = r->dp;
            uint8_t db_ret16 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all16 = r->a;
            uint16_t y_ret16 = r->y;
            bool carry_ret16 = r->c;
            bool overflow_ret16 = r->v;
            uint8_t value52 = BUS8_RDP(c, (db_ret16 << 0x10) + 0xA157);
            BUS8_SET(c, (db_ret16 << 0x10) + 0xA157, (uint8_t)(value52 + 1));
            uint8_t value53 = BUS8_RDP(c, (db_ret16 << 0x10) + 0xA156);
            BUS8_SET(c, (db_ret16 << 0x10) + 0xA156, (uint8_t)(value53 - 1));
            uint8_t value54 = BUS8_RDP(c, (db_ret16 << 0x10) + 0xA164);
            BUS8_SET(c, (db_ret16 << 0x10) + 0xA164, (uint8_t)(value54 - 1));
            if ((uint8_t)(value54 - 1) != 0) {
                a_hi2 = a_all16 >> 8;
                y2 = y_ret16;
                carry2 = carry_ret16;
                overflow2 = overflow_ret16;
                data_bank2 = db_ret16;
                direct_page2 = dp_ret16;
                continue;
            }
            a_hi2 = a_all16 >> 8;
            y2 = y_ret16;
            carry2 = carry_ret16;
            overflow2 = overflow_ret16;
            data_bank2 = db_ret16;
            direct_page2 = dp_ret16;
            break;
        }
        uint8_t value55 = BUS8_RDP(c, (db_ret14 << 0x10) + 0xA16C);
        if (value55 & 0x01) {
            uint8_t value56 = BUS8_RDP(c, (db_ret14 << 0x10) + 0xA164);
            BUS8_SET(c, (db_ret14 << 0x10) + 0xA164, (uint8_t)(value56 - 1));
            if ((uint8_t)(value56 - 1) != 0) {
                a_hi2 = a_all14 >> 8;
                y2 = y_ret14;
                carry2 = value55 & 0x01;
                overflow2 = overflow_ret14;
                data_bank2 = db_ret14;
                direct_page2 = dp_ret14;
                continue;
            }
            a_hi2 = a_all14 >> 8;
            y2 = y_ret14;
            carry2 = value55 & 0x01;
            overflow2 = overflow_ret14;
            data_bank2 = db_ret14;
            direct_page2 = dp_ret14;
            break;
        }
        r->a = (a_all14 >> 8 << 8) | (value55 >> 1);
        r->x = 0x0118;
        r->c = value55 & 0x01;
        r->z = 0;
        r->n = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0D18, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0D18); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        r->sp += 2;
        uint8_t db_ret17 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint8_t value57 = BUS8_RDP(c, (db_ret17 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret17 << 0x10) + 0xA156, (uint8_t)(value57 + 1));
        r->z = (uint8_t)(value57 + 1) == 0;
        r->n = (uint8_t)(value57 + 1) & 0x80;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0D1E, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0D1E); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        r->sp += 2;
        uint16_t dp_ret18 = r->dp;
        uint8_t db_ret18 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all18 = r->a;
        uint16_t y_ret18 = r->y;
        bool carry_ret18 = r->c;
        bool overflow_ret18 = r->v;
        uint8_t value58 = BUS8_RDP(c, (db_ret18 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret18 << 0x10) + 0xA157, (uint8_t)(value58 + 1));
        uint8_t value59 = BUS8_RDP(c, (db_ret18 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret18 << 0x10) + 0xA156, (uint8_t)(value59 - 1));
        uint8_t value60 = BUS8_RDP(c, (db_ret18 << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret18 << 0x10) + 0xA164, (uint8_t)(value60 - 1));
        if ((uint8_t)(value60 - 1) != 0) {
            a_hi2 = a_all18 >> 8;
            y2 = y_ret18;
            carry2 = carry_ret18;
            overflow2 = overflow_ret18;
            data_bank2 = db_ret18;
            direct_page2 = dp_ret18;
            continue;
        }
        a_hi2 = a_all18 >> 8;
        y2 = y_ret18;
        carry2 = carry_ret18;
        overflow2 = overflow_ret18;
        data_bank2 = db_ret18;
        direct_page2 = dp_ret18;
        break;
    }
    uint8_t value61 = RAM8(0x0000 + sp0 - 1);
    uint8_t value62 = RAM8(0x0000 + sp0);
    r->a = ((value62 << 8) | value61) ^ 0x4000;
    r->x = ((value62 << 8) | value61) ^ 0x4000;
    r->y = y2;
    r->c = carry2;
    r->z = (((value62 << 8) | value61) ^ 0x4000) == 0;
    r->n = (((value62 << 8) | value61) ^ 0x4000) & 0x8000;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank2;
    r->dp = direct_page2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0D35, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0D35); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint8_t db_ret19 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint8_t value63 = BUS8_RDP(c, (db_ret19 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret19 << 0x10) + 0xA156, (uint8_t)(value63 + 1));
    r->z = (uint8_t)(value63 + 1) == 0;
    r->n = (uint8_t)(value63 + 1) & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0D3B, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0D3B); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint8_t db_ret20 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint8_t value64 = BUS8_RDP(c, (db_ret20 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret20 << 0x10) + 0xA167, value64);
    uint8_t value65 = BUS8_RDP(c, (db_ret20 << 0x10) + 0xA163);
    BUS8_SET(c, (db_ret20 << 0x10) + 0xA163, (uint8_t)(value65 - 1));
    if ((uint8_t)(value65 - 1) != 0) {
        uint8_t value66 = BUS8_RDP(c, (db_ret20 << 0x10) + 0xA171);
        BUS8_SET(c, (db_ret20 << 0x10) + 0xA171, (uint8_t)(value66 + 1));
        uint8_t value67 = BUS8_RDP(c, (db_ret20 << 0x10) + 0xA171);
        BUS8_SET(c, (db_ret20 << 0x10) + 0xA171, (uint8_t)(value67 + 1));
        SET_A8(r, value64);
        r->z = (uint8_t)(value67 + 1) == 0;
        r->n = (uint8_t)(value67 + 1) & 0x80;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    uint8_t value68 = BUS8_RDP(c, (db_ret20 << 0x10) + 0xA15C);
    BUS8_SET(c, (db_ret20 << 0x10) + 0xA15C, (uint8_t)(value68 + 1));
    uint8_t value69 = BUS8_RDP(c, (db_ret20 << 0x10) + 0xA171);
    BUS8_SET(c, (db_ret20 << 0x10) + 0xA171, (uint8_t)(value69 + 1));
    uint8_t value70 = BUS8_RDP(c, (db_ret20 << 0x10) + 0xA171);
    BUS8_SET(c, (db_ret20 << 0x10) + 0xA171, (uint8_t)(value70 + 1));
    SET_A8(r, value64);
    r->z = (uint8_t)(value70 + 1) == 0;
    r->n = (uint8_t)(value70 + 1) & 0x80;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00C2A, SOM_RTS, "gen", publish_native_dialogue_frame_side_pairs, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 295, 122)
