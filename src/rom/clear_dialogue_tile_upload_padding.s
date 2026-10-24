; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $14DB
clear_dialogue_tile_upload_padding:
    rep #$20
    .a16
    lda #$0008
clear_dialogue_tile_upload_padding_c014e0:
    stz a:$0000,X
    inx
    inx
    dec
    bne clear_dialogue_tile_upload_padding_c014e0
    sep #$20
    rts
