; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

clear_colour_lookup_bank = $8607
mark_cyclic_component_permutations = $8577

.segment "CODE"
.org $8621
initialize_colour_lookup:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0008
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    jsr clear_colour_lookup_bank
    lda a:$0018
    clc
    .a16
    adc #$0030
    sta $07
    .a16
    lda #$0008
    sta $01
    .i16
    ldx #$0000
    stz $03
initialize_colour_lookup_864b:
    stx $05
    ldy $07
    lda f:$7E59E0,X
    sta a:$0000,Y
    lda f:$7E59E2,X
    sta a:$0002,Y
    tyx
    jsr mark_cyclic_component_permutations
    clc
    adc $03
    sta $03
    .a16
    cmp #$8000
    bcs initialize_colour_lookup_8679
    lda $05
    clc
    .a16
    adc #$0003
    tax
    dec $01
    bne initialize_colour_lookup_864b
    .a16
    lda #$0000
initialize_colour_lookup_8679:
    plb
    sta $07,S
    tsc
    clc
    .a16
    adc #$0006
    tcs
    pla
    plp
    pld
    rts
