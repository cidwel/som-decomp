.setcpu "65816"
.segment "CODE"
.org $F07E
map_control_0ff07e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
