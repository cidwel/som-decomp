.setcpu "65816"
.segment "CODE"
.org $07A2
map_control_0e07a2:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
