.setcpu "65816"
.segment "CODE"
.org $1DEE
map_control_0e1dee:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
