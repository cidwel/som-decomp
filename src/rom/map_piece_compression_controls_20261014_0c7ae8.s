.setcpu "65816"
.segment "CODE"
.org $7AE8
map_control_0c7ae8:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
