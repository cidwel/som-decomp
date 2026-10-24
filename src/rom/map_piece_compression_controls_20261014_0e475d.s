.setcpu "65816"
.segment "CODE"
.org $475D
map_control_0e475d:
    .byte $EB ; backreference distance high bits
    .byte $9B ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
