.setcpu "65816"
.segment "CODE"
.org $91D1
map_control_0c91d1:
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
