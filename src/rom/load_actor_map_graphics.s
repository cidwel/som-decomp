; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DFD3
load_actor_map_graphics:
    rep #$20
    phy
    .a16
    lda #$0008
    sta $00
    lda a:$E180,X
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    phx
    txy
    tax
load_actor_map_graphics_c1dfe8:
    lda f:$D00000,X
    sta a:$E070,Y
    inx
    inx
    iny
    iny
    dec $00
    bne load_actor_map_graphics_c1dfe8
    plx
    lda a:$E077,X
    sta a:$E065,X
    lda a:$E070,X
    .a16
    and #$03FF
    asl
    asl
    asl
    asl
    asl
    asl
    sta a:$E080,X
    sep #$20
    lda a:$E071,X
    lsr
    lsr
    .a8
    and #$07
    clc
    .a8
    adc #$D5
    sta a:$E082,X
    ply
    rts
