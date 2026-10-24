.setcpu "65816"
.segment "CODE"
.org $A452
map_control_0ea452:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
