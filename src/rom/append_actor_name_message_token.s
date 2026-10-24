; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_original_id = $E1E7
object_actor_kind = $E1FB
message_queue_buffer = $FE00

.segment "CODE"
.org $5C06
append_actor_name_message_token:
    lda a:object_actor_kind,X
    bmi append_actor_name_message_token_c05c19
    .a8
    lda #$54
    sta a:message_queue_buffer,Y
    iny
    lda a:object_original_id,X
    sta a:message_queue_buffer,Y
    iny
    rts
append_actor_name_message_token_c05c19:
    .a8
    lda #$57
    sta a:message_queue_buffer,Y
    iny
    lda a:object_original_id,X
    sec
    .a8
    sbc #$80
    sta a:message_queue_buffer,Y
    iny
    rts
