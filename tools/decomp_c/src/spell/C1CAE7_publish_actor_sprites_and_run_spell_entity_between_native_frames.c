#include "som_c.h"
/* SOM_POLL_HOOK */

/* C1CAE7 publish_actor_sprites_and_run_spell_entity_between_native_frames   [class B, 43 bytes, 23 instructions]
 * Source: src/rom/publish_actor_sprites_and_run_spell_entity_between_native_frames.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void publish_actor_sprites_and_run_spell_entity_between_native_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    uint64_t loop_guard = 0;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = y >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)y;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSL(c, 0xCAED, 0x00E328); GUARD_JSL(c, sp_call, 0xCAED); } /* cast_sprite_emission_long */
    r->sp += 5;
    uint16_t dp_ret = r->dp;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    BUS8_SET(c, (uint16_t)(dp_ret + 0xEC), 1);
    bool overflow1 = overflow_ret;
    for (;;) {
        LOOP_GUARD(loop_guard);
        uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret + 0xEC));
        overflow1 = value & 0x40;
        if (!((value & 1) != 0)) break;
    }
    if (x_ret) {
        uint8_t value2 = RAM8(0x0000 + sp0 - 4);
        uint8_t value3 = RAM8(0x0000 + sp0 - 3);
        RAM8(0x0000 + sp0 - 3) = value2;
        r->a = (a_all >> 8 << 8) | 1;
        r->x = value2;
        r->y = value3;
        r->c = carry_ret;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0xCB00, 0xC10038); GUARD_JSL(c, sp_call, 0xCB00); } /* execute_native_spell_entity_scheduler_long */
        r->sp += 4;
        bool x_ret3 = r->xf;
        uint16_t y_ret2 = r->y;
        if (x_ret3) {
            uint8_t value4 = RAM8(0x0000 + sp0 - 3);
            r->x = value4;
            r->y = (uint8_t)y_ret2;
            r->z = value4 == 0;
            r->n = value4 & 0x80;
            r->xf = 1;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSL(c, 0xCB05, 0x00E351); GUARD_JSL(c, sp_call, 0xCB05); } /* initialize_sprite_workspace_long */
            r->sp += 3;
            uint16_t dp_ret3 = r->dp;
            uint16_t a_all3 = r->a;
            uint16_t x_ret5 = r->x;
            uint16_t y_ret3 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            uint8_t value5 = RAM8(0x0000 + sp0 - 2);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0xEC), 2);
            bool zero1 = 0;
            bool negative1 = 0;
            bool overflow2 = overflow_ret3;
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0xEC));
                zero1 = (value6 & 2) == 0;
                negative1 = value6 & 0x80;
                overflow2 = value6 & 0x40;
                if (!((value6 & 2) != 0)) break;
            }
            uint8_t value7 = RAM8(0x0000 + sp0 - 1);
            uint8_t value8 = RAM8(0x0000 + sp0);
            r->a = (a_all3 >> 8 << 8) | 2;
            r->x = x_ret5;
            r->y = y_ret3;
            r->c = carry_ret3;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = value5;
            TAIL_CALL_DYN(c, 0xC10000 | (uint16_t)(((value8 << 8) | value7) + 1), SOM_RTS); /* jump through a pushed address */
        } else {
            c->fail = 3;
            return;
        }
    } else {
        uint8_t value13 = RAM8(0x0000 + sp0 - 4);
        uint8_t value14 = RAM8(0x0000 + sp0 - 3);
        uint8_t value15 = RAM8(0x0000 + sp0 - 2);
        uint8_t value16 = RAM8(0x0000 + sp0 - 1);
        RAM8(0x0000 + sp0 - 1) = value14;
        RAM8(0x0000 + sp0 - 2) = (uint8_t)((value14 << 8) | value13);
        r->a = (a_all >> 8 << 8) | 1;
        r->x = (value14 << 8) | value13;
        r->y = (value16 << 8) | value15;
        r->c = carry_ret;
        r->z = ((value16 << 8) | value15) == 0;
        r->n = ((value16 << 8) | value15) & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSL(c, 0xCB00, 0xC10038); GUARD_JSL(c, sp_call, 0xCB00); } /* execute_native_spell_entity_scheduler_long */
        r->sp += 3;
        bool x_ret7 = r->xf;
        if (x_ret7) {
            c->fail = 3;
            return;
        } else {
            uint8_t value20 = RAM8(0x0000 + sp0 - 2);
            uint8_t value21 = RAM8(0x0000 + sp0 - 1);
            r->x = (value21 << 8) | value20;
            r->z = ((value21 << 8) | value20) == 0;
            r->n = ((value21 << 8) | value20) & 0x8000;
            r->xf = 0;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0xCB05, 0x00E351); GUARD_JSL(c, sp_call, 0xCB05); } /* initialize_sprite_workspace_long */
            r->sp += 1;
            uint16_t dp_ret7 = r->dp;
            uint16_t a_all7 = r->a;
            uint16_t x_ret10 = r->x;
            uint16_t y_ret7 = r->y;
            bool carry_ret7 = r->c;
            bool overflow_ret7 = r->v;
            uint8_t value22 = RAM8(0x0000 + sp0);
            BUS8_SET(c, (uint16_t)(dp_ret7 + 0xEC), 2);
            bool zero4 = 0;
            bool negative4 = 0;
            bool overflow5 = overflow_ret7;
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value23 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 0xEC));
                zero4 = (value23 & 2) == 0;
                negative4 = value23 & 0x80;
                overflow5 = value23 & 0x40;
                if (!((value23 & 2) != 0)) break;
            }
            r->a = (a_all7 >> 8 << 8) | 2;
            r->x = x_ret10;
            r->y = y_ret7;
            r->c = carry_ret7;
            r->z = zero4;
            r->n = negative4;
            r->v = overflow5;
            r->mf = 1;
            r->xf = 0;
            r->db = value22;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC1CAE7, SOM_RTS, "gen", publish_actor_sprites_and_run_spell_entity_between_native_frames, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 43, 23)
