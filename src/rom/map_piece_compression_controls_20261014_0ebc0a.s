.setcpu "65816"
.segment "CODE"
.org $BC0A
map_control_0ebc0a:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $A6 ; distance low bit/count
