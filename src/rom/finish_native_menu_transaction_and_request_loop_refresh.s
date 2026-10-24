; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-transaction-finish.md.
.setcpu "65816"
.smart
.a8
.i16

request_event_menu_loop_and_initialize_input_state = $692D

.segment "CODE"
.org $760A
finish_native_menu_transaction_and_request_loop_refresh:
    jsr request_event_menu_loop_and_initialize_input_state
    sep #$20
    .a8
    lda #$40
    trb a:$1803
    .a8
    lda #$02
    tsb a:$1803
    rts
