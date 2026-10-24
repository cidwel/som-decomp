.setcpu "65816"
.segment "CODE"
.org $485A
map_control_0e485a:
    .byte $EB ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
