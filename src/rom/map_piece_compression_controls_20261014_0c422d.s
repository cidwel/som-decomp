.setcpu "65816"
.segment "CODE"
.org $422D
map_control_0c422d:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
