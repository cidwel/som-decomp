; Recovered Secret of Mana USA routine; behaviour documented in docs/cutscene-engine.md.
.setcpu "65816"
.smart
.a8
.i16

clear_event_request_scratch_and_return = $E881
event_request_scroll_transition = $E803
routine_01cbcf = $1CBCF

.segment "CODE"
.org $E7C9
event_request_map_transition:
    .a16
    cmp #$0C00
    bcs event_request_scroll_transition
    pha
    jsl f:routine_01cbcf
    rep #$20
    pla
    .a16
    and #$03FF
    sta a:$010E
    asl
    asl
    tax
    lda f:$C83000,X
    .a16
    and #$01FF
    sta $DC
    lda f:$C83001,X
    .a16
    and #$00FF
    lsr
    sta $DE
    lda f:$C83002,X
    sta $DF
    sep #$20
    .a8
    lda #$40
    sta $FF
    stz $E8
    brl clear_event_request_scratch_and_return
