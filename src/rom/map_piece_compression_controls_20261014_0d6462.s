.setcpu "65816"
.segment "CODE"
.org $6462
map_control_0d6462:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
