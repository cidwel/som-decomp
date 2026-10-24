.setcpu "65816"
.segment "CODE"
.org $0CD0
map_control_0c0cd0:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
