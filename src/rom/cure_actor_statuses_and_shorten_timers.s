; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_status_word = $E190
object_status_high = $E191
object_secondary_buff_flags = $E1B1
object_first_status_timer = $E1B2
object_spell_target_count = $E176

.segment "CODE"
.org $E9FC
cure_actor_statuses_and_shorten_timers:
    lda a:object_status_high,X
    .a8
    and #$FD
    sta a:object_status_high,X
    lda $9D
    .a8
    cmp #$08
    bne cure_actor_statuses_and_shorten_timers_c8ea29
cure_actor_statuses_and_shorten_timers_c8ea0a:
    .a8
    lda #$01
    sta a:object_first_status_timer,X
    sta a:$E1B3,X
    sta a:$E1B4,X
    sta a:$E1B5,X
    sta a:$E1B6,X
    rep #$20
    lda a:object_status_word,X
    .a16
    and #$8400
    sta a:object_status_word,X
    sep #$20
    rts
cure_actor_statuses_and_shorten_timers_c8ea29:
    .a8
    cmp #$04
    bcc cure_actor_statuses_and_shorten_timers_c8ea36
    lda a:object_spell_target_count,Y
    .a8
    cmp #$01
    bne cure_actor_statuses_and_shorten_timers_c8ea36
    bra cure_actor_statuses_and_shorten_timers_c8ea0a
cure_actor_statuses_and_shorten_timers_c8ea36:
    rep #$20
    lda $96
    lsr
    lsr
    sep #$20
    sta $A4
    .a8
    lda #$05
    sta $B2
cure_actor_statuses_and_shorten_timers_c8ea44:
    lda a:object_first_status_timer,X
    sec
    sbc $A4
    bcs cure_actor_statuses_and_shorten_timers_c8ea4e
    .a8
    lda #$00
cure_actor_statuses_and_shorten_timers_c8ea4e:
    bne cure_actor_statuses_and_shorten_timers_c8ea52
    .a8
    lda #$01
cure_actor_statuses_and_shorten_timers_c8ea52:
    sta a:object_first_status_timer,X
    inx
    dec $B2
    bne cure_actor_statuses_and_shorten_timers_c8ea44
    ldx $85
    ldx $85
    ldy $83
    lda a:object_secondary_buff_flags,X
    .a8
    ora #$04
    sta a:object_secondary_buff_flags,X
    rts
