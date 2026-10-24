.setcpu "65816"
.segment "CODE"
.org $434A
map_control_0e434a:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
