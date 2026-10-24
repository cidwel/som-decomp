.setcpu "65816"
.segment "CODE"
.org $4C66
map_control_0d4c66:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
