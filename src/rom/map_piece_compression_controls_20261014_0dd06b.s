.setcpu "65816"
.segment "CODE"
.org $D06B
map_control_0dd06b:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
