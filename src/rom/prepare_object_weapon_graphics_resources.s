; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $EA41
prepare_object_weapon_graphics_resources:
    phy
    txy
    rep #$20
    lda a:$E1E3,X
    .a16
    and #$00FF
    asl
    asl
    sta $00
    asl
    asl
    sec
    sbc $00
    tax
    sep #$20
    lda a:$E069,Y
    bne prepare_object_weapon_graphics_resources_c0ea63
    lda f:$D01004,X
    sta a:$E069,Y
prepare_object_weapon_graphics_resources_c0ea63:
    lda f:$D01000,X
    sta a:$E068,Y
    xba
    lda f:$D01003,X
    rep #$20
    pha
    tya
    lsr
    lsr
    lsr
    tax
    pla
    sep #$20
    sta a:$D030,X
    .a8
    cmp #$04
    bcc prepare_object_weapon_graphics_resources_c0ea85
    clc
    .a8
    adc #$12
    xba
prepare_object_weapon_graphics_resources_c0ea85:
    xba
    rep #$20
    .a16
    and #$00FF
    .i16
    cpy #$0600
    bcs prepare_object_weapon_graphics_resources_c0eaae
    pha
    lda a:$E068,Y
    xba
    .a16
    and #$FF00
    sta $00
    xba
    asl
    asl
    asl
    asl
    .a16
    eor #$FFFF
    inc
    clc
    adc $00
    clc
    adc a:$E077,Y
    sta a:$E065,Y
    pla
prepare_object_weapon_graphics_resources_c0eaae:
    pha
    asl
    asl
    tax
    lda f:$D4C000,X
    asl
    asl
    asl
    sta $00
    asl
    clc
    adc $00
    sta $00
    lda f:$D4C002,X
    sta a:$E06A,Y
    pla
    .i16
    cpy #$0600
    bcc prepare_object_weapon_graphics_resources_c0eadc
    lda a:$E1E3,Y
    asl
    lda a:$E07B,Y
    bcc prepare_object_weapon_graphics_resources_c0eafc
    lda a:$E07D,Y
    bra prepare_object_weapon_graphics_resources_c0eafc
prepare_object_weapon_graphics_resources_c0eadc:
    pha
    .a16
    cmp #$0008
    bcc prepare_object_weapon_graphics_resources_c0eae5
    .a16
    lda #$0000
prepare_object_weapon_graphics_resources_c0eae5:
    xba
    .i16
    cpy #$0400
    bcc prepare_object_weapon_graphics_resources_c0eaef
    clc
    .a16
    adc #$0800
prepare_object_weapon_graphics_resources_c0eaef:
    .a16
    adc #$1040
    sta a:$E07E,Y
    pla
    asl
    tax
    lda f:$D0FFD0,X
prepare_object_weapon_graphics_resources_c0eafc:
    tyx
    sta a:$E02A,X
    ply
    rts
