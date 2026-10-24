.setcpu "65816"
.segment "CODE"
.org $A0BF
map_control_0fa0bf:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
