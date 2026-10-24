.setcpu "65816"
.segment "CODE"
.org $8A95
map_control_0d8a95:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
