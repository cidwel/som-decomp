; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

consume_body_damage_or_parent_phase15_and_enter_hurt = $4DB9
select_native54_body_nearest_party_target = $4BEC

.segment "CODE"
.org $4D20
recover_body_target_after_thirty_two_ticks:
    ldx $87
    lda a:$00B0,X
    tax
    inc a:$00BC,X
    jsr consume_body_damage_or_parent_phase15_and_enter_hurt
    bcs recover_body_target_after_thirty_two_ticks_c24d4a
    .a16
    lda #$0020
    sta $95
    ldx $87
    lda a:$0096,X
    cmp $95
    bcc recover_body_target_after_thirty_two_ticks_c24d4a
    jsr select_native54_body_nearest_party_target
    ldx $87
    sta a:$00A9,X
    .a16
    lda #$0001
    sta a:$0094,X
recover_body_target_after_thirty_two_ticks_c24d4a:
    clc
    rts
