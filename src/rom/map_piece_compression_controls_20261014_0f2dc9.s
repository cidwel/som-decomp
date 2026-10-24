.setcpu "65816"
.segment "CODE"
.org $2DC9
map_control_0f2dc9:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
