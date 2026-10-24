.setcpu "65816"
.segment "CODE"
.org $CE93
map_control_0fce93:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
