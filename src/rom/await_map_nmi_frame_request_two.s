; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-overlay-wait.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CFD5
await_map_nmi_frame_request_two:
    sep #$20
    .a8
    lda #$02
    sta $EC
await_map_nmi_frame_request_two_c2cfdb:
    bit $EC
    bne await_map_nmi_frame_request_two_c2cfdb
    rts
