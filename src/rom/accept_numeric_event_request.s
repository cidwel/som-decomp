; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

clear_event_request_scratch_and_return = $E881
prepare_actor_for_new_event = $E88D
routine_c1e7c9 = $E7C9

.segment "CODE"
.org $E77B
accept_numeric_event_request:
    rep #$30
    phx
    .a16
    cmp #$0800
    bcs routine_c1e7c9
    sta $00
    lda $D0
    .a16
    and #$00FF
    beq accept_numeric_event_request_c1e794
    .a16
    cmp #$00FF
    beq accept_numeric_event_request_c1e794
    brl clear_event_request_scratch_and_return
accept_numeric_event_request_c1e794:
    lda $00
    .a16
    cmp #$0400
    php
    .a16
    and #$03FF
    asl
    tax
    plp
    bcs accept_numeric_event_request_c1e7ae
    lda f:$C90000,X
    sta $D1
    sep #$20
    .a8
    lda #$C9
    bra accept_numeric_event_request_c1e7b8
accept_numeric_event_request_c1e7ae:
    lda f:$CA0000,X
    sta $D1
    sep #$20
    .a8
    lda #$CA
accept_numeric_event_request_c1e7b8:
    sta $D3
    lda $D0
    .a8
    cmp #$01
    .a8
    lda #$01
    sta $D0
    bcc accept_numeric_event_request_c1e7c6
    plx
    rts
accept_numeric_event_request_c1e7c6:
    brl prepare_actor_for_new_event
