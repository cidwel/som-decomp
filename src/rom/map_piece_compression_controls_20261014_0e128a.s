.setcpu "65816"
.segment "CODE"
.org $128A
map_control_0e128a:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
