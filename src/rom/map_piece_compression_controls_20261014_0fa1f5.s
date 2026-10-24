.setcpu "65816"
.segment "CODE"
.org $A1F5
map_control_0fa1f5:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
