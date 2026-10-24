.setcpu "65816"
.segment "CODE"
.org $65AD
map_control_0d65ad:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
