; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16

advance_dialogue_graphics_origin_and_request_one_tile = $1450
copy_single_dialogue_glyph_tile_to_upload_buffer = $146A

.segment "CODE"
.org $1431
publish_single_dialogue_glyph_tile:
    jsr copy_single_dialogue_glyph_tile_to_upload_buffer
    jsr advance_dialogue_graphics_origin_and_request_one_tile
    rep #$20
    lda a:$A18C
    sta f:$001D06
    lda a:$A18E
    .a16
    and #$00FF
    clc
    adc a:$A18C
    sta a:$A18C
    sep #$20
    rts
