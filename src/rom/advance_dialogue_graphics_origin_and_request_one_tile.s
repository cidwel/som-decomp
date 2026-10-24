; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16

set_dialogue_graphics_transfer_size_preserving_status = $1936

.segment "CODE"
.org $1450
advance_dialogue_graphics_origin_and_request_one_tile:
    rep #$20
    lda a:$A189
    clc
    .a16
    adc #$0020
    sta a:$A189
    .a16
    lda #$0020
    sep #$20
    jsr set_dialogue_graphics_transfer_size_preserving_status
    .a8
    lda #$10
    sta a:$A18E
    rts
