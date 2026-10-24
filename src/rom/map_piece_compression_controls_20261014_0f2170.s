.setcpu "65816"
.segment "CODE"
.org $2170
map_control_0f2170:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
