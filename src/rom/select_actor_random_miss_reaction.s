; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

advance_additive_random_generator = $38A0

.segment "CODE"
.org $4E6F
select_actor_random_miss_reaction:
    rep #$20
    lda a:$E190,X
    .a16
    bit #$C57D
    sep #$20
    bne select_actor_random_miss_reaction_c04ea8
    lda a:$E1E5,X
    bmi select_actor_random_miss_reaction_c04e81
    rts
select_actor_random_miss_reaction_c04e81:
    lda a:$E175,X
    bne select_actor_random_miss_reaction_c04ea8
    jsr advance_additive_random_generator
    sta f:$004202
    .a8
    lda #$03
    sta f:$004203
    lda a:$E1FB,X
    .a8
    bit #$81
    bne select_actor_random_miss_reaction_c04e9e
    .a8
    lda #$0C
    bra select_actor_random_miss_reaction_c04ea0
select_actor_random_miss_reaction_c04e9e:
    .a8
    lda #$11
select_actor_random_miss_reaction_c04ea0:
    clc
    adc f:$004217
    sta a:$E1E5,X
select_actor_random_miss_reaction_c04ea8:
    rts
