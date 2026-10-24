.setcpu "65816"
.segment "CODE"
.org $70E7
map_control_0c70e7:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
