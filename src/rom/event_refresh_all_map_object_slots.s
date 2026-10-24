; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-object-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_map_object_slot_when_inactive_or_flag_rejected = $EA84

.segment "CODE"
.org $EA62
event_refresh_all_map_object_slots:
    rep #$10
    .i16
    ldx #$1600
    bit $ED
    bpl event_refresh_all_map_object_slots_c1ea6e
    .i16
    ldx #$0A00
event_refresh_all_map_object_slots_c1ea6e:
    stx $10
    jsr refresh_map_object_slot_when_inactive_or_flag_rejected
    rep #$20
    lda $10
    sec
    .a16
    sbc #$0200
    tax
    .a16
    cmp #$0600
    bcs event_refresh_all_map_object_slots_c1ea6e
    inc $D1
    rts
