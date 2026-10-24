.setcpu "65816"
.segment "CODE"
.org $92CF
map_control_0c92cf:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
