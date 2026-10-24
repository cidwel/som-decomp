; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D0B0
locate_selected_weapon_with_nonzero_level:
    rep #$10
    sep #$20
    .i16
    ldx #$0000
    lda a:$1874
    inc
    .a8
    cmp #$07
    bcc locate_selected_weapon_with_nonzero_level_d0d0c1
    .a8
    lda #$07
locate_selected_weapon_with_nonzero_level_d0d0c1:
    pha
locate_selected_weapon_with_nonzero_level_d0d0c2:
    lda f:$7EE3C8,X
    inx
    .a8
    and #$38
    beq locate_selected_weapon_with_nonzero_level_d0d0c2
    pla
    dec
    bne locate_selected_weapon_with_nonzero_level_d0d0c1
    dex
    lda f:$7EE3C8,X
    lsr
    lsr
    lsr
    rep #$20
    rtl
