; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

filter_damage_over_time_actor_statuses = $E50F
filter_low_actor_statuses = $E487
filter_transformation_actor_statuses = $E4D7
routine_c8e441 = $E441
routine_c8e52f = $E52F
routine_c8e5ff = $E5FF

object_status_word = $E190
object_previous_status_word = $E1EE
object_status_immunity = $E1AA
object_magic_defence = $E1A8
object_rebuild_flags = $E1FA
object_actor_kind = $E1FB
object_hp = $E182
object_low_status_timer = $E1B2
object_silence_balloon_timer = $E1B3
object_transformation_timer = $E1B5
object_damage_status_timer = $E1B6
object_timer_phase = $E1B9
object_combat_animation = $E1E5

.segment "CODE"
.org $E301
apply_actor_status_and_timers:
    rep #$20
    stz $98
    lda $9A
    ora $98
    sta $98
    lda a:object_status_immunity,X
    .a16
    eor #$FFFF
    sta $A4
    and $98
    sta $98
    stz $9A
    ora a:object_status_word,X
    and $A4
    sta a:object_status_word,X
    lda a:object_previous_status_word,X
    sta $A6
    .a16
    eor #$FFFC
    and a:object_status_word,X
    ora $98
    sta $98
    lda a:object_status_word,X
    .a16
    and #$FFFC
    cmp a:object_previous_status_word,X
    bne apply_actor_status_and_timers_c8e342
    lda $98
    bne apply_actor_status_and_timers_c8e34b
    sep #$20
    rtl
apply_actor_status_and_timers_c8e342:
    lda a:object_rebuild_flags,X
    .a16
    ora #$0002
    sta a:object_rebuild_flags,X
apply_actor_status_and_timers_c8e34b:
    .a16
    lda #$FFFF
    sta $B0
    lda a:object_status_word,X
    .a16
    eor #$FFFF
    and a:object_previous_status_word,X
    sta $AE
    bpl apply_actor_status_and_timers_c8e362
    jsr routine_c8e441
    rep #$20
apply_actor_status_and_timers_c8e362:
    lda a:object_status_word,X
    bpl apply_actor_status_and_timers_c8e374
    .a16
    and #$8000
    sta a:object_status_word,X
    lda $98
    .a16
    and #$8000
    sta $98
apply_actor_status_and_timers_c8e374:
    lda $98
    bpl apply_actor_status_and_timers_c8e382
    .a16
    lda #$8000
    sta $98
    sta a:object_status_word,X
    stz $B0
apply_actor_status_and_timers_c8e382:
    lda a:object_status_word,X
    .a16
    and #$FFFC
    sta a:object_previous_status_word,X
    jsr filter_low_actor_statuses
    jsr filter_transformation_actor_statuses
    jsr filter_damage_over_time_actor_statuses
    lda $98
    and a:object_status_word,X
    sta $98
    .a16
    bit #$4560
    beq apply_actor_status_and_timers_c8e3a9
    lda a:object_actor_kind,X
    .a16
    ora #$0002
    sta a:object_actor_kind,X
apply_actor_status_and_timers_c8e3a9:
    lda a:object_magic_defence,X
    lsr
    sta $A4
    lda $96
    lsr
    lsr
    sec
    sbc $A4
    sep #$20
    bpl apply_actor_status_and_timers_c8e3bc
    .a8
    lda #$00
apply_actor_status_and_timers_c8e3bc:
    .a8
    cmp #$14
    bcs apply_actor_status_and_timers_c8e3c2
    .a8
    lda #$14
apply_actor_status_and_timers_c8e3c2:
    sta $9C
    lda $99
    .a8
    bit #$60
    beq apply_actor_status_and_timers_c8e3d1
    lda $9C
    sta a:object_damage_status_timer,X
    lda $99
apply_actor_status_and_timers_c8e3d1:
    .a8
    bit #$1C
    beq apply_actor_status_and_timers_c8e3da
    lda $9C
    sta a:object_transformation_timer,X
apply_actor_status_and_timers_c8e3da:
    rep #$20
    lda $98
    .a16
    bit #$0180
    sep #$20
    beq apply_actor_status_and_timers_c8e3ea
    lda $9C
    sta a:object_silence_balloon_timer,X
apply_actor_status_and_timers_c8e3ea:
    lda $98
    .a8
    bit #$7C
    beq apply_actor_status_and_timers_c8e3f5
    lda $9C
    sta a:object_low_status_timer,X
apply_actor_status_and_timers_c8e3f5:
    lda $B0
    bne apply_actor_status_and_timers_c8e3fe
    .a8
    lda #$FF
    sta a:object_combat_animation,X
apply_actor_status_and_timers_c8e3fe:
    lda $AE
    bpl apply_actor_status_and_timers_c8e406
    jsl f:$C03F28
apply_actor_status_and_timers_c8e406:
    jsl f:$C04530
    sep #$20
    .a8
    lda #$05
    sta a:object_timer_phase,X
    jsr routine_c8e52f
    jsr routine_c8e5ff
    lda $80
    .a8
    ora #$40
    sta $80
    lda a:$E000
    beq apply_actor_status_and_timers_c8e427
    ldy a:object_hp
    bne apply_actor_status_and_timers_c8e43c
apply_actor_status_and_timers_c8e427:
    lda a:$E200
    beq apply_actor_status_and_timers_c8e431
    ldy a:$E382
    bne apply_actor_status_and_timers_c8e43c
apply_actor_status_and_timers_c8e431:
    lda a:$E400
    beq apply_actor_status_and_timers_c8e43b
    ldy a:$E582
    bne apply_actor_status_and_timers_c8e43c
apply_actor_status_and_timers_c8e43b:
    rtl
apply_actor_status_and_timers_c8e43c:
    jsl f:$C05A87
    rtl
