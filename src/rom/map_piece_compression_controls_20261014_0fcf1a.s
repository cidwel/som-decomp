.setcpu "65816"
.segment "CODE"
.org $CF1A
map_control_0fcf1a:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
