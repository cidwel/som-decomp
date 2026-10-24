; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16

exchange_dialogue_tilemap_entry_and_request_upload = $1BC0

.segment "CODE"
.org $13FD
publish_dialogue_tile_pair_and_advance_cursor:
    lda a:$A17D
    sta a:$A157
    lda a:$A17C
    sta a:$A156
    ldx a:$A17E
    phx
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    plx
    inx
    inc a:$A156
    phx
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    plx
    dec a:$A156
    inc a:$A157
    inx
    stx a:$A17E
    lda a:$A157
    sta a:$A17D
    lda a:$A156
    sta a:$A17C
    rts
