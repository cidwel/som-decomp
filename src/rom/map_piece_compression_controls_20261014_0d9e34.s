.setcpu "65816"
.segment "CODE"
.org $9E34
map_control_0d9e34:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
