.setcpu "65816"
.segment "CODE"
.org $4649
map_control_0e4649:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
