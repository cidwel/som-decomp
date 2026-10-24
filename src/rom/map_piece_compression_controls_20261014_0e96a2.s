.setcpu "65816"
.segment "CODE"
.org $96A2
map_control_0e96a2:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
