.setcpu "65816"
.segment "CODE"
.org $1E9B
map_control_0e1e9b:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
