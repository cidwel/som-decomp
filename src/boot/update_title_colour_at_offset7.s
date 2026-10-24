; Recovered Secret of Mana USA boot code. See docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8B5D
update_title_colour_at_offset7:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    stx $01
    lda f:$7E5DA0,X
    ldx a:$0042
    beq update_title_colour_at_offset7_8b72
    sta a:$0007,X
update_title_colour_at_offset7_8b72:
    ldx $01
    lda f:$7E5DE0,X
    ldx a:$0046
    beq update_title_colour_at_offset7_8b80
    sta a:$0007,X
update_title_colour_at_offset7_8b80:
    ldx $01
    lda f:$7E5E20,X
    ldx a:$004A
    beq update_title_colour_at_offset7_8b8e
    sta a:$0007,X
update_title_colour_at_offset7_8b8e:
    ldx $01
    lda f:$7E5E60,X
    ldx a:$004E
    beq update_title_colour_at_offset7_8b9c
    sta a:$0007,X
update_title_colour_at_offset7_8b9c:
    ldx $01
    sep #$20
    pla
    pla
    plp
    pld
    rts
