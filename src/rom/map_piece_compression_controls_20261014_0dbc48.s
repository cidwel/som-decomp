.setcpu "65816"
.segment "CODE"
.org $BC48
map_control_0dbc48:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
