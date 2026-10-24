.setcpu "65816"
.segment "CODE"
.org $B7D8
map_control_0eb7d8:
    .byte $EF ; backreference distance high bits
    .byte $1C ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
