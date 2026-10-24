; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-frames.md.
.setcpu "65816"
.smart
.a8
.i16

await_native_menu_vblank_edge = $28FF
expand_local_audio_preset_and_send_four_byte_request = $29D2

.segment "CODE"
.org $2930
request_native_menu_open_sound_and_fade_in:
    lda a:$A202
    beq request_native_menu_open_sound_and_fade_in_c0293a
    .a8
    lda #$00
    jsr expand_local_audio_preset_and_send_four_byte_request
request_native_menu_open_sound_and_fade_in_c0293a:
    .a8
    lda #$00
request_native_menu_open_sound_and_fade_in_c0293c:
    pha
    jsr await_native_menu_vblank_edge
    pla
    sta f:$002100
    inc
    inc
    .a8
    cmp #$0F
    bcc request_native_menu_open_sound_and_fade_in_c0293c
    jsr await_native_menu_vblank_edge
    .a8
    lda #$0F
    sta f:$002100
    rts
