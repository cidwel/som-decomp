; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CD17
restore_saved_map_camera:
    sep #$20
    rep #$10
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    lda a:$CD00
    sta $A8
    .a16
    and #$FFF0
    sta $88
    lda a:$CD02
    sta $AA
    .a16
    and #$FFF0
    sta $8A
    lda a:$CD04
    sta $AC
    .a16
    and #$FFF0
    sta $8C
    lda a:$CD06
    sta $AE
    .a16
    and #$FFF0
    sta $8E
    sep #$20
    plb
    rtl
