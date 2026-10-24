; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D0DA
locate_selected_armor_with_nonzero_level:
    rep #$10
    sep #$20
    .i16
    ldx #$0000
    lda a:$1875
    inc
locate_selected_armor_with_nonzero_level_d0d0e5:
    pha
locate_selected_armor_with_nonzero_level_d0d0e6:
    lda f:$7EE5C8,X
    inx
    .a8
    and #$07
    beq locate_selected_armor_with_nonzero_level_d0d0e6
    pla
    dec
    bne locate_selected_armor_with_nonzero_level_d0d0e5
    dex
    lda f:$7EE5C8,X
    rep #$20
    rtl
