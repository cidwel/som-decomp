.setcpu "65816"
.segment "CODE"
.org $BFCB
map_control_0ebfcb:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
