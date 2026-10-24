.setcpu "65816"
.segment "CODE"
.org $97CE
map_control_0e97ce:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
