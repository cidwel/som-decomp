.setcpu "65816"
.segment "CODE"
.org $6DCD
map_control_0e6dcd:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
