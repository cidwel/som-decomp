.setcpu "65816"
.segment "CODE"
.org $21A4
map_control_0e21a4:
    .byte $C4 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
