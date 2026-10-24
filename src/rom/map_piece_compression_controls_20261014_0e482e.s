.setcpu "65816"
.segment "CODE"
.org $482E
map_control_0e482e:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
