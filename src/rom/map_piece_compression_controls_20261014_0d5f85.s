.setcpu "65816"
.segment "CODE"
.org $5F85
map_control_0d5f85:
    .byte $C3 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
