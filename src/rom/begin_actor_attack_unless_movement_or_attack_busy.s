; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-attack-entry.md.
.setcpu "65816"
.smart
.a8
.i16

restore_actor_attack_palette_with_saved_bank = $B313
routine_01e40e = $1E40E

.segment "CODE"
.org $B24A
begin_actor_attack_unless_movement_or_attack_busy:
    lda f:$7EE060,X
    ora f:$7EE061,X
    ora f:$7EE01C,X
    beq begin_actor_attack_unless_movement_or_attack_busy_c0b259
    rts
begin_actor_attack_unless_movement_or_attack_busy_c0b259:
    .a8
    lda #$FF
    sta f:$7EE030,X
    .a8
    lda #$80
    sta f:$7EE01C,X
    .a8
    lda #$00
    sta f:$7EE036,X
    sta f:$7EE01D,X
    sta f:$7EE006,X
    sta f:$7EE007,X
    asl $00
    jsl f:routine_01e40e
    sep #$20
    sta f:$7EE011,X
    jsr restore_actor_attack_palette_with_saved_bank
    rts
