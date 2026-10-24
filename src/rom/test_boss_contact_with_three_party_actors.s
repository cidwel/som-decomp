; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_and_test_one_party_actor_boss_contact = $12A2

.segment "CODE"
.org $125B
test_boss_contact_with_three_party_actors:
    lda a:$0098,X
    .a16
    bit #$0010
    beq test_boss_contact_with_three_party_actors_c212a0
    lda a:$0066,X
    .a16
    cmp #$0040
    bcs test_boss_contact_with_three_party_actors_c212a0
    lda a:$002B,X
    sta $46
    lda a:$0032,X
    clc
    adc a:$00A5,X
    sta $4E
    lda a:$001E,X
    beq test_boss_contact_with_three_party_actors_c212a0
    asl
    tax
    lda f:$D97F09,X
    .a16
    and #$00FF
    sta $48
    lda f:$D97F0A,X
    .a16
    and #$00FF
    sta $50
    .i16
    ldy #$0000
test_boss_contact_with_three_party_actors_c21295:
    jsr prepare_and_test_one_party_actor_boss_contact
    iny
    .i16
    cpy #$0003
    bne test_boss_contact_with_three_party_actors_c21295
    ldx $87
test_boss_contact_with_three_party_actors_c212a0:
    clc
    rts
