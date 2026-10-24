.setcpu "65816"
.segment "CODE"
.org $4571
map_control_0d4571:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
