.setcpu "65816"
.segment "CODE"
.org $97B8
map_control_0e97b8:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
