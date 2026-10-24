.setcpu "65816"
.segment "CODE"
.org $1C92
map_control_0d1c92:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
