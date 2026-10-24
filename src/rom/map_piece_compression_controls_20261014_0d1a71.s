.setcpu "65816"
.segment "CODE"
.org $1A71
map_control_0d1a71:
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
