.setcpu "65816"
.segment "CODE"
.org $A44C
map_control_0ea44c:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
