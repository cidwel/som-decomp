.setcpu "65816"
.segment "CODE"
.org $A077
map_control_0da077:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
