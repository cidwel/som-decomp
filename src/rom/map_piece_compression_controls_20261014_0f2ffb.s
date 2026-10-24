.setcpu "65816"
.segment "CODE"
.org $2FFB
map_control_0f2ffb:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
