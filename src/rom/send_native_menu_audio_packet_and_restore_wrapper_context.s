; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-audio.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $CEDF
send_native_menu_audio_packet_and_restore_wrapper_context:
    sep #$20
    sta a:$1E01
    .a8
    lda #$02
    sta a:$1E00
    .a8
    lda #$0F
    sta a:$1E02
    stz a:$1E03
    jsl f:audio_command_sender_public_jump
    plp
    pla
    rtl
