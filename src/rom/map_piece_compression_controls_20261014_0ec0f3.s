.setcpu "65816"
.segment "CODE"
.org $C0F3
map_control_0ec0f3:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
