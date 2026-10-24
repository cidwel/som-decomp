; Recovered Secret of Mana USA routine; behaviour documented in docs/cutscene-engine.md.
.setcpu "65816"
.smart
.a8
.i16

clear_event_request_scratch_and_return = $E881
event_request_reserved_formats = $E871
routine_00bc01 = $BC01

.segment "CODE"
.org $E83A
event_request_destination_fade:
    .a16
    cmp #$0D80
    bcs event_request_reserved_formats
    bit $FE
    bmi event_request_destination_fade_c1e86e
    .a16
    and #$007F
    asl
    asl
    tax
    lda f:$C67C80,X
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
    lda f:$C67C82,X
    sta a:$0110
    jsl f:routine_00bc01
event_request_destination_fade_c1e86e:
    brl clear_event_request_scratch_and_return
