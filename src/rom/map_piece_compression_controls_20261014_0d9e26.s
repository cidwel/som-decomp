.setcpu "65816"
.segment "CODE"
.org $9E26
map_control_0d9e26:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
