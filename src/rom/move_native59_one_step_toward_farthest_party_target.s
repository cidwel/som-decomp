; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-setup.md.
.setcpu "65816"
.smart
.a8
.i16

derive_eight_way_direction_to_low_byte_target = $0941
select_farthest_active_living_party_actor_last_tie = $325A

.segment "CODE"
.org $8597
move_native59_one_step_toward_farthest_party_target:
    jsr select_farthest_active_living_party_actor_last_tie
    ldx $87
    sta a:$00A9,X
    jsr derive_eight_way_direction_to_low_byte_target
    ldx $87
    sta a:$00AB,X
    asl
    asl
    tax
    lda f:$C285CB,X
    sta $95
    lda f:$C285CD,X
    sta $97
    ldx $87
    lda $95
    clc
    adc a:$002B,X
    sta a:$002B,X
    lda $97
    clc
    adc a:$0032,X
    sta a:$0032,X
    rts
