.setcpu "65816"
.segment "CODE"
.org $6008
map_control_0e6008:
    .byte $E8 ; backreference distance high bits
    .byte $35 ; distance low bit/count
