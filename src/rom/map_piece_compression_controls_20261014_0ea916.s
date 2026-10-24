.setcpu "65816"
.segment "CODE"
.org $A916
map_control_0ea916:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
