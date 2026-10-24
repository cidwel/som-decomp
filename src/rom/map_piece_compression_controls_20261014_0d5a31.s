.setcpu "65816"
.segment "CODE"
.org $5A31
map_control_0d5a31:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
