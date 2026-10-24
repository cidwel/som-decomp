.setcpu "65816"
.segment "CODE"
.org $C562
map_control_0fc562:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
