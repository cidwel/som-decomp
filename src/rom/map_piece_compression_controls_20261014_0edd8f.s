.setcpu "65816"
.segment "CODE"
.org $DD8F
map_control_0edd8f:
    .byte $ED ; backreference distance high bits
    .byte $97 ; distance low bit/count
