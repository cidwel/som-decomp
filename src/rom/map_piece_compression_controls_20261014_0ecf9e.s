.setcpu "65816"
.segment "CODE"
.org $CF9E
map_control_0ecf9e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
