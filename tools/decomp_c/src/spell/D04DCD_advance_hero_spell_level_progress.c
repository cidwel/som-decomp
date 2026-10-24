#include "som_c.h"

/* D04DCD advance_hero_spell_level_progress   [class B, 161 bytes, 79 instructions]
 * Source: src/rom/advance_hero_spell_level_progress.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: B.
 */
static void advance_hero_spell_level_progress(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(ACTOR_KIND_FLAGS + y);
    if (!(value & 0x80)) {
        RETURN_RTL(c);
    }
    r->a = (a_hi << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4DD5, 0xD04E6E); GUARD_JSR(c, sp_call, 0x4DD5); } /* read_actor_element_spell_level */
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    uint8_t value2 = RAM8(0xCFFC);
    uint8_t a1;
    if (value2 != 8) {
        a1 = value2;
    } else {
        a1 = (uint8_t)(value2 + 1);
    }
    BUS8_SET(c, (uint16_t)(dp + 0xA6), a1);
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp + 0x9D));
    uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp + 0xA6));
    if (value3 >= value4) {
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 0x9E));
        BUS8_SET(c, (uint16_t)(dp + 0xA8), value5);
        if (x_ret) {
            uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp + 0x83));
            BUS8_SET(c, (uint16_t)(dp + 0xCC), RAM8(0xE177 + value6));
            uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
            uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp + 0xA8));
            RAM8(0xE1D8 + value8) = value9;
            uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp + 0x83));
            r->xf = 1;
            RETURN_RTL(c);
        } else {
            uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp + 0x83));
            BUS8_SET(c, (uint16_t)(dp + 0xCC), RAM8(0xE177 + value11));
            uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp + 0xCC));
            uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp + 0xA8));
            RAM8(0xE1D8 + value13) = value14;
            uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp + 0x83));
            r->xf = 0;
            RETURN_RTL(c);
        }
    }
    uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp + 0x9D));
    BUS8_SET(c, (uint16_t)(dp + 0xAC), (uint8_t)(9 - value16));
    if (!(RAM8(0x00ED) & 0x80)) {
        uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp + 0xAC));
        BUS8_SET(c, (uint16_t)(dp + 0xAC), value18 >> 1);
    }
    BUS8_SET(c, (uint16_t)(dp + 0xCC), RAM8(0xE177 + y_ret));
    if (x_ret) {
        uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
        uint8_t value21 = RAM8(0xE1D8 + value20);
        BUS8_SET(c, (uint16_t)(dp + 0x9E), value21);
        uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp + 0xAC));
        BUS8_SET(c, (uint16_t)(dp + 0xA8), (uint8_t)(value21 + value22));
        if ((uint8_t)(value21 + value22) < 0x64) {
            uint8_t value23 = BUS8_RDP(c, (uint16_t)(dp + 0x83));
            BUS8_SET(c, (uint16_t)(dp + 0xCC), RAM8(0xE177 + value23));
            uint8_t value25 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
            uint8_t value26 = BUS8_RDP(c, (uint16_t)(dp + 0xA8));
            RAM8(0xE1D8 + value25) = value26;
            uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp + 0x83));
            r->xf = 1;
            RETURN_RTL(c);
        }
        uint8_t value28 = BUS8_RDP(c, (uint16_t)(dp + 0x9D));
        if (value28 == 8) {
            BUS8_SET(c, (uint16_t)(dp + 0xA8), 0x63);
            uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp + 0x83));
            BUS8_SET(c, (uint16_t)(dp + 0xCC), RAM8(0xE177 + value29));
            uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
            uint8_t value32 = BUS8_RDP(c, (uint16_t)(dp + 0xA8));
            RAM8(0xE1D8 + value31) = value32;
            uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp + 0x83));
            r->xf = 1;
            RETURN_RTL(c);
        }
        BUS8_SET(c, (uint16_t)(dp + 0xA8), 0);
        uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp + 0x9D));
        BUS8_SET(c, (uint16_t)(dp + 0x9D), (uint8_t)(value34 + 1));
        uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp + 0x83));
        uint8_t value36 = RAM8(0xE177 + value35);
        uint8_t y1;
        bool carry1;
        bool overflow1;
        if ((value36 & 1) != 0) {
            BUS8_SET(c, (uint16_t)(dp + 0xCC), value36 >> 1);
            uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
            RAM8(0xE1C4 + value37) = (uint8_t)(RAM8(0xE1C4 + value37) + 1);
            y1 = value37;
            carry1 = value36 & 0x01;
            overflow1 = ((value21 ^ (uint8_t)(value21 + value22)) & (value22 ^ (uint8_t)(value21 + value22)) & 0x80) != 0;
        } else {
            BUS8_SET(c, (uint16_t)(dp + 0xCC), value36 >> 1);
            uint8_t value39 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
            uint8_t value40 = RAM8(0xE1C4 + value39);
            RAM8(0xE1C4 + value39) = (uint8_t)(value40 + 0x10);
            y1 = value39;
            carry1 = value40 + 0x10 > 0xFF;
            overflow1 = ((value40 ^ (uint8_t)(value40 + 0x10)) & ((uint8_t)(value40 + 0x10) ^ 0x10) & 0x80) != 0;
        }
        uint8_t value41 = BUS8_RDP(c, (uint16_t)(dp + 0xA8));
        RAM8(0x0000 + sp0) = value41;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
        RAM8(0x0000 + sp0 - 2) = y1;
        uint8_t value42 = BUS8_RDP(c, (uint16_t)(dp + 0x83));
        r->a = (a_all >> 8 << 8) | value41;
        r->x = value42;
        r->y = y1;
        r->c = carry1;
        r->z = value42 == 0;
        r->n = value42 & 0x80;
        r->v = overflow1;
        r->xf = 1;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4E4F, 0xC05B75); GUARD_JSL(c, sp_call, 0x4E4F); } /* enqueue_spell_element_level_up_notice */
        r->sp += 3;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        r->a = (a_all2 >> 8 << 8) | 0xCF;
        r->z = 0;
        r->n = 1;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4E55, 0xC03989); GUARD_JSL(c, sp_call, 0x4E55); } /* send_combat_sound_through_native_long_call_wrapper */
        r->sp += 3;
        bool m_ret = r->mf;
        bool x_ret4 = r->xf;
        if (x_ret4) {
            BUS8_SET(c, (uint16_t)(dp + 0xCC), RAM8(0x0000 + sp0 - 2));
            if (m_ret) {
                BUS8_SET(c, (uint16_t)(dp + 0xA8), RAM8(0x0000 + sp0));
                uint8_t value46 = BUS8_RDP(c, (uint16_t)(dp + 0x83));
                BUS8_SET(c, (uint16_t)(dp + 0xCC), RAM8(0xE177 + value46));
                uint8_t value48 = BUS8_RDP(c, (uint16_t)(dp + 0xCC));
                uint8_t value49 = BUS8_RDP(c, (uint16_t)(dp + 0xA8));
                RAM8(0xE1D8 + value48) = value49;
                uint8_t value50 = BUS8_RDP(c, (uint16_t)(dp + 0x83));
                r->mf = 1;
                r->xf = 1;
                RETURN_RTL(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            c->fail = 3;
            return;
        }
    } else {
        uint16_t value53 = BUS16_RDP(c, (uint16_t)(dp + 0xCC));
        uint8_t value54 = RAM8(0xE1D8 + value53);
        BUS8_SET(c, (uint16_t)(dp + 0x9E), value54);
        uint8_t value55 = BUS8_RDP(c, (uint16_t)(dp + 0xAC));
        BUS8_SET(c, (uint16_t)(dp + 0xA8), (uint8_t)(value54 + value55));
        if ((uint8_t)(value54 + value55) < 0x64) {
            uint16_t value56 = BUS16_RDP(c, (uint16_t)(dp + 0x83));
            BUS8_SET(c, (uint16_t)(dp + 0xCC), RAM8(0xE177 + value56));
            uint16_t value58 = BUS16_RDP(c, (uint16_t)(dp + 0xCC));
            uint8_t value59 = BUS8_RDP(c, (uint16_t)(dp + 0xA8));
            RAM8(0xE1D8 + value58) = value59;
            uint16_t value60 = BUS16_RDP(c, (uint16_t)(dp + 0x83));
            r->xf = 0;
            RETURN_RTL(c);
        }
        uint8_t value61 = BUS8_RDP(c, (uint16_t)(dp + 0x9D));
        if (value61 == 8) {
            BUS8_SET(c, (uint16_t)(dp + 0xA8), 0x63);
            uint16_t value62 = BUS16_RDP(c, (uint16_t)(dp + 0x83));
            BUS8_SET(c, (uint16_t)(dp + 0xCC), RAM8(0xE177 + value62));
            uint16_t value64 = BUS16_RDP(c, (uint16_t)(dp + 0xCC));
            uint8_t value65 = BUS8_RDP(c, (uint16_t)(dp + 0xA8));
            RAM8(0xE1D8 + value64) = value65;
            uint16_t value66 = BUS16_RDP(c, (uint16_t)(dp + 0x83));
            r->xf = 0;
            RETURN_RTL(c);
        }
        BUS8_SET(c, (uint16_t)(dp + 0xA8), 0);
        uint8_t value67 = BUS8_RDP(c, (uint16_t)(dp + 0x9D));
        BUS8_SET(c, (uint16_t)(dp + 0x9D), (uint8_t)(value67 + 1));
        uint16_t value68 = BUS16_RDP(c, (uint16_t)(dp + 0x83));
        uint8_t value69 = RAM8(0xE177 + value68);
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if ((value69 & 1) != 0) {
            BUS8_SET(c, (uint16_t)(dp + 0xCC), value69 >> 1);
            uint16_t value70 = BUS16_RDP(c, (uint16_t)(dp + 0xCC));
            RAM8(0xE1C4 + value70) = (uint8_t)(RAM8(0xE1C4 + value70) + 1);
            y2 = value70;
            carry2 = value69 & 0x01;
            overflow2 = ((value54 ^ (uint8_t)(value54 + value55)) & (value55 ^ (uint8_t)(value54 + value55)) & 0x80) != 0;
        } else {
            BUS8_SET(c, (uint16_t)(dp + 0xCC), value69 >> 1);
            uint16_t value72 = BUS16_RDP(c, (uint16_t)(dp + 0xCC));
            uint8_t value73 = RAM8(0xE1C4 + value72);
            RAM8(0xE1C4 + value72) = (uint8_t)(value73 + 0x10);
            y2 = value72;
            carry2 = value73 + 0x10 > 0xFF;
            overflow2 = ((value73 ^ (uint8_t)(value73 + 0x10)) & ((uint8_t)(value73 + 0x10) ^ 0x10) & 0x80) != 0;
        }
        uint8_t value74 = BUS8_RDP(c, (uint16_t)(dp + 0xA8));
        RAM8(0x0000 + sp0) = value74;
        RAM8(0x0000 + sp0 - 1) = x >> 8;
        RAM8(0x0000 + sp0 - 2) = (uint8_t)x;
        RAM8(0x0000 + sp0 - 3) = y2 >> 8;
        RAM8(0x0000 + sp0 - 4) = (uint8_t)y2;
        uint16_t value75 = BUS16_RDP(c, (uint16_t)(dp + 0x83));
        r->a = (a_all >> 8 << 8) | value74;
        r->x = value75;
        r->y = y2;
        r->c = carry2;
        r->z = value75 == 0;
        r->n = value75 & 0x8000;
        r->v = overflow2;
        r->xf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4E4F, 0xC05B75); GUARD_JSL(c, sp_call, 0x4E4F); } /* enqueue_spell_element_level_up_notice */
        r->sp += 5;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all4 = r->a;
        r->a = (a_all4 >> 8 << 8) | 0xCF;
        r->z = 0;
        r->n = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4E55, 0xC03989); GUARD_JSL(c, sp_call, 0x4E55); } /* send_combat_sound_through_native_long_call_wrapper */
        r->sp += 5;
        bool m_ret2 = r->mf;
        bool x_ret8 = r->xf;
        if (x_ret8) {
            c->fail = 3;
            return;
        } else {
            BUS16_SET(c, (uint16_t)(dp + 0xCC), (RAM8(0x0000 + sp0 - 3) << 8) | RAM8(0x0000 + sp0 - 4));
            if (m_ret2) {
                BUS8_SET(c, (uint16_t)(dp + 0xA8), RAM8(0x0000 + sp0));
                uint16_t value96 = BUS16_RDP(c, (uint16_t)(dp + 0x83));
                BUS8_SET(c, (uint16_t)(dp + 0xCC), RAM8(0xE177 + value96));
                uint16_t value98 = BUS16_RDP(c, (uint16_t)(dp + 0xCC));
                uint8_t value99 = BUS8_RDP(c, (uint16_t)(dp + 0xA8));
                RAM8(0xE1D8 + value98) = value99;
                uint16_t value100 = BUS16_RDP(c, (uint16_t)(dp + 0x83));
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            } else {
                c->fail = 3;
                return;
            }
        }
    }
}
SOM_REGISTER(0xD04DCD, SOM_RTL, "gen", advance_hero_spell_level_progress, 0, L_B, 5, 1, 0, 161, 79)
