; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

build_title_window_scanline_table = $CE6B
dispatch_parent_messages = $D17F

.segment "CODE"
.org $D377
expand_title_scanline_window:
    phd
    php
    rep #$30
    phb
    phx
    tsc
    tcd
    sep #$20
    .i16
    ldx #$0040
    stx $02
expand_title_scanline_window_d386:
    ldx $02
    inx
    stx $02
    .i16
    ldy #$0070
    jsr build_title_window_scanline_table
    .a8
    lda #$01
    .i16
    cpx #$0010
    beq expand_title_scanline_window_d3a2
    .i16
    ldx #$0003
    jsr dispatch_parent_messages
    .a8
    cmp #$00
    bne expand_title_scanline_window_d386
expand_title_scanline_window_d3a2:
    sta $03,S
    pla
    pla
    pla
    plp
    pld
    rts
