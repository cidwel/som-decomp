; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

merge_boss_contact_direction_flags = $12E2

.segment "CODE"
.org $12A2
prepare_and_test_one_party_actor_boss_contact:
    tya
    xba
    asl
    clc
    .a16
    adc #$E000
    sta $95
    tax
    lda a:$0000,X
    .a16
    cmp #$0001
    bne prepare_and_test_one_party_actor_boss_contact_c212e1
    lda a:$0002,X
    sta $56
    lda a:$0004,X
    sta $5E
    lda a:$0006,X
    sta $5A
    lda a:$0089,X
    .a16
    and #$0003
    inc
    asl
    tax
    lda f:$D97F09,X
    .a16
    and #$00FF
    sta $58
    lda f:$D97F0A,X
    .a16
    and #$00FF
    sta $60
    jsr merge_boss_contact_direction_flags
prepare_and_test_one_party_actor_boss_contact_c212e1:
    rts
