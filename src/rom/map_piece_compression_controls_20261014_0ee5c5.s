.setcpu "65816"
.segment "CODE"
.org $E5C5
map_control_0ee5c5:
    .byte $E8 ; backreference distance high bits
    .byte $AF ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $A2 ; distance low bit/count
