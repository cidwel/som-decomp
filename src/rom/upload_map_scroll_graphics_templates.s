; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F5CE
upload_map_scroll_graphics_templates:
    sep #$30
    ldx $1C
    lda f:$C80400,X
    rep #$30
    .a16
    and #$00FF
    asl
    tax
    sep #$20
    .a8
    lda #$00
    sta $00
upload_map_scroll_graphics_templates_c1f5e3:
    lda f:$C80441,X
    .a8
    and #$3F
    asl
    .a8
    ora #$80
    xba
    .a8
    lda #$80
    sta a:$2115
    .a8
    lda #$DC
    sta a:$4374
    .a8
    lda #$00
    rep #$20
    sta a:$4372
    .a16
    lda #$1801
    sta a:$4370
    .a16
    lda #$0080
    sta a:$4375
    lda $00
    .a16
    and #$0007
    xba
    lsr
    lsr
    clc
    .a16
    adc #$3600
    .a16
    ora #$0000
    sta a:$2116
    sep #$20
    .a8
    lda #$80
    sta a:$420B
    inx
    inc $00
    lda $00
    .a8
    cmp #$08
    bcc upload_map_scroll_graphics_templates_c1f5e3
    rts
