.setcpu "65816"
.segment "CODE"
.org $9655
map_control_0e9655:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
