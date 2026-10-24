; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_status_word = $E190

.segment "CODE"
.org $E50F
filter_damage_over_time_actor_statuses:
    lda a:object_status_word,X
    .a16
    bit #$4000
    beq filter_damage_over_time_actor_statuses_c8e51e
    .a16
    and #$DAFF
    sta a:object_status_word,X
    rts
filter_damage_over_time_actor_statuses_c8e51e:
    .a16
    bit #$2000
    beq filter_damage_over_time_actor_statuses_c8e52e
    .a16
    bit #$1860
    beq filter_damage_over_time_actor_statuses_c8e52e
    .a16
    and #$DFFF
    sta a:object_status_word,X
filter_damage_over_time_actor_statuses_c8e52e:
    rts
