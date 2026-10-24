.setcpu "65816"
.segment "CODE"
.org $46F4
map_control_0e46f4:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
