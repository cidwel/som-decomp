.setcpu "65816"
.segment "CODE"
.org $87F0
map_control_0c87f0:
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
