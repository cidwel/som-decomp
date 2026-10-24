.setcpu "65816"
.segment "CODE"
.org $A0D4
map_control_0fa0d4:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
