.setcpu "65816"
.segment "CODE"
.org $8006
map_control_0c8006:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
