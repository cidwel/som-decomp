.setcpu "65816"
.segment "CODE"
.org $A48F
map_control_0fa48f:
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $50 ; distance low bit/count
