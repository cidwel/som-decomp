; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-selection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $692D
request_event_menu_loop_and_initialize_input_state:
    rep #$20
    .a16
    lda #$0001
    sta a:$1826
    .a16
    lda #$8080
    sta a:$19F0
    sta a:$19F2
    rts
