.setcpu "65816"
.segment "CODE"
.org $13A2
map_control_0d13a2:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
