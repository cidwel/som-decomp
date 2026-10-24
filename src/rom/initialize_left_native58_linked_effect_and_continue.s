; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-linked-effects.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $8380
initialize_left_native58_linked_effect_and_continue:
    ldx $87
    jsr set_boss_animation_bank_low_byte_c7
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$012C
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$0066,X
    .a16
    lda #$07FF
    sta a:$0022,X
    inc a:$0094,X
