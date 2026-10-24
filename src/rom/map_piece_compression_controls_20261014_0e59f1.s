.setcpu "65816"
.segment "CODE"
.org $59F1
map_control_0e59f1:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
