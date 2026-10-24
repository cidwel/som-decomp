; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-list.md.
.setcpu "65816"
.smart
.a8
.i16

request_native_menu_audio_2a = $D0CF18
request_native_menu_audio_2b = $D0CF20

.segment "CODE"
.org $6F5E
play_native_menu_ring_open_or_change_sound:
    sep #$20
    lda a:$1812
    .a8
    cmp #$03
    bne play_native_menu_ring_open_or_change_sound_c06f6d
    jsl f:request_native_menu_audio_2b
    bra play_native_menu_ring_open_or_change_sound_c06f71
play_native_menu_ring_open_or_change_sound_c06f6d:
    jsl f:request_native_menu_audio_2a
play_native_menu_ring_open_or_change_sound_c06f71:
    rts
