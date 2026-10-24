; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-attack-entry.md.
.setcpu "65816"
.smart
.a8
.i16

restore_actor_attack_palette_with_saved_bank = $B313
routine_01e40e = $1E40E

.segment "CODE"
.org $B2A7
begin_actor_attack_variant_and_update_party_gauge:
    lda f:$7EE01C,X
    ora f:$7EE061,X
    beq begin_actor_attack_variant_and_update_party_gauge_c0b2b2
    rts
begin_actor_attack_variant_and_update_party_gauge_c0b2b2:
    .a8
    lda #$FF
    sta f:$7EE030,X
    .a8
    lda #$20
    sta f:$7EE01C,X
    .a8
    lda #$00
    sta f:$7EE036,X
    sta f:$7EE006,X
    sta f:$7EE007,X
    lda f:$7EE191,X
    .a8
    bit #$02
    beq begin_actor_attack_variant_and_update_party_gauge_c0b2db
    lda $F4
    lsr
    .a8
    and #$01
    bra begin_actor_attack_variant_and_update_party_gauge_c0b2e2
begin_actor_attack_variant_and_update_party_gauge_c0b2db:
    clc
    jsl f:routine_01e40e
    sep #$20
begin_actor_attack_variant_and_update_party_gauge_c0b2e2:
    sta f:$7EE011,X
    jsr restore_actor_attack_palette_with_saved_bank
    lda f:$7EE1ED,X
    bne begin_actor_attack_variant_and_update_party_gauge_c0b2f6
    .a8
    lda #$01
    sta f:$7EE01A,X
    rts
begin_actor_attack_variant_and_update_party_gauge_c0b2f6:
    rep #$20
    txa
    xba
    asl
    asl
    asl
    tay
    .a16
    lda #$2817
    sta a:$0A56,Y
    .a16
    lda #$0000
    sta a:$0A50,Y
    sta a:$0A52,Y
    sta a:$0A53,Y
    sep #$20
    rts
