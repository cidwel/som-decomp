; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-alternate-death.md.
.setcpu "65816"
.smart
.a8
.i16

restore_boss_palette_and_load_song_four = $629C

.segment "CODE"
.org $6273
release_party_control_and_restore_boss_palette_music:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    sep #$20
    .a8
    lda #$01
    sta a:$01B4,Y
    .a8
    lda #$7F
    and a:$000E,Y
    sta a:$000E,Y
    rep #$20
    jsr restore_boss_palette_and_load_song_four
    rts
