.setcpu "65816"
.segment "CODE"
.org $27D7
map_control_0d27d7:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
