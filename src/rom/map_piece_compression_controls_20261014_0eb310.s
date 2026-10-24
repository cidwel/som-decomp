.setcpu "65816"
.segment "CODE"
.org $B310
map_control_0eb310:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
