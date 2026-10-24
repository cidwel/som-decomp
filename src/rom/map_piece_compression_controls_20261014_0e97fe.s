.setcpu "65816"
.segment "CODE"
.org $97FE
map_control_0e97fe:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
