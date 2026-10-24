.setcpu "65816"
.segment "CODE"
.org $6038
map_control_0d6038:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
