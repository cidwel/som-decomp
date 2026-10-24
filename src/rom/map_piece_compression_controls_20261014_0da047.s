.setcpu "65816"
.segment "CODE"
.org $A047
map_control_0da047:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
