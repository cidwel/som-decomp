.setcpu "65816"
.segment "CODE"
.org $7031
map_control_0c7031:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
