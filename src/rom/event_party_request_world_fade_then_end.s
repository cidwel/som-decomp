; Complete selectors three/four: tools/event_party_fade.py.
.setcpu "65816"
.segment "CODE"
.org $EB80
.a8
event_party_request_world_fade_then_end:
    cmp #$03
    bne selector_four
    rep #$20
.a16
    lda #$0D80
    sta $FA
    lda #$0D80
    sta $FC
    sep #$20
.a8
    lda #$02
    bra request_fade
selector_four:
    rep #$20
.a16
    lda #$0D80
    sta $FA
    lda #$0D80
    sta $FC
    sep #$20
.a8
    lda #$84
request_fade:
    sta $E3
    jsl $00BC01
    brl $E9C4
