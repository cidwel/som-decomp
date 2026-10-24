.setcpu "65816"
.segment "CODE"
.org $97E4
map_control_0e97e4:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
