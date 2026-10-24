; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-palette.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CCD6
rotate_one_native_enabled_equipment_row_palette:
    pha
    phx
    phx
    tax
    lda a:$18A1,X
    plx
    .a16
    and #$0080
    bne rotate_one_native_enabled_equipment_row_palette_d0cd0d
    lda f:$7E0000,X
    pha
    lda f:$7E0002,X
    sta f:$7E0000,X
    lda f:$7E0004,X
    sta f:$7E0002,X
    lda f:$7E0006,X
    sta f:$7E0004,X
    lda f:$7E0008,X
    sta f:$7E0006,X
    pla
    sta f:$7E0008,X
rotate_one_native_enabled_equipment_row_palette_d0cd0d:
    plx
    txa
    clc
    .a16
    adc #$000A
    tax
    pla
    inc
    inc
    rts
