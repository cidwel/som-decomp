; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

load_conditional_map_piece = $CBD1

.segment "CODE"
.org $CB90
load_map_piece_list:
    rep #$30
    lda $DC
    asl
    tax
    lda f:$C85000,X
    sta $20
    lda f:$C85002,X
    sta $24
    sep #$30
    .a8
    lda #$C8
    sta $22
    phb
    .a8
    lda #$7F
    pha
    plb
load_map_piece_list_c0cbad:
    jsr load_conditional_map_piece
    rep #$30
    lda $20
    clc
    .a16
    adc #$0005
    sta $20
    cmp $24
    bcc load_map_piece_list_c0cbad
    sep #$30
    plb
    rts
