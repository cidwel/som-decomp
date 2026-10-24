.setcpu "65816"
.segment "CODE"
.org $B650
map_control_0eb650:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
