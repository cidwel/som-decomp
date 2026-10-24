; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4517
advance_native54_to_state2_after_animation:
    ldx $87
    lda a:$009E,X
    bne advance_native54_to_state2_after_animation_c24533
    .a16
    lda #$0002
    sta a:$0094,X
    .a16
    lda #$0003
    sta a:$001E,X
    stz a:$0096,X
    stz a:$00B2,X
    stz a:$0076,X
advance_native54_to_state2_after_animation_c24533:
    clc
    rts
