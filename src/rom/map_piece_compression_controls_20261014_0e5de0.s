.setcpu "65816"
.segment "CODE"
.org $5DE0
map_control_0e5de0:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
