; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4315
clear_six_actor_references_to_dead_actor:
    stz $A6
    stz $A7
    .a8
    lda #$06
    sta $B2
clear_six_actor_references_to_dead_actor_c0431d:
    ldy $A6
    lda $81
    cmp a:$E1AC,Y
    bne clear_six_actor_references_to_dead_actor_c0432b
    .a8
    lda #$FF
    sta a:$E1AC,Y
clear_six_actor_references_to_dead_actor_c0432b:
    lda $81
    cmp a:$E1AD,Y
    bne clear_six_actor_references_to_dead_actor_c04337
    .a8
    lda #$FF
    sta a:$E1AD,Y
clear_six_actor_references_to_dead_actor_c04337:
    lda $81
    cmp a:$E1EC,Y
    bne clear_six_actor_references_to_dead_actor_c04343
    .a8
    lda #$0F
    sta a:$E1EC,Y
clear_six_actor_references_to_dead_actor_c04343:
    lda $81
    cmp a:$E1F0,Y
    bne clear_six_actor_references_to_dead_actor_c0434f
    .a8
    lda #$FF
    sta a:$E1EC,Y
clear_six_actor_references_to_dead_actor_c0434f:
    inc $A7
    inc $A7
    dec $B2
    bne clear_six_actor_references_to_dead_actor_c0431d
    rts
