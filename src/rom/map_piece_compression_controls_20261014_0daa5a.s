.setcpu "65816"
.segment "CODE"
.org $AA5A
map_control_0daa5a:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
