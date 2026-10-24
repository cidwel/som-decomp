; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $30E3
request_boss_sound_with_parameter_word:
    sep #$20
    xba
    .a8
    lda #$02
    sta f:$001E00
    xba
    sta f:$001E01
    rep #$20
    txa
    sta f:$001E02
    jsl f:audio_command_sender_public_jump
    rts
