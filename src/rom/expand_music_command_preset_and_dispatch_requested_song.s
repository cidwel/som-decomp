; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-music-presets.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c30175 = $0175

.segment "CODE"
.org $05F3
expand_music_command_preset_and_dispatch_requested_song:
    rep #$20
    .a16
    and #$000F
    asl
    asl
    tax
    lda f:$C306CA,X
    sta $02
    lda f:$C306C8,X
    sta $00
    jmp routine_c30175
