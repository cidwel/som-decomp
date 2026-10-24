; Recovered Secret of Mana USA boot code. See docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8B15
update_title_colour_at_offset4:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    stx $01
    lda f:$7E5DA0,X
    ldx a:$0042
    beq update_title_colour_at_offset4_8b2a
    sta a:$0004,X
update_title_colour_at_offset4_8b2a:
    ldx $01
    lda f:$7E5DE0,X
    ldx a:$0046
    beq update_title_colour_at_offset4_8b38
    sta a:$0004,X
update_title_colour_at_offset4_8b38:
    ldx $01
    lda f:$7E5E20,X
    ldx a:$004A
    beq update_title_colour_at_offset4_8b46
    sta a:$0004,X
update_title_colour_at_offset4_8b46:
    ldx $01
    lda f:$7E5E60,X
    ldx a:$004E
    beq update_title_colour_at_offset4_8b54
    sta a:$0004,X
update_title_colour_at_offset4_8b54:
    ldx $01
    sep #$20
    pla
    pla
    plp
    pld
    rts
