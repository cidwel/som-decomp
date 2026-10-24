.setcpu "65816"
.segment "CODE"
.org $521C
map_control_0d521c:
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
