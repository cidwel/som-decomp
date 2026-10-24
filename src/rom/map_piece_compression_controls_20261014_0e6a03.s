.setcpu "65816"
.segment "CODE"
.org $6A03
map_control_0e6a03:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
