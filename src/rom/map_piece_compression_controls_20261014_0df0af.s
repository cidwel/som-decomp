.setcpu "65816"
.segment "CODE"
.org $F0AF
map_control_0df0af:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
