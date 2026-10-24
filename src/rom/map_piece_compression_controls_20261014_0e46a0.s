.setcpu "65816"
.segment "CODE"
.org $46A0
map_control_0e46a0:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
