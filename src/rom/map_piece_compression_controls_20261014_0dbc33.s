.setcpu "65816"
.segment "CODE"
.org $BC33
map_control_0dbc33:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
