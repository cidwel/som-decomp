.setcpu "65816"
.segment "CODE"
.org $A931
map_control_0ea931:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
