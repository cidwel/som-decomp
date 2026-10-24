; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

append_map_scroll_animation_record = $B147

.segment "CODE"
.org $B0EC
initialize_map_scroll_animation:
    sep #$30
    ldx $1C
    txa
    bmi initialize_map_scroll_animation_c1b0f6
    stz $90
    rtl
initialize_map_scroll_animation_c1b0f6:
    .a8
    lda #$40
    sta $90
    txa
    .a8
    and #$3F
    tax
    lda f:$C80401,X
    sec
    sbc f:$C80400,X
    asl
    bne initialize_map_scroll_animation_c1b10c
    .a8
    lda #$02
initialize_map_scroll_animation_c1b10c:
    sta $01
    stz $00
    lda f:$C80400,X
    rep #$30
    .a16
    and #$00FF
    asl
    tax
    .i16
    ldy #$0000
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    stz a:$8013
    stz a:$801B
    stz a:$8023
    stz a:$802B
    stz a:$8033
    stz a:$803B
initialize_map_scroll_animation_c1b137:
    lda f:$C80441,X
    jsr append_map_scroll_animation_record
    inx
    inc $00
    dec $01
    bne initialize_map_scroll_animation_c1b137
    plb
    rtl
