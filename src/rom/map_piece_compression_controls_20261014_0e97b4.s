.setcpu "65816"
.segment "CODE"
.org $97B4
map_control_0e97b4:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
