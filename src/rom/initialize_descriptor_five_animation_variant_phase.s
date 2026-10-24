; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five.md.
.setcpu "65816"
.smart
.a8
.i16

set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $603B
initialize_descriptor_five_animation_variant_phase:
    jsr set_boss_animation_bank_low_byte_c7
    lda a:$0042,X
    sta a:$007E,X
    .a16
    lda #$0010
    sta a:$001E,X
    rts
