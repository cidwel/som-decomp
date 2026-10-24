.setcpu "65816"
.segment "CODE"
.org $9226
map_control_0e9226:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
