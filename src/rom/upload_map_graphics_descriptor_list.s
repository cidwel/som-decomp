; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

upload_map_graphics_descriptor = $F456

.segment "CODE"
.org $F413
upload_map_graphics_descriptor_list:
    sep #$30
    .a8
    lda #$80
    sta a:$2115
    .a8
    lda #$CC
    sta $12
    lda $1C
    .a8
    and #$3F
    asl
    tax
    rep #$20
    lda f:$CCE27E,X
    sta $10
    lda f:$CCE280,X
    sec
    sbc $10
    sta $14
    .a16
    lda #$0000
    .i8
    ldy #$00
    sta a:$2116
    .a16
    lda #$1801
    sta a:$4370
upload_map_graphics_descriptor_list_c1f443:
    rep #$30
    lda [$10],Y
    iny
    iny
    phy
    jsr upload_map_graphics_descriptor
    rep #$30
    ply
    iny
    cpy $14
    bcc upload_map_graphics_descriptor_list_c1f443
    rts
