; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-queued-effect-requests.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_guarded_actor_cast_request_and_party_graphics = $88C7

.segment "CODE"
.org $DC38
consume_queued_guarded_cast_request:
    lda a:$19F1
    bpl consume_queued_guarded_cast_request_c1dc3e
    rts
consume_queued_guarded_cast_request_c1dc3e:
    .a8
    and #$03
    asl
    xba
    .a8
    lda #$00
    tax
    jmp prepare_guarded_actor_cast_request_and_party_graphics
