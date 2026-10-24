.setcpu "65816"
.segment "CODE"
.org $7D5E
map_control_0c7d5e:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
