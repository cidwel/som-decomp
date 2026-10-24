.setcpu "65816"
.segment "CODE"
.org $8AB7
map_control_0e8ab7:
    .byte $EB ; backreference distance high bits
    .byte $8E ; distance low bit/count
