; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-loader-music-command.md.
.setcpu "65816"
.smart
.a8
.i16

load_requested_song_with_native_parameter_four = $30C2

.segment "CODE"
.org $2240
boss_loader_consume_song_word_and_invoke_music_request:
    lda [$30]
    inc $30
    inc $30
    jmp load_requested_song_with_native_parameter_four
