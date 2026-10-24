.setcpu "65816"
.segment "CODE"
.org $A21B
map_control_0fa21b:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
