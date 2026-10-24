.setcpu "65816"
.segment "CODE"
.org $A0DE
map_control_0fa0de:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
