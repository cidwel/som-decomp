.setcpu "65816"
.segment "CODE"
.org $199E
map_control_0d199e:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
