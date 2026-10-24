.setcpu "65816"
.segment "CODE"
.org $A4ED
map_control_0fa4ed:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
