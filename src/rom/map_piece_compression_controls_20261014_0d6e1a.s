.setcpu "65816"
.segment "CODE"
.org $6E1A
map_control_0d6e1a:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
