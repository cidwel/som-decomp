.setcpu "65816"
.segment "CODE"
.org $5BF3
map_control_0c5bf3:
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
