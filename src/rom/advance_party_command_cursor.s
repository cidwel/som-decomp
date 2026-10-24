; Complete selector-five entry proof: tools/event_party_noop.py.
.setcpu "65816"
.segment "CODE"
.org $EB63
.a16
advance_party_command_cursor:
    rep #$20
    inc $D1
    inc $D1
    sep #$20
.a8
    lda $05
    cmp #$03
    bcs $EB7C
