.setcpu "65816"
.segment "CODE"
.org $97C8
map_control_0d97c8:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
