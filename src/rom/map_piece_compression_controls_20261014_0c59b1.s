.setcpu "65816"
.segment "CODE"
.org $59B1
map_control_0c59b1:
    .byte $E9 ; backreference distance high bits
    .byte $89 ; distance low bit/count
