.setcpu "65816"
.segment "CODE"
.org $B5A7
map_control_0fb5a7:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
