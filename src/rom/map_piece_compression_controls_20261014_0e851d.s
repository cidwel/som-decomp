.setcpu "65816"
.segment "CODE"
.org $851D
map_control_0e851d:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
