; Recovered Secret of Mana USA routine; behaviour documented in docs/cutscene-engine.md.
.setcpu "65816"
.smart
.a8
.i16

clear_event_request_scratch_and_return = $E881
event_request_destination_fade = $E83A
routine_01cbcb = $1CBCB

.segment "CODE"
.org $E803
event_request_scroll_transition:
    .a16
    cmp #$0D00
    bcs event_request_destination_fade
    bit $FE
    bmi event_request_scroll_transition_c1e837
    .a16
    and #$00FF
    asl
    tax
    lda f:$C67A80,X
    sta $00
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    sta $FA
    lda $01
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    sta $FC
    stz $F6
    sep #$20
    .a8
    lda #$04
    sta $E8
    jsl f:routine_01cbcb
event_request_scroll_transition_c1e837:
    brl clear_event_request_scratch_and_return
