.setcpu "65816"
.segment "CODE"
.org $7142
map_control_0e7142:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
