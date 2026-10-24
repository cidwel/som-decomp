.setcpu "65816"
.segment "CODE"
.org $2FDA
map_control_0c2fda:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
