.setcpu "65816"
.segment "CODE"
.org $BB18
map_control_0ebb18:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
