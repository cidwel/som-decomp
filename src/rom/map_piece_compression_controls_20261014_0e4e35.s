.setcpu "65816"
.segment "CODE"
.org $4E35
map_control_0e4e35:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
