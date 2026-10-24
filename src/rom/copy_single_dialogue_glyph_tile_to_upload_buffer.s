; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16

copy_requested_dialogue_rows_to_upload_buffer = $14C6

.segment "CODE"
.org $146A
copy_single_dialogue_glyph_tile_to_upload_buffer:
    .a8
    lda #$02
    sta a:$A171
    ldy a:$A189
    .i16
    ldx #$9400
    jsr copy_requested_dialogue_rows_to_upload_buffer
    rts
