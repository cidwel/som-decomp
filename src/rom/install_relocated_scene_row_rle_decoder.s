; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-tile-rows.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9985
install_relocated_scene_row_rle_decoder:
    rep #$20
    sep #$10
    .i8
    ldx #$3E
install_relocated_scene_row_rle_decoder_c0998b:
    lda a:$9A60,X
    sta a:$0B00,X
    dex
    dex
    bpl install_relocated_scene_row_rle_decoder_c0998b
    rts
