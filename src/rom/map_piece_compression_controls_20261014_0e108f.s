.setcpu "65816"
.segment "CODE"
.org $108F
map_control_0e108f:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
