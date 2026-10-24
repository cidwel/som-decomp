; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $398D
send_combat_sound_with_fixed_parameter_fifteen:
    sta a:$1E01
    .a8
    lda #$02
    sta a:$1E00
    .a8
    lda #$0F
    sta a:$1E02
    .a8
    lda #$00
    sta a:$1E03
    jsl f:audio_command_sender_public_jump
    rts
