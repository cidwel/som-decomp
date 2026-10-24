.setcpu "65816"
.segment "CODE"
.org $52B0
map_control_0c52b0:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
