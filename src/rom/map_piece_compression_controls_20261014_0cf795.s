.setcpu "65816"
.segment "CODE"
.org $F795
map_control_0cf795:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
