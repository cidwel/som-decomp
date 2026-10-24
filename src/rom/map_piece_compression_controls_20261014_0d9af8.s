.setcpu "65816"
.segment "CODE"
.org $9AF8
map_control_0d9af8:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
