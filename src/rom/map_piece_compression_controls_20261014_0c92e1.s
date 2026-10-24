.setcpu "65816"
.segment "CODE"
.org $92E1
map_control_0c92e1:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
