; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_full_boss_palette_transition_phase = $27C1

.segment "CODE"
.org $274C
update_boss_palette_transition_object:
    lda a:$009A,X
    beq update_boss_palette_transition_object_c22754
    jmp dispatch_full_boss_palette_transition_phase
update_boss_palette_transition_object_c22754:
    lda a:$009E,X
    bpl update_boss_palette_transition_object_c22790
    .a16
    and #$0F00
    xba
    asl
    sta $66
    lda a:$009C,X
    asl
    tax
    lda $66
    clc
    adc f:$D0BB24,X
    sta $76
    ldx $87
    lda a:$009E,X
    .a16
    and #$000F
    xba
    lsr
    lsr
    lsr
    clc
    .a16
    adc #$0600
    adc $66
    sta $79
    sep #$20
    .a8
    lda #$C2
    sta $78
    rep #$20
    lda [$76]
    sta ($79)
    sec
    rts
update_boss_palette_transition_object_c22790:
    .a16
    and #$000F
    xba
    lsr
    lsr
    lsr
    clc
    .a16
    adc #$0600
    sta $76
    lda a:$009C,X
    asl
    tax
    .a16
    lda #$C200
    sta $7A
    lda f:$D0BB24,X
    sta $79
    .i16
    ldy #$0000
update_boss_palette_transition_object_c227b0:
    lda [$79],Y
    sta ($76),Y
    iny
    iny
    .i16
    cpy #$0020
    bne update_boss_palette_transition_object_c227b0
    ldx $87
    rep #$20
    sec
    rts
