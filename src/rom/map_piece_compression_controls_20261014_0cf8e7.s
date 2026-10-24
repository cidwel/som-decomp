.setcpu "65816"
.segment "CODE"
.org $F8E7
map_control_0cf8e7:
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
