.setcpu "65816"
.segment "CODE"
.org $4688
map_control_0e4688:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
