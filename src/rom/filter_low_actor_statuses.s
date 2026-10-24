; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_status_word = $E190
object_hp = $E182
object_secondary_buff_flags = $E1B1

.segment "CODE"
.org $E487
filter_low_actor_statuses:
    rep #$20
    lda a:object_status_word,X
    .a16
    bit #$0040
    beq filter_low_actor_statuses_c8e49e
    .a16
    and #$9AC0
    sta a:object_status_word,X
    lsr a:object_hp,X
    inc a:object_hp,X
    rts
filter_low_actor_statuses_c8e49e:
    .a16
    bit #$0020
    beq filter_low_actor_statuses_c8e4aa
    .a16
    and #$9AE0
    sta a:object_status_word,X
    rts
filter_low_actor_statuses_c8e4aa:
    .a16
    bit #$0010
    beq filter_low_actor_statuses_c8e4bf
    .a16
    and #$FBF0
    sta a:object_status_word,X
    lda a:object_secondary_buff_flags,X
    .a16
    ora #$0001
    sta a:object_secondary_buff_flags,X
    rts
filter_low_actor_statuses_c8e4bf:
    .a16
    bit #$0008
    beq filter_low_actor_statuses_c8e4cb
    .a16
    and #$FBF0
    sta a:object_status_word,X
    rts
filter_low_actor_statuses_c8e4cb:
    .a16
    bit #$0004
    beq filter_low_actor_statuses_c8e4d6
    .a16
    and #$FFFC
    sta a:object_status_word,X
filter_low_actor_statuses_c8e4d6:
    rts
