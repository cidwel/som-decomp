.setcpu "65816"
.segment "CODE"
.org $5FDA
map_control_0e5fda:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
