.setcpu "65816"
.segment "CODE"
.org $E167
map_control_0de167:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
