; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-audio.md.
.setcpu "65816"
.smart
.a8
.i16

send_native_menu_audio_packet_and_restore_wrapper_context = $CEDF

.segment "CODE"
.org $CF20
request_native_menu_audio_2b:
    pha
    php
    sep #$20
    .a8
    lda #$2B
    bra send_native_menu_audio_packet_and_restore_wrapper_context
