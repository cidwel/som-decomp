.setcpu "65816"
.segment "CODE"
.org $A355
map_control_0fa355:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
