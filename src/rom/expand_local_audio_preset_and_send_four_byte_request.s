; Recovered Secret of Mana USA routine; behaviour documented in docs/audio-native-callers.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $29D2
expand_local_audio_preset_and_send_four_byte_request:
    tax
    phb
    .a8
    lda #$00
    pha
    plb
    txa
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    tax
    sep #$20
    .i16
    ldy #$0000
    .a8
    lda #$04
expand_local_audio_preset_and_send_four_byte_request_c029e8:
    xba
    lda f:$C02A34,X
    sta a:$1E00,Y
    inx
    iny
    xba
    dec
    bne expand_local_audio_preset_and_send_four_byte_request_c029e8
    plb
    jsl f:audio_command_sender_public_jump
    rts
