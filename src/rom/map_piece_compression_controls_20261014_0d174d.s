.setcpu "65816"
.segment "CODE"
.org $174D
map_control_0d174d:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
