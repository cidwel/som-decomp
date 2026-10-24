.setcpu "65816"
.segment "CODE"
.org $5C66
map_control_0d5c66:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
