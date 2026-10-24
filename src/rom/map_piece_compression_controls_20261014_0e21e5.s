.setcpu "65816"
.segment "CODE"
.org $21E5
map_control_0e21e5:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
