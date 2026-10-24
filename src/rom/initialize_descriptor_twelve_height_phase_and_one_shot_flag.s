; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-twelve.md.
.setcpu "65816"
.smart
.a8
.i16

set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $53F1
initialize_descriptor_twelve_height_phase_and_one_shot_flag:
    jsr set_boss_animation_bank_low_byte_c7
    stz a:$007E,X
    stz a:$00BE,X
    .a16
    lda #$0400
    sta a:$0066,X
    .a16
    lda #$0005
    sta a:$00A7,X
    lda a:$0042,X
    beq initialize_descriptor_twelve_height_phase_and_one_shot_flag_c2540b
initialize_descriptor_twelve_height_phase_and_one_shot_flag_c2540b:
    rts
