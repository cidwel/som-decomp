.setcpu "65816"
.segment "CODE"
.org $798B
map_control_0c798b:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
