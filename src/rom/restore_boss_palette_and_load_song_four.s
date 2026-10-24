; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-alternate-death.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_palette_with_cpu_words = $26F9
load_requested_song_with_native_parameter_four = $30C2

.segment "CODE"
.org $629C
restore_boss_palette_and_load_song_four:
    ldx $87
    lda a:$0018,X
    .a16
    and #$00FF
    tay
    lda a:$0042,X
    asl
    clc
    .a16
    adc #$0031
    tyx
    jsr copy_boss_palette_with_cpu_words
    .a16
    lda #$0004
    jsr load_requested_song_with_native_parameter_four
    rts
