.setcpu "65816"
.segment "CODE"
.org $826F
map_control_0e826f:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
