.setcpu "65816"
.segment "CODE"
.org $BA8D
map_control_0eba8d:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
