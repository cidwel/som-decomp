.setcpu "65816"
.segment "CODE"
.org $AC96
map_control_0dac96:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
