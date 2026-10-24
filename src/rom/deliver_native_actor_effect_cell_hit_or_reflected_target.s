; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-cells.md.
.setcpu "65816"
.smart
.a8
.i16

deliver_complete_cast_hit_to_target = $8D12

.segment "CODE"
.org $8E74
deliver_native_actor_effect_cell_hit_or_reflected_target:
    rep #$20
    lda a:$E116,Y
    phy
    phx
    tay
    jsr deliver_complete_cast_hit_to_target
    bcs deliver_native_actor_effect_cell_hit_or_reflected_target_c18e8b
    plx
    ply
    sep #$20
    .a8
    lda #$00
    sta a:$E110,Y
    rts
deliver_native_actor_effect_cell_hit_or_reflected_target_c18e8b:
    plx
    ply
    rep #$20
    sta a:$E116,Y
    rts
