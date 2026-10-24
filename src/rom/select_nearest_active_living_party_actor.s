; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-four.md.
.setcpu "65816"
.smart
.a8
.i16

derive_actor_manhattan_distance_from_selected_boss = $08F1

.segment "CODE"
.org $3224
select_nearest_active_living_party_actor:
    .i16
    ldy #$0000
    .a16
    lda #$7FFF
    sta $1A
    stz $1C
select_nearest_active_living_party_actor_c2322e:
    tya
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$0000,X
    .a16
    and #$00FF
    .a16
    cmp #$0001
    bne select_nearest_active_living_party_actor_c23251
    lda a:$0190,X
    bmi select_nearest_active_living_party_actor_c23251
    jsr derive_actor_manhattan_distance_from_selected_boss
    cmp $1A
    bcs select_nearest_active_living_party_actor_c23251
    sta $1A
    sty $1C
select_nearest_active_living_party_actor_c23251:
    iny
    .i16
    cpy #$0003
    bne select_nearest_active_living_party_actor_c2322e
    lda $1C
    rts
