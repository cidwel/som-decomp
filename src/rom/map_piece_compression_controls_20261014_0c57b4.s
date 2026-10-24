.setcpu "65816"
.segment "CODE"
.org $57B4
map_control_0c57b4:
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
