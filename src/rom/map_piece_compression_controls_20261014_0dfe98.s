.setcpu "65816"
.segment "CODE"
.org $FE98
map_control_0dfe98:
    .byte $C3 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
