.setcpu "65816"
.segment "CODE"
.org $895D
map_control_0d895d:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
