.setcpu "65816"
.segment "CODE"
.org $4C15
map_control_0e4c15:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
