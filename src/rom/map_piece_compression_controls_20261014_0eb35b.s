.setcpu "65816"
.segment "CODE"
.org $B35B
map_control_0eb35b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
