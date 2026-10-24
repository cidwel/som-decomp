; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-left-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7FB5
follow_parent_while_dead_or_restart:
    ldx $87
    ldy a:$00B0,X
    lda a:$002B,Y
    sec
    .a16
    sbc #$0040
    sta a:$002B,X
    lda a:$0032,Y
    clc
    .a16
    adc #$0010
    sta a:$0032,X
    lda a:$0094,Y
    .a16
    cmp #$0006
    beq follow_parent_while_dead_or_restart_c27fe3
    lda a:$0190,X
    bmi follow_parent_while_dead_or_restart_c27fe1
    .a16
    lda #$0001
    sta a:$0094,X
follow_parent_while_dead_or_restart_c27fe1:
    clc
    rts
follow_parent_while_dead_or_restart_c27fe3:
    sec
    rts
