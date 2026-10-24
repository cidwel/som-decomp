.setcpu "65816"
.segment "CODE"
.org $E235
map_control_0de235:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
