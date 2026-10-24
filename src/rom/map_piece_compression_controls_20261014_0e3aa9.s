.setcpu "65816"
.segment "CODE"
.org $3AA9
map_control_0e3aa9:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
