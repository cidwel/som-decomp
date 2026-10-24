.setcpu "65816"
.segment "CODE"
.org $A997
map_control_0ea997:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
