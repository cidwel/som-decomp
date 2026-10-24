.setcpu "65816"
.segment "CODE"
.org $F2A0
map_control_0cf2a0:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
