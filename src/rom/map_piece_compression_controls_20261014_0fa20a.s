.setcpu "65816"
.segment "CODE"
.org $A20A
map_control_0fa20a:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
