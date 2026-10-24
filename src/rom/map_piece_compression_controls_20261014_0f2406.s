.setcpu "65816"
.segment "CODE"
.org $2406
map_control_0f2406:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
