.setcpu "65816"
.segment "CODE"
.org $78A0
map_control_0e78a0:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
