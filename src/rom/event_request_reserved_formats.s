; Recovered Secret of Mana USA routine; behaviour documented in docs/cutscene-engine.md.
.setcpu "65816"
.smart
.a8
.i16

clear_event_request_scratch_and_return = $E881

.segment "CODE"
.org $E871
event_request_reserved_formats:
    .a16
    cmp #$0E00
    bcs event_request_reserved_formats_c1e879
    brl clear_event_request_scratch_and_return
event_request_reserved_formats_c1e879:
    .a16
    cmp #$0F00
    bcs clear_event_request_scratch_and_return
    brl clear_event_request_scratch_and_return
