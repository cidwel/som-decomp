.setcpu "65816"
.segment "CODE"
.org $14A0
map_control_0c14a0:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
