; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-public-pool-update.md.
.setcpu "65816"
.smart
.a8
.i16

cast_spell_public_jump = $C0001B
routine_01800f = $1800F
update_nine_boss_actor_slots_combat_definition_and_animation = $0DB2

.segment "CODE"
.org $01F9
update_boss_pool_then_consume_pending_cast_preserving_context:
    php
    phd
    phb
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    .a16
    lda #$0200
    tcd
    jsr update_nine_boss_actor_slots_combat_definition_and_animation
    lda a:$0360
    beq update_boss_pool_then_consume_pending_cast_preserving_context_c20236
    lda a:$02CA
    .a16
    and #$00FF
    bne update_boss_pool_then_consume_pending_cast_preserving_context_c20236
    ldx a:$0360
    jsl f:cast_spell_public_jump
    .a16
    and #$00FF
    bne update_boss_pool_then_consume_pending_cast_preserving_context_c20233
    lda a:$0360
    tax
    stz a:$0060,X
    .a16
    and #$1FFF
    tax
    jsl f:routine_01800f
update_boss_pool_then_consume_pending_cast_preserving_context_c20233:
    stz a:$0360
update_boss_pool_then_consume_pending_cast_preserving_context_c20236:
    plb
    pld
    plp
    rtl
