; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16

clear_dialogue_tile_upload_padding = $14DB

.segment "CODE"
.org $1235
copy_dialogue_window_rows_with_upload_padding:
copy_dialogue_window_rows_with_upload_padding_c01235:
    .a8
    lda #$10
copy_dialogue_window_rows_with_upload_padding_c01237:
    xba
    lda a:$0000,Y
    sta a:$0000,X
    inx
    iny
    xba
    dec
    bne copy_dialogue_window_rows_with_upload_padding_c01237
    jsr clear_dialogue_tile_upload_padding
    rep #$20
    tya
    clc
    .a16
    adc #$0010
    tay
    sep #$20
    dec a:$A175
    bne copy_dialogue_window_rows_with_upload_padding_c01235
    rts
