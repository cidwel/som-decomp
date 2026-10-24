; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_status_word = $E190

.segment "CODE"
.org $E4D7
filter_transformation_actor_statuses:
    lda a:object_status_word,X
    .a16
    bit #$1000
    beq filter_transformation_actor_statuses_c8e4e6
    .a16
    and #$92FF
    sta a:object_status_word,X
    rts
filter_transformation_actor_statuses_c8e4e6:
    .a16
    bit #$0800
    beq filter_transformation_actor_statuses_c8e4fe
    .a16
    bit #$0260
    bne filter_transformation_actor_statuses_c8e4f7
    .a16
    and #$9A13
    sta a:object_status_word,X
    rts
filter_transformation_actor_statuses_c8e4f7:
    .a16
    and #$F7FF
    sta a:object_status_word,X
    rts
filter_transformation_actor_statuses_c8e4fe:
    .a16
    bit #$0400
    beq filter_transformation_actor_statuses_c8e50e
    .a16
    bit #$617B
    beq filter_transformation_actor_statuses_c8e50e
    .a16
    and #$FBFF
    sta a:object_status_word,X
filter_transformation_actor_statuses_c8e50e:
    rts
