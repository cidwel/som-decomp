; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five.md.
.setcpu "65816"
.smart
.a8
.i16

compute_capped_boss_maximum_over_current_hp_ratio = $09B4

.segment "CODE"
.org $6059
advance_descriptor_five_hp_ratio_phase:
    ldx $87
    jsr compute_capped_boss_maximum_over_current_hp_ratio
    .a16
    cmp #$0002
    bcs advance_descriptor_five_hp_ratio_phase_c26067
    .a16
    lda #$DD60
    rts
advance_descriptor_five_hp_ratio_phase_c26067:
    ldx $87
    .a16
    lda #$0001
    sta a:$007E,X
    .a16
    lda #$DD63
    rts
