.setcpu "65816"
.segment "CODE"
.org $72AD
map_control_0c72ad:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
