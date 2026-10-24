.setcpu "65816"
.segment "CODE"
.org $A905
map_control_0ea905:
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
