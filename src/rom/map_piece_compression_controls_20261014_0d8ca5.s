.setcpu "65816"
.segment "CODE"
.org $8CA5
map_control_0d8ca5:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
