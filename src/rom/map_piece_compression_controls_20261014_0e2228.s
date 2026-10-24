.setcpu "65816"
.segment "CODE"
.org $2228
map_control_0e2228:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
