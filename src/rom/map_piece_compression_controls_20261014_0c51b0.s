.setcpu "65816"
.segment "CODE"
.org $51B0
map_control_0c51b0:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
