; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-tile-trigger.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01e76d = $1E76D

.segment "CODE"
.org $B630
scan_three_hero_tile_triggers_and_request_complete_event_format:
    rep #$10
    lda $D0
    beq scan_three_hero_tile_triggers_and_request_complete_event_format_c0b637
    rts
scan_three_hero_tile_triggers_and_request_complete_event_format_c0b637:
    .i16
    ldx #$0400
scan_three_hero_tile_triggers_and_request_complete_event_format_c0b63a:
    sep #$20
    lda f:$7EE045,X
    bne scan_three_hero_tile_triggers_and_request_complete_event_format_c0b678
    lda f:$7EE04B,X
    cmp $4D
    bcc scan_three_hero_tile_triggers_and_request_complete_event_format_c0b678
    sbc $4D
    asl
    sta $00
    lda $B8
    .a8
    and #$04
    lsr
    adc $00
    sta $00
    .a8
    lda #$00
    sta f:$7EE04B,X
    sta $01
    rep #$20
    lda $DC
    asl
    phx
    tax
    lda f:$C84000,X
    clc
    adc $00
    tax
    lda f:$C80000,X
    sta $00
    plx
    bra scan_three_hero_tile_triggers_and_request_complete_event_format_c0b683
scan_three_hero_tile_triggers_and_request_complete_event_format_c0b678:
    rep #$20
    txa
    sec
    .a16
    sbc #$0200
    tax
    bpl scan_three_hero_tile_triggers_and_request_complete_event_format_c0b63a
    rts
scan_three_hero_tile_triggers_and_request_complete_event_format_c0b683:
    rep #$20
    .a16
    lda #$0000
    sta f:$7EE006,X
    sta f:$7EE008,X
    lda $00
    .a16
    and #$0FFF
    stx $D4
    jsl f:routine_01e76d
    rts
