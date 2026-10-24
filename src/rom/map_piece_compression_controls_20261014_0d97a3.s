.setcpu "65816"
.segment "CODE"
.org $97A3
map_control_0d97a3:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
