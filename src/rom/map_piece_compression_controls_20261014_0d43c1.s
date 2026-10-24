.setcpu "65816"
.segment "CODE"
.org $43C1
map_control_0d43c1:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
