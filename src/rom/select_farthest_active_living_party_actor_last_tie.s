; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-action-helpers.md.
.setcpu "65816"
.smart
.a8
.i16

derive_actor_manhattan_distance_from_selected_boss = $08F1

.segment "CODE"
.org $325A
select_farthest_active_living_party_actor_last_tie:
    .i16
    ldy #$0000
    stz $1A
    stz $1C
select_farthest_active_living_party_actor_last_tie_c23261:
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
    bne select_farthest_active_living_party_actor_last_tie_c23284
    lda a:$0190,X
    bmi select_farthest_active_living_party_actor_last_tie_c23284
    jsr derive_actor_manhattan_distance_from_selected_boss
    cmp $1A
    bcc select_farthest_active_living_party_actor_last_tie_c23284
    sta $1A
    sty $1C
select_farthest_active_living_party_actor_last_tie_c23284:
    iny
    .i16
    cpy #$0003
    bne select_farthest_active_living_party_actor_last_tie_c23261
    lda $1C
    rts
