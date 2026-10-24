.setcpu "65816"
.segment "CODE"
.org $A976
map_control_0da976:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
