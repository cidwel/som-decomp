.setcpu "65816"
.segment "CODE"
.org $A23E
map_control_0ea23e:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
