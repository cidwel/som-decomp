; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-freeze-attack-gates.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B102
release_global_actor_freeze_when_visible_effects_finish:
    sep #$20
    bit $F1
    bvs release_global_actor_freeze_when_visible_effects_finish_c0b109
release_global_actor_freeze_when_visible_effects_finish_c0b108:
    rts
release_global_actor_freeze_when_visible_effects_finish_c0b109:
    rep #$10
    .i16
    ldx #$0A00
    bit $ED
    bmi release_global_actor_freeze_when_visible_effects_finish_c0b115
    .i16
    ldx #$0400
release_global_actor_freeze_when_visible_effects_finish_c0b115:
    lda f:$7EE000,X
    beq release_global_actor_freeze_when_visible_effects_finish_c0b125
    bmi release_global_actor_freeze_when_visible_effects_finish_c0b125
    lda f:$7EE060,X
    .a8
    cmp #$C0
    bcs release_global_actor_freeze_when_visible_effects_finish_c0b108
release_global_actor_freeze_when_visible_effects_finish_c0b125:
    rep #$20
    txa
    sec
    .a16
    sbc #$0200
    tax
    sep #$20
    bpl release_global_actor_freeze_when_visible_effects_finish_c0b115
    .a8
    lda #$40
    trb $F1
    rts
