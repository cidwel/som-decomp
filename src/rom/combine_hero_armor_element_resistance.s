; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4A2D
combine_hero_armor_element_resistance:
    .i16
    ldy #$3ED6
    lda [$C9],Y
    ora [$C6],Y
    ora [$C3],Y
    sta a:$E1A3,X
    stz a:$E1A2,X
    sta $A6
    asl
    .a8
    and #$2A
    sta $A4
    lda $A6
    lsr
    .a8
    and #$15
    ora $A4
    .a8
    and #$3F
    sta a:$E1A1,X
    stz a:$E1A0,X
    rts
