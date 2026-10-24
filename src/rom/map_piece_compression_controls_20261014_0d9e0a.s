.setcpu "65816"
.segment "CODE"
.org $9E0A
map_control_0d9e0a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
