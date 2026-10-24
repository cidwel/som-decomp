; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A241
release_vertical_irq_use:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    lda a:$008C
    beq release_vertical_irq_use_a256
    dec a:$008C
    bne release_vertical_irq_use_a262
release_vertical_irq_use_a256:
    lda a:$0090
    .a8
    and #$DF
    sta a:$0090
    sta f:$004200
release_vertical_irq_use_a262:
    plb
    plp
    pld
    rts
