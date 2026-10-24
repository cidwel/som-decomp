; Numeric encoded bank/offset pointers; the decoder ORs the bank with $C0.
.setcpu "65816"
map_tile_word_stream_08f000 = $08F000
map_tile_word_stream_08f7ae = $08F7AE
map_tile_word_stream_08fed6 = $08FED6
map_tile_word_stream_0b4080 = $0B4080
map_tile_word_stream_0b4801 = $0B4801
map_tile_word_stream_0b4f77 = $0B4F77
map_tile_word_stream_0b574a = $0B574A
map_tile_word_stream_0b5c87 = $0B5C87
map_tile_word_stream_0b6362 = $0B6362
map_tile_word_stream_0b6ac7 = $0B6AC7
map_tile_word_stream_0b7018 = $0B7018
map_tile_word_stream_0b748a = $0B748A
map_tile_word_stream_0b7cf2 = $0B7CF2
map_tile_word_stream_0b855a = $0B855A
map_tile_word_stream_0b8d5b = $0B8D5B
map_tile_word_stream_0b92a5 = $0B92A5
map_tile_word_stream_0b969d = $0B969D
map_tile_word_stream_0b9e84 = $0B9E84
map_tile_word_stream_0ba6ae = $0BA6AE
map_tile_word_stream_0baec7 = $0BAEC7
map_tile_word_stream_0bb65a = $0BB65A
map_tile_word_stream_0bbe5e = $0BBE5E
map_tile_word_stream_0bc5b8 = $0BC5B8
map_tile_word_stream_0bcd0e = $0BCD0E
map_tile_word_stream_0bd3a4 = $0BD3A4
map_tile_word_stream_0bd904 = $0BD904
map_tile_word_stream_0be0db = $0BE0DB
map_tile_word_stream_0be80f = $0BE80F
map_tile_word_stream_0bf079 = $0BF079
map_tile_word_stream_0bf6c1 = $0BF6C1
map_tile_word_stream_0bfc32 = $0BFC32
map_tile_word_stream_0c02d2 = $0C02D2
map_tile_word_stream_0c08e3 = $0C08E3
.segment "CODE"
.org $4000
map_tile_word_stream_pointers:
    .faraddr map_tile_word_stream_0b4080
    .faraddr map_tile_word_stream_0b4801
    .faraddr map_tile_word_stream_0b4f77
    .faraddr map_tile_word_stream_0b574a
    .faraddr map_tile_word_stream_0b5c87
    .faraddr map_tile_word_stream_0b6362
    .faraddr map_tile_word_stream_0b6ac7
    .faraddr map_tile_word_stream_0b7018
    .faraddr map_tile_word_stream_0b748a
    .faraddr map_tile_word_stream_0b7cf2
    .faraddr map_tile_word_stream_0b855a
    .faraddr map_tile_word_stream_0b8d5b
    .faraddr map_tile_word_stream_0b92a5
    .faraddr map_tile_word_stream_0b969d
    .faraddr map_tile_word_stream_0b9e84
    .faraddr map_tile_word_stream_0ba6ae
    .faraddr map_tile_word_stream_0baec7
    .faraddr map_tile_word_stream_0bb65a
    .faraddr map_tile_word_stream_0bbe5e
    .faraddr map_tile_word_stream_0bc5b8
    .faraddr map_tile_word_stream_0bcd0e
    .faraddr map_tile_word_stream_0bd3a4
    .faraddr map_tile_word_stream_0bd904
    .faraddr map_tile_word_stream_0be0db
    .faraddr map_tile_word_stream_0be80f
    .faraddr map_tile_word_stream_0bf079
    .faraddr map_tile_word_stream_0bf6c1
    .faraddr map_tile_word_stream_0bfc32
    .faraddr map_tile_word_stream_0c02d2
    .faraddr map_tile_word_stream_0c08e3
    .faraddr map_tile_word_stream_08f000
    .faraddr map_tile_word_stream_08f7ae
    .faraddr map_tile_word_stream_08fed6
