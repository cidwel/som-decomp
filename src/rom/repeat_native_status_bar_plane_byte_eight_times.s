; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-art.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6B96
repeat_native_status_bar_plane_byte_eight_times:
    .i16
    ldy #$0004
repeat_native_status_bar_plane_byte_eight_times_c76b99:
    sta a:$9400,X
    inx
    sta a:$9400,X
    inx
    dey
    bne repeat_native_status_bar_plane_byte_eight_times_c76b99
    rts
