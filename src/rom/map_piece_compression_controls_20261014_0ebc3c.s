.setcpu "65816"
.segment "CODE"
.org $BC3C
map_control_0ebc3c:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
