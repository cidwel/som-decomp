; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-cells.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_actor_effect_cell_toward_live_target = $8DDE

.segment "CODE"
.org $8DC5
iterate_native_effect_cells_with_shared_restore_state:
    sep #$20
    lda a:$E110,X
    .a8
    cmp #$04
    bne iterate_native_effect_cells_with_shared_restore_state_c18dcf
    rts
iterate_native_effect_cells_with_shared_restore_state_c18dcf:
    .i16
    ldy #$0000
    jsr advance_native_actor_effect_cell_toward_live_target
    .i16
    ldy #$0010
    jsr advance_native_actor_effect_cell_toward_live_target
    .i16
    ldy #$0020
