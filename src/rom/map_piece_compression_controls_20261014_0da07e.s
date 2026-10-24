.setcpu "65816"
.segment "CODE"
.org $A07E
map_control_0da07e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
