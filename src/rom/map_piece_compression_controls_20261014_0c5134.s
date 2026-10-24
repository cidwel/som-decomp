.setcpu "65816"
.segment "CODE"
.org $5134
map_control_0c5134:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
