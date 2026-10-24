.setcpu "65816"
.segment "CODE"
.org $BC1B
map_control_0ebc1b:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
