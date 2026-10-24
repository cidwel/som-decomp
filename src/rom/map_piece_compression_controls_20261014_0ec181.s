.setcpu "65816"
.segment "CODE"
.org $C181
map_control_0ec181:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
