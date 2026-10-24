.setcpu "65816"
.segment "CODE"
.org $FB1B
map_control_0dfb1b:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
