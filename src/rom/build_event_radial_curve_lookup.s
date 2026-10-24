; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-preparation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CB6F
build_event_radial_curve_lookup:
    rep #$30
    .i16
    ldy #$0000
build_event_radial_curve_lookup_c2cb74:
    rep #$20
    tyx
    lda f:$00FD22,X
    sta $08
    tya
    .a16
    eor #$01FE
    inc
    inc
    tax
    lda f:$00FD22,X
    sta $0A
    sep #$20
    .a8
    lda #$FF
    sta f:$004202
    lda $09
    beq build_event_radial_curve_lookup_c2cb9a
    .a8
    lda #$FF
    bra build_event_radial_curve_lookup_c2cba8
build_event_radial_curve_lookup_c2cb9a:
    lda $08
    sta f:$004203
    nop
    nop
    nop
    nop
    lda f:$004217
build_event_radial_curve_lookup_c2cba8:
    sta $08
    lda $0B
    beq build_event_radial_curve_lookup_c2cbb2
    .a8
    lda #$FF
    bra build_event_radial_curve_lookup_c2cbc0
build_event_radial_curve_lookup_c2cbb2:
    lda $0A
    sta f:$004203
    nop
    nop
    nop
    nop
    lda f:$004217
build_event_radial_curve_lookup_c2cbc0:
    sta $0A
    .a8
    lda #$00
    xba
    lda $08
    tax
    lda $0A
    sta a:$F700,X
    iny
    iny
    .i16
    cpy #$0200
    bcc build_event_radial_curve_lookup_c2cb74
    .i16
    ldx #$0000
    .i16
    ldy #$00D0
    .a8
    lda #$FF
    sta $08
build_event_radial_curve_lookup_c2cbde:
    lda a:$F700,X
    bne build_event_radial_curve_lookup_c2cbe8
    lda $08
    sta a:$F700,X
build_event_radial_curve_lookup_c2cbe8:
    sta $08
    inx
    dey
    bne build_event_radial_curve_lookup_c2cbde
    rts
