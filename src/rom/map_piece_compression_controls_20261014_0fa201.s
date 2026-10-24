.setcpu "65816"
.segment "CODE"
.org $A201
map_control_0fa201:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
