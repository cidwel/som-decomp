.setcpu "65816"
.segment "CODE"
.org $ABF2
map_control_0dabf2:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
