; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

process_actor_death_rewards_and_drop_conversion = $4203

.segment "CODE"
.org $3CA5
advance_actor_death_and_low_status_timer:
    lda a:$E190,X
    .a8
    bit #$03
    beq advance_actor_death_and_low_status_timer_c03cdd
    dec a:$E1B4,X
    bne advance_actor_death_and_low_status_timer_c03cdc
    lda a:$E175,X
    beq advance_actor_death_and_low_status_timer_c03cba
    inc a:$E1B4,X
    rts
advance_actor_death_and_low_status_timer_c03cba:
    lda a:$E190,X
    .a8
    and #$FC
    sta a:$E190,X
    ldy a:$E182,X
    bne advance_actor_death_and_low_status_timer_c03cdc
    lda a:$E1FB,X
    bpl advance_actor_death_and_low_status_timer_c03cd7
advance_actor_death_and_low_status_timer_c03ccc:
    .a8
    lda #$2F
    sta a:$E1E5,X
    lda $80
    .a8
    ora #$40
    sta $80
advance_actor_death_and_low_status_timer_c03cd7:
    .a8
    lda #$80
    sta a:$E191,X
advance_actor_death_and_low_status_timer_c03cdc:
    rts
advance_actor_death_and_low_status_timer_c03cdd:
    lda a:$E1FB,X
    bpl advance_actor_death_and_low_status_timer_c03ced
    lda a:$E191,X
    bmi advance_actor_death_and_low_status_timer_c03cdc
    ldy a:$E182,X
    beq advance_actor_death_and_low_status_timer_c03ccc
    rts
advance_actor_death_and_low_status_timer_c03ced:
    lda a:$E191,X
    bmi advance_actor_death_and_low_status_timer_c03cdc
    ldy a:$E182,X
    bne advance_actor_death_and_low_status_timer_c03cdc
    .a8
    lda #$80
    sta a:$E191,X
    lda a:$E1FA,X
    .a8
    ora #$02
    sta a:$E1FA,X
    rep #$20
    .a16
    lda #$0000
    sta a:$E1EE,X
    sta a:$E19E,X
    lda a:$E190,X
    .a16
    and #$8003
    sta a:$E190,X
    jsr process_actor_death_rewards_and_drop_conversion
    rts
