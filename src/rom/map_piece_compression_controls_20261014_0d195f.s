.setcpu "65816"
.segment "CODE"
.org $195F
map_control_0d195f:
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
