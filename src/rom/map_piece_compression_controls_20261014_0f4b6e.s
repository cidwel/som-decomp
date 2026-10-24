.setcpu "65816"
.segment "CODE"
.org $4B6E
map_control_0f4b6e:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
