; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-restore.md.
.setcpu "65816"
.smart
.a8
.i16

finish_previous_cast_and_request_followup_event = $C03F94

.segment "CODE"
.org $385E
finish_previous_cast_native_long_jump:
    jml f:finish_previous_cast_and_request_followup_event
