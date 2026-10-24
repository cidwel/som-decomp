.setcpu "65816"
.segment "CODE"
.org $E1D0
map_control_0de1d0:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
