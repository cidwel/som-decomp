.setcpu "65816"
.segment "CODE"
.org $F621
map_control_0cf621:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
