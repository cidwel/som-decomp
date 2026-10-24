.setcpu "65816"
.segment "CODE"
.org $48E8
map_control_0e48e8:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
