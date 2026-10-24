.setcpu "65816"
.segment "CODE"
.org $43A2
map_control_0d43a2:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
