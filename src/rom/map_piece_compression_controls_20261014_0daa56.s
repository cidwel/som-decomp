.setcpu "65816"
.segment "CODE"
.org $AA56
map_control_0daa56:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
