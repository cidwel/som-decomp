.setcpu "65816"
.segment "CODE"
.org $F5AE
map_control_0ff5ae:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
