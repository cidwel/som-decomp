; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $918A
select_actor_effect_direction_piece:
    .a8
    cmp #$10
    bcs select_actor_effect_direction_piece_c19190
    bra select_actor_effect_direction_piece_c191ba
select_actor_effect_direction_piece_c19190:
    .a8
    cmp #$30
    bcs select_actor_effect_direction_piece_c19196
    bra select_actor_effect_direction_piece_c191be
select_actor_effect_direction_piece_c19196:
    .a8
    cmp #$50
    bcs select_actor_effect_direction_piece_c1919c
    bra select_actor_effect_direction_piece_c191c2
select_actor_effect_direction_piece_c1919c:
    .a8
    cmp #$70
    bcs select_actor_effect_direction_piece_c191a2
    bra select_actor_effect_direction_piece_c191c6
select_actor_effect_direction_piece_c191a2:
    .a8
    cmp #$90
    bcs select_actor_effect_direction_piece_c191a8
    bra select_actor_effect_direction_piece_c191ca
select_actor_effect_direction_piece_c191a8:
    .a8
    cmp #$B0
    bcs select_actor_effect_direction_piece_c191ae
    bra select_actor_effect_direction_piece_c191ce
select_actor_effect_direction_piece_c191ae:
    .a8
    cmp #$D0
    bcs select_actor_effect_direction_piece_c191b4
    bra select_actor_effect_direction_piece_c191d2
select_actor_effect_direction_piece_c191b4:
    .a8
    cmp #$F0
    bcs select_actor_effect_direction_piece_c191ba
    bra select_actor_effect_direction_piece_c191d3
select_actor_effect_direction_piece_c191ba:
    .a8
    lda #$18
    bra select_actor_effect_direction_piece_c191d5
select_actor_effect_direction_piece_c191be:
    .a8
    lda #$48
    bra select_actor_effect_direction_piece_c191d5
select_actor_effect_direction_piece_c191c2:
    .a8
    lda #$24
    bra select_actor_effect_direction_piece_c191d5
select_actor_effect_direction_piece_c191c6:
    .a8
    lda #$54
    bra select_actor_effect_direction_piece_c191d5
select_actor_effect_direction_piece_c191ca:
    .a8
    lda #$3C
    bra select_actor_effect_direction_piece_c191d5
select_actor_effect_direction_piece_c191ce:
    .a8
    lda #$30
    bra select_actor_effect_direction_piece_c191d5
select_actor_effect_direction_piece_c191d2:
    rts
select_actor_effect_direction_piece_c191d3:
    .a8
    lda #$0C
select_actor_effect_direction_piece_c191d5:
    rep #$20
    .a16
    and #$00FF
    sta $00
    txa
    ora $00
    tax
    rts
