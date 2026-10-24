; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

copy_object_weapon_palette = $859B
restore_actor_cached_fifteen_palette_colors = $D8F3

.segment "CODE"
.org $CAAC
restore_actor_effect_palettes_unless_deferred:
    bit $5C
    bpl restore_actor_effect_palettes_unless_deferred_c1cab5
    .i16
    cpx #$0600
    bcs restore_actor_effect_palettes_unless_deferred_c1cabf
restore_actor_effect_palettes_unless_deferred_c1cab5:
    lda a:$E100,X
    bpl restore_actor_effect_palettes_unless_deferred_c1cabf
    jsr restore_actor_cached_fifteen_palette_colors
    sep #$20
restore_actor_effect_palettes_unless_deferred_c1cabf:
    lda a:$E104,X
    bpl restore_actor_effect_palettes_unless_deferred_c1cacc
    lda a:$E069,X
    jsr copy_object_weapon_palette
    sep #$20
restore_actor_effect_palettes_unless_deferred_c1cacc:
    rts
