; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-spell-skill-percentage.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $419C
compute_native_spell_percentage_from_packed_skill_and_hardware_arithmetic:
    phd
    phb
    php
    rep #$30
    pha
    .a16
    lda #$0300
    tcd
    pla
    .a16
    and #$00FF
    sep #$20
    sta f:$004202
    .a8
    lda #$63
    sta f:$004203
    .a8
    lda #$7E
    pha
    plb
    sty $A4
    rep #$20
    txa
    sep #$20
    tya
    lsr
    tay
    .a8
    lda #$00
    xba
    lda a:$E1C0,Y
    sta $A6
    .a8
    lda #$01
    bit $A4
    bne compute_native_spell_percentage_from_packed_skill_and_hardware_arithmetic_c041da
    lsr $A6
    lsr $A6
    lsr $A6
    lsr $A6
compute_native_spell_percentage_from_packed_skill_and_hardware_arithmetic_c041da:
    lda $A6
    .a8
    and #$0F
    tax
    rep #$20
    lda f:$004216
    sta f:$004204
    sep #$20
    lda f:$C043AC,X
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda f:$004214
    plp
    plb
    pld
    rtl
