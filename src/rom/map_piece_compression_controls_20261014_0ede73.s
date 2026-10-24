.setcpu "65816"
.segment "CODE"
.org $DE73
map_control_0ede73:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
