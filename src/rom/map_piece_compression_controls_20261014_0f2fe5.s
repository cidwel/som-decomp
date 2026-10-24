.setcpu "65816"
.segment "CODE"
.org $2FE5
map_control_0f2fe5:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
