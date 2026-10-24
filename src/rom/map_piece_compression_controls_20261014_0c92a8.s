.setcpu "65816"
.segment "CODE"
.org $92A8
map_control_0c92a8:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
