; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AE39
upload_cursor_tile_high_planes_and_clear_remainder:
    .i8
    ldy #$00
upload_cursor_tile_high_planes_and_clear_remainder_c2ae3b:
    stz a:$2118
    lda f:$02AECC,X
    sta a:$2119
    inx
    iny
    .i8
    cpy #$08
    bcc upload_cursor_tile_high_planes_and_clear_remainder_c2ae3b
upload_cursor_tile_high_planes_and_clear_remainder_c2ae4b:
    stz a:$2118
    stz a:$2119
    dey
    bne upload_cursor_tile_high_planes_and_clear_remainder_c2ae4b
    rts
