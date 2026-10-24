.setcpu "65816"
.segment "CODE"
.org $2396
map_control_0e2396:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
