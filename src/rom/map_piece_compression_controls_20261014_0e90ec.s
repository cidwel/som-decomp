.setcpu "65816"
.segment "CODE"
.org $90EC
map_control_0e90ec:
    .byte $E8 ; backreference distance high bits
    .byte $5E ; distance low bit/count
