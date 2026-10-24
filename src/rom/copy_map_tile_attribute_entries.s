; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A043
copy_map_tile_attribute_entries:
    .i16
    ldy #$0000
copy_map_tile_attribute_entries_c2a046:
    lda f:$CB0400,X
    .a16
    and #$00FF
    inx
    asl
    asl
    phx
    tax
    lda f:$CB0000,X
    sta ($14),Y
    iny
    iny
    lda f:$CB0002,X
    sta ($14),Y
    iny
    iny
    plx
    .i16
    cpy #$0300
    bcc copy_map_tile_attribute_entries_c2a046
    rts
