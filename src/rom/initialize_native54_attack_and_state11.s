; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-setup.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_row_public_jump = $C0006C
select_boss_animation_and_reset_frame_cursor = $1394
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $44D9
initialize_native54_attack_and_state11:
    ldx $87
    jsr set_boss_animation_bank_low_byte_c7
    stz a:$00B0,X
    stz a:$00BA,X
    stz a:$00BC,X
    stz a:$00BE,X
    .a16
    lda #$0003
    sta a:$001E,X
    .a16
    lda #$0000
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$000B
    sta a:$0094,X
    .a16
    lda #$FFF0
    sta a:$0062,X
    eor $C7
    inc
    sta a:$0045,X
    .a16
    lda #$001C
    clc
    adc a:$0042,X
    jsl f:boss_attack_row_public_jump
    ldx $87
    clc
    rts
