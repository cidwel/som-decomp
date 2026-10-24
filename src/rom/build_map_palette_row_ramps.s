; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

build_map_palette_color_ramp = $BD8D

.segment "CODE"
.org $BD56
build_map_palette_row_ramps:
    ldx a:$D204,Y
    inx
    inx
    .i16
    ldy #$0000
build_map_palette_row_ramps_c2bd5e:
    lda [$14],Y
    sta $00
    lda a:$0600,X
    sta $02
    phy
    phx
    tya
    clc
    adc $12
    sta $18
    jsr build_map_palette_color_ramp
    rep #$30
    plx
    ply
    inx
    inx
    iny
    iny
    .i16
    cpy #$001E
    bcc build_map_palette_row_ramps_c2bd5e
    ply
    plx
    lda $12
    sta a:$D208,Y
    clc
    .a16
    adc #$01E0
    sta $12
    rts
