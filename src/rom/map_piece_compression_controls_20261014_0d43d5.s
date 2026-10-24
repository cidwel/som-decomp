.setcpu "65816"
.segment "CODE"
.org $43D5
map_control_0d43d5:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
