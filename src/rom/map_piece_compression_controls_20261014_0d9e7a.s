.setcpu "65816"
.segment "CODE"
.org $9E7A
map_control_0d9e7a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
