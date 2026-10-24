; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-execution-check.md.
.setcpu "65816"
.smart
.a8
.i16

deliver_complete_cast_hit_to_target = $8D12
deliver_reflected_cast_hit_preserving_actor = $8D09
execute_native_spell_entity_scheduler_long = $C10038
restore_actor_weapon_after_cast = $8DAB
routine_00e328 = $E328
routine_00e351 = $E351
transfer_cast_presentation_to_target = $87C2

.segment "CODE"
.org $8C96
cancel_cast_and_deliver_pending_target_hits:
    ldx $14
    sep #$20
    lda a:$E110,X
    .a8
    cmp #$08
    bcc cancel_cast_and_deliver_pending_target_hits_c18cb9
    pha
    phx
    jsl f:routine_00e328
    sep #$20
    plx
    pla
    stx $14
    jsl f:execute_native_spell_entity_scheduler_long
    jsl f:routine_00e351
    sep #$20
    ldx $14
cancel_cast_and_deliver_pending_target_hits_c18cb9:
    stz a:$E060,X
    ldy a:$E116,X
    phx
    jsr deliver_complete_cast_hit_to_target
    rep #$10
    plx
    bcc cancel_cast_and_deliver_pending_target_hits_c18ccb
    jsr deliver_reflected_cast_hit_preserving_actor
cancel_cast_and_deliver_pending_target_hits_c18ccb:
    ldy a:$E126,X
    bmi cancel_cast_and_deliver_pending_target_hits_c18ced
    phx
    jsr deliver_complete_cast_hit_to_target
    rep #$10
    plx
    bcc cancel_cast_and_deliver_pending_target_hits_c18cdc
    jsr deliver_reflected_cast_hit_preserving_actor
cancel_cast_and_deliver_pending_target_hits_c18cdc:
    ldy a:$E136,X
    bmi cancel_cast_and_deliver_pending_target_hits_c18ced
    phx
    jsr deliver_complete_cast_hit_to_target
    rep #$10
    plx
    bcc cancel_cast_and_deliver_pending_target_hits_c18ced
    jsr deliver_reflected_cast_hit_preserving_actor
cancel_cast_and_deliver_pending_target_hits_c18ced:
    sep #$20
    lda a:$E108,X
    bpl cancel_cast_and_deliver_pending_target_hits_c18cf8
    txy
    jmp transfer_cast_presentation_to_target
cancel_cast_and_deliver_pending_target_hits_c18cf8:
    .i16
    cpx #$0600
    bcs cancel_cast_and_deliver_pending_target_hits_c18d08
    lda a:$E060,X
    bne cancel_cast_and_deliver_pending_target_hits_c18d08
    stz a:$E104,X
    jmp restore_actor_weapon_after_cast
cancel_cast_and_deliver_pending_target_hits_c18d08:
    rts
