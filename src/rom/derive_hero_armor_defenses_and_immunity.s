; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4A75
derive_hero_armor_defenses_and_immunity:
    .i16
    ldy #$3ED2
    lda a:$E189,X
    lsr
    lsr
    clc
    adc [$C9],Y
    clc
    adc [$C6],Y
    clc
    adc [$C3],Y
    sta a:$E1A4,X
    lda a:$E18C,X
    lsr
    lsr
    .i16
    ldy #$3ED4
    clc
    adc [$C9],Y
    clc
    adc [$C6],Y
    clc
    adc [$C3],Y
    sta a:$E1A7,X
    .a8
    lda #$00
    sta $A5
    sta $A7
    sta $A9
    lda a:$E18A,X
    sta $A4
    .i16
    ldy #$3ED1
    lda [$C9],Y
    sta $A6
    lda [$C6],Y
    sta $A8
    lda [$C3],Y
    rep #$20
    .a16
    and #$00FF
    clc
    adc $A4
    clc
    adc $A6
    clc
    adc $A8
    sta a:$E1A5,X
    sep #$20
    lda a:$E18C,X
    sta $A4
    .i16
    ldy #$3ED3
    lda [$C9],Y
    sta $A6
    lda [$C6],Y
    sta $A8
    lda [$C3],Y
    rep #$20
    .a16
    and #$00FF
    clc
    adc $A4
    clc
    adc $A6
    clc
    adc $A8
    sta a:$E1A8,X
    .i16
    ldy #$3ED7
    lda [$C9],Y
    ora [$C6],Y
    ora [$C3],Y
    .a16
    ora #$0800
    sta a:$E1AA,X
    sep #$20
    rts
