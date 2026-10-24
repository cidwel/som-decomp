.setcpu "65816"
.segment "CODE"
.org $5CEA
map_control_0e5cea:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
