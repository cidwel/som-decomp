.setcpu "65816"
.segment "CODE"
.org $1A45
map_control_0c1a45:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
