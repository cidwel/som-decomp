.setcpu "65816"
.segment "CODE"
.org $BC31
map_control_0ebc31:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
