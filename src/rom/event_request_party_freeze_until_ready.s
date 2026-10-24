; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16

routine_02b053 = $2B053
routine_c1ea54 = $EA54

.segment "CODE"
.org $EA43
event_request_party_freeze_until_ready:
    .a8
    lda #$80
    tsb $F1
    jsl f:routine_02b053
    bcc routine_c1ea54
    rts
