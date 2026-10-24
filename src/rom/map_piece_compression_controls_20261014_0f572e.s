.setcpu "65816"
.segment "CODE"
.org $572E
map_control_0f572e:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
