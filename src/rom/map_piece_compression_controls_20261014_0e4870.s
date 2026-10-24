.setcpu "65816"
.segment "CODE"
.org $4870
map_control_0e4870:
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
