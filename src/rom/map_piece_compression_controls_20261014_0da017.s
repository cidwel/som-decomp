.setcpu "65816"
.segment "CODE"
.org $A017
map_control_0da017:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
