.setcpu "65816"
.segment "CODE"
.org $4E48
map_control_0e4e48:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
