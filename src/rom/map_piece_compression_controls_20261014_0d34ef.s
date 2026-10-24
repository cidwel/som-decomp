.setcpu "65816"
.segment "CODE"
.org $34EF
map_control_0d34ef:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
