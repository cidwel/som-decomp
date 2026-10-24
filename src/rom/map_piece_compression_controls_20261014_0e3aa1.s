.setcpu "65816"
.segment "CODE"
.org $3AA1
map_control_0e3aa1:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
