.setcpu "65816"
.segment "CODE"
.org $70DE
map_control_0d70de:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
