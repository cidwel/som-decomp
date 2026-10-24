.setcpu "65816"
.segment "CODE"
.org $A4CF
map_control_0ea4cf:
    .byte $EA ; backreference distance high bits
    .byte $0A ; distance low bit/count
