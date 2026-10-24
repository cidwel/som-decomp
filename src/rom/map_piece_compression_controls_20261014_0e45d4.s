.setcpu "65816"
.segment "CODE"
.org $45D4
map_control_0e45d4:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
