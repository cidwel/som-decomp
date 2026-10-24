.setcpu "65816"
.segment "CODE"
.org $9271
map_control_0c9271:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
