; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BEB1
scan_map_palette_animation_color_span:
    phx
    phy
    .a8
    lda #$00
    xba
    lda a:$D204,Y
    inc
    inc
    tax
    .i16
    ldy #$0001
scan_map_palette_animation_color_span_c2bebf:
    lda a:$0601,X
    bpl scan_map_palette_animation_color_span_c2bed3
    inx
    inx
    iny
    .i16
    cpy #$0010
    bcc scan_map_palette_animation_color_span_c2bebf
    .a8
    lda #$01
    xba
    .a8
    lda #$03
    bra scan_map_palette_animation_color_span_c2bee5
scan_map_palette_animation_color_span_c2bed3:
    tya
    xba
    inx
    inx
    iny
scan_map_palette_animation_color_span_c2bed8:
    lda a:$0601,X
    bmi scan_map_palette_animation_color_span_c2bee5
    inx
    inx
    iny
    .i16
    cpy #$0010
    bcc scan_map_palette_animation_color_span_c2bed8
scan_map_palette_animation_color_span_c2bee5:
    tya
    dec
    xba
    ply
    plx
    rep #$20
    sta $02
    asl
    sta a:$D20A,Y
    sep #$20
    lda $03
    sec
    sbc $02
    sta a:$D20C,Y
    rts
