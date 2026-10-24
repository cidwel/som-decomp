.setcpu "65816"
.segment "CODE"
.org $BC2A
map_control_0dbc2a:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
