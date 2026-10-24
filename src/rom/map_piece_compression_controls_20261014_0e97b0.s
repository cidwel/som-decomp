.setcpu "65816"
.segment "CODE"
.org $97B0
map_control_0e97b0:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
