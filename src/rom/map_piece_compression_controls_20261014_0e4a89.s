.setcpu "65816"
.segment "CODE"
.org $4A89
map_control_0e4a89:
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
