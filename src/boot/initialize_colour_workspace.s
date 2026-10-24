; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_b081 = $B081

.segment "CODE"
.org $87DF
initialize_colour_workspace:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    sta a:$0020
    stz a:$0021
    .a8
    and #$80
    beq initialize_colour_workspace_87f9
    dec a:$0021
initialize_colour_workspace_87f9:
    xba
    sta a:$001E
    stz a:$001F
    .a8
    and #$80
    beq initialize_colour_workspace_8807
    dec a:$001F
initialize_colour_workspace_8807:
    stx a:$0024
    sty a:$0022
    stz a:$0026
    stz a:$0034
    .i16
    ldx #$0020
    jsr boot_b081
    stx a:$0030
    plb
    plp
    pld
    rts
