.setcpu "65816"
.segment "CODE"
.org $2A65
map_control_0d2a65:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
