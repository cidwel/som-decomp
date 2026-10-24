#include "som_c.h"

/* C1CBEA snapshot_map_scroll_and_actor_cache   [class B, 208 bytes, 101 instructions]
 * Source: src/rom/snapshot_map_scroll_and_actor_cache.s
 * Documented in docs/cutscene-engine.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABYCV.
 */
static void snapshot_map_scroll_and_actor_cache(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x00D4);
    uint16_t value2 = RAM16(0xE020 + value);
    RAM16_SET(0x0000, (uint16_t)(value2 - 0x80));
    RAM16_SET(0x0004, (uint16_t)(value2 - 0x80));
    uint16_t value3 = RAM16(0xE022 + value);
    RAM16_SET(0x0002, (uint16_t)(value3 - 0x70));
    RAM16_SET(0x0006, (uint16_t)(value3 - 0x70));
    if ((RAM16(0x0A80) & 0x0F) == 0) {
        RAM16_SET(0x0000, 0);
    }
    if ((RAM16(0x0A90) & 0x0F) == 0) {
        RAM16_SET(0x0002, 0);
    }
    if ((RAM16(0x0AA0) & 0x0F) == 0) {
        RAM16_SET(0x0004, 0);
    }
    if ((RAM16(0x0AB0) & 0x0F) == 0) {
        RAM16_SET(0x0006, 0);
    }
    uint16_t value8 = RAM16(0x00A8);
    uint16_t value9 = RAM16(0x0000);
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value8 + value9) & 0x8000)) {
        a1 = (uint8_t)(value8 + value9);
        a_hi1 = (uint16_t)(value8 + value9) >> 8;
    } else {
        uint16_t value10 = RAM16(0x00C0);
        a1 = (uint8_t)((uint16_t)(value8 + value9) + value10);
        a_hi1 = (uint16_t)((uint16_t)(value8 + value9) + value10) >> 8;
    }
    uint16_t value11 = RAM16(0x00C0);
    uint8_t a2;
    uint8_t a_hi2;
    if (((a_hi1 << 8) | a1) < value11) {
        a2 = a1;
        a_hi2 = a_hi1;
    } else {
        a2 = (uint8_t)(((a_hi1 << 8) | a1) - value11 - (((a_hi1 << 8) | a1) >= value11 ^ 1));
        a_hi2 = (uint16_t)(((a_hi1 << 8) | a1) - value11 - (((a_hi1 << 8) | a1) >= value11 ^ 1)) >> 8;
    }
    RAM16_SET(0xCD00, (a_hi2 << 8) | a2);
    uint16_t value12 = RAM16(0x00AA);
    uint16_t value13 = RAM16(0x0002);
    uint8_t a3;
    uint8_t a_hi3;
    if (!((uint16_t)(value12 + value13) & 0x8000)) {
        a3 = (uint8_t)(value12 + value13);
        a_hi3 = (uint16_t)(value12 + value13) >> 8;
    } else {
        uint16_t value14 = RAM16(0x00C2);
        a3 = (uint8_t)((uint16_t)(value12 + value13) + value14);
        a_hi3 = (uint16_t)((uint16_t)(value12 + value13) + value14) >> 8;
    }
    uint16_t value15 = RAM16(0x00C2);
    uint8_t a4;
    uint8_t a_hi4;
    if (((a_hi3 << 8) | a3) < value15) {
        a4 = a3;
        a_hi4 = a_hi3;
    } else {
        a4 = (uint8_t)(((a_hi3 << 8) | a3) - value15 - (((a_hi3 << 8) | a3) >= value15 ^ 1));
        a_hi4 = (uint16_t)(((a_hi3 << 8) | a3) - value15 - (((a_hi3 << 8) | a3) >= value15 ^ 1)) >> 8;
    }
    RAM16_SET(0xCD02, (a_hi4 << 8) | a4);
    uint16_t value16 = RAM16(0x00AC);
    uint16_t value17 = RAM16(0x0004);
    uint8_t a5;
    uint8_t a_hi5;
    if (!((uint16_t)(value16 + value17) & 0x8000)) {
        a5 = (uint8_t)(value16 + value17);
        a_hi5 = (uint16_t)(value16 + value17) >> 8;
    } else {
        uint16_t value18 = RAM16(0x00C4);
        a5 = (uint8_t)((uint16_t)(value16 + value17) + value18);
        a_hi5 = (uint16_t)((uint16_t)(value16 + value17) + value18) >> 8;
    }
    uint16_t value19 = RAM16(0x00C4);
    uint8_t a6;
    uint8_t a_hi6;
    if (((a_hi5 << 8) | a5) < value19) {
        a6 = a5;
        a_hi6 = a_hi5;
    } else {
        a6 = (uint8_t)(((a_hi5 << 8) | a5) - value19 - (((a_hi5 << 8) | a5) >= value19 ^ 1));
        a_hi6 = (uint16_t)(((a_hi5 << 8) | a5) - value19 - (((a_hi5 << 8) | a5) >= value19 ^ 1)) >> 8;
    }
    RAM16_SET(0xCD04, (a_hi6 << 8) | a6);
    uint16_t value20 = RAM16(0x00AE);
    uint16_t value21 = RAM16(0x0006);
    uint8_t a7;
    uint8_t a_hi7;
    if (!((uint16_t)(value20 + value21) & 0x8000)) {
        a7 = (uint8_t)(value20 + value21);
        a_hi7 = (uint16_t)(value20 + value21) >> 8;
    } else {
        uint16_t value22 = RAM16(0x00C6);
        a7 = (uint8_t)((uint16_t)(value20 + value21) + value22);
        a_hi7 = (uint16_t)((uint16_t)(value20 + value21) + value22) >> 8;
    }
    uint16_t value23 = RAM16(0x00C6);
    uint8_t a8;
    uint8_t a_hi8;
    if (((a_hi7 << 8) | a7) < value23) {
        a8 = a7;
        a_hi8 = a_hi7;
    } else {
        a8 = (uint8_t)(((a_hi7 << 8) | a7) - value23 - (((a_hi7 << 8) | a7) >= value23 ^ 1));
        a_hi8 = (uint16_t)(((a_hi7 << 8) | a7) - value23 - (((a_hi7 << 8) | a7) >= value23 ^ 1)) >> 8;
    }
    RAM16_SET(0xCD06, (a_hi8 << 8) | a8);
    uint16_t value24 = RAM16(0x00DC);
    RAM16_SET(0xCD08, value24);
    uint8_t value25 = RAM8(0xE00B + value);
    RAM8(0xCD0A) = value25;
    uint8_t a9 = value25;
    uint8_t a_hi9 = value24 >> 8;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    bool carry1 = 0;
    bool overflow1 = 0;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint8_t value26 = RAM8(0xC800 + x1);
            uint8_t a_hi10;
            uint16_t y2;
            if (!(value26 & 0x80)) {
                a_hi10 = a_hi9;
                y2 = y1;
            } else {
                r->x = x1;
                r->y = y1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                r->sp -= 1;
                JSR(c, 0xCC9B, 0xC1CCBA); /* refresh_snapshot_actor_position */
                r->sp += 1;
                uint16_t a_all = r->a;
                uint16_t y_ret = r->y;
                a_hi10 = a_all >> 8;
                y2 = y_ret;
            }
            RAM8(0xCD72 + y2) = RAM8(0xC80C + x1);
            RAM16_SET(0xCD70 + y2, RAM16(0xC80A + x1));
            if ((uint16_t)(y2 + 3) < 0x90) {
                uint8_t a9_next = (uint8_t)(x1 + 0x10);
                uint8_t a_hi9_next = (uint16_t)(x1 + 0x10) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 0x10);
                uint16_t y1_next = (uint16_t)(y2 + 3);
                bool carry1_next = (uint16_t)(y2 + 3) >= 0x90;
                bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
                a9 = a9_next;
                a_hi9 = a_hi9_next;
                x1 = x1_next;
                y1 = y1_next;
                carry1 = carry1_next;
                overflow1 = overflow1_next;
                first_pass = false;
                continue;
            }
            uint8_t a9_next2 = (uint8_t)(x1 + 0x10);
            uint8_t a_hi9_next2 = (uint16_t)(x1 + 0x10) >> 8;
            uint16_t x1_next2 = (uint16_t)(x1 + 0x10);
            uint16_t y1_next2 = (uint16_t)(y2 + 3);
            bool carry1_next2 = (uint16_t)(y2 + 3) >= 0x90;
            bool overflow1_next2 = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
            a9 = a9_next2;
            a_hi9 = a_hi9_next2;
            x1 = x1_next2;
            y1 = y1_next2;
            carry1 = carry1_next2;
            overflow1 = overflow1_next2;
            break;
        } else {
            uint8_t value29 = RAM8(0xC800 + x1);
            uint8_t a_hi11;
            uint16_t y3;
            if (!(value29 & 0x80)) {
                a_hi11 = a_hi9;
                y3 = y1;
            } else {
                r->x = x1;
                r->y = y1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                r->sp -= 1;
                JSR(c, 0xCC9B, 0xC1CCBA); /* refresh_snapshot_actor_position */
                r->sp += 1;
                uint16_t a_all2 = r->a;
                uint16_t y_ret2 = r->y;
                a_hi11 = a_all2 >> 8;
                y3 = y_ret2;
            }
            RAM8(0xCD72 + y3) = RAM8(0xC80C + x1);
            RAM16_SET(0xCD70 + y3, RAM16(0xC80A + x1));
            if ((uint16_t)(y3 + 3) < 0x90) {
                uint8_t a9_next3 = (uint8_t)(x1 + 0x10);
                uint8_t a_hi9_next3 = (uint16_t)(x1 + 0x10) >> 8;
                uint16_t x1_next3 = (uint16_t)(x1 + 0x10);
                uint16_t y1_next3 = (uint16_t)(y3 + 3);
                bool carry1_next3 = (uint16_t)(y3 + 3) >= 0x90;
                bool overflow1_next3 = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
                a9 = a9_next3;
                a_hi9 = a_hi9_next3;
                x1 = x1_next3;
                y1 = y1_next3;
                carry1 = carry1_next3;
                overflow1 = overflow1_next3;
                continue;
            }
            uint8_t a9_next4 = (uint8_t)(x1 + 0x10);
            uint8_t a_hi9_next4 = (uint16_t)(x1 + 0x10) >> 8;
            uint16_t x1_next4 = (uint16_t)(x1 + 0x10);
            uint16_t y1_next4 = (uint16_t)(y3 + 3);
            bool carry1_next4 = (uint16_t)(y3 + 3) >= 0x90;
            bool overflow1_next4 = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
            a9 = a9_next4;
            a_hi9 = a_hi9_next4;
            x1 = x1_next4;
            y1 = y1_next4;
            carry1 = carry1_next4;
            overflow1 = overflow1_next4;
            break;
        }
    }
    r->a = (a_hi9 << 8) | a9;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1CBEA, SOM_RTS, "gen", snapshot_map_scroll_and_actor_cache, 0, L_A | L_B | L_Y | L_C | L_V, 2, 0, 0, 208, 101)
