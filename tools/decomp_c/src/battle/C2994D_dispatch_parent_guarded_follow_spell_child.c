#include "som_c.h"

/* C2994D dispatch_parent_guarded_follow_spell_child   [class C, 130 bytes, 58 instructions]
 * Source: src/rom/dispatch_parent_guarded_follow_spell_child.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 * The 130 bytes are eight identical 16-byte dispatch stanzas (C2:994D, 995D, 996D, 997D, 998D, 999D, 99AD, 99BD) that differ only in the jump table
 * they index, plus the two-byte dead-parent exit at C2:99CD.  Every stanza address is an entry of its own (an object state table points at it).
 */

/* ldy $00B0,X; lda $0190,Y; bmi dead_parent; lda $0094,X; asl; tax; jmp (table,X) */
static void parent_guarded_dispatch(SomCtx *c, uint16_t table)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t x = r->x;
    const uint16_t parent = RAM16(0x00B0 + x);
    const uint16_t parent_flags = RAM16(0x0190 + parent);
    if (parent_flags & 0x8000) {
        r->a = parent_flags;
        r->y = parent;
        r->c = 1;
        r->z = parent_flags == 0;
        r->n = parent_flags & 0x8000;
        RETURN_RTS(c);
    }
    const uint16_t phase = RAM16(OBJECT_PHASE + x);
    const uint16_t index = (uint16_t)(phase << 1);
    r->a = index;
    r->x = index;
    r->y = parent;
    r->c = phase & 0x8000;
    r->z = index == 0;
    r->n = index & 0x8000;
    TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(table + index)), SOM_RTS);
}

#define STANZA(ADDR, NAME, TABLE) \
    static void NAME(SomCtx *c) { parent_guarded_dispatch(c, (TABLE)); } \
    SOM_REGISTER(ADDR, SOM_RTS, "hand", NAME, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 16, 7)

static void dispatch_parent_guarded_follow_spell_child(SomCtx *c) { parent_guarded_dispatch(c, 0x99CF); }
SOM_REGISTER(0xC2994D, SOM_RTS, "hand", dispatch_parent_guarded_follow_spell_child, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 130, 58)

STANZA(0xC2995D, dispatch_parent_guarded_directional_spell_child, 0x99D5)
STANZA(0xC2996D, dispatch_timer_palette_spell_child, 0x99DB)
STANZA(0xC2997D, dispatch_parent_guarded_status_spell_child, 0x99E1)
STANZA(0xC2998D, dispatch_alternating_palette_spell_child, 0x99E7)
STANZA(0xC2999D, dispatch_parent_guarded_pull_spell_child, 0x99ED)
STANZA(0xC299AD, dispatch_parent_guarded_sustained_follow_spell, 0x99F5)
STANZA(0xC299BD, dispatch_parent_guarded_binding_spell, 0x99FB)

/* C2:99CD delete_status_spell_child_for_dead_parent: sec; rts */
static void delete_status_spell_child_for_dead_parent(SomCtx *c)
{
    c->cpu.c = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC299CD, SOM_RTS, "hand", delete_status_spell_child_for_dead_parent, 0, L_C, 1, -1, -1, 2, 2)
