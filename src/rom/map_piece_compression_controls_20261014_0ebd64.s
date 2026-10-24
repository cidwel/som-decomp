.setcpu "65816"
.segment "CODE"
.org $BD64
map_control_0ebd64:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
