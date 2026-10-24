; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-four.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $08F1
derive_actor_manhattan_distance_from_selected_boss:
    lda a:$0002,X
    sta $95
    lda a:$0004,X
    sta $97
    ldx $87
    lda a:$002B,X
    sec
    sbc $95
    bpl derive_actor_manhattan_distance_from_selected_boss_c20909
    .a16
    eor #$FFFF
    inc
derive_actor_manhattan_distance_from_selected_boss_c20909:
    sta $95
    lda a:$0032,X
    sec
    sbc $97
    bpl derive_actor_manhattan_distance_from_selected_boss_c20917
    .a16
    eor #$FFFF
    inc
derive_actor_manhattan_distance_from_selected_boss_c20917:
    sta $97
    clc
    adc $95
    rts
