.setcpu "65816"
.segment "CODE"
.org $1019
map_control_0d1019:
    .byte $C1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
