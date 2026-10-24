.setcpu "65816"
.segment "CODE"
.org $5A21
map_control_0d5a21:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
