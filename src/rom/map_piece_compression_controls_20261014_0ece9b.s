.setcpu "65816"
.segment "CODE"
.org $CE9B
map_control_0ece9b:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
