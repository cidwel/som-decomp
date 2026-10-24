.setcpu "65816"
.segment "CODE"
.org $DE84
map_control_0fde84:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
