; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-freeze-attack-gates.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0b2f6 = $B2F6

.segment "CODE"
.org $B21C
consume_controller_selected_deferred_attack_or_begin_attack:
    rep #$10
    .a8
    and #$06
    xba
    .a8
    lda #$00
    tax
    lda f:$7EE060,X
    .a8
    cmp #$40
    beq consume_controller_selected_deferred_attack_or_begin_attack_c0b247
    lda f:$7EE19B,X
    bne consume_controller_selected_deferred_attack_or_begin_attack_c0b248
    lda f:$7EE01C,X
    bne consume_controller_selected_deferred_attack_or_begin_attack_c0b247
    lda f:$7EE01A,X
    beq consume_controller_selected_deferred_attack_or_begin_attack_c0b247
    .a8
    lda #$00
    sta f:$7EE01A,X
    brl routine_c0b2f6
consume_controller_selected_deferred_attack_or_begin_attack_c0b247:
    rts
consume_controller_selected_deferred_attack_or_begin_attack_c0b248:
    stz $00
