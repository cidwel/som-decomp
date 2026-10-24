; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01810e = $810E

.segment "CODE"
.org $8018
create_floating_combat_number_with_saved_context:
    php
    phd
    phb
    sep #$20
    xba
    .a8
    lda #$00
    pha
    pha
    pld
    bit $F1
    bmi create_floating_combat_number_with_saved_context_18039
    .a8
    lda #$7E
    pha
    plb
    xba
    sta a:$E04F,X
    .a8
    lda #$01
    sta a:$E061,X
    sty $1E
    jsr routine_01810e
create_floating_combat_number_with_saved_context_18039:
    plb
    pld
    plp
    rtl
